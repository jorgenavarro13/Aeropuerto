#ifndef PASAJERO_H
#define PASAJERO_H
#include <string>
using namespace std;

class Pasajero{

    private:

        string nombre;
        int telefono;
        int kilometros_acumulados;
        string contrasena;
        bool vuelo_reservado;
        bool descuento;
        int kilometrospara_acumular;
        int indice_reservar;

    public:

        Pasajero();

        void setNombre();
        void setTelefono();
        void setContrasena();

        string getNombre();
        int getTelefono();
        int getKilometros_acumulados();
        string getContrasena();
        bool getDescuento();
        int getIndice_vuelo();
        int getKilometros_acumular();

        bool verificaCredenciales();
        void acumulaKilometros();
        float aplicarDescuento();
        void modificaAtributos(int asientos, int indice_reserva, int km_acumular);
        void imprimePasajero();
        void cancelaReserva(int asientos, int indice_reserva, int km_acumular);

        virtual ~Pasajero();

};

#endif