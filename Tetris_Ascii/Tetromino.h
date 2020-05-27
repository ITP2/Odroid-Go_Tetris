#ifndef TETROMINO_H_INCLUDED
#define TETROMINO_H_INCLUDED
#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

class Tetromino{
    public:
        enum Tetro{I, J, L, O, S, T, Z}; //enum definiert begrenzten Wertebereich --> nur von diesen Typen können wir ein Tetromino erzeugen

        Tetromino( const Tetro type, char format = '#', char whitespace = ' '); //wenn Tetromino angelegt wird, muss auch mitgegeben werden, welcher Typ
        ~Tetromino();

    //getter
        const char** getActualBrickTemplate() const;
        const char getFormat() const;

    //Methoden
        void print() const;
        void printAllTemplates() const;
        void rotation(int key);

    private:
    //Eigenschaften
        Tetro type;
        const char format;
        char whitespace;

        char **actualBrickTemplate;
        size_t actualBrickIndex;
        vector <char**> brickFormTemplate; //Vektor für zweidimensionales Array (mit Zeiger-Zeiger)

    //Methoden
        void generateTemplate(const char t[4][4]); //Template wird erstellt

};



#endif // TETROMINO_H_INCLUDED
