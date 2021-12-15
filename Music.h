#include "Consts.h"

void beep(int note, int cl) {
  tone(BUZZER, note, cl);
}

void play(int* music, int size, Game* game) {
  for (int i = 0; i < size; i++) {
    beep(music[i], 120);
    delay(120);
  }
}
