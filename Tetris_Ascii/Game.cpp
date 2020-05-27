#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

Game::Game(const size_t height, const size_t width):
    field(height, width), actualBrick(NULL), isGameOver(false)  {

    srand(static_cast <size_t> (time(NULL)));
}

//getter

Field& Game::getField(){
    return this->field;
}

const Tetromino* Game::getActualBrick() const{
    return const_cast<const Tetromino*>(this->actualBrick);
}

//Methoden

bool Game::initializeNewBrick(){
    if(this->actualBrick != NULL){
        delete this->actualBrick;
    }
    this->field.setCursor(0, (this->field.getWidth() / 2) - 1);

    this->actualBrick = getRandomBrick();

    return true;
}

void Game::print(){
    this->field.print();
}

Tetromino* Game::getRandomBrick(){
    return new Tetromino (static_cast <Tetromino::Tetro> (rand() % 7));
}
