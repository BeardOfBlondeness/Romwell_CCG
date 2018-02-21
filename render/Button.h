#include "Sprite.h"

class Button : public Sprite {
public:
  void init(string path, int x, int y, int width, int height);
  int isClicked();
  void Hover();
private:
  int offsetX;
  int offsetY;
  int clickOffsetX;
  int clickOffsetY;
  bool isHovered = false, mouseDown = false;
  sf::Vector2i pos;
};
