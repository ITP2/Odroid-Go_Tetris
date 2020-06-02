#include <iostream>
#include "Tetromino.h"

using namespace std;

Tetromino::Tetromino(const Tetromino::Tetro type, char format, char whitespace)
: type(type), format(format), whitespace(whitespace), actualBrickTemplate(NULL){
    // wegen enum wieder Klasse und Typ in Klammer angeben (weil sowohl Konstruktor als auch
    // enum in Klasse Tetromino im Public-Bereich definiert wurden

    this->brickFormTemplate.resize(0); //Vektor initialisieren und auf Null setzen

    switch(type){
        case I: //Schablone ("Templates") für I (gibt nur 2 unterschiedliche Positionen)
            {
                const char t1[4][4] = {
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace
                };
                this->generateTemplate(t1);

                const char t2[4][4] = {
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->format, this->format, this->format, this->format,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t2);
            }
            break;
        case J: // Template für J (4 unterschiedliche Positionen)
            {
                const char t1[4][4] = {
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->format, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t1);

                const char t2[4][4] = {
                    this->format, this->whitespace, this->whitespace, this->whitespace,
                    this->format, this->format, this->format, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t2);

                const char t3[4][4] = {
                    this->whitespace, this->format, this->format, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t3);

                const char t4[4][4] = {
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->format, this->format, this->format, this->whitespace,
                    this->whitespace, this->whitespace, this->format, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t4);
            }
            break;
        case L: // Template für L (4 unterschiedliche Positionen)
            {
                const char t1[4][4] = {
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->format, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t1);

                const char t2[4][4] = {
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->format, this->format, this->format, this->whitespace,
                    this->format, this->whitespace, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t2);

                const char t3[4][4] = {
                    this->format, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t3);

                const char t4[4][4] = {
                    this->whitespace, this->whitespace, this->format, this->whitespace,
                    this->format, this->format, this->format, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t4);

            }
            break;
        case O: // Template für O (nur eine Position)
            {
                const char t1[4][4] = {
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->format, this->whitespace,
                    this->whitespace, this->format, this->format, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t1);
            }
            break;
        case S: // Template für S (2 unterschiedliche Positionen)
            {
                const char t1[4][4] = {
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->format, this->whitespace,
                    this->format, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t1);

                const char t2[4][4] = {
                    this->format, this->whitespace, this->whitespace, this->whitespace,
                    this->format, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t2);
            }
            break;
        case T: // Template für T (4 unterschiedliche Positionen)
            {
                const char t1[4][4] = {
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->format, this->format, this->format, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t1);

                const char t2[4][4] = {
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->format, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t2);

                const char t3[4][4] = {
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->format, this->format, this->format, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t3);

                const char t4[4][4] = {
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->format, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t4);
            }
            break;
        case Z: // Template für Z (2 unterschiedliche Positionen)
            {
                const char t1[4][4] = {
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace,
                    this->format, this->format, this->whitespace, this->whitespace,
                    this->whitespace, this->format, this->format, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t1);

                const char t2[4][4] = {
                    this->whitespace, this->format, this->whitespace, this->whitespace,
                    this->format, this->format, this->whitespace, this->whitespace,
                    this->format, this->whitespace, this->whitespace, this->whitespace,
                    this->whitespace, this->whitespace, this->whitespace, this->whitespace
                };
                this->generateTemplate(t2);
            }
            break;
    }
    this->actualBrickIndex = 0;
    this->actualBrickTemplate = this->brickFormTemplate[0]; //default: wird auf erste Schablone (Standard) gesetzt
}

Tetromino::~Tetromino(){
    for(size_t i = 0; i < this->brickFormTemplate.size(); i++){
        for(size_t j = 0; j < 4; j++){
            delete [] (this->brickFormTemplate[i][j]);
        }
        delete [] (this->brickFormTemplate[i]);
    }
}

//getter
const char** Tetromino::getActualBrickTemplate() const{
    return const_cast <const char**>(this->actualBrickTemplate);
}

const char Tetromino::getFormat() const{
    return this->format;
}

void Tetromino::generateTemplate(const char t[4][4]){ //Schablone erstellen, 4x4 Matrix
    // -> 3-dimensional: zuerst die Anzahl der unterschiedlichen Templates, dann ein Array mit 4 Feldern, wo jedem einzelnen Feld wiederum 4 Felder angehängt werden
    // (vorstellen wie eine 4x4 Tabelle oder Matrix)

    this->brickFormTemplate.push_back(new char*[4]);

    for(size_t i = 0; i < 4; i++){
        this->brickFormTemplate[brickFormTemplate.size()-1][i] = new char[4];
    }

    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            this->brickFormTemplate[brickFormTemplate.size()-1][i][j] = t[i][j];
        }
    }
}

void Tetromino::print() const{ //print-Funktion für einzelnes Template
    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            cout << this->actualBrickTemplate[i][j];
        }
        cout << endl;
    }
}

void Tetromino::printAllTemplates() const{ //print-Funktion für alle Templates eines types
    for(size_t i = 0; i < this->brickFormTemplate.size(); i++){
        for(size_t j = 0; j < 4; j++){
            for(size_t k = 0; k < 4; k++){
                cout << this->brickFormTemplate[i][j][k];
            }
            cout << endl;
        }
        cout << "\n" << endl;
    }
}

void Tetromino::rotation(int key){ //Rotier-Funktion für Steine
    int index = this->actualBrickIndex; //Startwert von actualBrickIndex = Position 0
    switch(key)
    {
    case 'a':
        index = ((index-1) + this->brickFormTemplate.size() ) % this->brickFormTemplate.size();
        this->actualBrickIndex = index; //actualBrickIndex auf neuen, aktuell gesetzten BrickIndex (also auf welche Schablone grad rotiert wurde) setzen
        this->actualBrickTemplate = this->brickFormTemplate[index]; //aktuelles Template in Array der Schablonen mit aktuellen Index speichern
        break;
    case 'd':
        index = ((index+1) + this->brickFormTemplate.size() ) % this->brickFormTemplate.size();
        this->actualBrickIndex = index;
        this->actualBrickTemplate = this->brickFormTemplate[index];
        break;

    }
}

