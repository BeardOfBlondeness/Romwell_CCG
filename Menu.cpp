#include "Menu.h"

Menu::Menu() {
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

void Menu::DrawBackground() {
  KeepFrameCount();
  if(clock1.getElapsedTime().asMilliseconds() - lastDrawTime > frameLength) {
    IncrementBackgroundSprite();
    lastDrawTime = clock1.getElapsedTime().asMilliseconds();
  }
}

void Menu::ButtonOperators() {
  play.Hover();
  deckBuilder.Hover();
  quit.Hover();
  background.Draw();
  title.Draw();
  play.Draw();
  deckBuilder.Draw();
  quit.Draw();

  play.isClicked();
  deckBuilder.isClicked();
  if(quit.isClicked()==2)window.close();
}

void Menu::KeepFrameCount() {
  if(frameCount%8==0) {
    frameCount = 0;
  } else {
    frameCount++;
  }
}

void Menu::IncrementBackgroundSprite() {
  if(currentBackgroundSprite < 6) {
    currentBackgroundSprite++;
  } else {
    currentBackgroundSprite = 0;
  }
  background.setRect(currentBackgroundSprite*1920, 0, 1920, 1080);
}
