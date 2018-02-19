#pragma once
#include <string>
#include <cassert>
#include "../global.h"
using namespace std;

class Sprite {
public:
    Sprite(string path);
    Sprite(string path, int x, int y);
    Sprite(string path, int x, int y, int width, int height);
    ~Sprite();
    void InitiateSprite();
    void Draw();
protected:
    sf::Texture tex;
    sf::Sprite renderSprite;
    string path;
    int x, y, width, height;
};
