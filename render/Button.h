#pragma once
#include "Sprite.h"

class Button : public Sprite {
public:
  void init(string path, int x, int y, int width, int height);
  void init(string path);
  int isClicked();
  void Hover();
  void setPos(int xPos, int yPos);
  void setSize(float x, float y);
private:
  int originalX;
  int originalY;
  int offsetX;
  int offsetY;
  int clickOffsetX;
  int clickOffsetY;
  bool isHovered = false, mouseDown = false;
  sf::Vector2i pos;
};
