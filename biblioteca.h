#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <string>

using namespace std;

struct Book {
    int id;         // ID de los libros
    string nombre;  //  Titulo de los libros 
    string autor;   //   Nombre del autor 
    int anio;      	//   Anio de publicacion 
    int paginas;  	//   Paginas del libro 
    int cantidad; 	//   Cantidad de libros disponibles
};

//ESTRUCTURAS DE LIBROS
struct comunicacion{
    string Autor1;
    int Anio1;
    int paginas1;
    string Nombre1;
    int ID1;
    int cantidad1;
};
struct matematica{
	string Autor2;
	int Anio2;
	int paginas2;
	string Nombre2;
	int ID2;
	int cantidad2;
};
struct programacion{
	string Autor3;
	int Anio3;
	int paginas3;
	string Nombre3;
	int ID3;
	int cantidad3;
};
struct quimica{
	string Autor4;
	int Anio4;
	int paginas4;
	string Nombre4;
	int ID4;
	int cantidad4;
};
struct historia{
	string Autor5;
	int Anio5;
	int paginas5;
	string Nombre5;
	int ID5;
	int cantidad5;
};
//ESTRUCTURAS DE REGISTRO DE DATOS PERSONALES
//ESTRUCTURA QUE GUARDA DATOS DEL PRESTAMO DE UN LIBRO
struct Prestamo {
    string nombre_libro;       // Nombre del libro prestado 
    string fecha_entrega;	   // Fecha de entrega del libro 
    string fecha_devolucion;   // Fecha de devolucion del libro 
    int id_prestamo; 		   // ID del libro prestado 
};
struct Registro_usuario{
	string NOMBRE;
	string APELLIDO_PAT;
	string APELLIDO_MAT;
	string DNI;
	string CODIGO;
	string EDAD;
	string EMAIL;
	string SEXO;
	string TELEFONO;
	Prestamo prestamos[50];
};


struct Registro_Administrador{
	string NOMBRE;
	string APELLIDO_PAT;
	string APELLIDO_MAT;
	string DNI;
	string CODIGO;
	string EDAD;
	string EMAIL;
	string SEXO;
	string TELEFONO;

};



 
#endif
