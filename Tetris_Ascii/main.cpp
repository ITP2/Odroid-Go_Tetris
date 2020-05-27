#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <conio.h>
//#include "Field.h"
//#include "Tetromino.h"
#include "Game.h"
#include "Functions.h"


using namespace std;

int main()
{
    Tetromino ted(Tetromino::J);
    Game tetris(15,10);

    tetris.initializeNewBrick();
    tetris.getField().drawBrick(tetris.getActualBrick());
    tetris.print();

    //int key; // Tastatureingabe

    Field &feld = tetris.getField();
    int i = 0;


    while(true){

        ++i;

        if(i % 200000000 == 0){
            feld.setCursor(feld.getCursor().getX()+1, feld.getCursor().getY());

            if(feld.isFree(tetris.getActualBrick())){
                clearScreen();

                feld.Clear(tetris.getActualBrick()->getFormat());

                feld.drawBrick(tetris.getActualBrick());
                tetris.print();
                i = 0;
            }
            else{
                feld.setCursor(feld.getCursor().getX()-1, feld.getCursor().getY());
            }
        }
    }

        /*

        system("cls");
        //clearScreen();
        ted.print();
        if(_kbhit()){ //fragt Tastatureingabe ab
            key = getch();

            switch(key)
            {
            case 'a':
            case 'A':
                ted.rotation('a');
                break;
            case 'd':
            case 'D':
                ted.rotation('d');
                break;
            }

            key = ' ';
        }
    }
    */


    system("PAUSE");
    return 0;
}
