#include <stdlib.h>
#include "Game.h"

Game::Game(int deck1[], int deck2[]) {
  std::cout << "Creating game";
  this->deck1 = randomiseDeckOrder(deck1);
  this->deck2 = randomiseDeckOrder(deck2);
  board1.push_back(deck1[0]);
  board2.push_back(deck2[0]);
}

Game::~Game() {
  std::cout << "Deleting initialised memory space for Game";
  delete [] randomisedOrder;
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
