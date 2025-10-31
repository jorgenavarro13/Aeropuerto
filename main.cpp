#include <iostream>
#include"Aeropuerto.h"
#include"Pasajero.h"
#include"Vuelo.h"
#include"Archivo.h"
using namespace std;

// Método del menú una vez iniciada sesión
void menu_principal(Pasajero &P){       // Recibo un Objeto de tipo Pasajero por referenicia "&P"
    Aeropuerto NLU;                     // Creo un objeto de la clase Aeropuerto llamado NLU(Aeropuerto del cual son los vuelos)
    NLU.hacerVectordeObjetosVuelo();    // Ejecutamos un metodo para realizar un vector <Vuelo> Vuelos; al cual accederemos durante la ejecucion del menu
    NLU.setDescuento(P.getDescuento()); // Validación de descuento, utilizamos metodo accesor de nuestro objeto Persona
    int action = 0;
    do{
        cout<<"Que acción deseas realizar en el aeropuerto?"<<endl;
        cout<<" <1> Desplegar todos los vuelos"<<endl;
        cout<<" <2> Filtrar vuelos por fecha"<<endl;
        cout<<" <3> Filtrar vuelos por precio"<<endl;
        cout<<" <4> Pedir detalle de un vuelo"<<endl;
        cout<<" <5> Reserva vuelo"<<endl;
        cout<<" <6> Mostrar datos de usuario: "<<endl;
        cout<<" <7> Cancelar reserva"<<endl;
        cout<<" <8> Salir"<<endl;
        cin>>action;
        cout<<"\n\n";
        switch(action){
            case 1:
                NLU.printAllFlights(P.getDescuento());
                break;
            case 2:
                NLU.imprimeFecha(P.getDescuento());
                break;
            case 3:
                NLU.imprimePrecio(P.getDescuento());
                break;
            case 4:
                NLU.pedirDetalleVuelo(P.getDescuento());
                break;
            case 5:
                int asientos, indice_reserva, km_acumular;
                NLU.reservaVuelo(asientos, indice_reserva, km_acumular);
                P.modificaAtributos(asientos,indice_reserva,km_acumular);
                NLU.pedirDetalleVuelo(P.getDescuento(),asientos,indice_reserva);
                break;
            case 6:
                P.imprimePasajero();
                break;
            case 7:
                NLU.cancelaVuelo(asientos,P.getIndice_vuelo());
                P.cancelaReserva(asientos,indice_reserva,km_acumular);
                break;
            case 8:
                cout<<"Saliendo..."<<endl;
                NLU.setDescuento(false);
                break;
            default:
                cout<<"Error, intentalo de nuevo"<<endl;
                break;
        }
    }
    while(action != 8);
    cout<<"Felicidades por completar el recorrido!"<<endl;
}

int main(){
    Archivo F;
    F.setNombreA("Usuarios.dat");
    Pasajero P;
    int opc = 0;
    do{
        cout<<"Bienvenido a ViajandoAndo"<<endl;
        cout<<"Seleccione una accion: "<<endl;
        cout<<" <1> Iniciar sesion"<<endl;
        cout<<" <2> Registrarse"<<endl;
        cout<<" <3> Salir"<<endl;
        cin>>opc;
        switch(opc){
        case 1:
            P.setNombre();
            P.setContrasena();
            if(P.verificaCredenciales()){
                cout<<"\nBienvenido de nuevo, "<<P.getNombre()<<"."<<endl;
                menu_principal(P);
            }
            else{
                cout<<"Usuario o contrasena incorrectos"<<endl;
                cout<<"Intentalo de nuevo"<<endl;
            }
            break;
        case 2:
            P.setNombre();
            F.escribir(P.getNombre());
            P.setContrasena();
            F.escribir(P.getContrasena());
            F.asignar_cero();
            cout<<"Usuario registrado"<<endl;
            menu_principal(P);
            break;
        case 3:
            cout<<"Saliendo..."<<endl;
            break;
        default:
            cout<<"Error, intentalo de nuevo"<<endl;
            break;
    }
    }
    while(opc!=3);

    return 0;
}
