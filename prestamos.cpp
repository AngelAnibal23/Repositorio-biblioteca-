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
        cout << "\t\t\t\t\t\t\tEl historial de prestamos esta lleno." << endl;
    }
    system("PAUSE");
}


// Funcion que busca el ID ingresado con el usuario y lo compara con las estructuras definidas
void prestamoLibro(Book libros[], int cantidad, int buscarID, int& indicePrestamos) {
    bool confirmacion = false;

    for (int i = 0; i < cantidad; ++i) {
        if (libros[i].id == buscarID) {
            cout << "\t\t\t\t\t\t\tLibro: " << libros[i].nombre << endl;
            cout << "\t\t\t\t\t\t\tDigite los dias de adquisicion (maximo 5 dias): ";
            
            int tiempo;
            while (true) {
                cin >> tiempo;
				//Sistema de validacion para la adquisicion del libro
                if (cin.fail() || tiempo < 1 || tiempo > 5) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\t\t\t\t\t\t\tLa cantidad de dias debe estar entre 1 y 5. Intente de nuevo: ";
                } else {
                    break;
                }
            }

			//Almacenando la hora de prestamo y devolucion en variables string 
            string fechaHora = obtenerFechaHoraActual();
            string fechaDevolucion = obtenerFechaDevolucion(tiempo);
            cout << "\t\t\t\t\t\t\tEl libro se entrego en la fecha: " << fechaHora << endl;
            cout << "\t\t\t\t\t\t\tSe espera que sea devuelto antes de: "<< fechaDevolucion << endl;

            registrarPrestamo(indicePrestamos, libros[i], tiempo, buscarID);

            confirmacion = true;
            break;
        }
    }

    if (!confirmacion) {
        cout << "\n\t\t\t\t\t\t\tEl ID ingresado no corresponde a ningun libro." << endl;
    }
}

//funcion que muestra el historial 
void mostrarHistorial( int cantidad) {
	Logo();
    cout << "\n\t\t\t\t\t\t\tHistorial de Prestamos:\n"<<endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << "\t\t\t\t\t\t\tLibro: " << registrar_usuario[cantidad_de_usuarios-1].prestamos[i].nombre_libro << endl;
        cout << "\t\t\t\t\t\t\tID del libro: "<<registrar_usuario[cantidad_de_usuarios-1].prestamos[i].id_prestamo << endl; 
        cout << "\t\t\t\t\t\t\tFecha de Prestamo: " << registrar_usuario[cantidad_de_usuarios-1].prestamos[i].fecha_entrega << endl;
        cout << "\t\t\t\t\t\t\tFecha de Devolucion: " << registrar_usuario[cantidad_de_usuarios-1].prestamos[i].fecha_devolucion << endl;
        cout << "\t\t\t\t\t\t\t--------------------------\n";
    }
    system("PAUSE");
}

//Funcion que devuelve el libro, en realidad eliminando el registro de prestamo
void devolverLibro(int& cantidad, int buscarID){
	 for(int i=0; i<cantidad; ++i){
	 	if(buscarID == registrar_usuario[cantidad_de_usuarios-1].prestamos[i].id_prestamo){
	 		registrar_usuario[cantidad_de_usuarios-1].prestamos[i]=registrar_usuario[cantidad_de_usuarios-1].prestamos[i+1];
	 		
	 		cout<<"\t\t\t\t\t\t\tEL LIBRO FUE DEVUELTO SATISFACTORIAMENTE!"<<endl; 
	 		cantidad--; 
	 	}
	 }
	system("PAUSE"); 
}


void menuPrestamos(Book libros[]){
    
    int cantidad; 
	int buscarID;
	int opcion;
	
	do {
		cout<<endl;
		Logo();
		cout<<"\t\t\t\t\t\t\t________________MENU DE PRESTAMOS________________"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|"; 
		cout<<endl<<"\t\t\t\t\t\t\t|\t1.- Prestamo de algun libro.\t\t|"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|";
		cout<<endl<<"\t\t\t\t\t\t\t|\t2.- Historial de prestamos. \t\t|"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|";
		cout<<endl<<"\t\t\t\t\t\t\t|\t3.- Devolver libro.         \t\t|"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|";
		cout<<endl<<"\t\t\t\t\t\t\t|\t0.- Salir.                  \t\t|"<<endl;
		cout<<"\t\t\t\t\t\t\t|\t\t                      \t\t|";
		cout<<endl<<"\t\t\t\t\t\t\t|_______________________________________________|"<<endl;;
		cout<<endl<<"\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";

        
		valida(opcion);
        
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
                break;
            }
            default: {
                cout << "\t\t\t\t\t\t\tOpcion invalida, por favor intente de nuevo." << endl;
                break;
            }
           
        }
        
        system("cls"); 
    } while (opcion != 0);
	

	system("cls");
}
void valida(int &entrada){
				
    while (true) {
        cin >> entrada;
        // Verificar si la entrada es valida
        if (cin.fail()) {
        	cin.clear(); // Limpiar el estado de error de cin
        	cin.ignore(10000, '\n'); // Ignorar la entrada incorrecta
        	cout << "\t\t\t\t\t\t\t Existe algun error. Por favor intente de nuevo: ";
        } else {
            break; // Salir del bucle si la entrada es valida
        }
    }
}

// Funcion que le muestra los prestamos en curso al administrador 
void mostrar_prestamos_activos_admin(int cantidad_usuarios, Registro_usuario usuarios[]) {
    cout << "\n\t\t\t\t\t\t\tPrestamos Activos:\n";
    for (int i = 0; i < cantidad_usuarios; ++i) {
        cout << "\t\t\t\t\t\t\tUsuario: " << usuarios[i].NOMBRE << " " << usuarios[i].APELLIDO_PAT << " " << usuarios[i].APELLIDO_MAT << endl;
        cout << "\t\t\t\t\t\t\tEmail: " << usuarios[i].EMAIL << endl;
        cout << "\t\t\t\t\t\t\tTelefono: " << usuarios[i].TELEFONO << endl;
        cout << "\t\t\t\t\t\t\tDNI: " << usuarios[i].DNI << endl;
        
        for (int j = 0; j < cantidadPrestamos; ++j) {
            if (!usuarios[i].prestamos[j].nombre_libro.empty()) {
                cout << "\t\t\t\t\t\t\t  - Libro: " << usuarios[i].prestamos[j].nombre_libro << endl;
                cout << "\t\t\t\t\t\t\t   Fecha de Prestamo: " << usuarios[i].prestamos[j].fecha_entrega << endl;
                cout << "\t\t\t\t\t\t\t   Fecha de Devolucion: " << usuarios[i].prestamos[j].fecha_devolucion << endl;
            }
        }
        cout << "\t\t\t\t\t\t\t----------------------------------------------------\n";
    }
    system("PAUSE"); 
    system("cls"); 
}

