#include <iostream>
#include <cstdlib>
#include "biblioteca.h"
#include "estructuras.h"
#include "libro1.h"
#include <string>
#include <ctime>


using namespace std;

Book libro[15]; 
Prestamo prest[50]; 
Registro registrar[1000];
int cantidad_de_usuarios;

int tiempo;
const int cantidadLibros = 15;
const int cantidadPrestamos = 50;



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
        cout << "\t\t\t\t\t\t\tEl historial de prestamos esta lleno." << endl;
    }
}

void prestamoLibro(Book libros[], int cantidad, long long buscarID, Prestamo prestamos[], int& indicePrestamos) {
    int confirmacion = 0;
	
    for (int i = 0; i < cantidad; ++i) {
    	
        if (libros[i].id == buscarID) {
            cout << "\t\t\t\t\t\t\tLibro: " << libros[i].nombre << endl;
            cout << "\t\t\t\t\t\t\tDigite los dias de adquisicion (maximo 5 dias): ";

            while (true) {
                cin >> tiempo;

                // Verificar si la entrada es válida
                if (cin.fail() || tiempo < 1 || tiempo > 5) {
                    cin.clear(); // Limpiar el estado de error de cin
                    cin.ignore(10000, '\n'); // Ignorar la entrada incorrecta
                    cout << "\t\t\t\t\t\t\tLa cantidad de dias debe estar entre 1 y 5. Intente de nuevo: ";
                } else {
                    break; // Salir del bucle si la entrada es válida
                }
            }

            string fechaHora = obtenerFechaHoraActual();
            string fechaDevolucion = obtenerFechaDevolucion(tiempo);
            cout << "\t\t\t\t\t\t\tEl libro se entrego en la fecha: " << endl << fechaHora << endl;
            cout << "\t\t\t\t\t\t\tSe espera que sea devuelto antes de: " << endl << fechaDevolucion << endl;

            registrarPrestamo(prestamos, indicePrestamos, libros[i], tiempo);

            confirmacion = 1;
            break;
        }
    }

    if (confirmacion==0) {
        cout << "\n\t\t\t\t\t\t\tEl ID ingresado no corresponde a ningun libro." << endl;
    }
    system("cls");
}

void mostrarHistorial(const Prestamo prestamos[], int cantidad) {
	Logo();
    cout << "\n\t\t\t\t\t\t\tHistorial de Prestamos:\n";
    for (int i = 0; i < cantidad; ++i) {
        cout << "\t\t\t\t\t\t\tLibro: " << prestamos[i].nombre_libro << endl;
        cout << "\t\t\t\t\t\t\tFecha de Prestamo: " << prestamos[i].fecha_entrega << endl;
        cout << "\t\t\t\t\t\t\tFecha de Devolucion: " << prestamos[i].fecha_devolucion << endl;
        cout << "\t\t\t\t\t\t\t--------------------------\n";
    }
    cout<<endl;
    system("PAUSE");
    system("cls");
}

comunicacion comu [10] = {
    {"Carlos Fernandez", 2016, 450, "Teoria y Practica de la Comunicacion", 101},
	{"Ana Martinez", 2019, 380, "Comunicacion Interpersonal en el Ambito Academico", 102},
    {"Jorge Ramirez", 2021, 410, "Comunicacion Digital para Estudiantes Universitarios", 103}
};
matematica mate [10] = {
	{"Erwin Kreyszig",2007,1272,"Matematicas avanzadas para ingenieros", 104},
	{"Granville, Smith y Longley",2012,960,"Calculo diferencial e integral", 103},
	{"Serge Lang",1996,480,"Algebra Lineal", 105}
};
programacion progr [10] = {
	{"Luis Torres",2018,520,"Introduccion a la Programacion con Python", 106},
	{"Marta Sanchez",2017,480,"Programacion en Java para Universitarios", 107},
	{"Jose Hernandez",2020,550,"Fundamentos de Programacion en C++", 108}
};
quimica quimi [10] = {
	{"Ricardo Morales",2016,700,"Quimica General: Principios y Aplicaciones Modernas", 109},
	{"Ana Fernandez",2018,640,"Quimica Organica: Teoria y Practica",110},
	{"Javier Gomez",2019,580,"Quimica Inorganica para Estudiantes Universitarios",111}
};
historia hist [10] = {
	{"Laura Rodriguez",2015,720,"Historia Contemporanea: Desde la Revolución Francesa hasta la Globalizacion",112},
	{"Miguel Alvarez",2017,650,"Historia de America Latina: Colonizacion y Desarrollo",113},
	{"Carmen Sanchez",2020,600,"Historia de España: Desde los Visigodos hasta la Democracia",114}
};

void mostrar(int numcateg){
	Logo();
	if(numcateg == 1) {
    	for(int a = 0; a < 10; a++) {
        	if(comu[a].ID1 != 0) {
         	   cout << "\t\t\t\t\tL" << a + 1 << "    ID: " << comu[a].ID1 << "   NOMBRE: " << comu[a].Nombre1 << endl << "\t\t\t\t\t\t\t         AUTOR: " ;
          	  cout << comu[a].Autor1 << comu[a].Anio1 << "   PAG: " << comu[a].paginas1<< endl;              
     		   }
   		 }
	} else if(numcateg == 2) {
    	for(int a = 0; a < 10; a++) {
       	 if(mate[a].ID2 != 0) {
          	  cout << "\t\t\t\t\tL" << a + 1 << "    ID: " << mate[a].ID2 << "   NOMBRE: " << mate[a].Nombre2 << endl << "\t\t\t\t\t\t\t         AUTOR: ";
          	  cout << mate[a].Autor2 << mate[a].Anio2 << "   PAG: " << mate[a].paginas2<<  endl;         
       		 }
    	}
	} else if(numcateg == 3) {
   	 	for(int a = 0; a < 10; a++) {
        	if(progr[a].ID3 != 0) {
            	cout << "\t\t\t\t\tL" << a + 1  << "    ID: " << progr[a].ID3  << "   NOMBRE: " << progr[a].Nombre3;
            	cout<< endl << "\t\t\t\t\t\t\t         AUTOR: " << progr[a].Autor3 << progr[a].Anio3<< "   PAG: " << progr[a].paginas3<< endl;           
      		  }
    	}
	} else if(numcateg == 4) {
    	for(int a = 0; a < 10; a++) {
        	if(quimi[a].ID4 != 0) {
          	  	cout << "\t\t\t\t\tL" << a + 1  << "    ID: " << quimi[a].ID4 << "   NOMBRE: " << quimi[a].Nombre4 << endl << "\t\t\t\t\t\t\t         AUTOR: ";
            	cout << quimi[a].Autor4 << quimi[a].Anio4    << "   PAG: " << quimi[a].paginas4 << endl;        
        	}
    	}
	} else if(numcateg == 5) {
    	for(int a = 0; a < 10; a++) {
        	if(hist[a].ID5 != 0) {
            	cout << "\t\t\t\t\tL" << a + 1 << "    ID: " << hist[a].ID5 << "   NOMBRE: " << hist[a].Nombre5 << endl << "\t\t\t\t\t\t\t         AUTOR: " ;
            	cout  << hist[a].Autor5 << hist[a].Anio5  << "   PAG: " << hist[a].paginas5   << endl;      
        	}
    	}
	}else{
    	cout<<" dato incorrecto"<<endl;
	}	

	
	
}
//funcion para abrir el menu de prestamos 

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
        }
    } while (opcion != 0);

	cout<<endl;
	system("PAUSE");
	cout<<endl;

	system("cls");
}


 Book libros[cantidadLibros] = {
        {101, "Teoria y Practica de la Comunicacion", "Carlos Fernandez", 2016, 450},
        {102, "Comunicacion Interpersonal en el Ambito Academico", "Ana Martinez", 2019, 380},
        {103, "Comunicacion Digital para Estudiantes Universitarios", "Jorge Ramirez", 2021, 410},
        {104, "Matematicas avanzadas para ingenieros", "Erwin Kreyszig", 2007, 1272},
        {105, "Calculo diferencial e integral", "Granville, Smith y Longley", 2012, 960},
        {106, "Algebra Lineal", "Serge Lang", 1996, 480},
        {107, "Introduccion a la Programacion con Python", "Luis Torres", 2018, 520},
        {108, "Programacion en Java para Universitarios", "Marta Sanchez", 2017, 480},
        {109, "Fundamentos de Programacion en C++", "Jose Hernandez", 2020, 550},
        {110, "Quimica General: Principios y Aplicaciones Modernas", "Ricardo Morales", 2016, 700},
        {111, "Quimica Organica: Teoria y Practica", "Ana Fernandez", 2018, 640},
        {112, "Quimica Inorganica para Estudiantes Universitarios", "Javier Gomez", 2019, 580},
        {113, "Historia Contemporanea: Desde la Revolución Francesa hasta la Globalizacion", "Laura Rodriguez", 2015, 720},
        {114, "Historia de America Latina: Colonizacion y Desarrollo", "Miguel Alvarez", 2017, 650},
        {115, "Historia de Espa�a: Desde los Visigodos hasta la Democracia", "Carmen Sanchez", 2020, 600}
    };



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
//MENU MOSTRAR INVENTARIO
void Menu_Mostrar(){
			
	int numcateg;
	

	Logo();
	cout<<"\t\t\t\t\t\t\t_________________MENU INVENTARIO_________________"<<endl;
	cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|"; //para centrar  5 \t ojo se trabaja con pantalla completa
	cout<<endl<<"\t\t\t\t\t\t\t|\t\t1.- Comunicacion. \t\t|"<<endl;
	cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
	cout<<endl<<"\t\t\t\t\t\t\t|\t\t2.- Matematica.   \t\t|"<<endl;
	cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
	cout<<endl<<"\t\t\t\t\t\t\t|\t\t3.- Programacion. \t\t|"<<endl;
	cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
	cout<<endl<<"\t\t\t\t\t\t\t|\t\t4.- Quimica.      \t\t|"<<endl;
	cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
	cout<<endl<<"\t\t\t\t\t\t\t|\t\t5.- Historia.     \t\t|"<<endl;
	cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
	cout<<endl<<"\t\t\t\t\t\t\t|\t\t0.- Salir.        \t\t|"<<endl;
	cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
	cout<<endl<<"\t\t\t\t\t\t\t|_______________________________________________|"<<endl;;
	cout<<endl<<"\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";
	
	cin>>numcateg;
	system("cls");
	mostrar(numcateg);
	
	cout<<endl;
	system("PAUSE");
	
}
	        

//INGRESA AL MENU DE USUARIO
void Menu_Usuario(){

	cout<<endl;
	int resp;
	do{
		//MENU
		Logo();

		cout<<"\t\t\t\t\t\t__________________MENU DE USUARIO________________________"<<endl;
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
			Menu_Mostrar();
			system("cls");
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
