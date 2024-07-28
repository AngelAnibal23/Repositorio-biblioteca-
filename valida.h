#ifndef VALIDA_H
#define VALIDA_H
#include "biblioteca.h"
#include "funciones.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
template<typename T>
void validar_codigo(T REG[], int i){//RECONOCE EL GUION DESPUES DE 4 DIGITOS,SI SE PONE UN LOS PRIMEROS 4 DIGITOS MENOR IGUAL 2024 Y MAYOR A 2000
	
	while(true){
	
	int j=0;
	if(REG[i].CODIGO[j] == '2'){
		j++;
	}
	if(REG[i].CODIGO[j] == '0'){
	
		j++;
	}
	if(REG[i].CODIGO[j] == '0'||REG[i].CODIGO[j] == '1'||REG[i].CODIGO[j] == '2'){
		j++;
	}
	if(REG[i].CODIGO[j] == '0'||REG[i].CODIGO[j] == '1'||REG[i].CODIGO[j] == '2'||REG[i].CODIGO[j] == '3'||REG[i].CODIGO[j] == '4'){
		j++;
	}
	if(REG[i].CODIGO[j] == '-'){
		j++;
	}
	for(int k=0;k<6;k++){
		j++;
	}
	if(j<10){
		fflush(stdin);
		cout<<"\t\t\t\t\t\t\t Error, Intente nuevamente: ";
		getline(cin, REG[i].CODIGO);	
	}else{
		break ;
	}
	
	}
}
template<typename T>
void validar_sexo(T REG[], int i){// VERIFICA SI ES H= HOMBRE Y M=MUJER
	int j=0;
	while(true){
		if( REG[i].SEXO[j]=='H'|| REG[i].SEXO[j]=='M'){
			break ;
		}else{
			fflush(stdin);
			cout<<"\t\t\t\t\t\t\t Error, Intente nuevamente: ";
			getline(cin, REG[i].SEXO);
		}
	}
}
template<typename T>
void validar_telefono(T REG[], int i){//VERIFICA SI HAY NUEVE NUMEROS
	int j;
	while(true){
	
	for(j=0;REG[i].TELEFONO[j]!='\0';j++){	
	}
	if(j==9){
		break;
	}else{
		fflush(stdin);
			cout<<"\t\t\t\t\t\t\t Error, Intente nuevamente: ";
			getline(cin, REG[i].TELEFONO);
	}
	}
}
template<typename T>
void validar_email(T REG[], int i){//RECONOSE LA EXISTENCIA DE UN @ EN LA CADENA
	int flag=0;
	while(true){
	
		for(int j=0;REG[i].EMAIL[j]!='\0';j++){
				if(REG[i].EMAIL[j]=='@'){
				flag=1;
				cout<<"yess";
				
			}	
		}
		if(flag==1){
			break ;
		}else{
			fflush(stdin);
			cout<<"\t\t\t\t\t\t\t Error, Intente nuevamente: ";
			getline(cin, REG[i].EMAIL);
		}
	}
}
template<typename T>
void validar_dni(T REG[], int i){//RECONOCE SI HAY 8 NUMEROS
	int j;
	while(true){
	
	for(j=0;REG[i].DNI[j]!='\0';j++){	
	}
	if(j==8){
		break;
	}else{
		fflush(stdin);
			cout<<"\t\t\t\t\t\t\t Error, Intente nuevamente: ";
			getline(cin, REG[i].DNI);
	}
	}
}
template<typename T>
void validar_edad(T REG[], int i){//RECONOCE SI HAY MAXIMO 3 DIGITOS
	int j;
	while(true){
	
	for(j=0;REG[i].EDAD[j]!='\0';j++){	
	}
	if(j<=3){
		break;
	}else{
		fflush(stdin);
			cout<<"\t\t\t\t\t\t\t Error, Intente nuevamente: ";
			getline(cin, REG[i].EDAD);
	}
	}
}
template<typename T>
void poner_mayuscula(T REG[], int i){//COLOCA MAYUSCULA A LAS LETRAS INICIALES DE NOMBRES Y APELLIDOS
	int j=0;
	REG[i].NOMBRE[j]=toupper(REG[i].NOMBRE[j]);
	REG[i].APELLIDO_PAT[j]=toupper(REG[i].APELLIDO_PAT[j]);
	REG[i].APELLIDO_MAT[j]=toupper(REG[i].APELLIDO_MAT[j]);
	for(j=0;REG[i].NOMBRE[j]!='\0';j++){
		if(REG[i].NOMBRE[j]==' '){
			REG[i].NOMBRE[j+1]=toupper(REG[i].NOMBRE[j+1]);
		}
	}
	
}
template<typename T>
void solicitarEntradaNoVacia(T REG[],int i ) {
    
    do {
        if (REG[i].NOMBRE.empty()) {
            cout << "\t\t\t\t\t\t\tIngrese un nombre:" ; 
            getline(cin, REG[i].NOMBRE );
        }else{
        	break;
		}
    } while(true) ;
    
}
template<typename T>
void solicitarEntradaNoVaciaAP(T REG[],int i ) {
    
    do {
        if (REG[i].APELLIDO_PAT.empty()) {
            cout << "\t\t\t\t\t\t\tIngrese su apellido:" ;
            getline(cin, REG[i].APELLIDO_PAT );
        }else{
        	break;
		}
    } while(true) ;
    
}
template<typename T>
void solicitarEntradaNoVaciaAM(T REG[],int i ) {
    
    do {
        if (REG[i].APELLIDO_MAT.empty()) {
            cout << "\t\t\t\t\t\t\tIngrese su apellido:" ;
            getline(cin, REG[i].APELLIDO_MAT );
        }else{
        	break;
		}
    } while(true) ;
    
}

//FUNCION DE REGISTRAR USUARIOS


#endif
