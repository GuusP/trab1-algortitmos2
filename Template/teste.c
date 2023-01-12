#include <stdio.h>
#include "ordenacao.h"
#include <stdlib.h>




int main(){
    int v[10];
    int j = 5;
    for (int i = 0; i < 10; i++)
    {
            v[i] = j;
            j--;
    }
    int* a;
    a = malloc(sizeof(int));
    *a = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", v[i]);
    }

    insertionSort(v, 10);
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", v[i]);
    }
    
    return 0;
}