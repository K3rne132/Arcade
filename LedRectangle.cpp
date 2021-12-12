#include "LedRectangle.h"
#include "Game.h"

LedRectangle::LedRectangle(Game* display, int top, int bottom, int left, int right) {
    this->display = display;
    this->top = top;
    this->bottom = bottom;
    this->left = left;
    this->right = right;
}

void LedRectangle::displayRectangle() {
    for (int i = this->top; i <= this->bottom; i++) {
        display->setLed(this->left, i, true);
        display->setLed(this->right, i, true);
    }
    for (int i = this->left; i <= this->right; i++) {
        display->setLed(i, this->top, true);
        display->setLed(i, this->bottom, true);
    }
}

void LedRectangle::hideRectangle() {
    for (int i = this->top; i <= this->bottom; i++) {
        display->setLed(this->left, i, false);
        display->setLed(this->right, i, false);
    }
    for (int i = this->left; i <= this->right; i++) {
        display->setLed(i, this->top, false);
        display->setLed(i, this->bottom, false);
    }
}