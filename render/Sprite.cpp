//
// Created by M1k3 on 13/02/2018.
//

#include "Sprite.h"

Sprite::Sprite() {
}

void Sprite::init(string path, int x, int y, int width, int height) {
      this->path = path;
      this->x = x;
      this->y = y;
      this->width = width;
      this->height = height;
      renderSprite.setPosition(x, y);
}

Sprite::Sprite(string path) {
    this->path = path;
}

Sprite::Sprite(string path, int x, int y) {
    this->path = path;
    this->x = x;
    this->y = y;
}

Sprite::Sprite(string path, int x, int y, int width, int height) {
    this->path = path;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    renderSprite.setPosition(x, y);
}

Sprite::~Sprite() {

}

void Sprite::InitiateSprite() {
    assert(tex.loadFromFile(path));
    renderSprite.setTexture(tex);
}

void Sprite::setSize(float x, float y) {
  renderSprite.setScale(x, y);
}

void Sprite::setPos(int xPos, int yPos) {
  renderSprite.setPosition(xPos, yPos);
}

void Sprite::Draw(){
    window.draw(renderSprite);
}

void Sprite::setRect(int x, int y, int width, int height) {
  xRect = x;
  yRect = y;
  renderSprite.setTextureRect(sf::IntRect(x, y, width, height));
}

int Sprite::getXRect() {
  return xRect;
}
