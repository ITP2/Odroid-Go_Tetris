#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <conio.h>
#include "Field.h"
#include "Tetromino.h"
//#include "Game.h" in Arbeit
#include "Functions.h"


using namespace std;

int main()
{
    Field field(15, 10);
    field.print();

    Tetromino ted(Tetromino::T);
    ted.printAllTemplates();

    /*
    int key; // Tastatureingabe

    while(true){

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
        }
    }
    */


    system("PAUSE");
    return 0;
}
