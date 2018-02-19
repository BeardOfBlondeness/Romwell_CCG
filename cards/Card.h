#pragma once
#include "../global.h"
#include <string>

using namespace std;

class Card {
public:
  Card();
  Card(string name, string rarity, int classType, int baseMana, int baseHealth, int baseDamage, string imagePath);
  int getBaseDamage();
  int getCurrentDamage();
  void setDamage(int damage);
  int getBaseMana();
  int getCurrentMana();
  void setMana(int mana);
  int getBaseHealth();
  int getCurrentHealth();
  void setCurrentHealth(int health);
protected:
  string name, rarity, imagePath;
  int classType, baseMana, currentMana, baseHealth, currentHealth, baseDamage, currentDamage;
};
