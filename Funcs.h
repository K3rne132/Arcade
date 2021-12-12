#ifndef FUNCS_H
#define FUNCS_H
#include "Consts.h"

float getVertical() {
    return analogRead(VERTICAL) / 1024.f;
}

float getHorizontal() {
    return analogRead(HORIZONTAL) / 1024.f;
}

bool isJoystickPressed() {
    if (digitalRead(CLICK) == HIGH)
        return false;
    return true;
}

vec newVec(unsigned char x, unsigned char y) {
	vec v;
	v.x = x;
	v.y = y;
	return v;
}

#endif