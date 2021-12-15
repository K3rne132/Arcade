#include "LedSprite.h"
#include "Game.h"

LedSprite::LedSprite(Game* display, long* img) {
  this->display = display;
  this->image = img;
}

void LedSprite::displayImage() {
  this->display->clearAll();
  for (int i = 0; i < 20; i++) {
    for (int j = 31; j >= 0; j--) {
      this->display->setLed((31 - j), i + 6, (image[i] >> j) & 0x00000001);
    }
  }
}
