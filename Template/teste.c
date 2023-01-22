#include <stdio.h>
#include "ordenacao.h"
#include <stdlib.h>
#include <time.h>



int main(){ 
    int tamVetor = 50000;
    int v[tamVetor];
    int j = tamVetor;
    clock_t start, end;//variáveis do tipo clock_t
    double total;

	
	
    for (int i = 0; i < tamVetor; i++)
    {
            v[i] = j;
            j--;
    }
    int* a;
    a = malloc(sizeof(int));
    *a = 0;

    /*for (int i = 0; i < tamVetor; i++)
    {
        printf("%d ", v[i]);
    }*/
    start = clock();//start recebe o "ciclo" corrente
    printf("comparacoes: %d\n", selectionSort(v, tamVetor)); 
    end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("total iSort: %f\n", total);

    start = clock();
    printf("comparacoes: %d\n", mergeSort(v, tamVetor)); 
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("total mSort: %f\n", total);

    /*for (int i = 0; i < tamVetor; i++)
    {
        printf("%d ", v[i]);
    }*/
    
    return 0;
}