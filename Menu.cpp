#include "Menu.h"


/*
* Constructor for the menu, initiates all sprites and adds rain sound
*/
Menu::Menu() {
  state = 0;
  currentBackgroundSprite = 0;
  background.init(bgPath, 0, 0, 1920, 1080);
  title.init(titlePath, 460, 80, 500, 200);
  play.init(playPath, 710, 400, 500, 200);
  deckBuilder.init(deckBuilderPath, 710, 600, 500, 200);
  quit.init(quitPath, 710, 800, 500, 200);
  title.InitiateSprite();
  background.InitiateSprite();
  play.InitiateSprite();
  deckBuilder.InitiateSprite();
  quit.InitiateSprite();
  if (!rain.openFromFile("res/menu/rain.wav")){
    std::cout << "Error..." << std::endl;
  } else{
    rain.setLoop(true);
    rain.setVolume(50);
    rain.play();
  }
}

Menu::~Menu() {

}

/*
* Draws the background image for the menu
*/
void Menu::DrawBackground() {
  KeepFrameCount();
  if(clock1.getElapsedTime().asMilliseconds() - lastDrawTime > frameLength) {
    IncrementBackgroundSprite();
    lastDrawTime = clock1.getElapsedTime().asMilliseconds();
  }
}

/*
* Draws the buttons and adds their operations
*/
void Menu::ButtonOperators() {
  play.Hover();
  deckBuilder.Hover();
  quit.Hover();
  background.Draw();
  title.Draw();
  play.Draw();
  deckBuilder.Draw();
  quit.Draw();
  if(play.isClicked()==2)state=1;
  if(deckBuilder.isClicked()==2)state=2;
  if(quit.isClicked()==2)window.close();
}

void Menu::KeepFrameCount() {
  if(frameCount%8==0) {
    frameCount = 0;
  } else {
    frameCount++;
  }
}

/*
* Animates the background using the sprite sheet
*/
void Menu::IncrementBackgroundSprite() {
  if(currentBackgroundSprite < 6) {
    currentBackgroundSprite++;
  } else {
    currentBackgroundSprite = 0;
  }
  background.setRect(currentBackgroundSprite*1920, 0, 1920, 1080);
}

/*
*Selects the state for the game to be in, e.g. "in game" or "in deck builder"
*/
void Menu::State() {
  cout << state;
  if(state == 0) {
    DrawBackground();
    ButtonOperators();
  }else if(state == 2) {

  }
}
