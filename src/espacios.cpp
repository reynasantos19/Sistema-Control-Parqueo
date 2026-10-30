#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Cantidad total de espacios del parqueo
const int TOTAL_ESPACIOS = 50;

// Estructura que representa un vehiculo
struct Vehiculo {
    string placa;
    bool ocupado;
};

// Arreglo de vehiculos
Vehiculo espacios[TOTAL_ESPACIOS] = {};
// Guarda los espacios ocupados en un archivo de texto
void guardarDatos() {
    ofstream archivo("datos_parqueo.txt");

    if (!archivo) {
        cout << "Error al guardar los datos." << endl;
        return;
    }

    for (int i = 0; i < TOTAL_ESPACIOS; i++) {
        if (espacios[i].ocupado) {
            archivo << i + 1 << " " << espacios[i].placa << endl;
        }
    }

    archivo.close();
}

// Recupera los datos guardados al iniciar
void cargarDatos() {
    ifstream archivo("datos_parqueo.txt");

    if (!archivo) {
        return;
    }

    int numero;
    string placa;

    while (archivo >> numero >> placa) {
        if (numero >= 1 && numero <= TOTAL_ESPACIOS) {
            espacios[numero - 1].ocupado = true;
            espacios[numero - 1].placa = placa;
        }
    }

    archivo.close();
}

// Cuenta recursivamente los espacios disponibles
int contarDisponibles(int indice) {
    // Caso base: se revisaron los 50 espacios
    if (indice == TOTAL_ESPACIOS) {
        return 0;
    }

    // Cuenta el espacio actual y continúa con el siguiente
    int disponible = espacios[indice].ocupado ? 0 : 1;

    return disponible + contarDisponibles(indice + 1);
}
// Muestra el estado de cada espacio
void mostrarDisponibilidad() {
    cout << "===== DISPONIBILIDAD DE ESPACIOS =====" << endl;
    cout << "Espacios disponibles: " << contarDisponibles(0) << endl;

    for (int i = 0; i < TOTAL_ESPACIOS; i++) {
        cout << "Espacio " << i + 1 << ": ";

        if (!espacios[i].ocupado) {
            cout << "Libre";
        } else {
            cout << "Ocupado - Placa: " << espacios[i].placa;
        }

        cout << endl;
    }
}

// Ocupa un espacio seleccionado
void ocuparEspacio(int numeroEspacio, string placa) {
    if (numeroEspacio < 1 || numeroEspacio > TOTAL_ESPACIOS) {
        cout << "Numero de espacio no valido." << endl;
        return;
    }

    if (espacios[numeroEspacio - 1].ocupado) {
        cout << "El espacio ya esta ocupado." << endl;
        return;
    }

    espacios[numeroEspacio - 1].ocupado = true;
    espacios[numeroEspacio - 1].placa = placa;
    guardarDatos();

    cout << "Espacio " << numeroEspacio
         << " ocupado correctamente." << endl;
}

// Libera un espacio cuando sale un vehiculo
void liberarEspacio(int numeroEspacio) {
    if (numeroEspacio < 1 || numeroEspacio > TOTAL_ESPACIOS) {
        cout << "Numero de espacio no valido." << endl;
        return;
    }

    if (!espacios[numeroEspacio - 1].ocupado) {
        cout << "El espacio ya esta libre." << endl;
        return;
    }

    espacios[numeroEspacio - 1].ocupado = false;
    espacios[numeroEspacio - 1].placa = "";
    guardarDatos();

    cout << "Espacio " << numeroEspacio
         << " liberado correctamente." << endl;
}