#include <iostream>
#include <string>
#include <fstream>
#include "Pasajero.h"
#include "Archivo.h"
using namespace std;

Pasajero::Pasajero(){
    nombre="";
    telefono = 0;
    contrasena="";
    kilometros_acumulados=0;
    vuelo_reservado=false;
    descuento=false;
    kilometrospara_acumular=0;
    indice_reservar=-1;
}

void Pasajero::setNombre(){
    cout<<"Ingrese su nombre"<<endl;
    cin.ignore();
    getline(cin, nombre);
}

void Pasajero::setTelefono(){
    cout<<"Ingrese su numero telefonico (10 digitos)"<<endl;
    cin>>telefono;
}

void Pasajero::setContrasena(){
    cout<<"Ingrese la contrasena"<<endl;
    cin>>contrasena;
}

string Pasajero::getNombre(){
    return nombre;
}

int Pasajero::getTelefono(){
    return telefono;
}

int Pasajero::getKilometros_acumulados(){
    return kilometros_acumulados;
}

string Pasajero::getContrasena(){
    return contrasena;
}

bool Pasajero::getDescuento(){
    return descuento;
}

int Pasajero::getIndice_vuelo(){
    return indice_reservar;
}

int Pasajero::getKilometros_acumular(){
    return kilometrospara_acumular;
}

bool Pasajero::verificaCredenciales() {
    Archivo F;
    ifstream Archivo;
    Archivo.open("Users.dat",ios::in);
    if(Archivo.fail()){
        cout<<"El archivo no se pudo abrir";
        exit(1);
    }

    string line;
    bool user_is = false;
    bool pass_is = false;
    bool kms_is = false;
    int lineanum = 1;

    while(getline(Archivo, line)){
        if(!user_is){
            if(line == nombre){
                user_is = true;
            }
        }
        else if(!pass_is ){
            if(line == contrasena){
                pass_is = true;
            }
        }
        else if(!kms_is){
            kilometros_acumulados = stoi(line);
            kms_is = true;
            if(kilometros_acumulados > 50000){
                descuento = true;
                cout<<"Felicidades, tienes un descuento del 40"<<"%"<<" en tu proximo vuelo"<<endl;
            }
        }
        if(user_is && pass_is && kms_is){
            Archivo.close();
            return true;
        }
    }

    Archivo.close();
    return false;
}

void Pasajero::modificaAtributos(int asientos, int indice_reserva, int km_acumular) {
    if (asientos > 0) {
        vuelo_reservado = true;
        kilometros_acumulados += km_acumular;
        indice_reservar=indice_reserva;
    }
    kilometrospara_acumular = km_acumular;
}

void Pasajero::imprimePasajero(){
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Kilometros acumulados: "<<getKilometros_acumulados()<<endl;
    if(vuelo_reservado){
        cout<<"TIENES UN VUELO RESERVADO"<<endl;
        cout<<"No. de vuelo: "<<getIndice_vuelo()<<endl;
        cout<<"Kms acumulados con este vuelo: "<<getKilometros_acumular()<<endl;
    }
    else{cout<<"Sin vuelos reservados"<<endl;}
}

void Pasajero::cancelaReserva(int asientos, int indice_reserva, int km_acumular){
    if(indice_reservar==-1){
        cout<<"No tienes ningun vuelo reservado.\n\n"<<endl;
    }
    else{
        cout<<"Cancelando su vuelo..."<<endl;
        vuelo_reservado = false;
        kilometros_acumulados -= km_acumular;
        indice_reservar=-1;
    }
    kilometrospara_acumular = 0;
    }

Pasajero::~Pasajero(){
}
