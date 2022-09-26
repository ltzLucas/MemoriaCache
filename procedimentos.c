#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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