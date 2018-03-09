#include "Card.h"

Card::Card() {
}

void Card::init(string name, string rarity, int classType, int baseMana, int baseHealth, int baseDamage, string imagePath, string description) {
  this->name = name;
  this->rarity = rarity;
  this->classType = classType;
  this->baseMana = baseMana;
  this->baseHealth = baseHealth;
  this->baseDamage = baseDamage;
  this->imagePath = imagePath;
  this->description = description;
  currentDamage = baseDamage;
  currentHealth = baseHealth;
  currentMana = baseMana;
  initiateText();
}

void Card::initiateText() {
  if(!poorRich.loadFromFile("res/fonts/PoorRichard.ttf"))
    cout << "Couldnt find font";
  nameImage.setFont(poorRich);
  nameImage.setString(name);
  nameImage.setCharacterSize(34);
  nameImage.setStyle(sf::Text::Bold);
  nameImage.setRotation(-32.0f);
  nameImage.setFillColor(sf::Color::Black);
  descImage.setFont(poorRich);
  descImage.setString(description);
  descImage.setCharacterSize(30);
}

void Card::initiateImage() {
  std::cout << "Path: " << imagePath;
  baseImage.init("res/game/cardBackground.png");
  cardImage.init(imagePath);
  int x = baseImage.getXPos();
  int y = baseImage.getYPos();
  nameImage.setPosition(x + 10 , y + 50);
  descImage.setPosition(x + 40, y + 250);
}

void Card::setLocation(int x, int y) {
    nameImage.setPosition(x + 10*xScale , y + 50*yScale);
    descImage.setPosition(x + 40*xScale, y + 250*yScale);
    baseImage.setPos(x, y);
    cardImage.setPos(x, y);
}

void Card::setSize(double x, double y) {
  xScale = x;
  yScale = y;
  nameImage.setPosition(x + 10*xScale , y + 50*yScale);
  descImage.setPosition(x + 40*xScale, y + 250*yScale);
  nameImage.setCharacterSize(34*xScale);
  descImage.setCharacterSize(30*xScale);
  baseImage.setSize(x, y);
  cardImage.setSize(x, y);
}

void Card::DrawCard() {
  cardImage.Draw();
  cout << "Drawn the image";
  baseImage.Draw();
  cout << "drawn the base image";
  window.draw(nameImage);
  cout << "drawn the name";
  window.draw(descImage);
  cout << "drawn the desc";
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

string Card::getName() {
  return name;
}
