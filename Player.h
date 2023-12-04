#pragma once
#include <vector>
#include "Card.h"

namespace consoleCards{
class Player
{
private:
	std::vector<Card> cards;

public:
	void AddCard(Card card) {
		cards.push_back(card);
	};

	void FlipCards() {
		for (int i = 0; i < cards.size(); i++) {
			cards[i].FlipOver();
		}
	}

	void Print() {
		for (int i = 0; i < cards.size(); i++) {
			cards[i].Print();
		}
	}
};
}