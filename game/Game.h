#include "../global.h"
#include <vector>
using namespace std;

class Game {
public:
  Game(int[] deck1, int[] deck2);
  bool waitForTurn(bool playerTurn);
private:
  int* randomiseDeckOrder(int[] deck);
  bool vectorContains(vector<int> vec, int val);
  const int deckSize = 31;
  int deck1[deckSize], deck2[deckSize];
  bool playerTurn;
  vector<int> hand1, hand2, board1, board2;
};
