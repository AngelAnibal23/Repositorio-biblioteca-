#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>

using namespace std; 

struct Registro{
	string NOMBRE;
	string DNI;
	string CODIGO;
	string EDAD;
	string EMAIL;
	string SEXO;
	string TELEFONO;
};

struct Prestamo {
    string nombre_libro;
    string fecha_entrega;
    string fecha_devolucion;
};

struct Book {
    long long id; 
    string nombre;
    string autor;
    int anio;
    int paginas;
};


#endif
