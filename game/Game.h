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
  void drawDecks();
  static const int deckSize = 31;
  int *deck1, *deck2;
  int *randomisedOrder = new int[deckSize];
  int cardNum;
  static const double deckScales = 1/1.5;
  bool playerTurn, gameBegin, entryAnimationDeck;
  vector<int> hand1, hand2, board1, board2;
  Sprite boardImage;
  Sprite *deck1Image = new Sprite[deckSize-1];
  Sprite *deck2Image = new Sprite[deckSize-1];
};
