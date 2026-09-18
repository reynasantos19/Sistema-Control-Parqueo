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