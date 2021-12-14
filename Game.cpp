#include "Game.h"
#include "LedString.h"
#include "LedRectangle.h"
#include "Funcs.h"

void Game::setLed(int x, int y, bool on) {
    LedControl* present;
    if (x < 8)
        present = &this->Matrix[0];
    else if (x < 16)
        present = &this->Matrix[1];
    else if (x < 24)
        present = &this->Matrix[2];
    else
        present = &this->Matrix[3];
    x = x % 8;
    int segment;
    if (y < 8)
        segment = 3;
    else if (y < 16)
        segment = 2;
    else if (y < 24)
        segment = 1;
    else
        segment = 0;
    y = y % 8;
    present->setLed(segment, 7 - x, y, on);
}

bool Game::AppleValid() {
	for (int i = 0; i < SnakeLength; i++) {
		if (Apple.x == SnakeSegments[i].x && Apple.y == SnakeSegments[i].y)
			return false;
	}
	return true;
}

Game::Game() :
    Matrix({
        LedControl(4, 3, 2, 4),
        LedControl(7, 6, 5, 4),
        LedControl(10, 9, 8, 4),
        LedControl(13, 12, 11, 4)
    }) {
        this->Selection = false;
    this->Status = State::Menu;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            this->Matrix[i].shutdown(j, false);
        }
        this->Matrix[i].setIntensity(0, 2);
    }
    clearAll();
}

void Game::clearAll() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->Matrix[i].clearDisplay(j);
        }
    }
}

void Game::setStatus(State s) {
    this->Status = s;
}

State Game::getStatus() {
    return this->Status;
}

void Game::menu() {
    LedString Title = LedString(this, "ARCADE", 6, 1, 3);
    Title.displayString();
    LedString Snake = LedString(this, "SNAKE", 5, 4, 14);
    Snake.displayString();
    LedString Tetris = LedString(this, "TETRIS", 6, 1, 22);
    Tetris.displayString();

    LedRectangle SelSnake = LedRectangle(this, 12, 20, 2, 29);
    LedRectangle SelTetris = LedRectangle(this, 20, 28, 0, 31);
    if (this->Selection)
        SelTetris.displayRectangle();
    else
        SelSnake.displayRectangle();
    this->Status = State::MenuUpdate;
}

void Game::menuUpdate() {
    if (getVertical() < .3f) {
        this->Selection = false;
        LedRectangle SelTetris = LedRectangle(this, 20, 28, 0, 31);
        SelTetris.hideRectangle();
        LedRectangle SelSnake = LedRectangle(this, 12, 20, 2, 29);
        SelSnake.displayRectangle();
    }
    else if (getVertical() > .7f) {
        this->Selection = true;
        LedRectangle SelSnake = LedRectangle(this, 12, 20, 2, 29);
        SelSnake.hideRectangle();
        LedRectangle SelTetris = LedRectangle(this, 20, 28, 0, 31);
        SelTetris.displayRectangle();
    }
    else if (isJoystickPressed()) {
      if (this->Selection == true)
          this->Status = State::TetrisInit;
      else if (this->Selection == false)
          this->Status = State::SnakeInit;
      clearAll();
      delay(1000);
    }
}

void Game::snakeInit() {
	this->AppleAppearance = true;
    this->SnakeLength = 2;
    LedRectangle border1 = LedRectangle(this, 0, 31, 0, 31);
    LedRectangle border2 = LedRectangle(this, 1, 30, 1, 30);
    LedRectangle border3 = LedRectangle(this, 2, 29, 2, 29);
    LedRectangle border4 = LedRectangle(this, 3, 28, 3, 28);
    LedRectangle border5 = LedRectangle(this, 4, 27, 4, 27);
    LedRectangle border6 = LedRectangle(this, 5, 26, 5, 26);
    LedRectangle border7 = LedRectangle(this, 5, 25, 6, 25);
    LedRectangle border8 = LedRectangle(this, 5, 24, 7, 24);
    LedRectangle border9 = LedRectangle(this, 22, 23, 7, 24);
    
    border1.displayRectangle();
    border2.displayRectangle();
    border3.displayRectangle();
    border4.displayRectangle();
    border5.displayRectangle();
    border6.displayRectangle();
    border7.displayRectangle();
    border8.displayRectangle();
    border9.displayRectangle();

    LedRectangle empty1 = LedRectangle(this, 24, 30, 8, 23);
    empty1.hideRectangle();
    LedRectangle empty2 = LedRectangle(this, 24, 30, 13, 18);
    empty2.hideRectangle();
    this->SnakeSegments[0] = newVec(15, 15);
	  this->Apple = newVec(10, 15);
	  this->Direction = Dir::Up;
    LedString ls = LedString(this, "000", 3, 9, 25);
    ls.displayNumber();
    this->Status = State::Snake;
}

void Game::snake() {
	if (this->AppleAppearance == true) {
		this->AppleAppearance = false;
		setLed(Apple.x, Apple.y, false);
	}
	else {
		this->AppleAppearance = true;
		setLed(Apple.x, Apple.y, true);
	}
	if (getHorizontal() > .7f && this->Direction != Dir::Right)
		this->Direction = Dir::Left;
	else if (getHorizontal() < .3f && this->Direction != Dir::Left)
		this->Direction = Dir::Right;
	else if (getVertical() > .7f && this->Direction != Dir::Up)
		this->Direction = Dir::Down;
	else if (getVertical() < .3f && this->Direction != Dir::Down)
		this->Direction = Dir::Up;
	
	for (int i = SnakeLength - 1; i > 0; i--) {
      SnakeSegments[i] = SnakeSegments[i - 1];
  }
	
	switch (this->Direction) {
		case Dir::Up:
			SnakeSegments[0].x;
			SnakeSegments[0].y--;
			break;
		case Dir::Down:
			SnakeSegments[0].x;
			SnakeSegments[0].y++;
			break;
		case Dir::Left:
			SnakeSegments[0].x--;
			SnakeSegments[0].y;
			break;
		case Dir::Right:
			SnakeSegments[0].x++;
			SnakeSegments[0].y;
			break;
	}
	
	if (SnakeLength >= 255) {
		delay(500);
		clearAll();
		delay(500);
	}
	
	if (SnakeSegments[0].x == Apple.x && SnakeSegments[0].y == Apple.y) {
		while (!AppleValid()) {
			int rand = millis() % 256;
			Apple.x = 8 + rand / 16;
			Apple.y = 6 + rand % 16;
		}
    SnakeLength--;
    char digits[] = {SnakeLength / 100 + 48, (SnakeLength % 100) / 10 + 48, (SnakeLength % 10 + 48)};
    LedString ls = LedString(this, digits, 3, 9, 25);
    ls.displayNumber();
		SnakeLength+=2;
	}
 
  setLed(SnakeSegments[0].x, SnakeSegments[0].y, true);
  setLed(SnakeSegments[SnakeLength - 1].x, SnakeSegments[SnakeLength - 1].y, false);
	
	if (SnakeSegments[0].x < 8 || SnakeSegments[0].x > 23 || SnakeSegments[0].y < 6 || SnakeSegments[0].y > 21) {
		delay(500);
		clearAll();
		delay(500);
		this->Status = State::Menu;
	}
	
    for (int i = 1; i < this->SnakeLength - 1; i++) {
		if (SnakeSegments[0].x == SnakeSegments[i].x && SnakeSegments[0].y == SnakeSegments[i].y) {
			delay(500);
			clearAll();
			delay(500);
			this->Status = State::Menu;
		}
	}
	delay(250);
}

void Game::tetrisInit() {
    this->Status = State::Tetris;
}

void Game::tetris() {
    
}
