#include "funciones.h"
#include "biblioteca.h"
#include <iostream>
#include <cstdlib>
#include <string>

int cantidad_de_usuarios = 0; 

Registro registrar[30]; 

using namespace std;

void Logo() {
    cout<<"\t\t\t\t\t----------------------------------------------------------------------------"<<endl;
    cout << "\t\t\t\t\t      0000    000   0000    0     000   00000   00000  00000   0000    000   " << endl;
    cout << "\t\t\t\t\t     0   0    0    0   0   0      0   0     0    0    0      0       0   0   "<< endl;
    cout << "\t\t\t\t\t    0000     0    0000    0      0   0     0    0    000    0       00000     " << endl;
    cout << "\t\t\t\t\t   0   0    0    0   0   0      0   0     0    0    0      0       0   0       " << endl;
    cout << "\t\t\t\t\t  0000    000   0000    0000  000   00000     0    00000   0000   0   0    " << endl;
    cout<<"\t\t\t\t\t----------------------------------------------------------------------------"<<endl<<endl<<endl;
}


void Menu_Principal() {
    int resp;
    do {
        Logo();
        cout<<"\t\t\t\t\t\t\t__________________MENU PRINCIPAL_________________"<<endl;
        cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
        cout<<endl<<"\t\t\t\t\t\t\t|\t\t1.- Usuario libre.\t\t|"<<endl;
        cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
        cout<<endl<<"\t\t\t\t\t\t\t|\t\t2.- Administrador.\t\t|"<<endl;
        cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
        cout<<endl<<"\t\t\t\t\t\t\t|\t\t0.- Salir.        \t\t|"<<endl;
        cout<<"\t\t\t\t\t\t\t|\t\t                  \t\t|";
        cout<<endl<<"\t\t\t\t\t\t\t|_______________________________________________|"<<endl;
        cout<<endl<<"\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";
        cin>>resp;

        system("cls");
        if(resp==1) {
            Menu_Usuario();
        } else if(resp==2) {
            //Menu_Administrador()
        }
    } while(resp!=0);
}


	 
void Menu_Usuario() {
    int resp;
    do {
        Logo();
        cout<<"\t\t\t\t\t\t__________________MENU PRINCIPAL_________________________"<<endl;
        cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
        cout<<endl<<"\t\t\t\t\t\t|\t\t1.- Registrarse.             \t\t|"<<endl;
        cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
        cout<<endl<<"\t\t\t\t\t\t|\t\t2.- Mostrar Inventario.      \t\t|"<<endl;
        cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
        cout<<endl<<"\t\t\t\t\t\t|\t\t3.- Prestarse un libro.      \t\t|"<<endl;
        cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
        cout<<endl<<"\t\t\t\t\t\t|\t\t0.- Volver al menu principal.\t\t|"<<endl;
        cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
        cout<<endl<<"\t\t\t\t\t\t|_______________________________________________________|"<<endl;
        cout<<endl<<"\t\t\t\t\t\t\t \tIngrese la respuesta: ";
        cin>>resp;
        system("cls");

        if(resp==1) {
            Registrar(registrar, cantidad_de_usuarios);
        }
        if(resp==2) {
            Menu_Mostrar();
			system("cls");
        }
        if(resp==3) {
            menuPrestamos(libros); 
        }
    } while(resp!=0);

    cout<<endl;
    system("PAUSE");
    cout<<endl;
    system("cls");
}


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


