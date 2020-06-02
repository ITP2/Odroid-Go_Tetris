#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include <cstddef>
#include <conio.h>
#include <vector>
#include "Field.h"


class Game{
    public:
        Game(const size_t height, const size_t width);

    //getter
        Field& getField();
        Tetromino* getActualBrick() const;
        const size_t& getIntervall() const;
        const size_t& getHighscore() const;

    //Methoden
        void action(int key);
        void movement();
        bool initializeNewBrick();
        bool run();
        void print() const;
        void printNextBrick() const;
        void updateHighscore(const size_t &lines);
        void printGameStatus() const;
        //void tampActualBrick(const Tetromino *brick);

    private:
    //Eigenschaften
        Field field;
        Tetromino *actualBrick;
        Tetromino *nextBrick;
        bool isGameOver;
        size_t intervall; // milliseconds
        size_t highscore;

    //Methoden
        Tetromino* getRandomBrick();

};


#endif // GAME_H_INCLUDED
