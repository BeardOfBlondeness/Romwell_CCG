#pragma once
#include "../global.h"
#include "Card.h"

class DefaultCard : public Card {
public:
  DefaultCard();
private:
  const string path = "res/game/cards/default.png";
  const string desc = "Your Default Card";
};
