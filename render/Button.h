#include "Sprite.h"

class Button : public Sprite {
public:
  void init(string path, int x, int y, int width, int height);
  bool isClicked();
  void Hover();
private:
  int offsetX;
  int offsetY;
  int clickOffsetX = offsetX/2;
  int clickOffsetY = offsetY/2;
  bool isHovered = false, mouseDown = false;
  sf::Vector2i pos;
};
