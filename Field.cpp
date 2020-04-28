#include "Field.h"

using namespace std;

Field::Field(size_t height, size_t width): field(NULL), height(height), width(width){
    this->field = new char*[height];

    for(size_t i = 0; i < height; i++){ //Schleife, in der pro Runde neue Zeile mit eingegebener Weite (quasi neues Array) erstellt wird
        this->field[i] = new char[width];

        for(size_t j = 0; j < width; j++){ //Schleife in Schleife, die jede neue Zeile mit Leerzeichen füllt
            this->field[i][j] = ' ';
        }
    }

    for(size_t i = 0; i < height-1; i++){ //height-1 wegen Boden, der anders aussieht
        this->field[i][0] = '|';
        this->field[i][width-1] = '|';
    }

    for(size_t i = 0; i < width; i++){ //Welle zeichnet den Boden
        this->field[height-1][i] = '~';
    }
}

Field::~Field(){
    for(size_t i = 0; i < height; i++){
        delete [] this->field[i];
    }
    delete [] this->field;
}

void Field::print() const{ //print-Funktion für Feld
    for(size_t i = 0; i < this->height; i++){
        for(size_t j = 0; j < this->width; j++){
            cout << this->field[i][j];
        }
        cout << endl;
    }
}
