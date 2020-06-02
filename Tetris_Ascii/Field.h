#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#include "Tetromino.h"
#include <iostream>
#include <cstddef>

using namespace std;

class Field{ //Klasse für Spielfeld
    public:
        struct Point{
            unsigned short x;
            unsigned short y;

            Point():
                x(0), y(0){
                }
            unsigned short getX() const{
                return this->x;
            }
            unsigned short getY() const{
                return this->y;
            }
            void setX(const unsigned short x){
                this->x = x;
            }
            void setY(const unsigned short y){
                this->y = y;
            }
        };

        Field(const size_t height, const size_t width); // Spieler kann zu Beginn Höhe und Breite des Feldes angeben
        ~Field();

    //getter
        size_t getHeight() const;
        size_t getWidth() const;
        const Point& getCursor() const;

    //Methoden
        void Clear (const char format = '#'); //einfache, aber unflexible Variante
    //  void Clear (const Point cursor, const Tetromino *brick); //kompliziertere, aber flexiblere Variante

        void setCursor (const unsigned short x, const unsigned short y);
        void print() const;
        bool isFree (const Tetromino *brick);
        bool drawBrick (const Tetromino *brick, const char format = '#');
        size_t clearCompleteLines();
    //  void tamp(const Tetromino *brick);

    private:

    //Eigenschaften
        Point cursor;
        char **field; //für dynamisches Array
        const size_t height; //Makro, Typedef für unsigned int
        const size_t width;
};

#endif // FIELD_H_INCLUDED
