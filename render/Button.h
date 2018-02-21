#include "Sprite.h"

class Button : public Sprite {
public:
  void init(string path, int x, int y, int width, int height);
  bool isClicked();
  void Hover();
private:
  int offsetX;
  int offsetY;
  bool isHovered = false;
  sf::Vector2i pos;
};
