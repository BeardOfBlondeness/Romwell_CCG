#include "Button.h"

bool Button::isClicked() {
  if(isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    if(!mouseDown) {
      setSize(1.05, 1.05);
      setPos(x-clickOffsetX, clickOffsetY);
      mouseDown = true;
      return true;
    }
  }
  if(mouseDown) {
    setSize(1.1, 1.1);
    setPos(x-offsetX, y-offsetY);
  }
  mouseDown = false;
  return false;
}

void Button::init(string path, int x, int y, int width, int height) {
  Sprite::init(path, x, y, width, height);
  offsetX = width/20;
  offsetY = height/20;
}

void Button::Hover() {
  pos = sf::Mouse::getPosition();
  if(pos.x > x && pos.y > y && pos.x < x+width && pos.y < y+height) {
    if(!isHovered) {
      setSize(1.1, 1.1);
      setPos(x-offsetX, y-offsetY);
      isHovered = true;
    }
  } else {
    if(isHovered) {
      setSize(1, 1);
      setPos(x, y);
      isHovered = false;
    }
  }
}
