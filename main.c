#include <stdio.h>
#include <stdlib.h>
#include "lista_int.h"




int main(int nargs, char ** args) {
    LISTA_BLOCO * lista = lst_criar();
    int n;
    for (int i = 0; i < 4; i++) {
        lista = lst_inserir(lista, i);    
    }
    int dados[4];
    int dadosProximo[4];
    int numeros[4];

    for (int i = 0; i < 4; i++) {
        int aux;
        printf("\nInsira dados para serem acessados na cache\n");
        scanf("%d",&aux);
        dados[i] = aux;
        dadosProximo[i] = aux + 1;
        numeros[i] = aux;
    }

    for (int i = 0; i < 4; i++) {
        dados[i] = ConverterToBinary(dados[i]);
        dadosProximo[i] = ConverterToBinary(dadosProximo[i]);

    }

    for (int i = 0; i < 4; i++) {

        int offSet = getOffSet(numeros[i]);
        int indice = getIndice(numeros[i]);
        int tag = getTag(numeros[i]);
        printf("Numero De entrada:%d \n",numeros[i]);
        printf ("OffSet: %d   Indice: %d    Tag: %d\n\n",offSet,indice,tag,dados[i]);
        printf("-----------ANTES------------\n\n");
        lst_imprimir(lista);
        lst_buscar(lista,indice,offSet,tag,dados[i],dadosProximo[i]);
        system("pause");
        printf("-----------DEPOIS------------\n\n");
        lst_imprimir(lista);
        system("pause");
    }
    lst_liberar(lista);
    return EXIT_SUCCESS;
}