#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Game.h"
#include "Functions.h"

//#pragma comment(lib, "winmm.lib")

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Tetromino ted(Tetromino::J);
    Game tetris(18,12);

    //Playsound("tetris.WAV", NULL, SND_LOOP | SND_ASYNC | SND_FILENAME);

    tetris.initializeNewBrick();
    tetris.getField().drawBrick(tetris.getActualBrick());
    tetris.print();

    int key; // Tastatureingabe

    Field &feld = tetris.getField();
    int i = 0;

    size_t actualTime = GetTickCount();

    long actualPlaytime = static_cast<size_t>(time(NULL));

    while(tetris.run()){

        if(_kbhit()){
            key = _getch();

            tetris.action(key);
            key = ' ';

            feld.Clear(tetris.getActualBrick()->getFormat());
            feld.drawBrick(tetris.getActualBrick());
            clearScreen();
            tetris.print();
        }

        i++;

        bool tamp = false;

        if(tamp || actualTime + tetris.getIntervall() < GetTickCount()){
            actualTime = GetTickCount();

            feld.setCursor(feld.getCursor().getX()+1, feld.getCursor().getY());

            if(feld.isFree(tetris.getActualBrick())){
                tamp = false;

                feld.Clear(tetris.getActualBrick()->getFormat());
                feld.drawBrick(tetris.getActualBrick());
                i = 0;
                clearScreen();
                tetris.print();
            }
            else{ //tamp!
                tamp = true;

                feld.setCursor(feld.getCursor().getX()-1, feld.getCursor().getY());
                feld.drawBrick(tetris.getActualBrick(), 'X'); //tamp!

                size_t lines = feld.clearCompleteLines();
                tetris.updateHighscore(lines);

                tetris.initializeNewBrick();
                clearScreen();
                tetris.print();
            }
            cout << endl;
            cout << "Next Brick:";
            cout << endl;
            tetris.printNextBrick();

            cout << endl;
            cout << "Highscore:\t";
            cout << tetris.getHighscore() << endl;
        }
    }

    system("CLS");
    cout << "GAME OVER" << endl;

    tetris.printGameStatus();
    cout << "Playtime: " << static_cast<size_t>(time(NULL)) - actualPlaytime << " Sec" << endl;

    system("PAUSE");
    return 0;
}
