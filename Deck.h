// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#ifdef CONSOLECARDS_EXPORTS
#define CONSOLECARDS_API __declspec(dllexport)
#else
#define CONSOLECARDS_API __declspec(dllimport)
#endif

#include "Card.h"
#include "Random.h"
#include <random>
#include <vector>
#include <iostream>
#include <list>

namespace consoleCards
{
	/**
	 * A deck of cards
	*/
	class CONSOLECARDS_API Deck
	{
	private:
		std::vector<Card> Cards;
	public:
		/**
		 * Constructor
		*/
		Deck() {
			Random::Initialize();
			for (int i = 0; i < 52; i++) {
				Cards.push_back(Card(Rank(Random::Next(13)), Suit(Random::Next(4))));
			}
		}

		/**
		 * Gets whether or not the deck is empty
		 * @return true if the deck is empty, false otherwise
		*/
		bool IsEmpty() {
			return Cards.empty();
		};

		/**
		 * Cuts the deck of cards at the given location
		 * @param Location location at which to cut the deck
		*/
		void Cut(unsigned int Location) {
			std::vector<Card> upperCut(Cards.begin(), Cards.begin() + Location);
			std::reverse(upperCut.begin(), upperCut.end());
			std::vector<Card> lowerCut(Cards.begin() + Location, Cards.end());

		};

		/**
		 * Shuffles the deck
		 * @see http://download.oracle.com/javase/1.5.0/docs/api/java/util/Collections.html#shuffle%28java.util.List%29
		*/
		void Shuffle() {
			auto rng = std::default_random_engine{};
			std::shuffle(Cards.begin(), Cards.end(), rng);
		};

		/**
		 * Takes the top card from the deck. If the deck is empty, throws
		 *		an exception
		 * @return top card
		*/
		Card TakeTopCard() {
			Card topCard = Cards[0];
			Cards.erase(Cards.begin());
			return topCard;
		};

		/**
		 * Prints the cards in the deck, top to bottom
		*/
		void Print() {
			for (int i = 0; i < Cards.size(); i++) {
				std::cout << Cards[i].GetRank() << " " << Cards[i].GetSuit() << "\n";
			}
	}
	};
}
