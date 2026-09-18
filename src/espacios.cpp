#include <iostream>
using namespace std;

// Cantidad total de espacios del parqueo
const int TOTAL_ESPACIOS = 50;

// Estado de los espacios:
// 0 = libre
// 1 = ocupado
int espacios[TOTAL_ESPACIOS] = {0};

// Muestra el estado de cada espacio
void mostrarDisponibilidad() {
    cout << "===== DISPONIBILIDAD DE ESPACIOS =====" << endl;

    for (int i = 0; i < TOTAL_ESPACIOS; i++) {
        cout << "Espacio " << i + 1 << ": ";

        if (espacios[i] == 0) {
            cout << "Libre";
        } else {
            cout << "Ocupado";
        }

        cout << endl;
    }
}
// Ocupa un espacio seleccionado por el usuario
void ocuparEspacio(int numeroEspacio) {
    if (numeroEspacio < 1 || numeroEspacio > TOTAL_ESPACIOS) {
        cout << "Numero de espacio no valido." << endl;
        return;
    }

    if (espacios[numeroEspacio - 1] == 1) {
        cout << "El espacio ya esta ocupado." << endl;
        return;
    }

    espacios[numeroEspacio - 1] = 1;

    cout << "Espacio " << numeroEspacio << " ocupado correctamente." << endl;
}