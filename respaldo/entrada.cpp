#include <iostream>
#include <string>
using namespace std;

// Registra la entrada de un vehiculo y devuelve su placa
string registrarEntrada() {
    string placa;

    cout << "===== REGISTRO DE ENTRADA =====" << endl;

    cout << "Ingrese la placa del vehiculo: ";
    cin >> placa;

    cout << "Vehiculo con placa " << placa << " registrado correctamente." << endl;

    return placa;
}