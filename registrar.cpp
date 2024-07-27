#include "biblioteca.h"
#include "funciones.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//FUNCION DE REGISTRAR USUARIOS
void Registrar_usuario(Registro_usuario REG[],int &cant_usu){
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
//REGISTRAR ADMINISTRADORES
void Registrar_admin(Registro_Administrador REG[],int &cant_admin){
	Logo();
	cout<<"\t\t\t\t\t\t\t\t-----REGISTRARSE-----"<<endl;
	int i = cant_admin;//asignamos a i la cantidad de usuarios registrados hasta el momento
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
		cout<<"\t\t\t\t\t\t\t\tDNI: ";
		getline(cin, REG[i].DNI);
		fflush(stdin);
		i++;
		cant_admin++;


	cout<<endl;
	system("PAUSE");
	cout<<endl;

	system("cls");
}
//FUNCION DE MOSTRAR USUARIOS Y ADMINISTRADORES REGISTRADOS
void Mostrar_usuarios_administradores(Registro_Administrador RE[], Registro_usuario REU[]){
	Logo();
	cout<<"\t\t\t\t\t\t\tADMINISTRADORES REGISTRADOS:"<<endl;
	for(int i=0;i<cantidad_de_administradores;i++){
		cout<<"\t\t\t\t\t\t\t"<<i+1<<".- "<<RE[i].NOMBRE<<"  SEXO:"<<RE[i].SEXO<<"   EDAD:"<<RE[i].EDAD<<endl;
	}
	cout<<"\t\t\t\t\t\t\tUSUARIOS REGISTRADOS:"<<endl;
	for(int i=0;i<cantidad_de_usuarios;i++){
		cout<<"\t\t\t\t\t\t\t"<<i+1<<".- "<<REU[i].NOMBRE<<"  SEXO:"<<REU[i].SEXO<<"   EDAD:"<<REU[i].EDAD<<endl;
	}
	system("PAUSE");
	system("cls");
}
