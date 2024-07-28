#include "biblioteca.h"
#include "funciones.h" 
#include <string>

const int cantidadLibros = 50;  
//INVENTARIO DE LIBROS
 Book libros[cantidadLibros] = {
        {101, "Teoria y Practica de la Comunicacion", "Carlos Fernandez", 2016, 450, 2},
        {102, "Comunicacion Interpersonal en el Ambito Academico", "Ana Martinez", 2019, 380, 1},
        {103, "Comunicacion Digital para Estudiantes Universitarios", "Jorge Ramirez", 2021, 410, 2},
        {201, "Matematicas avanzadas para ingenieros", "Erwin Kreyszig", 2007, 1272, 3},
        {202, "Calculo diferencial e integral", "Granville, Smith y Longley", 2012, 960, 2},
        {203, "Algebra Lineal", "Serge Lang", 1996, 480, 2},
        {301, "Introduccion a la Programacion con Python", "Luis Torres", 2018, 520, 1},
        {302, "Programacion en Java para Universitarios", "Marta Sanchez", 2017, 480, 2},
        {303, "Fundamentos de Programacion en C++", "Jose Hernandez", 2020, 550, 3},
        {401, "Quimica General: Principios y Aplicaciones Modernas", "Ricardo Morales", 2016, 700, 1},
        {402, "Quimica Organica: Teoria y Practica", "Ana Fernandez", 2018, 640, 2},
        {403, "Quimica Inorganica para Estudiantes Universitarios", "Javier Gomez", 2019, 580, 1},
        {501, "Historia Contemporanea: Desde la RevoluciÃ³n Francesa hasta la Globalizacion", "Laura Rodriguez", 2015, 720, 2},
        {502, "Historia de America Latina: Colonizacion y Desarrollo", "Miguel Alvarez", 2017, 650, 1},
        {503, "Historia de España: Desde los Visigodos hasta la Democracia", "Carmen Sanchez", 2020, 600, 1}
    };
