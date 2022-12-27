#include <stdio.h>
#include "ordenacao.h"
#include <stdlib.h>




int main(){
    int v[5];
    int j = 5;
    for (int i = 0; i < 5; i++)
    {
  
            v[i] = j;

        j--;
    }
    int* a;
    a = malloc(sizeof(int));
    *a = 0;
    selectionSort(v, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
    
    printf("\npos: %d", buscaBinaria(v, 5, 7, a));

    /*for (int i = 0; i < 5; i++)
    {
        printf("\n%d", v[i]);
    }*/

    return 0;
}