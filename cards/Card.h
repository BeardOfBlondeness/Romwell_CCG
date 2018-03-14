#pragma once
#include "../global.h"
#include "../render/Sprite.h"
#include "../render/Button.h"
#include <string>

using namespace std;

class Card {
public:
  Card();
  void init(string name, string rarity, int classType, int baseMana, int baseHealth, int baseDamage, string imagePath, string description);
  int getBaseDamage();
  int getCurrentDamage();
  void setDamage(int damage);
  int getBaseMana();
  int getCurrentMana();
  void setMana(int mana);
  int getBaseHealth();
  int getCurrentHealth();
  void setCurrentHealth(int health);
  void DrawCard();
  void setLocation(int x, int y);
  void setSize(double x, double y);
  void initiateImage();
  void Damage(Card * card);
  void setPosition(int x, int y);
  void Hover();
  string getName();
protected:
  void initiateText();
  int originalX;
  int originalY;
  int offsetX;
  int offsetY;
  int clickOffsetX;
  int clickOffsetY;
  bool isHovered = false, mouseDown = false;
  sf::Text nameImage;
  sf::Text descImage;
  sf::Font poorRich;
  string name, rarity, imagePath, description;
  int classType, baseMana, currentMana, baseHealth, currentHealth, baseDamage, currentDamage;
  Sprite cardImage, baseImage;
  double xScale, yScale;
  double scaler = 1/1.5;
  sf::Vector2i pos;
};
