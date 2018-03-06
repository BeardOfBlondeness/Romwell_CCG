#include "../global.h"
#include "../render/Sprite.h"
#include <vector>

using namespace std;

class Game {
public:
  Game(int deck1[], int deck2[]);
  Game();
  ~Game();
  bool WaitForTurn(bool playerTurn);
  int* getDeck(int deck);
  void Run();
private:
  int* randomiseDeckOrder(int deck[]);
  bool vectorContains(vector<int> vec, int val);
  void placeDecks();
  static const int deckSize = 31;
  int *deck1, *deck2;
  int *randomisedOrder = new int[deckSize];
  bool playerTurn, gameBegin;
  vector<int> hand1, hand2, board1, board2;
  Sprite board;
};
