#include <iostream>
#include <string>
using namespace std;

void mostrarDisponibilidad();
void ocuparEspacio(int numeroEspacio, string placa);
string registrarEntrada();
void registrarSalida();

int main() {
    cout << "====================================" << endl;
    cout << "   SISTEMA DE CONTROL DE PARQUEO" << endl;
    cout << "====================================" << endl;
    cout << "Sistema iniciado correctamente." << endl;

    mostrarDisponibilidad();

    int numeroEspacio;

    cout << endl;
    cout << "Ingrese el numero del espacio que desea ocupar: ";
    cin >> numeroEspacio;

    string placa = registrarEntrada();

    ocuparEspacio(numeroEspacio, placa);

    cout << endl;
    mostrarDisponibilidad();

    cout << endl;
    registrarSalida();

    cout << endl;
    mostrarDisponibilidad();

    return 0;
}