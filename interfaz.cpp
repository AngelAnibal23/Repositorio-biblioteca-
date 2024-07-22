#include <iostream>
#include <cstdlib>
#include "biblioteca.h"
#include "estructuras.h"
#include <string>
#include <ctime>

using namespace std;

int tiempo;
const int cantidadLibros = 15;
const int cantidadPrestamos = 50;

//ESTRUCTURA DE DATOS PERSONALES
struct Registro{
	string NOMBRE;
	string DNI;
	string CODIGO;
	string EDAD;
	string EMAIL;
	string SEXO;
	string TELEFONO;
};

struct Prestamo {
    string nombre_libro;
    string fecha_entrega;
    string fecha_devolucion;
};

struct Book {
    long long id; 
    string nombre;
    string autor;
    int anio;
    int paginas;
};

//funciones para que funcione el menu 3 

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
            
            while (true) {
                cin >> tiempo;

                // Verificar si la entrada es válida
                if (cin.fail() || tiempo < 1 || tiempo > 5) {
                    cin.clear(); // Limpiar el estado de error de cin
                    cin.ignore(10000, '\n'); // Ignorar la entrada incorrecta
                    cout << "La cantidad de dias debe estar entre 1 y 5. Intente de nuevo: ";
                } else {
                    break; // Salir del bucle si la entrada es válida
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


//funcion para abrir el menu de prestamos 

void menuPrestamos(Book libros[]){
     Prestamo prestamos[cantidadPrestamos];
	long long buscarID;
	int opcion, indicePrestamos = 0;
	
	do {
		
        cout << endl;
        cout << "1. Prestamo de algun libro." << endl;
        cout << "2. Historial de prestamos." << endl;
        cout << "3. SALIR." << endl;
        cout << "Digite la opcion: ";
        
        while (true) {
            cin >> opcion;

            // Verificar si la entrada es válida
            if (cin.fail()) {
                cin.clear(); // Limpiar el estado de error de cin
                cin.ignore(10000, '\n'); // Ignorar la entrada incorrecta
                cout << "Opción inválida, por favor intente de nuevo: ";
            } else {
                break; // Salir del bucle si la entrada es válida
            }
        }

        switch (opcion) {
            case 1: {
                cout << "Digite el ID del libro: ";
                
                while (true) {
                    cin >> buscarID;

                    // Verificar si la entrada es válida
                    if (cin.fail()) {
                        cin.clear(); // Limpiar el estado de error de cin
                        cin.ignore(10000, '\n'); // Ignorar la entrada incorrecta
                        cout << "ID inválido, por favor intente de nuevo: ";
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
            case 3: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default: {
                cout << "Opción inválida, por favor intente de nuevo." << endl;
                break;
            }
        }
    } while (opcion != 3);
    
	cout<<endl;
	system("PAUSE");
	cout<<endl;
	
	system("cls");
}


 Book libros[cantidadLibros] = {
        {9783161484100, "Teoria y Práctica de la Comunicacion", "Carlos Fernandez", 2016, 450},
        {9781402894626, "Comunicacion Interpersonal en el Ambito Academico", "Ana Martinez", 2019, 380},
        {9780743273565, "Comunicación Digital para Estudiantes Universitarios", "Jorge Ramirez", 2021, 410},
        {9780061120084, "Matematicas avanzadas para ingenieros", "Erwin Kreyszig", 2007, 1272},
        {9780156027656, "Calculo diferencial e integral", "Granville, Smith y Longley", 2012, 960},
        {9780060935467, "Algebra Lineal", "Serge Lang", 1996, 480},
        {9781568650401, "Introduccion a la Programacion con Python", "Luis Torres", 2018, 520},
        {9780385493574, "Programacion en Java para Universitarios", "Marta Sanchez", 2017, 480},
        {9780140283297, "Fundamentos de Programación en C++", "Jose Hernandez", 2020, 550},
        {9780743273566, "Quimica General: Principios y Aplicaciones Modernas", "Ricardo Morales", 2016, 700},
        {9780451529277, "Quimica Organica: Teoria y Practica", "Ana Fernandez", 2018, 640},
        {9780743273573, "Quimica Inorganica para Estudiantes Universitarios", "Javier Gomez", 2019, 580},
        {9780375755163, "Historia Contemporanea: Desde la Revolución Francesa hasta la Globalizacion", "Laura Rodriguez", 2015, 720},
        {9780440226127, "Historia de America Latina: Colonizacion y Desarrollo", "Miguel Alvarez", 2017, 650},
        {9781402894633, "Historia de España: Desde los Visigodos hasta la Democracia", "Carmen Sanchez", 2020, 600}
    };


Book libro[15]; 
Prestamo prest[50]; 
Registro registrar[1000];
int cantidad_de_usuarios;
//FUNCION DE REGISTRAR
void Registrar(Registro REG[],int &cant_usu){
	Logo();
	cout<<"\t\t\t\t\t\t\t\t-----REGISTRARSE-----"<<endl;
	int i = cant_usu;//asignamos a i la cantidad de usuarios registrados hasta el momento
		fflush(stdin);
		cout<<"\t\t\t\t\t\t\t\tNOMBRE: ";
		getline(cin, REG[i].NOMBRE);
		fflush(stdin);
		cout<<"\t\t\t\t\t\t\t\tSEXO: ";
		getline(cin, REG[i].SEXO);
		fflush(stdin);
		cout<<" \t\t\t\t\t\t\t\tEDAD: ";
		getline(cin, REG[i].EDAD);
		fflush(stdin);
		cout<<"\t\t\t\t\t\t\t\tTELEFONO: ";
		getline(cin, REG[i].TELEFONO);
		fflush(stdin);
		cout<<"\t\t\t\t\t\t\t\tEMAIL: ";
		getline(cin, REG[i].EMAIL);
		fflush(stdin);
		cout<<"\t\t\t\t\t\t\t\tCODIGO UNIVERSITARIO: ";
		fflush(stdin);
		getline(cin, REG[i].CODIGO);
		cout<<"\t\t\t\t\t\t\t\tDNI: ";
		getline(cin, REG[i].DNI);
		fflush(stdin);
		i++;
		cant_usu++;
	
	
	cout<<endl;
	system("PAUSE");
	cout<<endl;
	
	system("cls");
}



//Imprime el logo de BIBLIOTECA
void Logo(){
	cout<<"\t\t\t\t\t----------------------------------------------------------------------------"<<endl;
    cout << "\t\t\t\t\t      0000    000   0000    0     000   00000   00000  00000   0000    000   " << endl;
    cout << "\t\t\t\t\t     0   0    0    0   0   0      0   0     0    0    0      0       0   0   "<< endl;
    cout << "\t\t\t\t\t    0000     0    0000    0      0   0     0    0    000    0       00000     " << endl;
    cout << "\t\t\t\t\t   0   0    0    0   0   0      0   0     0    0    0      0       0   0       " << endl;
    cout << "\t\t\t\t\t  0000    000   0000    0000  000   00000     0    00000   0000   0   0    " << endl;
	cout<<"\t\t\t\t\t----------------------------------------------------------------------------"<<endl<<endl<<endl;
}
//muestra el menu principal
void Menu_Principal(){
	int resp;
		int numero;
		do{
			
			Logo();
			cout<<"\t\t\t\t\t\t\t__________________MENU PRINCIPAL_________________"<<endl;
			cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|"; //para centrar  5 \t ojo se trabaja con pantalla completa
			cout<<endl<<"\t\t\t\t\t\t\t|\t\t1.- Usuario libre.\t\t|"<<endl;
			cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
			cout<<endl<<"\t\t\t\t\t\t\t|\t\t2.- Administrador.\t\t|"<<endl;
			cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
			cout<<endl<<"\t\t\t\t\t\t\t|\t\t0.- Salir.        \t\t|"<<endl;
			cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
			cout<<endl<<"\t\t\t\t\t\t\t|_______________________________________________|"<<endl;;
			cout<<endl<<"\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";cin>>resp;
		
			system("cls");
			if(resp==1){
				
				Menu_Usuario();
				
			}else if(resp==2){
				//Menu_Administrador()
			}
		}while(resp!=0);
}

//INGRESA AL MENU DE USUARIO
void Menu_Usuario(){

	cout<<endl;
	int resp;
	do{
		//MENU
		Logo();
		
		cout<<"\t\t\t\t\t\t__________________MENU PRINCIPAL_________________________"<<endl;
			cout<<"\t\t\t\t\t\t|\t\t                              \t\t|"; //para centrar  5 \t ojo se trabaja con pantalla completa
			cout<<endl<<"\t\t\t\t\t\t|\t\t1.- Registrarse.             \t\t|"<<endl;
			cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
			cout<<endl<<"\t\t\t\t\t\t|\t\t2.- Mostrar Inventario.      \t\t|"<<endl;
			cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
			cout<<endl<<"\t\t\t\t\t\t|\t\t3.- Prestarse un libro.      \t\t|"<<endl;
			cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
			cout<<endl<<"\t\t\t\t\t\t|\t\t0.- Volver al menu principal.\t\t|"<<endl;
			cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
			cout<<endl<<"\t\t\t\t\t\t|_______________________________________________________|"<<endl;;
			cout<<endl<<"\t\t\t\t\t\t\t \tIngrese la respuesta: ";cin>>resp;
		system("cls");
	
		if(resp==1){
			Registrar(registrar,cantidad_de_usuarios);
		}
		if(resp==2){
			
		}
		if(resp==3){
	       menuPrestamos(libros); 
		}
		
	}while(resp!=0);
	
	
	cout<<endl;
	system("PAUSE");
	cout<<endl;
	system("cls");
}

