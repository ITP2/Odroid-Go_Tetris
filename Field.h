#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#include <iostream>
#include <cstddef>

using namespace std;

class Field{ //Klasse f�r Spielfeld
    public:
        Field(const size_t height, const size_t width); // Spieler kann zu Beginn H�he und Breite des Feldes angeben
        ~Field();

        void print() const;

    private:
        char **field; //f�r dynamisches Array

        const size_t height; //Makro, Typedef f�r unsigned int
        const size_t width;
};

#endif // FIELD_H_INCLUDED
