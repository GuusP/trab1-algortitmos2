#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

void insereVetorOrdenado(int vetor[], int tam){
    for(int i = 0; i < tam; i++)
        vetor[i] = i + 1;
    
}

void insereVetorDecrescente(int vetor[], int tam){
    int j = tam;
    for(int i = 0; i < tam; i++){
        vetor[i] = j;
        j--;
    }
}

void imprimeVetor(int vetor[], int tamVetor){
    for(int i=0; i < tamVetor; i++){
        if( i < 10 || tamVetor - i < 11)
		    printf("%d ", vetor[i]);

        if(i == 10 && tamVetor - i >= 11)
            printf("... ");
	}

    printf("\n");
}

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp = 0;

	//Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	//Veja um exemplo de alocação dinâmica a seguir
	int tamVetor = 50000;
	int* vetor = malloc(tamVetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	//Depois de alocado, o vetor pode ser utilizado normalmente
	//Não esqueça de desalocar no final do programa via free
		
	insereVetorOrdenado(vetor, tamVetor);

    
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
    printf("\n");
    printf("Para cada leva de testes, sera dito qual foi o tamanho considerado do vetor e como ele eh\nApos cada teste da leva, o vetor eh redefinido para o estado inicial passado antes do primeiro teste da atual leva\n\n");

	//Para medir o tempo, inclua time.h, e siga o exemplo:
	clock_t start, end;//variáveis do tipo clock_t
    double total;
    insereVetorDecrescente(vetor, tamVetor);
    printf("Os testes a seguir serao realizados num vetor em ordem decrescente. Segue o vetor: \n");
    imprimeVetor(vetor, tamVetor);

    start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, 10);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nInsertion Sort (tamVetor: 10, vetor em ordem decrescente): \nComparacoes = %d, Tempo = %f\n", numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, 10);

    insereVetorDecrescente(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, 10);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nSelection Sort (tamVetor: 10, vetor em ordem decrescente): \nComparacoes = %d, Tempo = %f\n", numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, 10);

    insereVetorDecrescente(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, 10);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nMerge Sort (tamVetor: 10, vetor em ordem decrescente): \nComparacoes = %d, Tempo = %f\n", numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, 10);
    
	//o tempo total é a diferença dividia pelos ciclos por segundo
	/*total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f", total);

	numComp = selectionSort(vetor, 3);
	numComp = mergeSort(vetor, 3);
	numComp = quickSort(vetor, 3);*/

	
	//idxBusca = buscaBinaria(vetor, tamVetor, 9999, &numComp);
    //printf("\n%d %d", idxBusca, numComp);
	//idxBusca = buscaBinaria(vetor, 3, 10, &numComp);

	
	

	//É obrigatório que você libere a memória alocada dinâmicamente via fee
	free(vetor);

	return 0;
}
