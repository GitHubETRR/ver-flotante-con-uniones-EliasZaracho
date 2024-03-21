#include <stdio.h> 

union valores{
    float var;
    unsigned char varBytes[4];
};

int main()
{
 union valores numeros;
 printf("Ingrese un numero:\n ");
 scanf("%f",&numeros.var);
 for(int i=0; i<4; i++){
     printf("%x\n", numeros.varBytes[i]);
 }
    return 0;
}
