#include "Card.h"

Card::Card() {
}

Card::Card(string name, string rarity, int classType, int baseMana, int baseHealth, int baseDamage, string imagePath) {
this->name = name;
this->rarity = rarity;
this->classType = classType;
this->baseMana = baseMana;
this->baseHealth = baseHealth;
this->baseDamage = baseDamage;
this->imagePath = imagePath;
currentDamage = baseDamage;
currentHealth = baseHealth;
currentMana = baseMana;
}

int Card::getBaseDamage() {
  return baseDamage;
}

int Card::getCurrentDamage() {
  return currentDamage;
}

void Card::setDamage(int damage) {
  currentDamage = damage;
}

int Card::getBaseMana() {
  return baseMana;
}

int Card::getCurrentMana() {
  return currentMana;
}

void Card::setMana(int mana) {
  currentMana = mana;
}

int Card::getBaseHealth() {
  return baseHealth;
}

int Card::getCurrentHealth() {
  return currentHealth;
}

void Card::setCurrentHealth(int health) {
  currentHealth = health;
}
