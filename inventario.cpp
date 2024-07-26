#include <iostream>
#include <cstdlib>
#include "biblioteca.h"
#include "funciones.h"
#include <string>
#include <ctime>
#include <string>


comunicacion comu [10] = {
    {"Carlos Fernandez", 2016, 450, "Teoria y Practica de la Comunicacion", 101},
	{"Ana Martinez", 2019, 380, "Comunicacion Interpersonal en el Ambito Academico", 102},
    {"Jorge Ramirez", 2021, 410, "Comunicacion Digital para Estudiantes Universitarios", 103}
};
matematica mate [10] = {
	{"Erwin Kreyszig",2007,1272,"Matematicas avanzadas para ingenieros", 104},
	{"Granville, Smith y Longley",2012,960,"Calculo diferencial e integral", 103},
	{"Serge Lang",1996,480,"Algebra Lineal", 105}
};
programacion progr [10] = {
	{"Luis Torres",2018,520,"Introduccion a la Programacion con Python", 106},
	{"Marta Sanchez",2017,480,"Programacion en Java para Universitarios", 107},
	{"Jose Hernandez",2020,550,"Fundamentos de Programacion en C++", 108}
};
quimica quimi [10] = {
	{"Ricardo Morales",2016,700,"Quimica General: Principios y Aplicaciones Modernas", 109},
	{"Ana Fernandez",2018,640,"Quimica Organica: Teoria y Practica",110},
	{"Javier Gomez",2019,580,"Quimica Inorganica para Estudiantes Universitarios",111}
};
historia hist [10] = {
	{"Laura Rodriguez",2015,720,"Historia Contemporanea: Desde la Revolución Francesa hasta la Globalizacion",112},
	{"Miguel Alvarez",2017,650,"Historia de America Latina: Colonizacion y Desarrollo",113},
	{"Carmen Sanchez",2020,600,"Historia de España: Desde los Visigodos hasta la Democracia",114}
};


void mostrar(int numcateg){
	Logo();
	if(numcateg == 1) {
    	for(int a = 0; a < 10; a++) {
        	if(comu[a].ID1 != 0) {
         	   cout << "\t\t\t\t\tL" << a + 1 << "    ID: " << comu[a].ID1 << "   NOMBRE: " << comu[a].Nombre1 << endl << "\t\t\t\t\t\t\t         AUTOR: " ;
          	  cout << comu[a].Autor1 << comu[a].Anio1 << "   PAG: " << comu[a].paginas1<< endl;              
     		   }
   		 }
	} else if(numcateg == 2) {
    	for(int a = 0; a < 10; a++) {
       	 if(mate[a].ID2 != 0) {
          	  cout << "\t\t\t\t\tL" << a + 1 << "    ID: " << mate[a].ID2 << "   NOMBRE: " << mate[a].Nombre2 << endl << "\t\t\t\t\t\t\t         AUTOR: ";
          	  cout << mate[a].Autor2 << mate[a].Anio2 << "   PAG: " << mate[a].paginas2<<  endl;         
       		 }
    	}
	} else if(numcateg == 3) {
   	 	for(int a = 0; a < 10; a++) {
        	if(progr[a].ID3 != 0) {
            	cout << "\t\t\t\t\tL" << a + 1  << "    ID: " << progr[a].ID3  << "   NOMBRE: " << progr[a].Nombre3;
            	cout<< endl << "\t\t\t\t\t\t\t         AUTOR: " << progr[a].Autor3 << progr[a].Anio3<< "   PAG: " << progr[a].paginas3<< endl;           
      		  }
    	}
	} else if(numcateg == 4) {
    	for(int a = 0; a < 10; a++) {
        	if(quimi[a].ID4 != 0) {
          	  	cout << "\t\t\t\t\tL" << a + 1  << "    ID: " << quimi[a].ID4 << "   NOMBRE: " << quimi[a].Nombre4 << endl << "\t\t\t\t\t\t\t         AUTOR: ";
            	cout << quimi[a].Autor4 << quimi[a].Anio4    << "   PAG: " << quimi[a].paginas4 << endl;        
        	}
    	}
	} else if(numcateg == 5) {
    	for(int a = 0; a < 10; a++) {
        	if(hist[a].ID5 != 0) {
            	cout << "\t\t\t\t\tL" << a + 1 << "    ID: " << hist[a].ID5 << "   NOMBRE: " << hist[a].Nombre5 << endl << "\t\t\t\t\t\t\t         AUTOR: " ;
            	cout  << hist[a].Autor5 << hist[a].Anio5  << "   PAG: " << hist[a].paginas5   << endl;      
        	}
    	}
	}else{
    	cout<<" dato incorrecto"<<endl;
	}	
}

