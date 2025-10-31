#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include "Vuelo.h"
#include <string>
#include <vector>
using namespace std;

class Aeropuerto{

    private:
    
        vector <Vuelo> Vuelos;

    public:

        Aeropuerto();

        // Modificadores
        void setPrecio();
        void setMatricula();
        void setDistancia();
        void setDescuento(bool descuento);

        // Especializados
        void printAllFlights(bool descuento); // Todos los vuelos (por orden de matrícula)
        void hacerVectordeObjetosVuelo(); // Hacer vector de objetos vuelo
        void pedirDetalleVuelo(bool descuento);
        void pedirDetalleVuelo(bool descuento, int asientos, int indice_reserva); // Sobrecarga de método, se usa para cuando reserva
        void reservaVuelo(int &asientos, int &indice_reserva, int &km_acumular);
        void imprimeFecha(bool descuento); // Imprime los vuelos que se tienen en la fecha seleccionada
        void imprimePrecio(bool descuento); // Imprime los vuelos en base al precio
        void cancelaVuelo(int asientos,int);
        void registrarUsuario();

        virtual ~Aeropuerto();

};

#endif 