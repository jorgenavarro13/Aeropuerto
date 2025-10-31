#ifndef VUELO_H
#define VUELO_H
#include <string>
using namespace std;
#include <iostream>

class Vuelo{

    private:
        int matricula;
        string fecha;
        string destino;
        int precio;
        string hora;
        string modelo;
        string identificador;
        int distancia;
        int asientos_reservados;
        int capacidad;
        int combustible;
        int precio_descuento;

    public:

        Vuelo();

        Vuelo(int matricula, string fecha, string destino, int precio, string hora,
            string modelo, string identificador, int distancia, int asientos_reservados,
            int capacidad, int combustible, int precio_descuento);

        // Accesores
        int getMatricula() const;
        string getFecha() const;
        string getDestino() const;
        int getPrecio() const;
        string getHora() const;
        string getModelo() const;
        string getIdentificador() const;
        int getDistancia() const;
        int getAsientosReservados() const;
        int getCapacidad() const;
        int getCombustible() const;
        int getPrecioDescuento() const;

        // Especializados
        void setPrecioDescuento(bool descuento);
        void imprimirVuelo(bool descuento);   
        void reservarViaje();
        void agregarPasajeros(int asientos);
        void quitarPasajeros(int asientos);

};

#endif 