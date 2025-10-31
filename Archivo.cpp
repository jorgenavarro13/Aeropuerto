#include "Archivo.h"
#include <iostream>
#include<fstream>
using namespace std;

Archivo::Archivo(){
    nombre="";
}

void Archivo::setNombreA(string n){
    nombre=n;
}

string Archivo::getNombreA(){
    return nombre;
}

void Archivo::escribir(string s){

    ofstream Archivo;
    string name;
    string pw;

    Archivo.open("Users.dat",ios::app); // Importante usar app en lugar de out para no borrar los demás registros
    if(Archivo.fail()){
        cout<<"El archivo no se pudo abrir";
        exit(1);
    }

    Archivo<<s<<endl;
    Archivo.close();

}

void Archivo::asignar_cero(){

    ofstream Archivo;

    Archivo.open("Users.dat",ios::app);
    if(Archivo.fail()){
        cout<<"El archivo no se pudo abrir";
        exit(1);
    }

    Archivo<<"0"<<endl;
    Archivo.close();

}

void Archivo::leer(){
    
    ifstream Archivo;
    string name;
    string pw;

    Archivo.open("Users.dat",ios::in);
    if(Archivo.fail()){
        cout<<"El archivo no se pudo abrir";
        exit(1);
    }

    getline(Archivo, name);
    getline(Archivo, pw);
}

Archivo::~Archivo(){
}