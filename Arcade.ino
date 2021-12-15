#include <LedControl.h>
#include "Game.h"
#include "Consts.h"

Game game;

void setup() {
    game = Game();
}

void loop() {
    switch (game.getStatus()) {
    case State::Menu:
        game.menu();
        break;
    case State::MenuUpdate:
        game.menuUpdate();
        break;
    case State::SnakeInit:
        game.snakeInit();
        break;
    case State::Snake:
        game.snake();
        break;
    case State::NyanInit:
        game.nyanInit();
        break;
    case State::Nyan:
        game.nyan();
        break;
    }
}
