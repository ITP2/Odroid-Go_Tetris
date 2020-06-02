#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

Game::Game(const size_t height, const size_t width):
    field(height, width), actualBrick(NULL), nextBrick(NULL), isGameOver(false), intervall(1000), highscore(0)  {

    srand(static_cast <size_t> (time(NULL)));
}

//getter

Field& Game::getField(){
    return this->field;
}

Tetromino* Game::getActualBrick() const{
    return this->actualBrick;
}

const size_t& Game::getIntervall() const{
    return this->intervall;
}

const size_t& Game::getHighscore() const{
    return this->highscore;
}

//Methoden

void Game::action(int key){
    switch(key){
    case 224: //Irgendeine Arrow Taste wurde eingetippt
        this->movement();
        break;
    case 'a':
    case 'A':
        this->actualBrick->rotation('a');
        if(!this->field.isFree(this->actualBrick)){
            this->actualBrick->rotation('d');
        }
        break;

    case 'd':
    case 'D':
        this->actualBrick->rotation('d');
        if(!this->field.isFree(this->actualBrick)){
            this->actualBrick->rotation('a');
        }
        break;
    case ' ':
        system("CLS");

        cout << "PAUSE" << endl;
        cout << endl;

        cout << "..zum Weiterspielen beliebige Taste drücken!" << endl;

        system("PAUSE");
        system("CLS");

    }
}

void Game::movement(){
    int key = _getch();

    switch(key){

    case 75: //Move left
        this->field.setCursor(this->field.getCursor().getX(), this->field.getCursor().getY() - 1);
        if(!this->field.isFree(this->actualBrick)){
            this->field.setCursor(this->field.getCursor().getX(), this->field.getCursor().getY() + 1);
        }
        break;
    case 77: //Move right
        this->field.setCursor(this->field.getCursor().getX(), this->field.getCursor().getY() + 1);
        if(!this->field.isFree(this->actualBrick)){
            this->field.setCursor(this->field.getCursor().getX(), this->field.getCursor().getY() - 1);
        }
        break;
    case 80: //Move Down
        this->field.setCursor(this->field.getCursor().getX() + 1, this->field.getCursor().getY());
        if(!this->field.isFree(this->actualBrick)){
            this->field.setCursor(this->field.getCursor().getX() - 1, this->field.getCursor().getY());
        }
        break;
    }
}

bool Game::initializeNewBrick(){
    if(this->actualBrick != NULL){
        delete this->actualBrick;
    }
    this->field.setCursor(0, (this->field.getWidth() / 2) - 1);

    if(this->nextBrick != NULL){
        this->actualBrick = this->nextBrick;
    }else{
        this->actualBrick = getRandomBrick();
    }

    this->nextBrick = getRandomBrick();

    if(this->field.isFree(this->actualBrick)){
        return true;
    }else{
        this->isGameOver = true;
        return false;
    }
}

bool Game::run(){
    return !this->isGameOver;
}

void Game::print() const{
    this->field.print();
}

void Game::printNextBrick() const{
    if(this->nextBrick != NULL){
        this->nextBrick->print();
    }
}

void Game::updateHighscore(const size_t &lines){
    switch(lines){
    case 1:
        this->highscore += 100;
        break;
    case 2:
        this->highscore += 250;
        break;
    case 3:
        this->highscore += 500;
        break;
    case 4:
        this->highscore += 1000;
        break;
    }

    //10
    if(this->highscore > 60000){
        this->intervall = 400;
    }
    //9
    else if(this->highscore > 55000){
        this->intervall = 480;
    }
    //8
    else if(this->highscore > 50000){
        this->intervall = 540;
    }
    //7
    else if(this->highscore > 45000){
        this->intervall = 620;
    }
    //6
    else if(this->highscore > 40000){
        this->intervall = 700;
    }
    //5
    else if(this->highscore > 35000){
        this->intervall = 780;
    }
    //4
    else if(this->highscore > 30000){
        this->intervall = 860;
    }
    //3
    else if(this->highscore > 25000){
        this->intervall = 940;
    }
    //2
    else if(this->highscore > 20000){
        this->intervall = 920;
    }
}

void Game::printGameStatus() const{
    cout << "Highscore: " << this->highscore << endl;
}

/*
void Game::tampActualBrick(const Tetromino *brick){
    this->field.tamp(brick);
}
*/

Tetromino* Game::getRandomBrick(){
    return new Tetromino (static_cast <Tetromino::Tetro> (rand() % 7));
}
