#include "../global.h"
#include "Card.h"

class TopHat : public Card {
public:
  TopHat();
private:
  string path = "res/game/cards/topHat.png";
  string desc = "Increase your Default cards damage by 1";
};