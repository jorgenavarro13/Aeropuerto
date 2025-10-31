#include "Vuelo.h"
#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>

// Este es el constructor por defecto, para inicializar mi objeto
Vuelo::Vuelo()
    : matricula(0), fecha(""), destino(""), precio(0), hora(""),
    modelo(""), identificador(""), distancia(0), asientos_reservados(0),
    capacidad(0), combustible(0), precio_descuento(0) {}

// Este es mi segundo constructor, con parámetros que me sirven para darle valor a mis atributos y poder meterlo en mi vector vuelos
Vuelo::Vuelo(int matricula, string fecha, string destino, int precio, string hora,
            string modelo, string identificador, int distancia, int asientos_reservados,
            int capacidad, int combustible, int precio_descuento)
    : matricula(matricula), fecha(fecha), destino(destino), precio(precio), hora(hora),
    modelo(modelo), identificador(identificador), distancia(distancia),
    asientos_reservados(asientos_reservados), capacidad(capacidad), combustible(combustible), precio_descuento(precio_descuento){}

// Métodos getters
int Vuelo::getMatricula() const { return matricula; }
string Vuelo::getFecha() const { return fecha; }
string Vuelo::getDestino() const { return destino; }
int Vuelo::getPrecio() const { return precio; }
string Vuelo::getHora() const { return hora; }
string Vuelo::getModelo() const { return modelo; }
string Vuelo::getIdentificador() const { return identificador; }
int Vuelo::getDistancia() const { return distancia; }
int Vuelo::getAsientosReservados() const { return asientos_reservados; }
int Vuelo::getCapacidad() const { return capacidad; }
int Vuelo::getCombustible() const { return combustible; }
int Vuelo::getPrecioDescuento() const {return precio_descuento;}

// Especializados

void Vuelo::setPrecioDescuento(bool descuento) {
    if(descuento){
        precio_descuento=precio*0.6;
    }
    else{
        precio_descuento=precio;
    }
}

void Vuelo::imprimirVuelo(bool descuento){
    cout << "Matricula: " << matricula << "\n"
            << "Fecha: " << fecha << "\n"
            << "Destino: " << destino << "\n"
            << "Precio: $" << precio << "\n"
            << "Hora: " << hora << "\n"
            << "Modelo: " << modelo << "\n"
            << "Identificador: " << identificador << "\n"
            << "Distancia: " << distancia << " km\n"
            << "Asientos Reservados: " << asientos_reservados << " / " << capacidad << "\n"
            << "Combustible: " << combustible << " litros\n";
            if(descuento){
                cout << "Precio con descuento: $" << precio_descuento << "\n";
            }
            cout<< "---------------------------\n";
}

// Método para reservar un asiento
void Vuelo::reservarViaje() {
    int asientos=0;
    cout<<"Cuantos asientos requiere?: "<<endl;
    do{
    cin>>asientos;
    }
    while(asientos<=0);
    if ((asientos_reservados+asientos) < capacidad) {
        asientos_reservados=asientos_reservados+asientos;
        cout << "Reserva exitosa. Ahora hay " << asientos_reservados << " asientos reservados"<<endl;
    } else {
        cout << "No hay asientos disponibles para reservar."<<endl;
    }
}

void Vuelo::agregarPasajeros(int asientos){
    asientos_reservados=asientos_reservados+asientos; // Agregamos asientos reservados a mi vuelo
}

void Vuelo::quitarPasajeros(int asientos){
    asientos_reservados=asientos_reservados-asientos; // Quitamos asientos reservados a mi vuelo
}