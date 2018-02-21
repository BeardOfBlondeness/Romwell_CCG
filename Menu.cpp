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
}

Menu::~Menu() {

}

void Menu::DrawBackground() {
  KeepFrameCount();
  if(clock1.getElapsedTime().asMilliseconds() - lastDrawTime > frameLength) {
    IncrementBackgroundSprite();
    lastDrawTime = clock1.getElapsedTime().asMilliseconds();
  }
  play.Hover();
  deckBuilder.Hover();
  quit.Hover();
  background.Draw();
  title.Draw();
  play.Draw();
  deckBuilder.Draw();
  quit.Draw();

  if(play.isClicked()) {
    std::cout << "Pressed";
  }
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
