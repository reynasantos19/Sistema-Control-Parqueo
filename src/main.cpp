#include <iostream>
using namespace std;

void mostrarDisponibilidad();
void ocuparEspacio(int numeroEspacio);
void registrarEntrada();

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

ocuparEspacio(numeroEspacio);

cout << endl;
mostrarDisponibilidad();

return 0;
}