#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void){

    struct Bloco{
    int indice;
    int valido;
    int tag;
    int dados;
};

    struct Bloco b1;
   
   int tamanhoCache = 8;
   int tamanhoBloco = 2;
   int assosiavidade = 2;
   int bitsOffSet = 1;
   int bitsIndice = 1;

   int cache[2][2] = 0;

    
    
    int acess;
    printf("Digite um valor: ");
    scanf("%d", &acess);

    acess = ConverterToBinary(acess);
    printf("%d", acess);

    return 0;








}