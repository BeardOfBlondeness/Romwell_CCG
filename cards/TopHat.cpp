#include "TopHat.h"

TopHat::TopHat() : Card() {
  this->Card::init("TopHat", "common", 0, 0, 2, 1, path, desc);
  this->initiateImage();
}

void TopHat::init() {
  this->Card::init("TopHat", "common", 0, 0, 2, 1, path, desc);
  this->initiateImage();
}
