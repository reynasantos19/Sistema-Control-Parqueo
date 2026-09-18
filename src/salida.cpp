#include <iostream>
using namespace std;

// Funcion que libera un espacio del parqueo
void liberarEspacio(int numeroEspacio);

// Registra la salida de un vehiculo
void registrarSalida() {
    int numeroEspacio;

    cout << "===== REGISTRO DE SALIDA =====" << endl;

    cout << "Ingrese el numero del espacio que desea liberar: ";
    cin >> numeroEspacio;

    liberarEspacio(numeroEspacio);
}