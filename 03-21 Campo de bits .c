#include <stdio.h>

// Estructura para almacenar los datos del número flotante
typedef struct {
    float valorNumerico; 
    unsigned char bytesNumero[4]; // Arreglo de bytes que representa el número flotante en memoria
    int parteEntera; 
} DatosNumeroFlotante;

void mostrarMenuPrincipal();
void obtenerOpcionMenu(int *opcionSeleccionada);
void ingresarNumeroFlotante(DatosNumeroFlotante *datosFlotante);
void imprimirDatosNumeroFlotante(DatosNumeroFlotante datosFlotante);

int main(void) {
    DatosNumeroFlotante datosFlotante; 
    int opcionSeleccionada; // Variable para almacenar la opción del menú seleccionada

    do {
        mostrarMenuPrincipal();
        obtenerOpcionMenu(&opcionSeleccionada);
        switch (opcionSeleccionada) {
            case 2:
                // Imprimir los datos del número flotante ingresado
                imprimirDatosNumeroFlotante(datosFlotante);
                break;
            case 1:
                // Ingresar un nuevo número flotante
                ingresarNumeroFlotante(&datosFlotante);
                break;
        }
    } while (opcionSeleccionada != 3); // Repetir hasta que se seleccione la opción 3 (Cerrar el programa)

    return 0;
}

// Función para mostrar el menú principal
void mostrarMenuPrincipal() {
    printf("---------------------------\n");
    printf("𝅇- Ingresar un número        (1)\n");
    printf("𝅇- Mostrar número almacenado (2)\n");
    printf("𝅇- Cerrar el programa        (3)\n");
    printf("---------------------\n");
}

// Función para obtener la opción del menú seleccionada por el usuario
void obtenerOpcionMenu(int *opcionSeleccionada) {
    int lecturaCorrrecta; // Variable para verificar si la entrada del usuario es válida

    do {
        lecturaCorrrecta = scanf("%d", opcionSeleccionada);

        // Verificar si la entrada es inválida, no es un número o si no es un valor entre 1 y 3
        if (lecturaCorrrecta == 0) {
            printf("Entrada inválida. Intente nuevamente.\n");
        }
        else if (*opcionSeleccionada < 1 || *opcionSeleccionada > 3) {
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (lecturaCorrrecta == 0 || (*opcionSeleccionada < 1 || *opcionSeleccionada > 3));
}

// Función para ingresar un número flotante
void ingresarNumeroFlotante(DatosNumeroFlotante *datosFlotante) {
    printf("Ingrese un número flotante: ");

    if (scanf("%f", &datosFlotante->valorNumerico) != 1) {
        printf("Entrada inválida. Intente nuevamente.\n");
        // Asigna un valor predeterminado si la entrada es inválida
        datosFlotante->valorNumerico = 0.0f;
    }

    // Obtener la parte entera del número flotante
    datosFlotante->parteEntera = (int)datosFlotante->valorNumerico;
    unsigned char *punteroBytes = (unsigned char *)&datosFlotante->valorNumerico;
    for (int i = 0; i < 4; i++) {
        datosFlotante->bytesNumero[i] = punteroBytes[i];
    }
}

// Función para imprimir los datos del número flotante
void imprimirDatosNumeroFlotante(DatosNumeroFlotante datosFlotante) {
    unsigned int bytesHexadecimales = 0; // Variable para almacenar los bytes en formato hexadecimal

    // Construir el valor hexadecimal a partir de los bytes
    for (int i = 0; i < 4; i++) {
        bytesHexadecimales |= (datosFlotante.bytesNumero[i] << (8 * (3 - i)));
    }

    printf("Se guardó el número como: 0x%08X \n", bytesHexadecimales);
    printf("El número ingresado fue %f\n", datosFlotante.valorNumerico);
    printf("La parte entera en hexadecimal es: 0x%X\n", datosFlotante.parteEntera);
}
