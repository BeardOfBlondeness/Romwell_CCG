#include "../global.h"
#include "../render/Sprite.h"
#include "../cards/Card.h"
#include "../cards/DefaultCard.h"
#include <vector>
#include <SFML/Audio.hpp>
using namespace std;

class Game {
public:
  Game(Card deck1[], Card deck2[]);
  Game();
  ~Game();
  bool WaitForTurn(bool playerTurn);
  Card* getDeck(int deck);
  void Run();
private:
  Card* randomiseDeckOrder(Card deck[]);
  bool vectorContains(vector<Card> vec, Card val);
  void placeDecks();
  void drawDecks();
  void drawHands();
  static const int deckSize = 31;
  const int yEnemyBoard = 225;
  const int yYourBoard = 550;
  const int xBoard = 400;
  Card *deck1, *deck2;
  Card *randomisedOrder = new Card[deckSize];
  int cardNum;
  const double deckScales = 1/1.5;
  bool playerTurn, gameBegin, entryAnimationDeck;
  vector<Card*> hand1, hand2, board1, board2;
  Sprite boardImage;
  Sprite *deck1Image = new Sprite[deckSize-1];
  Sprite *deck2Image = new Sprite[deckSize-1];
  sf::Music cardSound;
};
