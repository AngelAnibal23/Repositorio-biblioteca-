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
    // Funcion para validar el c�digo en el formato YYYY-NNNNNN.
    // Los primeros cuatro d�gitos deben estar entre 2000 y 2024, seguido de un guion y seis d�gitos.

    while(true) { // Bucle infinito que continúa hasta que se ingrese un código válido.

        int j = 0; // Índice para recorrer los caracteres del codigo.

        // Verificar que el primer caracter sea '2'.
        if (REG[i].CODIGO[j] == '2') {
            j++;
        }

        // Verificar que el segundo caracter sea '0'.
        if (REG[i].CODIGO[j] == '0') {
            j++;
        }

        // Verificar que el tercer caracter sea '0' o '1' o '2'.
        if (REG[i].CODIGO[j] == '0' || REG[i].CODIGO[j] == '1' || REG[i].CODIGO[j] == '2') {
            j++;
        }

        // Verificar que el cuarto caracter sea '0', '1', '2', '3', o '4'.
        if (REG[i].CODIGO[j] == '0' || REG[i].CODIGO[j] == '1' || REG[i].CODIGO[j] == '2' || REG[i].CODIGO[j] == '3' || REG[i].CODIGO[j] == '4') {
            j++;
        }

        // Verificar que el siguiente caracter sea un guion '-'.
        if (REG[i].CODIGO[j] == '-') {
            j++;
        }

        // Verificar que los siguientes seis caracteres sean digitos.
        for (int k = 0; k < 6; k++) {
            j++; // Incrementar el índice para cada digito.

        }

        // Si el indice j es menor que 10, el codigo no es valido.
        // Solicitar una nueva entrada.
        if (j < 10) {
            //fflush(stdin); // Limpiar el bufer de entrada 
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            getline(cin, REG[i].CODIGO);
        } else {
            break; // Salir del bucle si el codigo es valido.
        }
    }
}


template<typename T>
void validar_sexo(T REG[], int i) {
    // Función para validar la entrada del sexo. Debe ser 'H' para Hombre o 'M' para Mujer.

    int j = 0; // Índice para verificar el primer carácter del campo SEXO.

    while(true) { // Bucle infinito que continúa hasta que se ingrese una entrada válida.
        // Verifica si el carácter es 'H' o 'M'.
        if (REG[i].SEXO[j] == 'H' || REG[i].SEXO[j] == 'M') {
            break; // Sale del bucle si la entrada es válida.
        } else {
            // Si la entrada no es valida, solicita una nueva entrada.
            fflush(stdin); // Limpia el búfer de entrada
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            getline(cin, REG[i].SEXO); // Lee una nueva entrada 
        }
    }
}
template<typename T>
void validar_telefono(T REG[], int i) {
    // Función para validar que el numero de TELEFONO contenga exactamente 9 dígitos numéricos.
    int entrada;
	while(true){
	
    	if (REG[i].TELEFONO>100000000 && REG[i].TELEFONO<1000000000) {
            break; 
        } else {
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            valida(entrada);
            REG[i].TELEFONO=entrada;
			 // Lee una nueva entrada para el campo TELEFONO.
        }
    }
}

template<typename T>
void validar_email(T REG[], int i) {
    // Función para validar que el campo EMAIL contenga al menos un carácter '@'.

    int flag = 0; // Variable para indicar si se encontró un '@' en la cadena.

    while(true) { // Bucle infinito que continúa hasta que se ingrese un email válido.

        // Recorre la cadena en el campo EMAIL para buscar el carácter '@'.
        for (int j = 0; REG[i].EMAIL[j] != '\0'; j++) {
            if (REG[i].EMAIL[j] == '@') {
                flag = 1; // Establece el flag si se encuentra un '@'   
            } 
			if(REG[i].EMAIL[j] == '.'){
				flag=2;//establece 2 al flag si encuentra '.'
			}   
        }

        // Verifica si se encontró un '@' en la cadena.
        if (flag == 2) {
            break; // Sale del bucle si se encontró un '@'.
        } else {
            // Si no se encontró '@', solicita una nueva entrada.
            
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            getline(cin, REG[i].EMAIL); // Lee una nueva entrada para el campo EMAIL.
        }
    }
}

template<typename T>
void validar_dni(T REG[], int i) {
    // FunciOn para validar que el campo DNI contenga exactamente 8 dígitos.
	int entrada;
    while(true) { // Bucle infinito que continúa hasta que se ingrese un DNI válido.

        
        if (REG[i].DNI>10000000 && REG[i].DNI<100000000) {
            break; 
        } else {
            cout<<"\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            valida(entrada);
            REG[i].DNI=entrada;
			 // Lee una nueva entrada para el campo DNI.
        }
    }
}

template<typename T>
void validar_edad(T REG[], int i) {
    int entrada;
    while(true) { // hasta que se ingrese una edad valida.
		
        if (REG[i].EDAD>0 && REG[i].EDAD<150) {
            break; 
        } else {
            // Si la edad tiene más de 3 caracteres, solicita una nueva entrada.
            cout << "\t\t\t\t\t\t\t Error, Intente nuevamente: ";
            valida(entrada);
            REG[i].EDAD=entrada;
			
			
			 // Lee una nueva entrada para el campo EDAD.
        }
    }
}

template<typename T>
void poner_mayuscula(T REG[], int i) {
    // Función para convertir la primera letra de nombres y apellidos a mayúscula.

    int j = 0; // Variable para recorrer las cadenas de caracteres.

    // Convierte la primera letra del nombre a mayúscula.
    REG[i].NOMBRE[j] = toupper(REG[i].NOMBRE[j]);

    // Convierte la primera letra del apellido paterno a mayúscula.
    REG[i].APELLIDO_PAT[j] = toupper(REG[i].APELLIDO_PAT[j]);

    // Convierte la primera letra del apellido materno a mayúscula.
    REG[i].APELLIDO_MAT[j] = toupper(REG[i].APELLIDO_MAT[j]);

    // Recorre el nombre para convertir a mayúscula la primera letra de cada palabra.
    for (j = 0; REG[i].NOMBRE[j] != '\0'; j++) {
        // Si encuentra un espacio, convierte la letra siguiente a mayúscula.
        if (REG[i].NOMBRE[j] == ' ') {
            REG[i].NOMBRE[j + 1] = toupper(REG[i].NOMBRE[j + 1]);
        }
    }
}

template<typename T>
void solicitarEntradaNoVacia(T REG[], int i) {
    // Solicita al usuario que ingrese un nombre si el campo está vacío.
    do {
        // Si el campo NOMBRE está vacío, solicita al usuario que ingrese un nombre.
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
    // Solicita al usuario que ingrese un apellido paterno si el campo está vacío.
    do {
        // Si el campo APELLIDO_PAT está vacío, solicita al usuario que ingrese un apellido paterno.
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
    // Solicita al usuario que ingrese un apellido materno si el campo está vacío.
    do {
        // Si el campo APELLIDO_MAT está vacío, solicita al usuario que ingrese un apellido materno.
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
		cout<<"\t\t\t\t\t\t\tPARA MAS INFORMACION INGRESEEL NUMERO DE LISTA:";
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
