#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include <cstddef>
#include <vector>
#include "Field.h"


class Game{
    public:
        Game(const size_t height, const size_t width);

    //getter
        Field& getField();
        const Tetromino* getActualBrick() const;

    //Methoden
        bool initializeNewBrick();
        void print();

    private:
    //Eigenschaften
        Field field;
        Tetromino *actualBrick;
        bool isGameOver;

    //Methoden
        Tetromino* getRandomBrick();

};


#endif // GAME_H_INCLUDED
