#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "biblioteca.h"
#include <string>
#include <iostream>
#include <cstdlib>

extern const int cantidadLibros;
extern Book libros[15];

void Logo();
string obtenerFechaHoraActual();
string obtenerFechaDevolucion(int dias_sumar);
void registrarPrestamo(Prestamo prestamos[], int& indice, const Book& libro, int dias_prestamo);
void prestamoLibro(Book libros[], int cantidad, long long buscarID, Prestamo prestamos[], int& indicePrestamos);
void mostrarHistorial(const Prestamo prestamos[], int cantidad);
void menuPrestamos(Book libros[]);
void Registrar(Registro REG[], int& cant_usu);
void Menu_Principal();
void Menu_Usuario();
void Menu_Mostrar();
void mostrar(int numcateg); 

#endif // F
