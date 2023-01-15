#include <stdio.h>
#include "ordenacao.h"
#include <stdlib.h>




int main(){ 
    int tamVetor = 10;
    int v[tamVetor];
    int j = tamVetor;
   
    for (int i = 0; i < tamVetor; i++)
    {
            v[i] = j;
            j--;
    }
    int* a;
    a = malloc(sizeof(int));
    *a = 0;

    for (int i = 0; i < tamVetor; i++)
    {
        printf("%d ", v[i]);
    }

    printf("comparacoes: %d\n", mergeSort(v, tamVetor)); 
    for (int i = 0; i < tamVetor; i++)
    {
        printf("%d ", v[i]);
    }
    
    return 0;
}