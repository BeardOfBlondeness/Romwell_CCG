#pragma once
#include "../global.h"
#include "../render/Sprite.h"
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
  string getName();
protected:
  void initiateText();
  sf::Text nameImage;
  sf::Text descImage;
  sf::Font poorRich;
  string name, rarity, imagePath, description;
  int classType, baseMana, currentMana, baseHealth, currentHealth, baseDamage, currentDamage;
  Sprite baseImage, cardImage;
  double xScale, yScale;
};
