#include "ordenacao.h"
#include <math.h>
#include <string.h>

void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Gustavo Vinicius Paulino", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
	return 20220067;
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
    if(tam <= 0)
        return -1;
    
    int i = tam - 1;

    *numComparacoes += 1;
    if(valor == vetor[i])
        return i;

    return buscaSequencial(vetor, tam - 1, valor, numComparacoes);

	return -1;
}


//TODO: número de comparações BuscaBinaria
int buscaBinariaAux(int vetor[], int a, int b, int valor, int* numComparacoes){
    if(a > b)
        return -1;

    int meio = (a + b) / 2;
    if(valor == vetor[meio])
        return meio;

    if(valor < vetor[meio])
        return buscaBinariaAux(vetor, a, meio - 1, valor, numComparacoes);

    return buscaBinariaAux(vetor, meio + 1, b, valor, numComparacoes);       
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
    
	*numComparacoes = 99;
	return buscaBinariaAux(vetor, 0, tam - 1, valor, numComparacoes);
}

int buscaInsertionSort(int vetor[], int tam, int valor){
    if(tam <= 0)
        return 0;

    int i = tam - 1;
    if(valor >= vetor[i])
        return i + 1;

    return buscaInsertionSort(vetor, tam - 1, valor);
}

void trocar(int a, int b, int vetor[]){
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

int* inserir(int vetor[], int tam){
    int p = buscaInsertionSort(vetor, tam - 1, vetor[tam - 1]);
    
    for (int i = tam - 1; i > p; i--)
        trocar(i, i - 1, vetor);
    
    return vetor;
}

//TODO: Comparações insertionSort
int insertionSort(int vetor[], int tam){	
	if(tam <= 1)
        return 0;

    insertionSort(vetor, tam - 1);
    inserir(vetor, tam);
    return 1;
}

//TODO: Comparaões selectionSort
int minimo(int vetor[], int a, int b){
    if(a >= b)
        return a;
    
    int menor = minimo(vetor, a, b - 1);

    if(vetor[b] < vetor[menor])
        menor = b;

    return menor;
    
}

int selectionSortAux(int vetor[], int a, int b){
    if(a >= b)
        return 0;

    trocar(a, minimo(vetor, a, b), vetor);
    return selectionSortAux(vetor, a + 1, b);
}

int selectionSort(int vetor[], int tam){
	selectionSortAux(vetor, 0, tam - 1);
}

void copiar(int v[], int u[], int a, int b){
    for (int i = 0; i <= b - a; i++)
    {
        v[a+i] = u[i];
    }
    
}

int merge(int vetor[], int a, int m, int b){
    if(a >= b)
        return 0;

    int i = a;
    int j = m + 1;
    int u[b - a + 1];
    int p;
    for (int k = 0; k <= b - a; k++)
    {
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
}

//TODO: Comparações Merge Sort.
int mergeSortAux(int vetor[], int a, int b){
    if(a >= b)
        return 0;
    
    int m = (a + b)/2;

    mergeSortAux(vetor, a, m);
    mergeSortAux(vetor, m + 1, b);
    merge(vetor, a, m, b);
}

int mergeSort(int vetor[], int tam){
	mergeSortAux(vetor, 0, tam - 1);
	return -1;
}

int quickSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

int heapSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}