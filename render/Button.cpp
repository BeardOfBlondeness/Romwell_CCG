#include "Button.h"

int Button::isClicked() {
  if(isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    if(!mouseDown) {
      setSize(1.05, 1.05);
      setPos(x-clickOffsetX, y-clickOffsetY);
      mouseDown = true;
      return 1;
    }
  } else {
    if(mouseDown && isHovered) {
      setSize(1.1, 1.1);
      setPos(x-offsetX, y-offsetY);
      return 2;
    }
    mouseDown = false;
    return 0;
  }
}

void Button::init(string path, int x, int y, int width, int height) {
  Sprite::init(path, x, y, width, height);
  offsetX = width/20;
  offsetY = height/20;
  clickOffsetX = offsetX/2;
  clickOffsetY = offsetY/2;
  originalX = x;
  originalY = y;
}

void Button::init(string path) {
  Sprite::init(path);
}

void Button::setSize(float x, float y) {
  renderSprite.setScale(x, y);
  offsetX = (width*x)/20;
  offsetY = (height*y)/20;
  clickOffsetX = offsetX/2;
  clickOffsetY = offsetY/2;
}

void Button::setPos(int xPos, int yPos) {
  x = xPos;
  y = yPos;
  originalX = x;
  originalY = y;
  renderSprite.setPosition(xPos, yPos);
}

void Button::Hover() {
  pos = sf::Mouse::getPosition() - window.getPosition();
  if(pos.x > x && pos.y > y && pos.x < x+width && pos.y < y+height) {
    if(!isHovered) {
      Sprite::setSize(1.1, 1.1);
      Sprite::setPos(originalX-offsetX,originalY-offsetY);
      isHovered = true;
    }
  } else {
    if(isHovered) {
      Sprite::setSize(1, 1);
      Sprite::setPos(originalX, originalY);
      isHovered = false;
    }
  }
}
