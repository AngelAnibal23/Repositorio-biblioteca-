#include <string>
#include <cstdlib>
#include "valida.h"
#include "biblioteca.h"
#include "funciones.h"

using namespace std;

//FUNCION DE REGISTRAR USUARIOS
void Registrar_usuario(Registro_usuario REG[],int &cant_usu){
	Logo();
	cout<<"\t\t\t\t\t\t\t\t-----REGISTRARSE-----"<<endl;
	int i = cant_usu;//asignamos a i la cantidad de usuarios registrados hasta el momento
		fflush(stdin);
		cout<<"\t\t\t\t\t\t\t\tNOMBRES: ";
		getline(cin, REG[i].NOMBRE);
		solicitarEntradaNoVacia(REG,i);
		cout<<"\t\t\t\t\t\t\t\tAPELLIDO PATERNO: ";
		getline(cin, REG[i].APELLIDO_PAT);
		solicitarEntradaNoVaciaAP(REG,i );
		cout<<"\t\t\t\t\t\t\t\tAPELLIDO MATERNO: ";
		getline(cin, REG[i].APELLIDO_MAT);
		solicitarEntradaNoVaciaAM(REG, i );
		cout<<"\t\t\t\t\t\t\t\tSEXO(H/M): ";
		getline(cin, REG[i].SEXO);
		///validar_sexo(REG,i);
		cout<<" \t\t\t\t\t\t\t\tEDAD: ";
		getline(cin, REG[i].EDAD);
		//validar_edad(REG,i);
		cout<<"\t\t\t\t\t\t\t\tDNI: ";
		getline(cin, REG[i].DNI);
		//validar_dni(REG,i);
		cout<<"\t\t\t\t\t\t\t\tCODIGO UNIVERSITARIO: ";
		getline(cin, REG[i].CODIGO);
		//validar_codigo(REG,i);
		cout<<"\t\t\t\t\t\t\t\tTELEFONO: ";
		getline(cin, REG[i].TELEFONO);
		//validar_telefono(REG,i);
		cout<<"\t\t\t\t\t\t\t\tEMAIL: ";
		getline(cin, REG[i].EMAIL);
		//validar_email(REG,i);
		
		
		poner_mayuscula(REG,i);
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
		cout<<"\t\t\t\t\t\t\t\tNOMBRES: ";
		getline(cin, REG[i].NOMBRE);
		solicitarEntradaNoVacia(REG,i);
		cout<<"\t\t\t\t\t\t\t\tAPELLIDO PATERNO: ";
		getline(cin, REG[i].APELLIDO_PAT);
		solicitarEntradaNoVaciaAP(REG,i );
		cout<<"\t\t\t\t\t\t\t\tAPELLIDO MATERNO: ";
		getline(cin, REG[i].APELLIDO_MAT);
		solicitarEntradaNoVaciaAM(REG, i );
		cout<<"\t\t\t\t\t\t\t\tSEXO(H/M): ";
		getline(cin, REG[i].SEXO);
		validar_sexo(REG,i);
		cout<<" \t\t\t\t\t\t\t\tEDAD: ";
		getline(cin, REG[i].EDAD);
		validar_edad(REG,i);
		cout<<"\t\t\t\t\t\t\t\tTELEFONO: ";
		getline(cin, REG[i].TELEFONO);
		validar_telefono(REG,i);
		cout<<"\t\t\t\t\t\t\t\tEMAIL: ";
		getline(cin, REG[i].EMAIL);
		validar_email(REG,i);
		cout<<"\t\t\t\t\t\t\t\tDNI: ";
		getline(cin, REG[i].DNI);
		validar_dni(REG,i);
		poner_mayuscula(REG,i);
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
		cout<<"\t\t\t\t\t\t\t"<<i+1<<".- "<<RE[i].NOMBRE<<" "<<RE[i].APELLIDO_PAT<<" "<<RE[i].APELLIDO_MAT<<endl;
		cout<<"\t\t\t\t\t\t\t  SEXO:"<<RE[i].SEXO<<"   EDAD:"<<RE[i].EDAD<<endl;
	}
	cout<<"\t\t\t\t\t\t\tUSUARIOS REGISTRADOS:"<<endl;
	for(int i=0;i<cantidad_de_usuarios;i++){
		cout<<"\t\t\t\t\t\t\t"<<i+1<<".- "<<REU[i].NOMBRE<<" "<<REU[i].APELLIDO_PAT<<" "<<REU[i].APELLIDO_MAT<<endl;
		cout<<"\t\t\t\t\t\t\t  SEXO:"<<REU[i].SEXO<<"   EDAD:"<<REU[i].EDAD<<endl<<REU[i].prestamos[i].nombre_libro;//<<REU[i];
	}
	system("PAUSE");
	system("cls");
}
