#include "LedString.h"
#include "Game.h"

void LedString::draw(const unsigned char* letter, int x, int y) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j ++) {
            bool test = (letter[i] >> j) & 0x01;
            this->display->setLed(x + 3 - j, y + i, test);
        }
    }
}

void LedString::displayLetter(char letter, int x, int y) {
    draw(Letters[letter - 65], x, y);
}

void LedString::displayDigit(char digit, int x, int y) {
    draw(Numbers[digit - 48], x, y);
}

LedString::LedString(Game* display, const char* str, int size, int x_beg, int y_beg) {
    this->display = display;
    this->str = str;
    this->size = size;
    this->x = x_beg;
    this->y = y_beg;
}

void LedString::displayString() {
    for (int i = 0; i < this->size; i ++) {
        displayLetter(this->str[i], this->x + 5 * i, y);
    }
}

void LedString::displayNumber() {
    for (int i = 0; i < this->size; i ++) {
        displayDigit(this->str[i], this->x + 5 * i, y);
    }
}
