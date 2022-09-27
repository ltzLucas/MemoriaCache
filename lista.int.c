#include <stdlib.h>
#include <stdio.h>
#include "lista_int.h"

LISTA_BLOCO * lst_criar(void) {
    return (LISTA_BLOCO *) NULL;
}

LISTA_BLOCO * lst_inserir(LISTA_BLOCO * lista, int dados) {
    LISTA_BLOCO * nodo = (LISTA_BLOCO *) malloc(sizeof(LISTA_BLOCO));
    nodo->dado1 = 0;
    nodo->dado2 = 0;
    nodo->tag = 0;
    nodo->valido = 0;
    nodo->id = dados;
    if (dados % 2 == 0) {
        nodo->indice = 0;
    }else{
        nodo->indice = 1;
    }
    nodo->ptr_proximo = lista;
    return nodo;
}

void lst_imprimir(LISTA_BLOCO * lista) {
    LISTA_BLOCO * nodo = lista;
        printf("\n------------Cache-----------\n");
    while (nodo != NULL) {
        printf("|--------------------------\n");
        printf("|                          ");
        printf("\n|Indice: %d                 ", nodo->indice);
        printf("\n|Valido: %d                 ", nodo->valido);
        printf("\n|Tag: %d                    ", nodo->tag);
        printf("\n|Dados: %d  %d         ", nodo->dado1,nodo->dado2);
        printf("\n|                          \n");
        nodo = nodo->ptr_proximo;
    }
}

void lst_liberar(LISTA_BLOCO * lista) {
    LISTA_BLOCO * nodo = lista, * aux;
    while (nodo != NULL) {
        aux = nodo->ptr_proximo;
        free(nodo);
        nodo = aux;
    }
}

int lst_buscar(LISTA_BLOCO * lista, int indice,int offset,int tag,int dado,int dadoProximo,int leitura_escrita) {
    LISTA_BLOCO * nodo = lista;

    while (nodo != NULL) {
        if (nodo->indice == indice) { // achou em qual indice procura
            if (nodo->tag == tag && nodo->dado1 == dado || nodo->dado2 == dado) {
                printf("\n|-------|\n");
                printf("|  HIT  | \n");
                printf("|-------|\n");
                return calculaTempo(leitura_escrita, 0);
            }
            if (nodo->valido == 0) {
                printf("\n|----------|\n");
                printf("|   MISS   | \n");
                printf("|----------|\n");
                nodo->valido = 1;
                nodo->tag = tag;
                nodo->dado1 = dado;
                nodo->dado2 = dadoProximo;
                nodo->tempoNaCache = 1;
                atribuir_zero(lista,nodo->id);
                return calculaTempo(leitura_escrita, 1);
            }
            if (nodo->valido == 1 && nodo->tempoNaCache == 0) {

                printf("\n|----------|\n");
                printf("|   SUBS   | \n");
                printf("|----------|\n");
                nodo->valido = 1;
                nodo->tag = tag;
                nodo->dado1 = dado;
                nodo->dado2 = dadoProximo;
                nodo->tempoNaCache = 1;
                atribuir_zero(lista,nodo->id);
                return calculaTempo(leitura_escrita, 1);;
            }
        }
        nodo = nodo->ptr_proximo;
    }
    return NULL;
}

LISTA_BLOCO * atribuir_zero(LISTA_BLOCO * lista,int id) {
    LISTA_BLOCO * nodo = lista;

    while (nodo != NULL) {
        if (nodo->id != id && nodo->indice == 1) {
            nodo->tempoNaCache = 0;
            //printf("\nLista: %d esta com o temponaCache em: %d \n",nodo->id,nodo->tempoNaCache);
        }
        if (nodo->id != id && nodo->indice == 0) {
            nodo->tempoNaCache = 0;
            //printf("\nLista: %d esta com o temponaCache em: %d \n",nodo->id,nodo->tempoNaCache);
        }

        nodo = nodo->ptr_proximo;
    }
    return NULL;

}

int ConverterToBinary (int n){
    int bin=0;
    int i, j=1;
    
    while (n != 0){
        i = n % 2;
        bin = bin + (i*j);
        n = n/2;
        j = j*10;
        i = n % 2;
    }    
    return bin;
}

int getOffSet(int n) {
    if(n &(1<<0)){
        return 1;
    }
    return 0;
}
int getIndice(int n){
    if (n &(1<<1)) {
        return 1;
    }
    return 0;    
}
int getTag(int n){
    int tag1,tag2,tag3,tag4;
    int concatenacao;
    
    if (n &(1<<2)){
        tag1 = 1;
    }else{
        tag1 = 0; 
    }

    if (n &(1<<3)){
        tag2 = 1;
    }else{
        tag2 = 0; 
    }

    if (n &(1<<4)){
        tag3 = 1;
    }else{
        tag3 = 0; 
    }

    if (n &(1<<5)){
        tag4 = 1;
    }else{
        tag4 = 0; 
    }
    
    concatenacao = (tag4*10 + tag3);
    concatenacao = (concatenacao * 10) + tag2;
    return concatenacao = (concatenacao * 10) + tag1;
}

int calculaTempo(int leitura_escrita,int x){
    if (x == 0) {          // SE X == 0 faz o  calculo de HIT
        return 10;         
    } else if(x == 1) {    // SE X == 1 faz o calcula de MISS

        if (leitura_escrita == 0 ) {    // 0 significa LEITURA
            return 10 + 20;
        }else {                         // ESCRITA
            return 10 + 20 + 30;
        }
    }
}


