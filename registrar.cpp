#include <string>
#include <cstdlib>
#include "valida.h"
#include "biblioteca.h"
#include "funciones.h"

using namespace std;

//FUNCION DE REGISTRAR USUARIOS
void Registrar_usuario(Registro_usuario REG[], int &cant_usu) {
    Logo(); // Muestra el logotipo

    cout << "\t\t\t\t\t\t\t\t-----REGISTRARSE-----" << endl;

    int i = cant_usu; // Asigna a 'i' la cantidad actual de usuarios registrados
    fflush(stdin); // Limpia el buffer de entrada para evitar problemas con getline

    // Solicita y valida los datos del usuario
    cout << "\t\t\t\t\t\t\t\tNOMBRES: ";
    getline(cin, REG[i].NOMBRE);
    solicitarEntradaNoVacia(REG, i);

    cout << "\t\t\t\t\t\t\t\tAPELLIDO PATERNO: ";
    getline(cin, REG[i].APELLIDO_PAT);
    solicitarEntradaNoVaciaAP(REG, i);

    cout << "\t\t\t\t\t\t\t\tAPELLIDO MATERNO: ";
    getline(cin, REG[i].APELLIDO_MAT);
    solicitarEntradaNoVaciaAM(REG, i);

    cout << "\t\t\t\t\t\t\t\tSEXO(H/M): ";
    getline(cin, REG[i].SEXO);
    validar_sexo(REG, i);

    cout << " \t\t\t\t\t\t\t\tEDAD: ";
    getline(cin, REG[i].EDAD);
    validar_edad(REG, i);

    cout << "\t\t\t\t\t\t\t\tDNI: ";
    getline(cin, REG[i].DNI);
    validar_dni(REG, i);

    cout << "\t\t\t\t\t\t\t\tCODIGO UNIVERSITARIO: ";
    getline(cin, REG[i].CODIGO);
    validar_codigo(REG, i);

    cout << "\t\t\t\t\t\t\t\tTELEFONO: ";
    getline(cin, REG[i].TELEFONO);
    validar_telefono(REG, i);

    cout << "\t\t\t\t\t\t\t\tEMAIL: ";
    getline(cin, REG[i].EMAIL);
    validar_email(REG, i);

    poner_mayuscula(REG, i); // Convierte el inicio de nombre y apellido  a mayusculas

    
    cant_usu++; // Incrementa la cantidad de usuarios registrados

    cout << endl;
    system("PAUSE"); // Pausa el sistema
    cout << endl;

    system("cls"); // Limpia la pantalla para volver al menú
}


//REGISTRAR ADMINISTRADORES

void Registrar_admin(Registro_Administrador REG[], int &cant_admin) {
    Logo(); // Muestra el logotipo

    cout << "\t\t\t\t\t\t\t\t-----REGISTRARSE-----" << endl;

    int i = cant_admin; // Asigna a 'i' la cantidad actual de administradores registrados
    fflush(stdin); // Limpia el buffer de entrada para evitar problemas con getline

    // Solicita y valida los datos del administrador
    cout << "\t\t\t\t\t\t\t\tNOMBRES: ";
    getline(cin, REG[i].NOMBRE);
    solicitarEntradaNoVacia(REG, i);

    cout << "\t\t\t\t\t\t\t\tAPELLIDO PATERNO: ";
    getline(cin, REG[i].APELLIDO_PAT);
    solicitarEntradaNoVaciaAP(REG, i);

    cout << "\t\t\t\t\t\t\t\tAPELLIDO MATERNO: ";
    getline(cin, REG[i].APELLIDO_MAT);
    solicitarEntradaNoVaciaAM(REG, i);

    cout << "\t\t\t\t\t\t\t\tSEXO(H/M): ";
    getline(cin, REG[i].SEXO);
    validar_sexo(REG, i);

    cout << " \t\t\t\t\t\t\t\tEDAD: ";
    getline(cin, REG[i].EDAD);
    validar_edad(REG, i);

    cout << "\t\t\t\t\t\t\t\tTELEFONO: ";
    getline(cin, REG[i].TELEFONO);
    validar_telefono(REG, i);

    cout << "\t\t\t\t\t\t\t\tEMAIL: ";
    getline(cin, REG[i].EMAIL);
    validar_email(REG, i);

    cout << "\t\t\t\t\t\t\t\tDNI: ";
    getline(cin, REG[i].DNI);
    validar_dni(REG, i);

    poner_mayuscula(REG, i); // Convierte los datos a mayusculas para uniformidad

    
    cant_admin++; // Incrementa la cantidad de administradores registrados

    cout << endl;
    system("PAUSE"); // Pausa el sistema para que el usuario lea la información
    cout << endl;

    system("cls"); // Limpia la pantalla para volver al menú
}
void Mostrar_registros(Registro_Administrador RE[], Registro_usuario REU[],int cantidad_de_administradores,int cantidad_de_usuarios){
	int resp;
	do{

	Logo();
		cout<<"\t\t\t\t\t\t_______________________MOSTRAR DATOS_____________________"<<endl;
		cout<<"\t\t\t\t\t\t|\t\t                              \t\t|"; 
		cout<<endl<<"\t\t\t\t\t\t|\t1.- Mostrar usuarios ordenados por email.      \t|"<<endl;
		cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
		cout<<endl<<"\t\t\t\t\t\t|\t2.- Mostrar listado general de usuarios.       \t|"<<endl;
		cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
		cout<<endl<<"\t\t\t\t\t\t|\t3.- Mostrar listado general de Administradores \t|"<<endl;
		cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
		cout<<endl<<"\t\t\t\t\t\t|\t0.- Salir.                                     \t|"<<endl;
		cout<<"\t\t\t\t\t\t|\t\t                              \t\t|";
		cout<<endl<<"\t\t\t\t\t\t|_______________________________________________________|"<<endl;;
		cout<<endl<<"\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";
		valida(resp);
		system("cls");
		if(resp==1){
			Logo();
			cout<<"\t\t\t\t\t\t\tUSUARIOS: "<<endl;
			mostrar_orden_gmail(REU,cantidad_de_usuarios );
			cout<<"\t\t\t\t\t\t\tADMINISTRADORES: "<<endl;
			mostrar_orden_gmail(RE,cantidad_de_administradores );
			system("cls");
		}else if(resp==2){
			Logo();
			cout<<"\t\t\t\t\t\t\tUSUARIOS: "<<endl;
			mostra_general(REU,cantidad_de_usuarios );
			system("cls");
		}else if(resp==3){
			Logo();
			cout<<"\t\t\t\t\t\t\tADMINISTRADORES: "<<endl;
			mostra_general(RE,cantidad_de_administradores);
			system("cls");
		}
	
	}while(resp!=0);
	system("cls");
}
//FUNCION DE MOSTRAR USUARIOS Y ADMINISTRADORES REGISTRADOS
void Mostrar_usuarios_administradores(Registro_Administrador RE[], Registro_usuario REU[]) {
    Logo(); // Muestra el logotipo

    // Muestra los administradores registrados
    cout << "\t\t\t\t\t\t\tADMINISTRADORES REGISTRADOS:" << endl;
    if (cantidad_de_administradores == 0) {
        cout << endl << "\t\t\t\t\t\t\tLista vacia" << endl; // Mensaje si no hay administradores registrados
    } else {
        cout << endl;
        for (int i = 0; i < cantidad_de_administradores; i++) {
            cout << "\t\t\t\t\t\t\t" << i + 1 << ".- " << RE[i].NOMBRE << " " << RE[i].APELLIDO_PAT << " " << RE[i].APELLIDO_MAT << endl;
            cout << "\t\t\t\t\t\t\t  SEXO:" << RE[i].SEXO << "   EDAD:" << RE[i].EDAD << endl;
        }
    }

    // Muestra los usuarios registrados
    cout << "\t\t\t\t\t\t\tUSUARIOS REGISTRADOS:" << endl;
    if (cantidad_de_usuarios == 0) {
        cout << endl << "\t\t\t\t\t\t\tLista vacia" << endl; // Mensaje si no hay usuarios registrados
    } else {
        cout << endl;
        for (int i = 0; i < cantidad_de_usuarios; i++) {
            cout << "\t\t\t\t\t\t\t" << i + 1 << ".- " << REU[i].NOMBRE << " " << REU[i].APELLIDO_PAT << " " << REU[i].APELLIDO_MAT << endl;
            cout << "\t\t\t\t\t\t\t  SEXO:" << REU[i].SEXO << "   EDAD:" << REU[i].EDAD << endl;
        }
    }

    system("PAUSE"); // Pausa el sistema para que el usuario lea la informacion
    system("cls"); // Limpia la pantalla para volver al menu
}



