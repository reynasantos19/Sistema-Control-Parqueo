#include <iostream>
#include <string>
using namespace std;

// Cantidad total de espacios del parqueo
const int TOTAL_ESPACIOS = 50;

// Estado de los espacios:
// 0 = libre
// 1 = ocupado
int espacios[TOTAL_ESPACIOS] = {0};

// Placa del vehiculo asignado a cada espacio
string placas[TOTAL_ESPACIOS];

// Muestra el estado de cada espacio
void mostrarDisponibilidad() {
    cout << "===== DISPONIBILIDAD DE ESPACIOS =====" << endl;

    for (int i = 0; i < TOTAL_ESPACIOS; i++) {
        cout << "Espacio " << i + 1 << ": ";

        if (espacios[i] == 0) {
            cout << "Libre";
        } else {
            cout << "Ocupado - Placa: " << placas[i];
        }

        cout << endl;
    }
}

// Ocupa un espacio seleccionado por el usuario
void ocuparEspacio(int numeroEspacio, string placa) {
    if (numeroEspacio < 1 || numeroEspacio > TOTAL_ESPACIOS) {
        cout << "Numero de espacio no valido." << endl;
        return;
    }

    if (espacios[numeroEspacio - 1] == 1) {
        cout << "El espacio ya esta ocupado." << endl;
        return;
    }

    espacios[numeroEspacio - 1] = 1;
    placas[numeroEspacio - 1] = placa;

    cout << "Espacio " << numeroEspacio << " ocupado correctamente." << endl;
}

// Libera un espacio cuando un vehiculo sale
void liberarEspacio(int numeroEspacio) {
    if (numeroEspacio < 1 || numeroEspacio > TOTAL_ESPACIOS) {
        cout << "Numero de espacio no valido." << endl;
        return;
    }

    if (espacios[numeroEspacio - 1] == 0) {
        cout << "El espacio ya esta libre." << endl;
        return;
    }

    espacios[numeroEspacio - 1] = 0;
    placas[numeroEspacio - 1] = "";

    cout << "Espacio " << numeroEspacio << " liberado correctamente." << endl;
}