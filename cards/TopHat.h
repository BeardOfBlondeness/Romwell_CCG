#pragma once
#include "../global.h"
#include "Card.h"

class TopHat : public Card {
public:
  TopHat();
  void init();
private:
  string path = "res/game/cards/topHat.png";
  string desc = "Icrement damage";
};
