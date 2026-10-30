#include <iostream>
#include <string>
#include <limits>
using namespace std;

void mostrarDisponibilidad();
void ocuparEspacio(int numeroEspacio, string placa);
string registrarEntrada();
void registrarSalida();

int main() {
    int opcion = 0;
    int numeroEspacio;
    string placa;

    do {
        cout << endl;
        cout << "====================================" << endl;
        cout << "     SISTEMA DE CONTROL DE PARQUEO" << endl;
        cout << "====================================" << endl;
        cout << "1. Registrar entrada de vehiculo" << endl;
        cout << "2. Registrar salida de vehiculo" << endl;
        cout << "3. Consultar disponibilidad" << endl;
        cout << "4. Salir del sistema" << endl;
        cout << "====================================" << endl;
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << endl << "Entrada no valida. Ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                cout << endl;
                cout << "Ingrese el numero del espacio (1-50): ";

                if (!(cin >> numeroEspacio)) {
                    cout << "Numero no valido." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (numeroEspacio < 1 || numeroEspacio > 50) {
                    cout << "El espacio debe estar entre 1 y 50." << endl;
                    break;
                }

                placa = registrarEntrada();
                ocuparEspacio(numeroEspacio, placa);
                break;

            case 2:
                cout << endl;
                registrarSalida();
                break;

            case 3:
                cout << endl;
                mostrarDisponibilidad();
                break;

            case 4:
                cout << endl;
                cout << "Gracias por utilizar el sistema." << endl;
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << endl;
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }

    } while (opcion != 4);

    return 0;
}
