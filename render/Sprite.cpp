//
// Created by M1k3 on 13/02/2018.
//

#include "Sprite.h"

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
}

Sprite::~Sprite() {

}

void Sprite::InitiateSprite() {
    assert(tex.loadFromFile(path));
    renderSprite.setTexture(tex);
}

void Sprite::Draw(){
    window.draw(renderSprite);
}