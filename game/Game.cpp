#include <stdlib.h>
#include "Game.h"

Game::Game(Card deck1[], Card deck2[]) {
  /*std::cout << "Creating game";
  this->deck1 = randomiseDeckOrder(deck1);
  this->deck2 = randomiseDeckOrder(deck2);
  for(int i = 0; i < 5; i++) {
    hand1.push_back(deck1[i]);
    hand2.push_back(deck2[i]);
    hand1.at(i)->setSize(deckScales, deckScales);
    hand2.at(i)->setSize(deckScales, deckScales);
    hand1.at(i)->setLocation(xBoard+(i*250), yHand);
    hand2.at(i)->setLocation(xBoard+(i*250), yEnemyHand);
  }
  board1.push_back(new DefaultCard());
  board2.push_back(new DefaultCard());
  boardImage.init("res/game/background.png", 0, 0, 1920, 1080);
  gameBegin = true;
  giveHands = false;
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
  if (!cardSound.openFromFile("res/game/cardSound.wav")){
    std::cout << "Error..." << std::endl;
  } else{
    cardSound.setVolume(50);
  }
  cardNum = 0;*/
}

/*
* TODO fix the BAD ALLOC for deck1 (maybe make them pointerS?)
*/
void Game::init(Card* deck1[], Card* deck2[]) {
  std::cout << endl << endl << "Displaying COntents After: " << endl;
  for(int i = 0; i < 30; i++) {
    cout << deck1[i]->getName() << endl;
  }
  cout << "beginning init";
  //this->deck1 = randomiseDeckOrder(deck1);
  cout << "randomised deck1";
  //this->deck2 = randomiseDeckOrder(deck2);
  cout << "randomised deck2";
  cout << endl << endl << endl << "THIS IS 2s name:" << deck1[1]->getName();
  for(int i = 0; i < 5; i++) {
    cout << "BEGINNING FOR LOOP" << endl;
    hand1.push_back(deck1[i]);
    cout << "pushing back";
    cout << endl << endl << endl << "THIS IS HAND1S name:" << hand1.at(i)->getName();
    hand2.push_back(deck2[i]);
    cout << endl << endl << endl << "THIS IS HAND2S SIZE: " << hand2.size();
    cout << "pushed back for " << i << endl;
    hand1.at(i)->setSize(deckScales, deckScales);
    hand2.at(i)->setSize(deckScales, deckScales);
    cout << " set Sizes for " << i << endl;
    hand1.at(i)->setLocation(xBoard+(i*250), yHand);
    hand2.at(i)->setLocation(xBoard+(i*250), yEnemyHand);
    cout << " set locations for " << i << endl;
  }
  board1.push_back(new DefaultCard());
  board2.push_back(new DefaultCard());
  boardImage.init("res/game/background.png", 0, 0, 1920, 1080);
  gameBegin = true;
  giveHands = false;
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
  if (!cardSound.openFromFile("res/game/cardSound.wav")){
    std::cout << "Error..." << std::endl;
  } else{
    cardSound.setVolume(50);
  }
  cardNum = 0;
}

Game::Game(){}

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
  if(deck == 1)
    retDeck = deck1;
  else
    retDeck = deck2;
  return retDeck;
}

bool Game::vectorContains(vector<Card> vec, Card val) {
  for(int i=0;i<vec.size();i++) {
    if(vec.at(i).getName() == val.getName()) return true;
  }
  return false;
}

void Game::Run() {
  cout << endl << "drawing board image!";
  boardImage.Draw();
  cout << endl << "beginning game";
  if(gameBegin)
    placeDecks();
  else if(giveHands)
    placeHands();
  cout << endl << "drawing hands";
  drawHands();
  cout << endl << "drawing decks";
  drawDecks();
  cout << endl << "drawing boards";
  drawBoards();
}

void Game::drawHands() {
  cout << endl << "SIZE of hand1: " << hand1.size();
  if(hand1.size() > 0) {
    for(int i = 0; i < hand1.size(); i++) {
      cout << endl << "Drawing card for1 " << i;
      hand1.at(i)->DrawCard();
    }
    for(int i = 0; i < hand2.size(); i++) {
      cout << endl << "Drawing card for2 " << i;
      hand2.at(i)->DrawCard();
    }
  }
}

void Game::drawBoards() {
  if(board1.size() > 0) {
    for(int i = 0; i < board1.size(); i++) {
      board1.at(i)->Card::Hover();
      board1.at(i)->Card::DrawCard();
    }
  }
  if(board2.size() > 0) {
    for(int i = 0; i < board2.size(); i++) {
      board2.at(i)->Card::Hover();
      board2.at(i)->Card::DrawCard();
    }
  }
}

void Game::placeDecks() {
  cardSound.play();
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
      if(cardNum >= 30) {
        gameBegin = false;
        giveHands = true;
        cardSound.stop();
      }
    }
  }
}

void Game::placeHands() {
  for(int i = 0; i < 5; i++) {
    if(hand1.at(i)->getYPos() < yEnemyHand)
      hand1.at(i)->setLocation(hand1.at(i)->getXPos(), hand1.at(i)->getYPos() + 10);
    if(hand2.at(i)->getYPos() > yHand)
      hand2.at(i)->setLocation(hand2.at(i)->getXPos(), hand1.at(i)->getYPos() - 10);
    else
      giveHands = false;
  }
}

void Game::drawDecks() {
  for(int i = 0; i < deckSize-1; i++) {
    deck1Image[i].Draw();
    deck2Image[i].Draw();
  }
}
