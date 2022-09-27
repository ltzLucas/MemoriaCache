#include <stdio.h>
#include <stdlib.h>
#include "lista_int.h"

//tc : Tempo de acesso à cache                        10
//trd : TEmpo de leitura da DRAM                      200
//twd : Tempo de escrita da DRAM                      300

int main(void) {
    int tempo = 0;
    LISTA_BLOCO * lista = lst_criar();
    int Tamanhobusca;
    printHeader();

    printf("+--------------------------------------------------------+\n");
    printf("|Quantas buscas deseja fazer na memoria ?                |\n");
    printf("+--------------------------------------------------------+\n");    
    scanf("%d",&Tamanhobusca);

    for (int i = 0; i < 4; i++) {
        lista = lst_inserir(lista, i);    
    }
    int dados[4];
    int dadosProximo[4];
    int numeros[4];
    int leitura_escrita[4];

    for (int i = 0; i < Tamanhobusca; i++) {
        int aux;
        int aux1;
        printf("+--------------------------------------------------------+\n");
        printf("| Insira dados para serem acessados na cache:            |\n");
        printf("+--------------------------------------------------------+\n");
        scanf("%d",&aux);
        int ok=0;
        do{
            printf("+----------------------------------------------------------+\n");
            printf("| Para esse dado vc deseja fazer uma leitura ou escrita?   |\n");
            printf("|  [0]Leitura     [1]Escrita                               |\n");
            printf("+----------------------------------------------------------+\n");
            scanf("%d",&aux1);                     // 0 leitura             1 escrita
            if(aux1 == 0 || aux1 == 1){
                ok = 1;
            }
        }while(ok == 0);

        dados[i] = aux;    //DADOS QUE SERAO CONVERTIDOS EM BINARIO
        dadosProximo[i] = aux + 1; // DADOS DOS PROXIMOS NUMEROS
        numeros[i] = aux;  //NUMERO Q O USUARIO DIGITOU
        leitura_escrita[i] = aux1;  
    }

    for (int i = 0; i < Tamanhobusca; i++) {
        dados[i] = ConverterToBinary(dados[i]);
        dadosProximo[i] = ConverterToBinary(dadosProximo[i]);

    }

    for (int i = 0; i < Tamanhobusca; i++) {
        int contador = 0;
        int offSet = getOffSet(numeros[i]);

        int indice = getIndice(numeros[i]);

        int tag = getTag(numeros[i]);

        printf("Numero De entrada:%d \n",numeros[i]);
        printf ("OffSet: %d   Indice: %d    Tag: %d\n\n",offSet,indice,tag);
        
        printf("+--------------------------+\n");
        printf("|           Antes          |\n");
        printf("+--------------------------+\n");


        lst_imprimir(lista);
        contador = lst_buscar(lista,indice,tag,dados[i],dadosProximo[i],leitura_escrita[i]);
        tempo = tempo + contador;
        system("pause");
        system("cls");
        printf("+--------------------------+\n");
        printf("|          DEPOIS          |\n");
        printf("+--------------------------+\n");
        lst_imprimir(lista);
        system("pause");
        system("cls");
    }
    printf("+--------------------------------------------------------+\n");
    printf("|   O tempo total foi de: %d                             |\n",tempo);
    printf("+--------------------------------------------------------+\n");

    lst_liberar(lista);
    return EXIT_SUCCESS;
}