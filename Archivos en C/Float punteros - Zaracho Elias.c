#include <stdio.h> 
int main()
{
    float var=-15;
    unsigned char *p =(unsigned char*)&var;
    printf("0x%x\n", *p);
    printf("0x%x\n", *(p+1));
    printf("0x%x\n", *(p+2));
    printf("0x%x\n", *(p+3));
    
}