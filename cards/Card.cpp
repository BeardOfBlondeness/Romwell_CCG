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
  damageString = to_string(baseDamage);
  healthString = to_string(baseHealth);
  initiateText();
}

Card::Card(string name, string rarity, int classType, int baseMana, int baseHealth, int baseDamage, string imagePath, string description) {
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
  damageString = to_string(baseDamage);
  healthString = to_string(baseHealth);
  initiateText();
}

string Card::to_string(int num) {
 return static_cast<ostringstream*>( &(ostringstream() << num) )->str();
}

void Card::initiateText() {
  if(!poorRich.loadFromFile("res/fonts/PoorRichard.TTF")) {
    cout << "Couldnt find font";
  } else {
    nameImage.setFont(poorRich);
    descImage.setFont(poorRich);
    damageImage.setFont(poorRich);
    healthImage.setFont(poorRich);
  }
  nameImage.setString(name);
  nameImage.setCharacterSize(34);
  nameImage.setStyle(sf::Text::Bold);
  nameImage.setRotation(-32.0f);
  nameImage.setColor(sf::Color::Black);
  descImage.setString(description);
  descImage.setCharacterSize(30);
  damageImage.setString(damageString);
  damageImage.setCharacterSize(45);
  healthImage.setString(healthString);
  healthImage.setCharacterSize(45);
}

void Card::initiateImage() {
  baseImage.init("res/game/cardBackground.png");
  cardImage.init(imagePath);
  int x = baseImage.getXPos();
  int y = baseImage.getYPos();
  setRelativePositions(x, y);
}

void Card::Damage(Card * card) {
  card->setCurrentHealth(this->currentDamage);
}

void Card::setLocation(int x, int y) {
    setRelativePositions(x, y);
    baseImage.setPos(x, y);
    cardImage.setPos(x, y);
    originalX = x;
    originalY = y;
}

void Card::setPosition(int x, int y) {
      setRelativePositions(x, y);
      baseImage.setPos(x, y);
      cardImage.setPos(x, y);
}

void Card::setRelativePositions(int x, int y) {
  nameImage.setPosition(x + 10*xScale , y + 50*yScale);
  descImage.setPosition(x + 40*xScale, y + 250*yScale);
  damageImage.setPosition(x+41*xScale, y+340*yScale);
  healthImage.setPosition(x+230*xScale, y+343*yScale);
}

void Card::Hover() {
  pos = sf::Mouse::getPosition() - window.getPosition();
  if(pos.x > originalX && pos.y > originalY && pos.x < originalX+(scaler*300) && pos.y < originalY+(scaler*420)) {
    if(!isHovered) {
      setSize(1.1*scaler, 1.1*scaler);
      setPosition(originalX-offsetX,originalY-offsetY);
      isHovered = true;
    }
  } else {
    if(isHovered) {
      setSize(scaler, scaler);
      setPosition(originalX, originalY);
      isHovered = false;
    }
  }
}

void Card::setSize(double x, double y) {
  xScale = x;
  yScale = y;
  setRelativePositions(x, y);
  nameImage.setCharacterSize(34*xScale);
  descImage.setCharacterSize(30*xScale);
  damageImage.setCharacterSize(45*xScale);
  healthImage.setCharacterSize(45*xScale);
  baseImage.setSize(x, y);
  cardImage.setSize(x, y);
  offsetX = (300*x)/20;
  offsetY = (420*y)/20;
  clickOffsetX = offsetX/2;
  clickOffsetY = offsetY/2;
}

void Card::DrawCard() {
  cardImage.Draw();
  baseImage.Draw();
  window.draw(nameImage);
  window.draw(descImage);
  window.draw(damageImage);
  window.draw(healthImage);
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

int Card::getYPos() {
  return baseImage.getYPos();
}

int Card::getXPos() {
  return baseImage.getXPos();
}
