#include <stdlib.h>
#include "Game.h"

Game::Game(int[] deck1, int[] deck2) {
  this->deck1 = randomiseDeckOrder(deck1);
  this->deck2 = randomiseDeckOrder(deck2);
  board1.push_back(deck1[0]);
  board2.push_back(deck2[0]);
}

bool Game::waitForTurn(bool playerTurn) {

}

int* Game::randomiseDeckOrder(int[] deck) {
  int randomisedOrder[deckSize], takenItem;
  vector<int> takenItemList;
  for(int i=0;i<deckSize;i++) {
    do {
      takenItem = deck[rand() % 31 + 1];
    }while(vectorContains(takenItemList, takenItem));
    randomisedOrder[i] = takenItem;
    takenItemList.push_back(takenItem);
  }return randomisedOrder;
}

bool Game::vectorContains(vector<int> vec, int val) {
  for(int i=0;i<vec.size();i++) {
    if(vec.at(i) == val)
      return true;
  }
  return false;
}
