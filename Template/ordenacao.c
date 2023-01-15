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


    if(indice >= 0)
        *numComparacoes += 1;
        if(vetor[indice] == valor)
            return indice;
    

	return -1;
}


//Comparações: log(base 2) de N + 2 (pior caso) [quando vai para o maior lado]
// log(base 2) de N + 1 qnd vai para o menor lado e o elemento está
//Melhor caso: log(base 2) de N qnd vai para o menor lado e o elemento não está
int buscaBinariaAux(int vetor[], int a, int b, int valor, int* numComparacoes){
    if(a > b)
        return a - 1;
        
    int meio = (a + b) / 2;

    *numComparacoes += 1;
    if(valor < vetor[meio])
        return buscaBinariaAux(vetor, a, meio - 1, valor, numComparacoes);

    return buscaBinariaAux(vetor, meio + 1, b, valor, numComparacoes);       
}

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
    int u[b - a + 1];
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
int mergeSort(int vetor[], int tam){
    int comparacoes = 0;

	mergeSortAux(vetor, 0, tam - 1, &comparacoes);
	return comparacoes;
}

int quickSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

int heapSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}