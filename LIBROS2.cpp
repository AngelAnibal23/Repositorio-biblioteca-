#include<iostream>
#include<string>
#include "libro.h"

using namespace std;


struct comunicacion{
    string Autor1;
    int Anio1;
    int paginas1;
    string Nombre1;
    long long ID1;
};
struct matematica{
	string Autor2;
	int Anio2;
	int paginas2;
	string Nombre2;
	long long ID2;
};
struct programacion{
	string Autor3;
	int Anio3;
	int paginas3;
	string Nombre3;
	long long ID3;
};
struct quimica{
	string Autor4;
	int Anio4;
	int paginas4;
	string Nombre4;
	long long ID4;
};
struct historia{
	string Autor5;
	int Anio5;
	int paginas5;
	string Nombre5;
	long long ID5;
};

comunicacion comu [10] = {
        {"Carlos Fernandez", 2016, 450, "Teoria y Practica de la Comunicacion", 9783161484100},
        {"Ana Martinez", 2019, 380, "Comunicacion Interpersonal en el Ambito Academico",9781402894626},
        {"Jorge Ramirez", 2021, 410, "Comunicacion Digital para Estudiantes Universitarios",9780743273565}
    };
matematica mate [10] = {
	{"Erwin Kreyszig",2007,1272,"Matematicas avanzadas para ingenieros",9780061120084},
	{"Granville, Smith y Longley",2012,960,"Calculo diferencial e integral",9780156027656},
	{"Serge Lang",1996,480,"Algebra Lineal",9780060935467}
};
programacion progr [10] = {
		{"Luis Torres",2018,520,"Introduccion a la Programacion con Python",9781568650401},
		{"Marta Sanchez",2017,480,"Programacion en Java para Universitarios",9780385493574},
		{"Jose Hernandez",2020,550,"Fundamentos de Programacion en C++",9780140283297}
	};
	quimica quimi [10] = {
		{"Ricardo Morales",2016,700,"Quimica General: Principios y Aplicaciones Modernas",9780743273566},
		{"Ana Fernandez",2018,640,"Quimica Organica: Teoria y Practica",9780451529277},
		{"Javier Gomez",2019,580,"Quimica Inorganica para Estudiantes Universitarios",9780743273573}
	};
	historia hist [10] = {
		{"Laura Rodriguez",2015,720,"Historia Contemporanea: Desde la Revolución Francesa hasta la Globalizacion",9780375755163},
		{"Miguel Alvarez",2017,650,"Historia de America Latina: Colonizacion y Desarrollo",9780440226127},
		{"Carmen Sanchez",2020,600,"Historia de España: Desde los Visigodos hasta la Democracia",9781402894633}
	};
	
void mostrar(int numcateg){
	if(numcateg==1){
		for(int a=0;a<10;a++){
			if(comu[a].ID1!=0){
				cout<<comu[a].ID1<<"   "<<comu[a].Autor1<<"   "<<comu[a].Anio1<<"   pag: "<<comu[a].paginas1<<"   "<<comu[a].Nombre1<<endl;
			}
		}
	}else if(numcateg==2){
		for(int a=0;a<10;a++){
			if(mate[a].ID2!=0){
				cout<<mate[a].ID2<<"   "<<mate[a].Autor2<<"   "<<mate[a].Anio2<<"   pag: "<<mate[a].paginas2<<"   "<<mate[a].Nombre2<<endl;
			}
		}
	}else if(numcateg==3){
		for(int a=0;a<10;a++){
			if(progr[a].ID3!=0){
				cout<<progr[a].ID3<<"   "<<progr[a].Autor3<<"   "<<progr[a].Anio3<<"   pag: "<<progr[a].paginas3<<"   "<<progr[a].Nombre3<<endl;
			}
		}
	}else if(numcateg==4){
		for(int a=0;a<10;a++){
			if(quimi[a].ID4!=0){
				cout<<quimi[a].ID4<<"   "<<quimi[a].Autor4<<"   "<<quimi[a].Anio4<<"   pag: "<<quimi[a].paginas4<<"   "<<quimi[a].Nombre4<<endl;
			}
		}
	}else if(numcateg==5){
		for(int a=0;a<10;a++){
			if(hist[a].ID5!=0){
				cout<<hist[a].ID5<<"   "<<hist[a].Autor5<<"   "<<hist[a].Anio5<<"   pag: "<<hist[a].paginas5<<"   "<<hist[a].Nombre5<<endl;
			}
		}
	}else{
		cout<<" dato incorrecto"<<endl;
	}
}