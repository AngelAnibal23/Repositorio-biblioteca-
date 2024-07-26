#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

void Menu_Principal();
void Menu_Usuario();
void Logo();
void Menu_Mostrar();

using namespace std;
//ESTRUCTURA DE DATOS PERSONALES
struct comunicacion{
    string Autor1;
    int Anio1;
    int paginas1;
    string Nombre1;
    int ID1;
};
struct matematica{
	string Autor2;
	int Anio2;
	int paginas2;
	string Nombre2;
	int ID2;
};
struct programacion{
	string Autor3;
	int Anio3;
	int paginas3;
	string Nombre3;
	int ID3;
};
struct quimica{
	string Autor4;
	int Anio4;
	int paginas4;
	string Nombre4;
	int ID4;
};
struct historia{
	string Autor5;
	int Anio5;
	int paginas5;
	string Nombre5;
	int ID5;
};

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
//void Registrar(Registro REG[], int &cant_usu); 

 
#endif
