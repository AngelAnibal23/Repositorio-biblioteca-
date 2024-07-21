#include <iostream>
#include <cstdlib>
#include "biblioteca.h"
#include "estructuras.h"

using namespace std;
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
			long long buscarID; 
			cin>>buscarID; 
            prestamoLibro(libros, cantidadLibros, buscarID, prestamos, indicePrestamos);
		}
		
	}while(resp!=0);
	
	
	cout<<endl;
	system("PAUSE");
	cout<<endl;
	system("cls");
}

