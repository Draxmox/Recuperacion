#include <stdio.h>
#include <string.h>

#define NUM_ALUMNOS 6
#define NUM_NOTAS 3
#define PROMEDIO_APROBADO 6

void imprimirAlumnos(char alumnos[][2][20], double notas[][3]) {
    printf("Alumnos:\n");
    for (int i = 0; i < 6; i++) {
        double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;
        char estado[20];
        if (promedio >= 6)
            strcpy(estado, "Aprobado");
        else
            strcpy(estado, "Reprobado");
        printf("Nombre: %s %s - Notas: %.1lf, %.1lf, %.1lf - Promedio: %.1lf - Estado: %s\n",
               alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio, estado);
    }
}
void buscarAlumnoXApellido(char alumnos[][2][20], double notas[][3]) {
    char apellido[20];
    int encontrado = 0;
    printf("Ingrese el apellido del alumno a buscar: ");
    scanf("%s", apellido);


    int coincidencias = 0;
    for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], apellido) == 0) {
            coincidencias++;
        }
    }

    if (coincidencias == 0) { 
        printf("Alumno no encontrado.\n");
        return;
    }

   
    if (coincidencias > 1) {
        char nombre[20];
        printf("Se encontraron varios alumnos con el mismo apellido. Ingrese también el nombre del alumno: ");
        scanf("%s", nombre);
        for (int i = 0; i < 6; i++) {
            if (strcmp(alumnos[i][0], nombre) == 0 && strcmp(alumnos[i][1], apellido) == 0) {
                encontrado = 1;
                double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;
                char estado[20];
                if (promedio >= 6)
                    strcpy(estado, "Aprobado");
                else
                    strcpy(estado, "Reprobado");
                printf("Nombre: %s %s - Notas: %.1lf, %.1lf, %.1lf - Promedio: %.1lf - Estado: %s\n",
                       alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio, estado);
                break;
            }
        }
    } else { 
        for (int i = 0; i < 6; i++) {
            if (strcmp(alumnos[i][1], apellido) == 0) {
                encontrado = 1;
                double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;
                char estado[20];
                if (promedio >= 6)
                    strcpy(estado, "Aprobado");
                else
                    strcpy(estado, "Reprobado");
                printf("Nombre: %s %s - Notas: %.1lf, %.1lf, %.1lf - Promedio: %.1lf - Estado: %s\n",
                       alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio, estado);
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Alumno no encontrado.\n");
    }
}

void editarCalificaciones(char alumnos[][2][20], double notas[][3]) {
    char apellido[20];
    printf("Ingrese el apellido del alumno para editar sus calificaciones: ");
    scanf("%s", apellido);
    int coincidencias = 0;
    int encontrado = 0;

    
    for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], apellido) == 0) {
            coincidencias++;
        }
    }

    if (coincidencias == 0) { 
        printf("Alumno no encontrado.\n");
        return;
    }

   
    if (coincidencias > 1) {
        char nombre[20];
        printf("Se encontraron varios alumnos con el mismo apellido. Ingrese también el nombre del alumno: ");
        scanf("%s", nombre);
        for (int i = 0; i < 6; i++) {
            if (strcmp(alumnos[i][0], nombre) == 0 && strcmp(alumnos[i][1], apellido) == 0) {
                encontrado = 1;
                printf("Ingrese las nuevas calificaciones para %s %s:\n", alumnos[i][0], alumnos[i][1]);
                printf("Nota 1: ");
                scanf("%lf", &notas[i][0]);
                printf("Nota 2: ");
                scanf("%lf", &notas[i][1]);
                printf("Nota 3: ");
                scanf("%lf", &notas[i][2]);
                printf("Las calificaciones han sido actualizadas.\n");
                break;
            }
        }
    } else { 
        for (int i = 0; i < 6; i++) {
            if (strcmp(alumnos[i][1], apellido) == 0) {
                encontrado = 1;
                printf("Ingrese las nuevas calificaciones para %s %s:\n", alumnos[i][0], alumnos[i][1]);
                printf("Nota 1: ");
                scanf("%lf", &notas[i][0]);
                printf("Nota 2: ");
                scanf("%lf", &notas[i][1]);
                printf("Nota 3: ");
                scanf("%lf", &notas[i][2]);
                printf("Las calificaciones han sido actualizadas.\n");
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Alumno no encontrado.\n");
    }
}