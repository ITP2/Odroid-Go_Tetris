#include <iostream>
#include "Functions.h"

void clearScreen(){ //Funktionen aus windows.h
    HANDLE hOut; // Zeiger auf das aktuelle Fenster
    COORD position; //Struktur Koordinate

    hOut = GetStdHandle(STD_OUTPUT_HANDLE); //bekommen aktuellen Consolen Output

    position.X = 0; //bei position struct zwei Werte, X und Y
    position.Y = 0;

    SetConsoleCursorPosition(hOut, position);
}
