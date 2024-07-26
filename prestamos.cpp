#include "funciones.h"
#include "biblioteca.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int cantidadPrestamos = 50;

string obtenerFechaHoraActual() {
    time_t tiempo_actual = time(NULL);
    tm* ahora_local = localtime(&tiempo_actual);

    char arreglo_hora[100];
    strftime(arreglo_hora, sizeof(arreglo_hora), "%d/%m/%Y %H:%M:%S", ahora_local);
    
    return string(arreglo_hora);
}

string obtenerFechaDevolucion(int dias_sumar) {
    time_t tiempo_actual = time(NULL);
    tm* ahora_local = localtime(&tiempo_actual);

    ahora_local->tm_mday += dias_sumar;
    
    mktime(ahora_local);

    char devolucion[100];
    strftime(devolucion, sizeof(devolucion), "%d/%m/%Y %H:%M:%S", ahora_local);
    
    return string(devolucion);
}

void registrarPrestamo(Prestamo prestamos[], int& indice, const Book& libro, int dias_prestamo) {
    if (indice < cantidadPrestamos) {
        Prestamo prestamo;
        prestamo.nombre_libro = libro.nombre;
        prestamo.fecha_entrega = obtenerFechaHoraActual();
        prestamo.fecha_devolucion = obtenerFechaDevolucion(dias_prestamo);
        prestamos[indice] = prestamo;
        indice++;
    } else {
        cout << "El historial de prestamos esta lleno." << endl;
    }
}

void prestamoLibro(Book libros[], int cantidad, long long buscarID, Prestamo prestamos[], int& indicePrestamos) {
    bool confirmacion = false;

    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].id == buscarID) {
            cout << "Libro: " << libros[i].nombre << endl;
            cout << "Digite los dias de adquisicion (maximo 5 dias): ";
            
            int tiempo;
            while (true) {
                cin >> tiempo;

                if (cin.fail() || tiempo < 1 || tiempo > 5) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "La cantidad de dias debe estar entre 1 y 5. Intente de nuevo: ";
                } else {
                    break;
                }
            }

            string fechaHora = obtenerFechaHoraActual();
            string fechaDevolucion = obtenerFechaDevolucion(tiempo);
            cout << "El libro se entrego en la fecha: " << endl << fechaHora << endl;
            cout << "Se espera que sea devuelto antes de: " << endl << fechaDevolucion << endl;

            registrarPrestamo(prestamos, indicePrestamos, libros[i], tiempo);

            confirmacion = true;
            break;
        }
    }

    if (!confirmacion) {
        cout << "\nEl ID ingresado no corresponde a ningun libro." << endl;
    }
}

void mostrarHistorial(const Prestamo prestamos[], int cantidad) {
    cout << "\nHistorial de Prestamos:\n";
    for (int i = 0; i < cantidad; ++i) {
        cout << "Libro: " << prestamos[i].nombre_libro << endl;
        cout << "Fecha de Prestamo: " << prestamos[i].fecha_entrega << endl;
        cout << "Fecha de Devolucion: " << prestamos[i].fecha_devolucion << endl;
        cout << "--------------------------\n";
    }
}


void menuPrestamos(Book libros[]){
     Prestamo prestamos[cantidadPrestamos];
	int buscarID;
	int opcion, indicePrestamos = 0;

	do {
		cout<<endl;
		Logo();
		cout<<"\t\t\t\t\t\t\t________________MENU DE PRESTAMOS________________"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|"; //para centrar  5 \t ojo se trabaja con pantalla completa
		cout<<endl<<"\t\t\t\t\t\t\t|\t1.- Prestamo de algun libro.\t\t|"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|";
		cout<<endl<<"\t\t\t\t\t\t\t|\t2.- Historial de prestamos. \t\t|"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|";
		cout<<endl<<"\t\t\t\t\t\t\t|\t0.- Salir.                  \t\t|"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|";
		cout<<endl<<"\t\t\t\t\t\t\t|_______________________________________________|"<<endl;;
		cout<<endl<<"\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";

        

        while (true) {
            cin >> opcion;

            // Verificar si la entrada es válida
            if (cin.fail()) {
                cin.clear(); // Limpiar el estado de error de cin
                cin.ignore(10000, '\n'); // Ignorar la entrada incorrecta
                cout << "\t\t\t\t\t\t\tOpcion invalida, por favor intente de nuevo: ";
            } else {
                break; // Salir del bucle si la entrada es válida
            }
        }
        system("cls");

        switch (opcion) {
            case 1: {
            	Menu_Mostrar();
                cout << "\t\t\t\t\t\t\tDigite el ID del libro: ";

                while (true) {
                    cin >> buscarID;

                    // Verificar si la entrada es válida
                    if (cin.fail()) {
                        cin.clear(); // Limpiar el estado de error de cin
                        cin.ignore(10000, '\n'); // Ignorar la entrada incorrecta
                        cout << "\t\t\t\t\t\t\tID invalido, por favor intente de nuevo: ";
                    } else {
                        break; // Salir del bucle si la entrada es válida
                    }
                }

                prestamoLibro(libros, cantidadLibros, buscarID, prestamos, indicePrestamos);
                break;
            }
            case 2: {
                mostrarHistorial(prestamos, indicePrestamos);
                break;
            }
            case 0: {
                cout << "\t\t\t\t\t\t\tSaliendo del programa." << endl;
                break;
            }
            default: {
                cout << "\t\t\t\t\t\t\tOpcion invalida, por favor intente de nuevo." << endl;
                break;
            }
           // system("cls"); 
        }
        system("PAUSE"); 
        system("cls"); 
    } while (opcion != 0);
	
	
	cout<<endl;
	system("PAUSE");
	cout<<endl;

	system("cls");
}

