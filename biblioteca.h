#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

void Menu_Principal();
void Menu_Usuario();
void Logo();
void Registrar(Registro REG[], int &cant_usu); 
void prestamoLibro(Book libros[], int cantidad, long long buscarID, Prestamo prestamos[], int& indicePrestamos); 
 
#endif
