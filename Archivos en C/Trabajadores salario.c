#include <stdio.h>
#include <string.h>

// Definir el límite máximo de empleados
#define EMPLEADOS_MAX 5

// Definir la longitud máxima del nombre del empleado
#define MAX_LONGITUD_NOMBRE 50

// Definir la estructura Empleado
struct Empleado {
    char nombre[MAX_LONGITUD_NOMBRE];
    int edad;
    float salario;
};

// Declarar un array de empleados
struct Empleado empleados[EMPLEADOS_MAX];

// Prototipos de funciones
void ingresarDatos();
void procesarDatos();
void mostrarDatos();

int main() {
    int opcion;

    do {
        // Menú interactivo
        printf("\nMenu:\n");
        printf("1. Ingresar datos de un empleado\n");
        printf("2. Procesar y mostrar informacion relevante de los empleados\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarDatos(); // Llamada a la función para ingresar datos de un empleado
                break;
            case 2:
                procesarDatos(); // Llamada a la función para procesar datos y mostrar información relevante
                mostrarDatos();  // Llamada a la función para mostrar datos de todos los empleados
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}

// Función para ingresar datos de un empleado
void ingresarDatos() {
    static int contador = 0;

    if (contador < EMPLEADOS_MAX) {
        printf("\nIngrese los datos del empleado %d:\n", contador + 1);
        printf("Nombre: ");
        scanf("%s", empleados[contador].nombre);
        printf("Edad: ");
        scanf("%d", &empleados[contador].edad);
        printf("Salario: ");
        scanf("%f", &empleados[contador].salario);

        contador++;
    } else {
        printf("No se pueden ingresar mas empleados.\n");
    }
}

// Función para procesar datos y mostrar información relevante
void procesarDatos() {
    if (empleados[0].salario == 0) {
        printf("No hay datos de empleados ingresados.\n");
        return;
    }

    float sumaSalarios = 0;
    float promedioSalarios;
    float salarioMaximo = empleados[0].salario;
    char nombreMaximo[MAX_LONGITUD_NOMBRE];

    // Calcular el promedio de salarios y encontrar el empleado con el salario más alto
    for (int i = 0; i < EMPLEADOS_MAX; i++) {
        sumaSalarios += empleados[i].salario;

        if (empleados[i].salario > salarioMaximo) {
            salarioMaximo = empleados[i].salario;
            strcpy(nombreMaximo, empleados[i].nombre);
        }
    }

    promedioSalarios = sumaSalarios / EMPLEADOS_MAX;

    printf("\nPromedio de salarios: %.2f\n", promedioSalarios);
    printf("Empleado con el salario mas alto: %s\n", nombreMaximo);
}

// Función para mostrar datos de todos los empleados
void mostrarDatos() {
    if (empleados[0].salario == 0) {
        printf("No hay datos de empleados ingresados.\n");
        return;
    }

    // Mostrar la información de todos los empleados
    printf("\nDatos de los empleados:\n");
    for (int i = 0; i < EMPLEADOS_MAX; i++) {
        printf("Empleado %d:\n", i + 1);
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("Edad: %d\n", empleados[i].edad);
        printf("Salario: %.2f\n", empleados[i].salario);
    }
}
