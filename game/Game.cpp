#include <stdlib.h>
#include "Game.h"

Game::Game(Card deck1[], Card deck2[]) {
  std::cout << "Creating game";
  this->deck1 = randomiseDeckOrder(deck1);
  this->deck2 = randomiseDeckOrder(deck2);
  //board1.push_back();
  //board2.push_back(deck2[0]);
  boardImage.init("res/game/background.png", 0, 0, 1920, 1080);
  for(int i = 0; i < deckSize-1; i++) {
    deck1Image[i].init("res/game/cardBack.png", 1700, -410);
    deck1Image[i].setSize(deckScales, deckScales);
    deck2Image[i].init("res/game/cardBack.png", 1700, 1480);
    deck2Image[i].setSize(deckScales, deckScales);
  }
  entryAnimationDeck = true;
  cardNum = 0;
  gameBegin = true;
}

/*
*TODO delete this
*/
Game::Game() {
  board1.push_back(new DefaultCard());
  board2.push_back(new DefaultCard());
  boardImage.init("res/game/background.png", 0, 0, 1920, 1080);
  gameBegin = true;
  entryAnimationDeck = true;
  board1.at(0)->setSize(deckScales, deckScales);
  board2.at(0)->setSize(deckScales, deckScales);
  board1.at(0)->setLocation(xBoard, yEnemyBoard);
  board2.at(0)->setLocation(xBoard, yYourBoard);
  for(int i = 0; i < deckSize-1; i++) {
    deck1Image[i].init("res/game/cardBack.png", 1653, -400);
    deck1Image[i].setSize(deckScales, deckScales);
    deck2Image[i].init("res/game/cardBack.png", 1649, 1180);
    deck2Image[i].setSize(deckScales, deckScales);
  }
  cardNum = 0;
}

Game::~Game() {
  std::cout << "Deleting initialised memory space for Game";
  delete [] randomisedOrder;
  delete [] deck1Image;
  delete [] deck2Image;
}

bool Game::WaitForTurn(bool playerTurn) {
  return 0;
}

Card* Game::randomiseDeckOrder(Card deck[]) {
  Card takenItem;
  vector<Card> takenItemList;
  for(int i=0;i<deckSize;i++) {
    do {
      takenItem = deck[rand() % 31 + 1];
    }while(vectorContains(takenItemList, takenItem));
    randomisedOrder[i] = takenItem;
    takenItemList.push_back(takenItem);
  }
  return randomisedOrder;
}

Card* Game::getDeck(int deck) {
  Card* retDeck;
  if(deck == 1) {
    retDeck = deck1;
  }else {
    retDeck = deck2;
  }
  return retDeck;
}

bool Game::vectorContains(vector<Card> vec, Card val) {
  for(int i=0;i<vec.size();i++) {
    if(vec.at(i).getName() == val.getName()) return true;
  }
  return false;
}

void Game::Run() {
  boardImage.Draw();
  if(gameBegin)
    placeDecks();
  drawDecks();
  drawHands();
}

void Game::drawHands() {
  cout << "SIZE: " << board1.size();
  if(board1.size() > 0) {
    cout << "Its inside the if";
    for(int i = 0; i < board1.size(); i++) {
      board1.at(i)->Card::DrawCard();
    }
  }
  if(board2.size() > 0) {
    for(int i = 0; i < board2.size(); i++) {
      board2.at(i)->Card::DrawCard();
    }
  }
}

void Game::placeDecks() {
  if(entryAnimationDeck) {
    if(deck1Image[cardNum].getYPos() < 3)
      deck1Image[cardNum].setPos(deck1Image[cardNum].getXPos(), deck1Image[cardNum].getYPos()+80);
    else {
      deck1Image[cardNum].setPos(deck1Image[cardNum].getXPos(), 105);
      cardNum++;
      if(cardNum >= 30) {
        entryAnimationDeck = false;
        cardNum = 0;
      }
    }
  } else {
    if(deck2Image[cardNum].getYPos() > 760)
      deck2Image[cardNum].setPos(deck2Image[cardNum].getXPos(), deck2Image[cardNum].getYPos()-80);
    else {
      deck2Image[cardNum].setPos(deck2Image[cardNum].getXPos(), 680);
      cardNum++;
      cout << "\n\n\n" << cardNum << " For 2";
      if(cardNum >= 30)
        gameBegin = false;
    }
  }
}

void Game::drawDecks() {
  for(int i = 0; i < deckSize-1; i++) {
    deck1Image[i].Draw();
    deck2Image[i].Draw();
  }
}
