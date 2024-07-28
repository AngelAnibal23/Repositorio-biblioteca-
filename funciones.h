#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "biblioteca.h"
#include <string>
#include <iostream>
#include <cstdlib>
//VARIABLES GLOBALES
extern const int cantidadLibros;
extern Book libros[15];
extern int cantidad_de_usuarios; 
extern int cantidad_de_administradores; 

void Logo();//FUNCION QUE IMPRIME EL LOGO "BIBLIOTECA" UBICADO EN INTERFAZ
string obtenerFechaHoraActual();//FUNCION QUE OBTIENE LA HORA UBICADO EN PRESTAMOS
string obtenerFechaDevolucion(int dias_sumar);//FUNCION QUE OBTIENE LA FECHA DE DEVOLUCION SUMANDO LOS DIAS DE PRESTAMO UBICADO EN PRESTAMO
void registrarPrestamo(Prestamo prestamos[], int& indice, const Book& libro, int dias_prestamo);//FUNCION QUE UTILIZA LA ESTRUCTURA PRESTAMOS PARA GUARDAR LOS DATOS DEL PRESTAMO 
void prestamoLibro(Book libros[], int cantidad, long long buscarID, Prestamo prestamos[], int& indicePrestamos);//FUNCION QUE MUESTRA UN LIBRO SEGUN INDIQUES EL ID  Y PIDE LOS DIAS DE PRESTAMO
void mostrarHistorial(const Prestamo prestamos[], int cantidad);//MUESTRA EL HISTORIAL DE PRESTAMOS
void menuPrestamos(Book libros[]);
void Registrar_usuario(Registro_usuario REG[], int &cant_usu);
void Menu_Principal();
void Menu_Usuario();
void Menu_Mostrar();
void mostrar(int numcateg); //FUNCION QUE MUESTRA LIBROS DE UN CATEGORIA EN ESPECIFICA
void Menu_Administrador();
void Mostrar_usuarios_administradores(Registro_Administrador RE[], Registro_usuario REU[]);
void Registrar_admin(Registro_Administrador REG[],int &cant_admin);
void valida(int &entrada);
void agregarlibro();
void AgregarL();
void librosobtenidos();
#endif // F
