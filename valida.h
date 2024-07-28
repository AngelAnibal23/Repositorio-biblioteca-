#ifndef VALIDA_H
#define VALIDA_H
#include "biblioteca.h"
#include "funciones.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template<typename T>
void validar_codigo(T REG[], int i) {
    // Funci�n para validar el c�digo en el formato YYYY-NNNNNN.
    // Los primeros cuatro d�gitos deben estar entre 2000 y 2024, seguido de un guion y seis d�gitos.

    while(true) { // Bucle infinito que contin�a hasta que se ingrese un c�digo v�lido.

        int j = 0; // �ndice para recorrer los caracteres del c�digo.

        // Verificar que el primer car�cter sea '2'.
        if (REG[i].CODIGO[j] == '2') {
            j++;
        }

        // Verificar que el segundo car�cter sea '0'.
        if (REG[i].CODIGO[j] == '0') {
            j++;
        }

        // Verificar que el tercer car�cter sea '0' o '1' o '2'.
        if (REG[i].CODIGO[j] == '0' || REG[i].CODIGO[j] == '1' || REG[i].CODIGO[j] == '2') {
            j++;
        }

        // Verificar que el cuarto car�cter sea '0', '1', '2', '3', o '4'.
        if (REG[i].CODIGO[j] == '0' || REG[i].CODIGO[j] == '1' || REG[i].CODIGO[j] == '2' || REG[i].CODIGO[j] == '3' || REG[i].CODIGO[j] == '4') {
            j++;
        }

        // Verificar que el siguiente car�cter sea un guion '-'.
        if (REG[i].CODIGO[j] == '-') {
            j++;
        }

        // Verificar que los siguientes seis caracteres sean d�gitos.
        for (int k = 0; k < 6; k++) {
            j++; // Incrementar el �ndice para cada d�gito.
        }

        // Si el �ndice j es menor que 10, el c�digo no es v�lido.
        // Solicitar una nueva entrada.
        if (j < 10) {
            fflush(stdin); // Limpiar el b�fer de entrada 
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            getline(cin, REG[i].CODIGO);
        } else {
            break; // Salir del bucle si el c�digo es v�lido.
        }
    }
}
        

template<typename T>
void validar_sexo(T REG[], int i) {
    // Funci�n para validar la entrada del sexo. Debe ser 'H' para Hombre o 'M' para Mujer.

    int j = 0; // �ndice para verificar el primer car�cter del campo SEXO.

    while(true) { // Bucle infinito que contin�a hasta que se ingrese una entrada v�lida.
        // Verifica si el car�cter es 'H' o 'M'.
        if (REG[i].SEXO[j] == 'H' || REG[i].SEXO[j] == 'M') {
            break; // Sale del bucle si la entrada es v�lida.
        } else {
            // Si la entrada no es valida, solicita una nueva entrada.
            fflush(stdin); // Limpia el b�fer de entrada
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            getline(cin, REG[i].SEXO); // Lee una nueva entrada 
        }
    }
}
template<typename T>
void validar_telefono(T REG[], int i) {
    // Funci�n para validar que el numero de TELEFONO contenga exactamente 9 d�gitos num�ricos.

    int j; // �ndice para contar la longitud del numero de tel�fono.

    while(true) { // Bucle infinito que contin�a hasta que se ingrese un numero de tel�fono v�lido.
        
        // Contar el numero de caracteres en el campo TELEFONO.
        for (j = 0; REG[i].TELEFONO[j] != '\0'; j++) {
            // El bucle se ejecuta mientras no se alcance el car�cter nulo de fin de cadena.
        }

        // Verificar si el n�mero de caracteres es igual a 9.
        if (j == 9) {
            break; // Sale del bucle si la longitud es exactamente 9.
        } else {
            // Si la longitud no es 9, solicita una nueva entrada.
            fflush(stdin); // Limpia el bufer de entrada 
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            getline(cin, REG[i].TELEFONO); // Lee una nueva entrada para el campo TELEFONO.
        }
    }
}

template<typename T>
void validar_email(T REG[], int i) {
    // Funci�n para validar que el campo EMAIL contenga al menos un car�cter '@'.

    int flag = 0; // Variable para indicar si se encontr� un '@' en la cadena.

    while(true) { // Bucle infinito que contin�a hasta que se ingrese un email v�lido.

        // Recorre la cadena en el campo EMAIL para buscar el car�cter '@'.
        for (int j = 0; REG[i].EMAIL[j] != '\0'; j++) {
            if (REG[i].EMAIL[j] == '@') {
                flag = 1; // Establece el flag si se encuentra un '@'.
                
            }    
        }

        // Verifica si se encontr� un '@' en la cadena.
        if (flag == 1) {
            break; // Sale del bucle si se encontr� un '@'.
        } else {
            // Si no se encontr� '@', solicita una nueva entrada.
            fflush(stdin); // Limpia el b�fer de entrada 
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            getline(cin, REG[i].EMAIL); // Lee una nueva entrada para el campo EMAIL.
        }
    }
}

template<typename T>
void validar_dni(T REG[], int i) {
    // Funci�n para validar que el campo DNI contenga exactamente 8 d�gitos.

    int j; // Variable para contar el n�mero de caracteres en DNI.

    while(true) { // Bucle infinito que contin�a hasta que se ingrese un DNI v�lido.

        // Recorre la cadena en el campo DNI para contar el n�mero de caracteres.
        for (j = 0; REG[i].DNI[j] != '\0'; j++) {    
        }

        // Verifica si el n�mero de caracteres en DNI es exactamente 8.
        if (j == 8) {
            break; // Sale del bucle si el DNI tiene exactamente 8 caracteres.
        } else {
            // Si el DNI no tiene exactamente 8 caracteres, solicita una nueva entrada.
            fflush(stdin); // Limpia el b�fer de entrada 
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            getline(cin, REG[i].DNI); // Lee una nueva entrada para el campo DNI.
        }
    }
}

template<typename T>
void validar_edad(T REG[], int i) {
    // Funci�n para validar que el campo EDAD contenga un m�ximo de 3 d�gitos.

    int j; // Variable para contar el n�mero de caracteres en EDAD.

    while(true) { // Bucle infinito que contin�a hasta que se ingrese una edad v�lida.

        // Recorre la cadena en el campo EDAD para contar el n�mero de caracteres.
        for (j = 0; REG[i].EDAD[j] != '\0'; j++) {    
        }

        // Verifica si el n�mero de caracteres en EDAD es de 3 o menos.
        if (j <= 3) {
            break; // Sale del bucle si la edad tiene 3 o menos caracteres.
        } else {
            // Si la edad tiene m�s de 3 caracteres, solicita una nueva entrada.
            fflush(stdin); // Limpia el b�fer de entrada 
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            getline(cin, REG[i].EDAD); // Lee una nueva entrada para el campo EDAD.
        }
    }
}

template<typename T>
void poner_mayuscula(T REG[], int i) {
    // Funci�n para convertir la primera letra de nombres y apellidos a may�scula.

    int j = 0; // Variable para recorrer las cadenas de caracteres.

    // Convierte la primera letra del nombre a may�scula.
    REG[i].NOMBRE[j] = toupper(REG[i].NOMBRE[j]);

    // Convierte la primera letra del apellido paterno a may�scula.
    REG[i].APELLIDO_PAT[j] = toupper(REG[i].APELLIDO_PAT[j]);

    // Convierte la primera letra del apellido materno a may�scula.
    REG[i].APELLIDO_MAT[j] = toupper(REG[i].APELLIDO_MAT[j]);

    // Recorre el nombre para convertir a may�scula la primera letra de cada palabra.
    for (j = 0; REG[i].NOMBRE[j] != '\0'; j++) {
        // Si encuentra un espacio, convierte la letra siguiente a may�scula.
        if (REG[i].NOMBRE[j] == ' ') {
            REG[i].NOMBRE[j + 1] = toupper(REG[i].NOMBRE[j + 1]);
        }
    }
}

template<typename T>
void solicitarEntradaNoVacia(T REG[], int i) {
    // Solicita al usuario que ingrese un nombre si el campo est� vac�o.
    do {
        // Si el campo NOMBRE est� vac�o, solicita al usuario que ingrese un nombre.
        if (REG[i].NOMBRE.empty()) {
            cout << "\t\t\t\t\t\t\tIngrese un nombre:"; 
            getline(cin, REG[i].NOMBRE);
        } else {
            // Si el campo ya tiene un valor, sale del bucle.
            break;
        }
    } while(true);
}

template<typename T>
void solicitarEntradaNoVaciaAP(T REG[], int i) {
    // Solicita al usuario que ingrese un apellido paterno si el campo est� vac�o.
    do {
        // Si el campo APELLIDO_PAT est� vac�o, solicita al usuario que ingrese un apellido paterno.
        if (REG[i].APELLIDO_PAT.empty()) {
            cout << "\t\t\t\t\t\t\tIngrese su apellido paterno:"; 
            getline(cin, REG[i].APELLIDO_PAT);
        } else {
            // Si el campo ya tiene un valor, sale del bucle.
            break;
        }
    } while(true);
}

template<typename T>
void solicitarEntradaNoVaciaAM(T REG[], int i) {
    // Solicita al usuario que ingrese un apellido materno si el campo est� vac�o.
    do {
        // Si el campo APELLIDO_MAT est� vac�o, solicita al usuario que ingrese un apellido materno.
        if (REG[i].APELLIDO_MAT.empty()) {
            cout << "\t\t\t\t\t\t\tIngrese su apellido materno:"; 
            getline(cin, REG[i].APELLIDO_MAT);
        } else {
            // Si el campo ya tiene un valor, sale del bucle.
            break;
        }
    } while(true);
}
template<typename T>
void mostrar_orden_gmail(T RE[],int cnt_cont){
	
	if(cnt_cont==0){
		cout<<endl<<"\t\t\t\t\t\t\tVacio."<<endl;
	}
	int i,j,m,l,k,n;
	for(i=0;i<cnt_cont-1;i++){
		for(j=0;RE[i].EMAIL[j]!='@';j++){
				
			}
		for(l=i+1;l<cnt_cont;l++){
		
			for(k=0;RE[l].EMAIL[k]!='@';k++){
				
			}
			
			if(RE[i].EMAIL[j+1]>RE[l].EMAIL[k+1]){
				string aux;
				aux=RE[i].EMAIL;
				RE[i].EMAIL=RE[l].EMAIL;
				RE[l].EMAIL=aux;
			
				
				
			}
		}
	}
		
	
	for(m=0; m<cnt_cont;m++ ){
	cout<<"\t\t\t\t\t\t\tEmail "<<m+1<<": "<<RE[m].EMAIL<<endl;
	}
	
	cout<<endl;
	system("PAUSE");
	
}
template<typename T>
void mostra_general(T CE[],int cnt_cont){
	
	cout<<"\t\t\t\t\t\t\t-------LISTA GENERAL-----"<<endl;
	int num_cont;
	
	for(int i=0; i<cnt_cont;i++ ){
		
	cout<<"\t\t\t\t\t\t\tPERSONA "<<i+1<<": "<<CE[i].NOMBRE<<endl;
	}
	if(cnt_cont==0){
		cout<<"\t\t\t\t\t\t\tLista vacia.";
	}else{
		cout<<"\t\t\t\t\t\t\tPARA MAS INFORMACION INGRESE EL NUMERO DE LISTA:";
		cin>>num_cont;
		int i=0;
	while(true){
		if(i==num_cont){
			cout<<"\t\t\t\t\t\t\t-----DATOS------"<<endl;
			cout<<"\t\t\t\t\t\t\tNombre: "<<CE[i-1].NOMBRE<<" "<<CE[i-1].APELLIDO_PAT<<" "<<CE[i-1].APELLIDO_MAT<<endl;
			cout<<"\t\t\t\t\t\t\tSexo: "<<CE[i-1].SEXO<<endl;
			cout<<"\t\t\t\t\t\t\tEdad: "<<CE[i-1].EDAD<<endl;
			cout<<"\t\t\t\t\t\t\tTelefono: "<<CE[i-1].TELEFONO<<endl;
			cout<<"\t\t\t\t\t\t\tEmail: "<<CE[i-1].EMAIL<<endl;
			cout<<"\t\t\t\t\t\t\tDni: "<<CE[i-1].DNI<<endl;
			
			break ;
		}
		i++;
	}
	}
	
	
	cout<<endl;
	system("PAUSE");
	
}

#endif
