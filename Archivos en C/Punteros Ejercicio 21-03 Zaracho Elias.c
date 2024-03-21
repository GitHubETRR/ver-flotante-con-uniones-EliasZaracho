int main()
{
    char var=2;
    char * var_ptr=&var;
    
    printf("el valor de var es: %d\n" ,var);
    printf("la dirección de var es: %d\n" ,&var);
    printf("la dirección del puntero es: %d\n" ,var_ptr);
}