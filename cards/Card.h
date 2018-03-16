#pragma once
#include "../global.h"
#include "../render/Sprite.h"
#include "../render/Button.h"
#include <string>
#include <sstream>

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
  int getYPos();
  int getXPos();
  string getName();
protected:
  void initiateText();
  void setRelativePositions(int x, int y);
  string to_string(int num);
  int originalX;
  int originalY;
  int offsetX;
  int offsetY;
  int clickOffsetX;
  int clickOffsetY;
  bool isHovered = false, mouseDown = false;
  sf::Text nameImage;
  sf::Text descImage;
  sf::Text damageImage;
  sf::Text healthImage;
  sf::Font poorRich;
  string name, rarity, imagePath, description, damageString, healthString;
  int classType, baseMana, currentMana, baseHealth, currentHealth, baseDamage, currentDamage;
  Sprite cardImage, baseImage;
  double xScale, yScale;
  double scaler = 1/1.5;
  sf::Vector2i pos;
};
