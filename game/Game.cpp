#include <stdlib.h>
#include "Game.h"

Game::Game(int deck1[], int deck2[]) {
  std::cout << "Creating game";
  this->deck1 = randomiseDeckOrder(deck1);
  this->deck2 = randomiseDeckOrder(deck2);
  board1.push_back(deck1[0]);
  board2.push_back(deck2[0]);
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
  boardImage.init("res/game/background.png", 0, 0, 1920, 1080);
  gameBegin = true;
  entryAnimationDeck = true;
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

int* Game::randomiseDeckOrder(int deck[]) {
  int takenItem;
  vector<int> takenItemList;
  for(int i=0;i<deckSize;i++) {
    do {
      takenItem = deck[rand() % 31 + 1];
    }while(vectorContains(takenItemList, takenItem));
    randomisedOrder[i] = takenItem;
    takenItemList.push_back(takenItem);
  }
  return randomisedOrder;
}

int* Game::getDeck(int deck) {
  int* retDeck;
  if(deck == 1) {
    retDeck = deck1;
  }else {
    retDeck = deck2;
  }
  return retDeck;
}

bool Game::vectorContains(vector<int> vec, int val) {
  for(int i=0;i<vec.size();i++) {
    if(vec.at(i) == val) return true;
  }
  return false;
}

void Game::Run() {
  boardImage.Draw();
  if(gameBegin)
    placeDecks();
  drawDecks();
}

void Game::placeDecks() {
  if(entryAnimationDeck) {
    if(deck1Image[cardNum].getYPos() < 03)
      deck1Image[cardNum].setPos(deck1Image[cardNum].getXPos(), deck1Image[cardNum].getYPos()+80);
    else {
      deck1Image[cardNum].setPos(deck1Image[cardNum].getXPos(), 105);
      cardNum++;
      if(cardNum > 30) {
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
      if(cardNum > 30)
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
