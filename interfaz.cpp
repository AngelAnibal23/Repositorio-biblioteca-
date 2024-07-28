#include "funciones.h"
#include "biblioteca.h"
#include <iostream>
#include <cstdlib>
#include <string>

int cantidad_de_usuarios = 0; 
int cantidad_de_administradores=0;
Registro_usuario registrar_usuario[30]; 
Registro_Administrador registrar_administrador[30];
using namespace std;
//Dispuesta para ser llamada por las demas funciones
void Logo() {
    cout<<"\t\t\t\t\t----------------------------------------------------------------------------"<<endl;
    cout << "\t\t\t\t\t      0000    000   0000    0     000   00000   00000  00000   0000    000   " << endl;
    cout << "\t\t\t\t\t     0   0    0    0   0   0      0   0     0    0    0      0       0   0   "<< endl;
    cout << "\t\t\t\t\t    0000     0    0000    0      0   0     0    0    000    0       00000     " << endl;
    cout << "\t\t\t\t\t   0   0    0    0   0   0      0   0     0    0    0      0       0   0       " << endl;
    cout << "\t\t\t\t\t  0000    000   0000    0000  000   00000     0    00000   0000   0   0    " << endl;
    cout<<"\t\t\t\t\t----------------------------------------------------------------------------"<<endl<<endl<<endl;
}

//INGRESA AL MENU DE ADMINISTRADOR:	        
void Menu_Administrador() {
    int resp; // Variable para almacenar la respuesta del usuario

    do {
        // Muestra el logotipo
        Logo();

        // Muestra el menú de administrador
        cout << "\t\t\t\t\t\t__________________MENU DE ADMINISTRADOR__________________________" << endl;
        cout << "\t\t\t\t\t\t|\t\t                                 \t\t|";
        cout << endl << "\t\t\t\t\t\t|\t\t1.- Registrarse.                 \t\t|" << endl; 
        cout << "\t\t\t\t\t\t|\t\t                                 \t\t|"; 
        cout << endl << "\t\t\t\t\t\t|\t\t2.- Mostrar personas registradas.\t\t|" << endl; 
        cout << "\t\t\t\t\t\t|\t\t                                 \t\t|"; 
        cout << endl << "\t\t\t\t\t\t|\t\t3.- Agregar un libro.            \t\t|" << endl; 
        cout << "\t\t\t\t\t\t|\t\t                                 \t\t|"; 
        cout << endl << "\t\t\t\t\t\t|\t\t4.- Quitar libros.               \t\t|" << endl;
        cout << "\t\t\t\t\t\t|\t\t                                 \t\t|"; 
        cout << endl << "\t\t\t\t\t\t|\t\t5.- Prestamos en curso.          \t\t|" << endl; 
        cout << "\t\t\t\t\t\t|\t\t                                 \t\t|"; 
        cout << endl << "\t\t\t\t\t\t|\t\t0.- Volver al menu principal.    \t\t|" << endl;
        cout << "\t\t\t\t\t\t|\t\t                                 \t\t|"; 
        cout << endl << "\t\t\t\t\t\t|_______________________________________________________________|" << endl; 
        cout << endl << "\t\t\t\t\t\t\t \tIngrese la respuesta: ";

        valida(resp); // Valida la entrada del usuario

        system("cls"); // Limpia la pantalla

        // Maneja la opcion seleccionada por el usuario
        if (resp == 1) {
            Registrar_admin(registrar_administrador, cantidad_de_administradores); // Redirige a una funcion para registrar un nuevo administrador
        }
        if (resp == 2) {
            Mostrar_registros(registrar_administrador, registrar_usuario,cantidad_de_administradores,cantidad_de_usuarios); // Muestra los usuarios y administradores registrados
        }
        if (resp == 3) {
            AgregarL(); // Llama a la funcion para agregar un libro
        }
        if (resp == 4) {
            QuitarL(); // Llama a la funcion para quitar libros
        }
        if (resp == 5) {
            mostrar_prestamos_activos_admin(cantidad_de_usuarios, registrar_usuario); // Muestra los prestamos activos
        }

    } while (resp != 0); // Repite el menu hasta que el usuario elija salir (opcion 0)

    
    system("cls"); // Limpia la pantalla antes de volver al menu principal
}

//INGRESA AL MENU PRINCIPAL
void Menu_Principal() {
    int resp; // Variable para almacenar la respuesta del usuario

    do {
        Logo(); // Llama a la función Logo para mostrar el logotipo
        cout << "\t\t\t\t\t\t\t__________________MENU PRINCIPAL_________________" << endl;
        cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
        cout << endl << "\t\t\t\t\t\t\t|\t\t1.- Usuario libre.\t\t|" << endl; 
        cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
        cout << endl << "\t\t\t\t\t\t\t|\t\t2.- Administrador.\t\t|" << endl; 
        cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
        cout << endl << "\t\t\t\t\t\t\t|\t\t0.- Salir.        \t\t|" << endl; 
        cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
        cout << endl << "\t\t\t\t\t\t\t|_______________________________________________|" << endl; // Línea final del menú
        cout << endl << "\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";

        valida(resp); // Llama a la funcion valida para obtener una opción válida del usuario

        system("cls"); // Limpia la pantalla

        if (resp == 1) { // Si el usuario elige la opción 1
            Menu_Usuario(); // Llama a la funcion Menu_Usuario para mostrar el menu de usuario libre
        } else if (resp == 2) { // Si el usuario elige la opción 2
            Menu_Administrador(); // Llama a la funcion Menu_Administrador para mostrar el menu de administrador
        }
    } while (resp != 0); // Repite el menú hasta que el usuario elija salir (opción 0)
}



//INGRESA AL MENU DE USUARIO	 
void Menu_Usuario() {
    int resp; // Variable para almacenar la respuesta del usuario
    int retiene = 0; // Variable para verificar si el usuario ya está registrado

    do {
        Logo(); // Llamada a la función Logo para mostrar el logotipo
        cout << "\t\t\t\t\t\t__________________MENU DE USUARIO________________________" << endl;
        cout << "\t\t\t\t\t\t|\t\t                              \t\t|";
        cout << endl << "\t\t\t\t\t\t|\t\t1.- Registrarse.             \t\t|" << endl;
        cout << "\t\t\t\t\t\t|\t\t                              \t\t|";
        cout << endl << "\t\t\t\t\t\t|\t\t2.- Mostrar Inventario.      \t\t|" << endl;
        cout << "\t\t\t\t\t\t|\t\t                              \t\t|";
        cout << endl << "\t\t\t\t\t\t|\t\t3.- Prestarse un libro.      \t\t|" << endl;
        cout << "\t\t\t\t\t\t|\t\t                              \t\t|";
        cout << endl << "\t\t\t\t\t\t|\t\t0.- Volver al menu principal.\t\t|" << endl;
        cout << "\t\t\t\t\t\t|\t\t                              \t\t|";
        cout << endl << "\t\t\t\t\t\t|_______________________________________________________|" << endl;
        cout << endl << "\t\t\t\t\t\t\t \tIngrese la respuesta: ";
        valida(resp); // Llamada a la funcion valida para obtener una respuesta válida del usuario

        if (resp == 1) { // Si el usuario elige la opción 1
            if (retiene == 1) { // Verifica si ya está registrado
                cout << "\t\t\t\t\t\tYa se encuentra registrado.";
                system("PAUSE"); // Pausa el sistema para que el usuario pueda ver el mensaje
            }
        }

        system("cls"); // Limpia la pantalla

        if (resp == 1) { // Si el usuario elige registrarse y no esta registrado
            if (retiene == 0) {
                Registrar_usuario(registrar_usuario, cantidad_de_usuarios); // Llama a la funcion para registrar al usuario
                retiene = 1; // Marca que el usuario ya está registrado
            } else {
                // No hace nada si ya esta registrado
            }
        }

        if (resp == 2) { // Si el usuario elige mostrar el inventario
            Menu_Mostrar(); // Llama a la funcion para mostrar el inventario
            system("cls"); // Limpia la pantalla
        }

        if (resp == 3) { // Si el usuario elige prestarse un libro
            if (retiene == 0) { // Verifica si el usuario no esta registrado
                Logo();
                cout << "\t\t\t\t\t\tDebe registrarse antes.";
                system("PAUSE"); // Pausa el sistema para que el usuario pueda ver el mensaje
                system("cls"); // Limpia la pantalla
            } else {
                menuPrestamos(libros); // Llama a la funcion para gestionar los préstamos de libros
            }
        }

        if (resp == 0) { // Si el usuario elige volver al menu principal
            retiene = 0; // Resetea la variable de retencion
        }
    } while (resp != 0); // Repite el menu hasta que el usuario elija salir (opción 0)
    
    system("cls"); // Limpia la pantalla antes de salir
}
//INGRESA AL MENU INVENTARIO
void Menu_Mostrar() {
    int numcateg; // Variable para almacenar la opcion de categoría seleccionada por el usuario

    Logo(); // Llama a la funcion Logo para mostrar el logotipo
    cout << "\t\t\t\t\t\t\t_________________MENU INVENTARIO_________________" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|"; 
    cout << endl << "\t\t\t\t\t\t\t|\t\t1.- Comunicacion. \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|"; 
    cout << endl << "\t\t\t\t\t\t\t|\t\t2.- Matematica.   \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|"; 
    cout << endl << "\t\t\t\t\t\t\t|\t\t3.- Programacion. \t\t|" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|"; 
    cout << endl << "\t\t\t\t\t\t\t|\t\t4.- Quimica.      \t\t|" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|"; 
    cout << endl << "\t\t\t\t\t\t\t|\t\t5.- Historia.     \t\t|" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|"; 
    cout << endl << "\t\t\t\t\t\t\t|_______________________________________________|" << endl; 
    cout << endl << "\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";

    valida(numcateg); // Llama a la funcion valida para obtener una opcion valida del usuario
    system("cls"); // Limpia la pantalla
    mostrar(numcateg); // Llama a la funcion mostrar para mostrar el inventario segun la categoria seleccionada

    cout << endl;
    system("PAUSE"); // Pausa el sistema para que el usuario pueda ver la informacion mostrada
}


void AgregarL() {
    Logo(); // Muestra el logotipo

    // Muestra el menú de opciones para agregar libros
    cout << "\t\t\t\t\t\t\t_________________MENU INVENTARIO_________________" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|"; 
    cout << endl << "\t\t\t\t\t\t\t|\t\t1.- Comunicacion. \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t2.- Matematica.   \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t3.- Programacion. \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t4.- Quimica.      \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t5.- Historia.     \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t0.- Salir.        \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|_______________________________________________|" << endl;
    cout << endl << "\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";

    agregarlibro(); // Llama a la funcion para agregar un libro

    system("PAUSE"); // Pausa el sistema 
    system("cls"); // Limpia la pantalla antes de volver al menu del administrador
}

void QuitarL() {
    Logo(); // Muestra el logotipo

    // Muestra el menú de opciones para quitar libros
    cout << "\t\t\t\t\t\t\t_________________MENU INVENTARIO_________________" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|"; 
    cout << endl << "\t\t\t\t\t\t\t|\t\t1.- Comunicacion. \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t2.- Matematica.   \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t3.- Programacion. \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t4.- Quimica.      \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t5.- Historia.     \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|\t\t0.- Salir.        \t\t|" << endl; 
    cout << "\t\t\t\t\t\t\t|\t\t                  \t\t|";
    cout << endl << "\t\t\t\t\t\t\t|_______________________________________________|" << endl; 
    cout << endl << "\t\t\t\t\t\t\t\t \tIngrese la respuesta: ";

    quitarlibro(); // Llama a la funcion para quitar un libro

    system("PAUSE"); // Pausa el sistema 
    system("cls"); // Limpia la pantalla antes de volver al menu de administrador
}

