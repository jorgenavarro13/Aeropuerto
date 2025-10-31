#include "Aeropuerto.h"
#include "Vuelo.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include <iostream>

Aeropuerto::Aeropuerto(){
    vector <Vuelo> Vuelos;
}

Aeropuerto::~Aeropuerto(){ // Destructor
}

void Aeropuerto::hacerVectordeObjetosVuelo(){

    ifstream archivo("vuelos.txt");

    if (archivo.fail()) {
        cout << "Error al abrir el archivo." << endl;
        exit(1);
        }

    string  destino, hora, modelo, identificador, fecha; // Declaramos el tipo de variables que recuperara el archivo
    int matricula, precio, distancia, asientos_reservados, capacidad, combustible;

    while (archivo>>matricula>>fecha>>destino>>precio>>hora>>modelo>>identificador>>distancia>>asientos_reservados>>capacidad>>combustible) {
        Vuelos.emplace_back(matricula, fecha, destino, precio, hora, modelo, identificador, distancia, asientos_reservados, capacidad, combustible, precio);
    }       // También pude haber usado push_back, sin embargo necesitaba crear Vuelo vuelo_temporal(archivo, matrícula,....); Vuelos.push_back(vuelotemp)
            // emplace_back crea un objeto directamente dentro del vector Vuelos, no crea copias y ahorramos líneas

}

void Aeropuerto::setDescuento(bool descuento){
    for(int i=0; i<Vuelos.size(); i++){
        Vuelos[i].setPrecioDescuento(descuento);
    }
}

void Aeropuerto::printAllFlights(bool descuento){ // Imprimimos todos los vuelos, hacemos ciclo for por la totalidad de nuestro vector y recabando los datos con métodos accesores
    for(int i=0; i<Vuelos.size(); i++){
        cout<<"No.vuelo: "<<Vuelos[i].getMatricula()<<"   Fecha:" <<Vuelos[i].getFecha()<<"      Destino:"<<Vuelos[i].getDestino()<<"\nPrecio:"<<Vuelos[i].getPrecio()<<"        Hora: "<<Vuelos[i].getHora()<<"             Modelo de avion:"<<Vuelos[i].getModelo()<<" \nIdentificador de vuelo:"<<Vuelos[i].getIdentificador()<<"            Distancia de vuelo:"<<Vuelos[i].getDistancia()<<" \nAsientos reservados:"<<Vuelos[i].getAsientosReservados()<<"                        Capacidad de pasajeros:"<<Vuelos[i].getCapacidad()<<"\nLts Combustible:"<<Vuelos[i].getCombustible();
        if(descuento){                              // Utilizamos el pase de parametros para cuando nuestro Pasajero tiene suficientes kilómetros recorridas
            cout<<" \nPrecio con descuento: "<<Vuelos[i].getPrecioDescuento();
        }
        cout<<"\n\n\n";
        cout<<"-----------------------------------------------------------------------------------------------\n";
    }
}

void Aeropuerto::reservaVuelo(int &asientos, int &indice_reserva, int &km_acumular) { // Necesitaba retornar varios parámetros y decidí pasarlos por referencia
    asientos=0; // Todos estos parámetros los regreso al main por medio de referencias
    indice_reserva=-1;
    km_acumular=0;
    do {
        cout<<"Introduce el indice del vuelo a reservar (0-28): ";
        cin>>indice_reserva;

        if(indice_reserva<0 || indice_reserva>=Vuelos.size()){
            cout<<"Indice no válido. Intenta de nuevo."<<endl;
        }
    } while(indice_reserva<0 || indice_reserva>=Vuelos.size());
    do {
        cout<<"Cuantos asientos requiere: ";
        cin>>asientos;

        if(asientos <= 0){
            cout<<"Numero de asientos no valido. Intenta de nuevo."<<endl;
        }
    } while(asientos<=0);

    if ((Vuelos[indice_reserva].getAsientosReservados()+asientos)<Vuelos[indice_reserva].getCapacidad()){
        Vuelos[indice_reserva].agregarPasajeros(asientos);
        cout<<"Reserva exitosa. Ahora hay "<<Vuelos[indice_reserva].getAsientosReservados()<<" asientos reservados"<<endl;


        km_acumular=asientos*Vuelos[indice_reserva].getDistancia();
    } else {
        cout <<"No hay suficientes asientos disponibles para reservar."<<endl;
        asientos = 0;
    }
}

void Aeropuerto::imprimeFecha(bool descuento){
    int mes=0;
    int dia=0;
    string v_mes="";
    string v_fecha="";
    string guionbajo="_";

    cout << "En este aeropuerto solo contamos con vuelos para febrero y marzo.\nIngrese el numero del mes a seleccionar\n<2>Febrero\n<3>Marzo" << endl;

    do {
        cin>>mes;
    } while (mes!=2 && mes!=3);

    cout<< "Ingrese el dia del mes; "<<endl;

    do {
        cin>>dia;
    } while (dia<=0 ||dia>31);

    if (mes==2) {v_mes="febrero";}          // Asignamos el mes por número
    else if (mes==3) {v_mes="marzo";}

    v_fecha=to_string(dia)+guionbajo+v_mes;    // Convertir para que pueda comparar

    for (int i=0; i<Vuelos.size(); i++) {    // Buscar vuelos que coincidan con la fecha
        if (Vuelos[i].getFecha()==v_fecha) {
            Vuelos[i].imprimirVuelo(descuento);
        }
    }

    cout<<"\n\n Esos son los vuelos disponibles para la fecha seleccionada\n\n"<<endl;
}

void Aeropuerto::imprimePrecio(bool descuento){
    int presupuesto=0;
    cout<<"Cual es tu presupuesto maximo para un solo ticket de vuelo(MXN):" <<endl;
    do{
    cin>>presupuesto;
    }
    while(presupuesto<=0);
    for (int i=0; i<Vuelos.size();i++){ // Recorremos el vector Vuelos
        if (presupuesto>=Vuelos[i].getPrecioDescuento()){ // Comparamos el presupuesto del usuario con el precio del objeto Vuelo actual, si es menor se imprime
            Vuelos[i].imprimirVuelo(descuento);
        }
    }
}

void Aeropuerto::pedirDetalleVuelo(bool descuento){ // Pides detalle de vuelo en específico
    int indice;
    cout << "Introduce el indice del vuelo (0-28): ";
    cin >> indice;

    if(indice>=0 && indice<Vuelos.size()) {
        Vuelos[indice].imprimirVuelo(descuento);
    } else {
        cout << "Indice no valido." <<endl;
    }
}

// Sobrecarga de métodos, en uno  se ocupa un solo parámetro mientras que en el otro se le pasan 3 y de diverso tipo.

void Aeropuerto::pedirDetalleVuelo(bool descuento, int asientos,int indice_reserva){//Sirve cuando reservas vuelo, imprima todos los tickets
    for(int i=0;i<asientos;i++){
            Vuelos[indice_reserva].imprimirVuelo(descuento);
    }
}

void Aeropuerto::cancelaVuelo(int asientos,int indicereserva){
    if (indicereserva!=-1){ // El índice reserva es un atributo determinado con (-1) en la construcción de cualquier objeto pasajero, en cuanto se reserva se cambia ese atributo, por lo que en cuanto este sea diferente de -1 hay una reserva y puedes cancelar un vuelo.
            Vuelos[indicereserva].quitarPasajeros(asientos);
    }
    else{cout<<"No tienes vuelos que cancelar."<<endl;}
}