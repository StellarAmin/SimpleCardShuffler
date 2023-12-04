// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#ifdef CONSOLECARDS_EXPORTS
#define CONSOLECARDS_API __declspec(dllexport)
#else
#define CONSOLECARDS_API __declspec(dllimport)
#endif
#define stringify(name)

#include "Rank.h"
#include "Suit.h"
#include <iostream>

namespace consoleCards
{
	/**
	 * A playing card
	*/
	class CONSOLECARDS_API Card
	{
	private:
		Rank rank;
		Suit suit;
		bool bFaceUp;
	public:
		/**
		 * Constructs a card with the given rank and suit
		 * @param Rank rank
		 * @param Suit suit
		*/
		Card(consoleCards::Rank Rank, consoleCards::Suit Suit) {
			this->rank = Rank;
			this->suit = Suit;
			bFaceUp = false;
		};

		/**
		 * Gets the string representation of the card rank. If
		 *		the card isn't face up, returns a string to that effect
		 * @return rank
		*/
		std::string GetRank() {
			if (bFaceUp) return "Card is not face up";
			return to_rankString(rank);
		}

		/**
		 * Gets the string representation of the card suit. If
		 *		the card isn't face up, returns a string to that effect
		 * @return suit
		*/
		std::string GetSuit() {
			if (bFaceUp) return "Card is not face up";
			return to_suitString(suit);
		}

		/**
		 * Gets whether or not the card is face up
		 * @return true if face up, false if face down
		*/
		bool IsFaceUp() {
			return bFaceUp;
		}

		/**
		 * Flips the card over
		*/
		void FlipOver() {
			bFaceUp = !bFaceUp;
		}

		/**
		 * Prints the card
		*/
		void Print() {
			std::cout << GetSuit() << " of " << GetRank() << "\n";
		}
	};
}