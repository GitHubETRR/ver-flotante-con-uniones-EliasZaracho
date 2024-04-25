#include <stdio.h>

void obtenerNumeroReal(float* ptrNumeroReal); // Obtener un número real del usuario
void imprimirBytesFloat(float* ptrNumeroReal); // Imprimir los bytes de un número real

int main() {
    float numeroReal;

    printf("Ingrese un numero real:\n");
    obtenerNumeroReal(&numeroReal); // Llamada para obtener el número ingresado

    imprimirBytesFloat(&numeroReal); // Pasamos el puntero al número real

    return 0;
}

void obtenerNumeroReal(float* ptrNumeroReal) {
    scanf("%f", ptrNumeroReal); // Almacenamos el número ingresado
}

void imprimirBytesFloat(float* ptrNumeroReal) {
    printf("Bytes del numero real: ");


    unsigned char* ptrBytes = (unsigned char*)ptrNumeroReal;//con el puntero accedo a los bytes del num

    for (int i = sizeof(float) - 1; i >= 0; i--) { //imprimo los bytes de atras para adenlante
        printf("%02X ", *(ptrBytes + i));
    }
}