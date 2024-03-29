#include "ordenacao.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Gustavo Vinicius Paulino", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
	return 20220067;
}

//Retorna a posição que o elemento VALOR deve ser inserido no vetor
// realiza N comparações
int buscaSequencialAux(int vetor[], int a, int b, int valor, int *numComparacoes){
    if(a > b)
        return a - 1;

    *numComparacoes += 1;
    if(valor >= vetor[b])
        return b;

    return buscaSequencialAux(vetor, a, b - 1, valor, numComparacoes);
}


int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
    int indice = buscaSequencialAux(vetor, 0, tam - 1, valor, numComparacoes);


    if(indice >= 0){
        *numComparacoes += 1;
        if(vetor[indice] == valor)
            return indice;
    }
        
    

	return -1;
}



int buscaBinariaAux(int vetor[], int a, int b, int valor, int* numComparacoes){
    if(a > b)
        return a - 1;
        
    int meio = (a + b) / 2;

    *numComparacoes += 1;
    if(valor < vetor[meio])
        return buscaBinariaAux(vetor, a, meio - 1, valor, numComparacoes);

    return buscaBinariaAux(vetor, meio + 1, b, valor, numComparacoes);       
}

//Comparações: log(base 2) de N + 2 (pior caso) [quando vai para o maior lado]
// log(base 2) de N + 1 qnd vai para o menor lado e o elemento está
//Melhor caso: log(base 2) de N qnd vai para o menor lado e o elemento não está
int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
    int indice = buscaBinariaAux(vetor, 0, tam - 1, valor, numComparacoes);

	if(indice >= 0){
        *numComparacoes += 1;
        if(vetor[indice] == valor)
            return indice;
    }

    return -1;
}

void trocar(int a, int b, int vetor[]){
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

void inserir(int vetor[], int tam, int *numComparacoes){
    int p = buscaSequencialAux(vetor, 0, tam - 2, vetor[tam - 1], numComparacoes);
    
    for (int i = tam - 1; i > p + 1; i--)
        trocar(i, i - 1, vetor);
    
    return;
}

void insertionSortAux(int vetor[], int tam, int *numComparacoes){	
	if(tam <= 1)
        return;

    insertionSortAux(vetor, tam - 1, numComparacoes);
    inserir(vetor, tam, numComparacoes);
    return;
}

//Comparações: (n^2 - n) / 2
//Trocas: 0 se o vetor ja estiver ordenado e (n^2 - n)/2 se o vetor estiver em ordem decrescente (pior caso)
// quando mais próximo da posição correta o elemento está, menor é o nmr de trocas
int insertionSort(int vetor[], int tam){
    int comparacoes = 0;

    insertionSortAux(vetor, tam, &comparacoes);

    return comparacoes;
}


int minimo(int vetor[], int a, int b, int *numComparacoes){
    if(a >= b)
        return a;
    
    int menor = minimo(vetor, a, b - 1, numComparacoes);

    *numComparacoes += 1;
    if(vetor[b] < vetor[menor])
        menor = b;

    return menor;
    
}

void selectionSortAux(int vetor[], int a, int b, int *numComparacoes){
    if(a >= b)
        return;

    trocar(a, minimo(vetor, a, b, numComparacoes), vetor);
    selectionSortAux(vetor, a + 1, b, numComparacoes);
}

// Comparações: (n^2 - n) / 2
// Trocas: n - 1
int selectionSort(int vetor[], int tam){
    int comparacoes= 0;

	selectionSortAux(vetor, 0, tam - 1, &comparacoes);

    return comparacoes;
}

void copiar(int v[], int u[], int a, int b){
    for (int i = 0; i <= b - a; i++)
    {
        v[a+i] = u[i];
    }
    
}

void merge(int vetor[], int a, int m, int b, int *numComparacoes){
    if(a >= b)
        return;

    int i = a;
    int j = m + 1;
    int *u;
    u = malloc(sizeof(int)*(b - a + 1));
    int p;
    for (int k = 0; k <= b - a; k++)
    {
        *numComparacoes += 1;
        if(j > b || (i <= m && vetor[i] < vetor[j])){
            p = i;
            i++;
        }else{
            p = j;
            j++;
        }

        u[k] = vetor[p];
    }
    copiar(vetor, u, a, b);
    free(u);
}

void mergeSortAux(int vetor[], int a, int b, int *numComparacoes){
    if(a >= b)
        return;
    
    int m = (a + b)/2;

    mergeSortAux(vetor, a, m, numComparacoes);
    mergeSortAux(vetor, m + 1, b, numComparacoes);
    merge(vetor, a, m, b, numComparacoes);
}

//comparações: nlogn 
//merges: n - 1
//memória: n + nlog(n)
int mergeSort(int vetor[], int tam){
    int comparacoes = 0;

	mergeSortAux(vetor, 0, tam - 1, &comparacoes);
	return comparacoes;
}

int particiona(int vetor[], int a, int b, int *numComparacoes){
    int pivo = vetor[b];
    int m = a;

    for(int i = a; i <= b - 1; i++){
        *numComparacoes += 1;
        if(vetor[i] <= pivo){
            trocar( m, i, vetor);
            m++;
        }
    }

    trocar(m, b, vetor);

    return m;
}

void quickSortAux(int vetor[], int a, int b, int *numComparacoes){
    if(a >= b)
        return;

	int m = particiona(vetor, a, b, numComparacoes);

    quickSortAux(vetor, a, m - 1, numComparacoes);
    quickSortAux(vetor, m + 1, b, numComparacoes);
}

//pior caso: (n^2+n - 2)/2
//melhor caso e caso médio: nlogn
int quickSort(int vetor[], int tam){
    int comparacoes = 0;

	quickSortAux(vetor, 0, tam - 1, &comparacoes);
	return comparacoes;
}

int indiceFilhoEsquerdo(int i){
    return (i << 1) + 1;
}

int indiceFilhoDireito(int i){
    return (i << 1) + 2;
}

int maxHeapify(int heap[], int i, int n){
    int l = indiceFilhoEsquerdo(i);
    int r = indiceFilhoDireito(i);
    int maior;
    int comparacoes = 0;

    maior = i;
    if(l < n){
        comparacoes += 1;
        if(heap[l] > heap[i])
            maior = l;
    }

    if(r < n){
        comparacoes += 1;
        if(heap[r] > heap[maior])
        maior = r;
    }

    if(maior != i){
        trocar(i, maior, heap);
        return comparacoes + maxHeapify(heap, maior, n);
    }

    return comparacoes;
}

int construirMaxHeap(int vetor[], int n){
    int comparacoes = 0;
    for(int i = n / 2 - 1; i >= 0; i--){
        comparacoes += maxHeapify(vetor, i, n);
    }
     return comparacoes;   
}

//pior caso: n + 2nlogn
int heapSort(int v[], int n){
    int comparacoes = 0;
    comparacoes += construirMaxHeap(v, n);
    
    for (int i = n - 1; i >= 1; i--)
    {
        trocar( i, 0, v);
        comparacoes += maxHeapify(v, 0, i);
    }
    
    return comparacoes;
}
