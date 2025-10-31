#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <iostream>
using namespace std;

class Archivo{

    private:
        string nombre;

    public:
        Archivo();
        void setNombreA(string n);
        string getNombreA();
        void escribir(string s);
        void asignar_cero(); // Importante para los kilómetros
        void leer();
        virtual ~Archivo();

};

#endif 