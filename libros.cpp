#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Imprime el logo de BIBLIOTECA
void Logo(){
	cout<<"  ----------------------------------------------------------------------------"<<endl;
    cout << "       0000    000   0000    0     000   00000   00000  00000   0000    000   " << endl;
    cout << "      0   0    0    0   0   0      0   0     0    0    0      0       0   0   "<< endl;
    cout << "     0000     0    0000    0      0   0     0    0    000    0       00000     " << endl;
    cout << "    0   0    0    0   0   0      0   0     0    0    0      0       0   0       " << endl;
    cout << "   0000    000   0000    0000  000   00000     0    00000   0000   0   0    " << endl;
	cout<<"  ----------------------------------------------------------------------------"<<endl;
}

struct comunicacion{
	string Autor1;
	int Anio1;
	int paginas1;
	string Nombre1;
};
struct matematica{
	string Autor2;
	int Anio2;
	int paginas2;
	string Nombre2;
};
struct programacion{
	string Autor3;
	int Anio3;
	int paginas3;
	string Nombre3;
};
struct quimica{
	string Autor4;
	int Anio4;
	int paginas4;
	string Nombre4;
};
struct historia{
	string Autor5;
	int Anio5;
	int paginas5;
	string Nombre5;
};

//INGRESA AL MENU DE USUARIO
void Menu_Usuario(){
	
	int resp;
	do{
		//MENU
		Logo();
		cout<<"    MENU DE USUARIO:" <<endl<<endl;
		cout<<"    1.- Registrarse."<<endl<<"    2.- Mostrar Inventario. "<<endl<<"    3.- Prestar un libro."<<endl<<"    0.- Volver al menu principal";
		cout<<endl<<endl<<"    Ingrese su respuesta: ";cin>>resp;
		system("cls");
		if(resp==1){
		//	Registrar(registrar,cantidad_de_usarios);
		}
		if(resp==2){
			
		}
		if(resp==3){
			
		}
		
	}while(resp!=0);
	
	
	cout<<endl;
	system("PAUSE");
	cout<<endl;
	system("cls");
}

//PRINCIPAL
int main() {
	int resp;
	system("color f0");
	int numcatego;
	int TAM1=10, TAM2=10, TAM3=10, TAM4=10, TAM5=10;
	comunicacion comu [10] = {
		{"Carlos Fernandez",2016,450,"Teoria y Práctica de la Comunicacion"},
		{"Ana Martinez",2019,380,"Comunicacion Interpersonal en el Ambito Academico"},
		{"Jorge Ramirez",2021,410,"Comunicación Digital para Estudiantes Universitarios"}
	};
	matematica mate [10] = {
		{"Erwin Kreyszig",2007,1272,"Matematicas avanzadas para ingenieros"},
		{"Granville, Smith y Longley",2012,960,"Calculo diferencial e integral"},
		{"Serge Lang",1996,480,"Algebra Lineal"}
	};
	programacion progr [10] = {
		{"Luis Torres",2018,520,"Introduccion a la Programacion con Python"},
		{"Marta Sanchez",2017,480,"Programacion en Java para Universitarios"},
		{"Jose Hernandez",2020,550,"Fundamentos de Programación en C++"}
	};
	quimica quimi [10] = {
		{"Ricardo Morales",2016,700,"Quimica General: Principios y Aplicaciones Modernas"},
		{"Ana Fernandez",2018,640,"Quimica Organica: Teoria y Practica"},
		{"Javier Gomez",2019,580,"Quimica Inorganica para Estudiantes Universitarios"}
	};
	historia hist [10] = {
		{"Laura Rodriguez",2015,720,"Historia Contemporanea: Desde la Revolución Francesa hasta la Globalizacion"},
		{"Miguel Alvarez",2017,650,"Historia de America Latina: Colonizacion y Desarrollo"},
		{"Carmen Sanchez",2020,600,"Historia de España: Desde los Visigodos hasta la Democracia"}
	};
	
	int numero;
	do{
		
		Logo();
		cout<<"   MENU PRINCIPAL"<<endl<<endl;
		cout<<"    1.- Usuario libre. "<<endl<<"    2.- Administrador. "<<endl<<"    0.- Salir."<<endl<<endl;
		cout<<"    Ingrese la respuesta: ";
		cin>>resp;
	
		system("cls");
		if(resp==1){
		cout<<"ESCRIBE EL NUMERO DE LA CATEGORIA"<<endl<<"1. Comunicacion     2.-matematica     3.-programacion     4.-quimica     5.-historia"<<endl;
	cin>>numcatego;
	int resp;	
			Menu_Usuario();
			
		}else if(resp==2){
			//Menu_Administrador();
		}
	}while(resp!=0);
	
    return 0;
}
