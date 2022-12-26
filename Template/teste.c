#include <stdio.h>
#include "ordenacao.h"
#include <stdlib.h>
int main(){
    int v[5];

    for (int i = 0; i < 5; i++)
    {
        v[i] = i+1;
    }
    int* a;
    a = malloc(sizeof(int));
    *a = 0;
    printf("%d", buscaSequencial(v, 5, 10, a));
    printf("\n%d", *a);

    return 0;
}