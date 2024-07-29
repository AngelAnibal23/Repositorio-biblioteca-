#include "funciones.h"
#include "biblioteca.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;


const int cantidadPrestamos = 30;
//Prestamo prestamos[cantidadPrestamos];
int indicePrestamos = 0;

//Funcion que obtiene la hora del sistema y la almacena en un arreglo. 
string obtenerFechaHoraActual() {
    time_t tiempo_actual = time(NULL);
    tm* ahora_local = localtime(&tiempo_actual);

    char arreglo_hora[100];
    strftime(arreglo_hora, sizeof(arreglo_hora), "%d/%m/%Y %H:%M:%S", ahora_local);
    
    return string(arreglo_hora);
}

//Funcion que convierte la hora de devolucion, con los dias de adquisicion en un arreglo 
string obtenerFechaDevolucion(int dias_sumar) {
    time_t tiempo_actual = time(NULL);
    tm* ahora_local = localtime(&tiempo_actual);

    ahora_local->tm_mday += dias_sumar;
    
    mktime(ahora_local);

    char devolucion[100];
    strftime(devolucion, sizeof(devolucion), "%d/%m/%Y %H:%M:%S", ahora_local);
    
    return string(devolucion);
}

// funcion que registra el prestamo, segun el ID del libro 
void registrarPrestamo(int& indice, const Book& libro, int dias_prestamo, int buscarID) {
    if (indice < cantidadPrestamos) {
        
        registrar_usuario[cantidad_de_usuarios-1].prestamos[indice].nombre_libro = libro.nombre;
        registrar_usuario[cantidad_de_usuarios-1].prestamos[indice].fecha_entrega = obtenerFechaHoraActual();
        registrar_usuario[cantidad_de_usuarios-1].prestamos[indice].fecha_devolucion = obtenerFechaDevolucion(dias_prestamo);
        registrar_usuario[cantidad_de_usuarios-1].prestamos[indice].id_prestamo = buscarID; 
        
        indice++;
    } else {
        cout << "El historial de prestamos esta lleno." << endl;
    }
}


// Funcion que busca el ID ingresado con el usuario y lo compara con las estructuras definidas
void prestamoLibro(Book libros[], int cantidad, int buscarID, int& indicePrestamos) {
    bool confirmacion = false;

    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].id == buscarID) {
            cout << "Libro: " << libros[i].nombre << endl;
            cout << "Digite los dias de adquisicion (maximo 5 dias): ";
            
            int tiempo;
            while (true) {
                cin >> tiempo;
				//Sistema de validacion para la adquisicion del libro
                if (cin.fail() || tiempo < 1 || tiempo > 5) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "La cantidad de dias debe estar entre 1 y 5. Intente de nuevo: ";
                } else {
                    break;
                }
            }

			//Almacenando la hora de prestamo y devolucion en variables string 
            string fechaHora = obtenerFechaHoraActual();
            string fechaDevolucion = obtenerFechaDevolucion(tiempo);
            cout << "El libro se entrego en la fecha: " << endl << fechaHora << endl;
            cout << "Se espera que sea devuelto antes de: " << endl << fechaDevolucion << endl;

            registrarPrestamo(indicePrestamos, libros[i], tiempo, buscarID);

            confirmacion = true;
            break;
        }
    }

    if (!confirmacion) {
        cout << "\nEl ID ingresado no corresponde a ningun libro." << endl;
    }
}

//funcion que muestra el historial 
void mostrarHistorial( int cantidad) {
    cout << "\nHistorial de Prestamos:\n";
    for (int i = 0; i < cantidad; ++i) {
        cout << "Libro: " << registrar_usuario[cantidad_de_usuarios-1].prestamos[i].nombre_libro << endl;
        cout << "ID del libro: "<<registrar_usuario[cantidad_de_usuarios-1].prestamos[i].id_prestamo << endl; 
        cout << "Fecha de Prestamo: " << registrar_usuario[cantidad_de_usuarios-1].prestamos[i].fecha_entrega << endl;
        cout << "Fecha de Devolucion: " << registrar_usuario[cantidad_de_usuarios-1].prestamos[i].fecha_devolucion << endl;
        cout << "--------------------------\n";
    }
}

//Funcion que devuelve el libro, en realidad eliminando el registro de prestamo
void devolverLibro(int& cantidad, int buscarID){
	 for(int i=0; i<cantidad; ++i){
	 	if(buscarID == registrar_usuario[cantidad_de_usuarios-1].prestamos[i].id_prestamo){
	 		registrar_usuario[cantidad_de_usuarios-1].prestamos[i]=registrar_usuario[cantidad_de_usuarios-1].prestamos[i+1];
	 		
	 		cout<<"EL LIBRO FUE DEVUELTO SATISFACTORIAMENTE!"<<endl; 
	 		cantidad--; 
	 	}
	 }
	 
}


void menuPrestamos(Book libros[]){
    
    int cantidad; 
	int buscarID;
	int opcion;
	
	do {
		cout<<endl;
		Logo();
		cout<<"\t\t\t\t\t\t\t________________MENU DE PRESTAMOS________________"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|"; //para centrar  5 \t ojo se trabaja con pantalla completa
		cout<<endl<<"\t\t\t\t\t\t\t|\t1.- Prestamo de algun libro.\t\t|"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|";
		cout<<endl<<"\t\t\t\t\t\t\t|\t2.- Historial de prestamos. \t\t|"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|";
		cout<<endl<<"\t\t\t\t\t\t\t|\t3.- Devolver libro. \t\t|"<<endl;
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
				valida(buscarID);
                prestamoLibro(libros, cantidadLibros, buscarID, indicePrestamos);
                break;
            }
            case 2: {
                mostrarHistorial(indicePrestamos);
                break;
            }
            case 3: {
            	Menu_Mostrar();
                cout << "\t\t\t\t\t\t\tDigite el ID del libro: ";
				valida(buscarID);
				devolverLibro(indicePrestamos, buscarID); 
            	break;
            }
            case 0: {
                cout << "\t\t\t\t\t\t\tSaliendo." << endl;
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
void valida(int &entrada){
				
    while (true) {
        cin >> entrada;
        // Verificar si la entrada es válida
        if (cin.fail()) {
        	cin.clear(); // Limpiar el estado de error de cin
        	cin.ignore(10000, '\n'); // Ignorar la entrada incorrecta
        	cout << "\t\t\t\t\t\t\t Existe algun error. Por favor intente de nuevo: ";
        } else {
            break; // Salir del bucle si la entrada es válida
        }
    }
}

// Funcion que le muestra los prestamos en curso al administrador 
void mostrar_prestamos_activos_admin(int cantidad_usuarios, Registro_usuario usuarios[]) {
    cout << "\nPrestamos Activos:\n";
    for (int i = 0; i < cantidad_usuarios; ++i) {
        cout << "Usuario: " << usuarios[i].NOMBRE << " " << usuarios[i].APELLIDO_PAT << " " << usuarios[i].APELLIDO_MAT << endl;
        cout << "Email: " << usuarios[i].EMAIL << endl;
        cout << "Telefono: " << usuarios[i].TELEFONO << endl;
        cout << "DNI: " << usuarios[i].DNI << endl;
        
        for (int j = 0; j < cantidadPrestamos; ++j) {
            if (!usuarios[i].prestamos[j].nombre_libro.empty()) {
                cout << "  - Libro: " << usuarios[i].prestamos[j].nombre_libro << endl;
                cout << "    Fecha de Prestamo: " << usuarios[i].prestamos[j].fecha_entrega << endl;
                cout << "    Fecha de Devolucion: " << usuarios[i].prestamos[j].fecha_devolucion << endl;
            }
        }
        cout << "----------------------------------------------------\n";
    }
    system("PAUSE"); 
    system("cls"); 
}

