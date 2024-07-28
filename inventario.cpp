#include <iostream>
#include <cstdlib>
#include "biblioteca.h"
#include "funciones.h"
#include <string>
#include <ctime>
#include <string>

comunicacion comu [10] = {   //muestra los datos ya almacenados de comunicacion
    {"Carlos Fernandez", 2016, 450, "Teoria y Practica de la Comunicacion", 101,2},
	{"Ana Martinez", 2019, 380, "Comunicacion Interpersonal en el Ambito Academico", 102,1},
    {"Jorge Ramirez", 2021, 410, "Comunicacion Digital para Estudiantes Universitarios", 103,2}
};
matematica mate [10] = {   //muestra los datos ya almacenados de matematica
	{"Erwin Kreyszig",2007,1272,"Matematicas avanzadas para ingenieros", 104,3},
	{"Granville, Smith y Longley",2012,960,"Calculo diferencial e integral", 105,2},
	{"Serge Lang",1996,480,"Algebra Lineal", 106,2}
};
programacion progr [10] = {   //muestra los datos ya almacenados de programacion
	{"Luis Torres",2018,520,"Introduccion a la Programacion con Python", 107,1},
	{"Marta Sanchez",2017,480,"Programacion en Java para Universitarios", 108,2},
	{"Jose Hernandez",2020,550,"Fundamentos de Programacion en C++", 109,3}
};
quimica quimi [10] = {   //muestra los datos ya almacenados de quimica
	{"Ricardo Morales",2016,700,"Quimica General: Principios y Aplicaciones Modernas", 110,1},
	{"Ana Fernandez",2018,640,"Quimica Organica: Teoria y Practica",111,2},
	{"Javier Gomez",2019,580,"Quimica Inorganica para Estudiantes Universitarios",112,1}
};
historia hist [10] = {   //muestra los datos ya almacenados de historia
	{"Laura Rodriguez",2015,720,"Historia Contemporanea: Desde la Revolucion Francesa hasta la Globalizacion",113,2},
	{"Miguel Alvarez",2017,650,"Historia de America Latina: Colonizacion y Desarrollo",114,1},
	{"Carmen Sanchez",2020,600,"Historia de Espania: Desde los Visigodos hasta la Democracia",115,1}
};


void mostrar(int numcateg){
	Logo();
	if(numcateg == 1) {   //muestra al usuario los datos del libro de comunicacion
    	for(int a = 0; a < 10; a++) {
        	if(comu[a].cantidad1 > 0) {
         	   cout << "\t\t\t\t\tL" << a + 1 << "    ID: " << comu[a].ID1 << "   NOMBRE: " << comu[a].Nombre1 << endl << "\t\t\t\t\t\t\t         AUTOR: " ;
          	  cout << comu[a].Autor1 <<"   "<<  comu[a].Anio1 << "   PAG: " << comu[a].paginas1<< endl << "\t\t\t\t\t\t\t         CANT: " << comu[a].cantidad1 << endl;              
     	    }
   		}
	} else if(numcateg == 2) {   //muestra al usuario los datos del libro de matematica
    	for(int a = 0; a < 10; a++) {
       	 if(mate[a].cantidad2 > 0) {
          	  cout << "\t\t\t\t\tL" << a + 1 << "    ID: " << mate[a].ID2 << "   NOMBRE: " << mate[a].Nombre2 << endl << "\t\t\t\t\t\t\t         AUTOR: ";
          	  cout << mate[a].Autor2 <<"   "<<  mate[a].Anio2 << "   PAG: " << mate[a].paginas2<<  endl<< "\t\t\t\t\t\t\t         CANT: " << mate[a].cantidad2 << endl;         
       		 }
    	}
	} else if(numcateg == 3) {   //muestra al usuario los datos del libro de programacion
   	 	for(int a = 0; a < 10; a++) {
        	if(progr[a].cantidad3 > 0) {
            	cout << "\t\t\t\t\tL" << a + 1  << "    ID: " << progr[a].ID3  << "   NOMBRE: " << progr[a].Nombre3 << endl << "\t\t\t\t\t\t\t         AUTOR: ";
				cout << progr[a].Autor3 <<"   "<< progr[a].Anio3<< "   PAG: " << progr[a].paginas3<< endl << "\t\t\t\t\t\t\t         CANT: " << progr[a].cantidad3 << endl;           
      		  }
    	}
	} else if(numcateg == 4) {   //muestra al usuario los datos del libro de quimica
    	for(int a = 0; a < 10; a++) {
        	if(quimi[a].cantidad4 > 0) {
          	  	cout << "\t\t\t\t\tL" << a + 1  << "    ID: " << quimi[a].ID4 << "   NOMBRE: " << quimi[a].Nombre4 << endl << "\t\t\t\t\t\t\t         AUTOR: ";
            	cout << quimi[a].Autor4 <<"   "<<  quimi[a].Anio4    << "   PAG: " << quimi[a].paginas4 << endl << "\t\t\t\t\t\t\t         CANT: " << quimi[a].cantidad4 << endl;        
        	}
    	}
	} else if(numcateg == 5) {   //muestra al usuario los datos del libro de historia
    	for(int a = 0; a < 10; a++) {
        	if(hist[a].cantidad5 > 0) {
            	cout << "\t\t\t\t\tL" << a + 1 << "    ID: " << hist[a].ID5 << "   NOMBRE: " << hist[a].Nombre5 << endl << "\t\t\t\t\t\t\t         AUTOR: " ;
            	cout  << hist[a].Autor5 <<"   "<<  hist[a].Anio5  << "   PAG: " << hist[a].paginas5   << endl << "\t\t\t\t\t\t\t         CANT: " << hist[a].cantidad5 << endl;      
        	}
    	}
	}	
}

//FUNCION DE AGREGAR UN LIBRO
void agregarlibro(){
	int numcateg;
	int aux=1;
	cin>>numcateg;
	system("cls");
	Logo();
	if(numcateg == 1) {   
    	for(int a = 0; a < 10; a++){ 
    		if(aux==1){                //AGREGA EL LIBRO SOLO UNA VEZ
    			if(comu[a].ID1 ==0){
	    			cin.ignore();	
	    			cout<<"\t\t\t\t\t\t\t\tAUTOR: ";
	    			getline(cin, comu[a].Autor1);	
	    			cout<<"\t\t\t\t\t\t\t\tID: ";
	    			cin>>comu[a].ID1;
	    			cout<<"\t\t\t\t\t\t\t\tANIO DE PUBLICACION: ";
	    			cin>>comu[a].Anio1;
	    			cout<<"\t\t\t\t\t\t\t\tPAGINAS: ";
	    			cin>>comu[a].paginas1;
	    			cin.ignore();
	    			cout<<"\t\t\t\t\t\t\t\tTITULO: ";
	    			getline(cin, comu[a].Nombre1);
	    			cout<<"\t\t\t\t\t\t\t\tCANTIDAD: ";
	    			cin>>comu[a].cantidad1;
	    			aux++;
				}
			}
		}
	}else if(numcateg == 2) {   
    	for(int a = 0; a < 10; a++) {
       	    if(aux==1){
    			if(mate[a].ID2 ==0){
	    			cin.ignore();
	    			cout<<"\t\t\t\t\t\t\t\tAUTOR: ";
	    			getline(cin, mate[a].Autor2);
	    			cout<<"\t\t\t\t\t\t\t\tID: ";
	    			cin>>mate[a].ID2;
	    			cout<<"\t\t\t\t\t\t\t\tANIO DE PUBLICACION: ";
	    			cin>>mate[a].Anio2;
	    			cout<<"\t\t\t\t\t\t\t\tPAGINAS: ";
	    			cin>>mate[a].paginas2;
	    			cin.ignore();
	    			cout<<"\t\t\t\t\t\t\t\tTITULO: ";
	    			getline(cin, mate[a].Nombre2);
	    			cout<<"\t\t\t\t\t\t\t\tCANTIDAD: ";
	    			cin>>mate[a].cantidad2;
	    			aux++;
				}
			}
    	}
	}else if(numcateg == 3) {   
	    for(int a = 0; a < 10; a++) {
        	if(aux==1){
	    		if(progr[a].ID3 ==0){
	    			cin.ignore();
					cout<<"\t\t\t\t\t\t\t\tAUTOR: ";
	    			getline(cin, progr[a].Autor3);	
	    			cout<<"\t\t\t\t\t\t\t\tID: ";
	    			cin>>progr[a].ID3;
	    			cout<<"\t\t\t\t\t\t\t\tANIO DE PUBLICACION: ";
	    			cin>>progr[a].Anio3;
	    			cout<<"\t\t\t\t\t\t\t\tPAGINAS: ";
	    			cin>>progr[a].paginas3;
	    			cin.ignore();	
	    			cout<<"\t\t\t\t\t\t\t\tTITULO: ";
	    			getline(cin, progr[a].Nombre3);
	    			cout<<"\t\t\t\t\t\t\t\tCANTIDAD: ";
	    			cin>>progr[a].cantidad3;
	    			aux++;
				}
			}
		}
	}else if(numcateg == 4) {   
    	for(int a = 0; a < 10; a++) {
        	if(aux==1){
    			if(quimi[a].ID4 ==0){
    				cin.ignore();	
    				cout<<"\t\t\t\t\t\t\t\tAUTOR: ";
    				getline(cin, quimi[a].Autor4);	
    				cout<<"\t\t\t\t\t\t\t\tID: ";
    				cin>>quimi[a].ID4;
    				cout<<"\t\t\t\t\t\t\t\tANIO DE PUBLICACION: ";
    				cin>>quimi[a].Anio4;
    				cout<<"\t\t\t\t\t\t\t\tPAGINAS: ";
    				cin>>quimi[a].paginas4;
    				cin.ignore();
    				cout<<"\t\t\t\t\t\t\t\tTITULO: ";
    				getline(cin, quimi[a].Nombre4);
    				cout<<"\t\t\t\t\t\t\t\tCANTIDAD: ";
    				cin>>quimi[a].cantidad4;
    				aux++;
				}
			}
    	}
	} else if(numcateg == 5) {   //muestra al usuario los datos del libro de historia
    	for(int a = 0; a < 10; a++) {
        	if(aux==1){
    			if(hist[a].ID5 ==0){
    				cin.ignore();
    				cout<<"\t\t\t\t\t\t\t\tAUTOR: ";
	    			getline(cin, hist[a].Autor5);
	    			cout<<"\t\t\t\t\t\t\t\tID: ";
	    			cin>>hist[a].ID5;
	    			cout<<"\t\t\t\t\t\t\t\tANIO DE PUBLICACION: ";
	    			cin>>hist[a].Anio5;
	    			cout<<"\t\t\t\t\t\t\t\tPAGINAS: ";
	    			cin>>hist[a].paginas5;
	    			cin.ignore();
	    			cout<<"\t\t\t\t\t\t\t\tTITULO: ";
	    			getline(cin, hist[a].Nombre5);
	    			cout<<"\t\t\t\t\t\t\t\tCANTIDAD: ";
	    			cin>>hist[a].cantidad5;
	    			aux++;
				}
			}
    	}
	}else if(numcateg == 0){
    	system("cls");
	}
}
void quitarlibro(){
	int numcateg;
	cin>>numcateg;
	system("cls");
	int IDlibro;
	mostrar(numcateg);
	if(numcateg == 1) { 
	  cout<<"\t\t\t\t\t\t\t\tescribe el ID : ";
	  cin>>IDlibro;
    	for(int a = 0; a < 10; a++){ 
    		if(comu[a].ID1==IDlibro){
    			comu[a].cantidad1--;
			}
		}
	}else if(numcateg == 2) {   
    	for(int a = 0; a < 10; a++) {
       	    if(mate[a].ID2==IDlibro){
    			mate[a].cantidad2--;
			}
    	}
	}else if(numcateg == 3) {   
	    for(int a = 0; a < 10; a++) {
        	if(progr[a].ID3==IDlibro){
    			progr[a].cantidad3--;
			}
		}
	}else if(numcateg == 4) {   
    	for(int a = 0; a < 10; a++) {
        	if(quimi[a].ID4==IDlibro){
    			quimi[a].cantidad4--;
			}
    	}
	} else if(numcateg == 5) {  
    	for(int a = 0; a < 10; a++) {
    		if(hist[a].ID5==IDlibro){
    			hist[a].cantidad5--;
			}
    	}
    }
}
