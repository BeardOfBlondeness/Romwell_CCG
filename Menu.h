#include "global.h"
#include "render/Sprite.h"
#include "render/Button.h"

class Menu {
public:
  Menu();
  ~Menu();
  void DrawBackground();
  void KeepFrameCount();
  void IncrementBackgroundSprite();
private:
  Sprite title;
  Sprite background;
  Button play;
  Button deckBuilder;
  Button quit;
  int frameCount, currentBackgroundSprite;
  string titlePath = "res/menu/title.png", bgPath = "res/menu/bgSheet.png", playPath = "res/menu/play.png", deckBuilderPath = "res/menu/deckBuilder.png", quitPath = "res/menu/quit.png";
  double lastDrawTime = 0, frameLength = 1000/24;
  sf::Clock clock1;
};
