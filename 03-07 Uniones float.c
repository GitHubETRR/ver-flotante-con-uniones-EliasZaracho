#include <stdio.h>
union DatosNumero {
    float numeroReal;
    unsigned char bytesNumero[4];  // Arreglo de 4 bytes (sizeof(float) = 4)
};

void imprimirBytesNumero(union DatosNumero datos); //declaro la función 

int main() {
    union DatosNumero datos;

    printf("Ingrese un numero real: ");
    scanf("%f", &datos.numeroReal);
    imprimirBytesNumero(datos); //llamo a la función

    return 0;
}


void imprimirBytesNumero(union DatosNumero datos) { // Defino que hace la función
    printf("Bytes del numero real: ");
    for (int i = 0; i < 4; i++) {
        printf("%02X ", datos.bytesNumero[i]);  // Formato hexadecimal con 2 dígitos
    }
}
