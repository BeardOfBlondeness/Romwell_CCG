#include "../global.h"
#include "../render/Sprite.h"
#include "../cards/Card.h"
#include "../cards/DefaultCard.h"
#include "../cards/TopHat.h"
#include <vector>
#include <SFML/Audio.hpp>
using namespace std;

class Game {
public:
  Game(Card deck1[], Card deck2[]);
  Game();
  void init(Card deck1[], Card deck2[]);
  ~Game();
  bool WaitForTurn(bool playerTurn);
  Card* getDeck(int deck);
  void Run();
private:
  Card* randomiseDeckOrder(Card deck[]);
  bool vectorContains(vector<Card> vec, Card val);
  void placeDecks();
  void drawDecks();
  void drawBoards();
  void placeHands();
  void drawHands();
  static const int deckSize = 31;
  const int yEnemyBoard = 225;
  const int yYourBoard = 550;
  const int xBoard = 400;
  const int yHand = 700;
  const int yEnemyHand = -100;
  Card *deck1, *deck2;
  Card *randomisedOrder = new Card[deckSize];
  int cardNum, deck1Counter, deck2Counter;
  const double deckScales = 1/1.5;
  bool playerTurn, gameBegin, giveHands, entryAnimationDeck;
  vector<Card*> board1, board2;
  vector<Card> hand1, hand2;
  Sprite boardImage;
  Sprite *deck1Image = new Sprite[deckSize-1];
  Sprite *deck2Image = new Sprite[deckSize-1];
  sf::Music cardSound;
};
