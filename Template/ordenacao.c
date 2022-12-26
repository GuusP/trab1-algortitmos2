#include "ordenacao.h"

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

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	*numComparacoes = 99;
	return -1;
}

int insertionSort(int vetor[], int tam){	
	vetor[0] = 99;
	return -1;
}

int selectionSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

int mergeSort(int vetor[], int tam){
	vetor[0] = 99;
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