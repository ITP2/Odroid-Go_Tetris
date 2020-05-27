#include "Field.h"

using namespace std;

Field::Field( const size_t height, const size_t width): field(NULL), height(height), width(width){
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

//getter

size_t Field::getHeight() const{
    return this->height;
}

size_t Field::getWidth() const{
    return this->width;
}

const Field::Point& Field::getCursor() const{
    return this->cursor;
}

//Methoden

void Field::Clear(const char format){
    for(size_t i = 0; i < this->height; i++){
        for(size_t j = 0; j < this->width; j++){
            if(this->field[i][j] == format)
                this->field[i][j] = ' ';
        }
    }
}

void Field::Clear(const Field::Point cursor, const Tetromino *brick){
    const char**tmp = brick->getActualBrickTemplate();

    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            if(tmp[i][j] == brick->getFormat())
                this->field[cursor.getX() + i][cursor.getY() + j] = ' ';
        }
    }
}

void Field::setCursor(const unsigned short x, const unsigned short y){
    this->cursor.setX(x);
    this->cursor.setY(y);
}

void Field::print() const{ //print-Funktion für Feld
    for(size_t i = 0; i < this->height; i++){
        for(size_t j = 0; j < this->width; j++){
            cout << this->field[i][j];
        }
        cout << endl;
    }
}

bool Field::isFree (const Tetromino *brick){
    const char**tmp = brick->getActualBrickTemplate();

    const size_t x = this->cursor.getX();
    const size_t y = this->cursor.getY();

    if(x < 0 || x >= this->height || y < 0 || y >= this->width){
        return false;
    }

    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            if(tmp[i][j] == brick->getFormat()){
                    if(this->field[x+i][y+j] == 'X'
                       || this->field[x+i][y+j] == '|'
                       || this->field[x+i][y+j] == '~')
                        return false;
            }
        }
    }
    return true;
}

bool Field::drawBrick(const Tetromino *brick){
    const char**tmp = brick->getActualBrickTemplate();

    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            if(tmp[i][j] == brick->getFormat())
                this->field[this->cursor.getX()+i][this->cursor.getY()+j] = tmp[i][j];
        }
    }
    return true;
}
