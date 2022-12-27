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
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
    
    mergeSort(v, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("\n%d", v[i]);
    }

    return 0;
}