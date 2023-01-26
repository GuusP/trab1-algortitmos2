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

void insereVetorAleatorio(int vetor[], int tam){
    for(int i = 0; i < tam; i++)
        vetor[i] = rand() % 50000;
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

void copiarVet(int v1[], int v2[], int tam){
    for (int i = 0; i < tam; i++)
    {
        v1[i] = v2[i];
    }
    
}



void testesSorts(int vetor[], int tamVetor, int vetorAleatorio[]){

    clock_t start, end;//variáveis do tipo clock_t
    double total;

    
    insereVetorDecrescente(vetor, tamVetor);
    printf("\nOs testes a seguir serao realizados num vetor em ordem DECRESCENTE de tam = %d. Segue o vetor: \n", tamVetor);
    imprimeVetor(vetor, tamVetor);

    start = clock();//start recebe o "ciclo" corrente
	int numComp = insertionSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nInsertion Sort (tamVetor: %d, vetor em ordem decrescente): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);

    insereVetorDecrescente(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nSelection Sort (tamVetor: %d, vetor em ordem decrescente): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);        
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);

    insereVetorDecrescente(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nMerge Sort (tamVetor: %d, vetor em ordem decrescente): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);   

    insereVetorDecrescente(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nQuick Sort (tamVetor: %d, vetor em ordem decrescente): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);  

    printf("\n### --------------------------------------------------------------------------------------------------- ###\n");

    insereVetorOrdenado(vetor, tamVetor);
    printf("\nOs testes a seguir serao realizados num vetor ORDENADO de tam = %d. Segue o vetor: \n", tamVetor);
    imprimeVetor(vetor, tamVetor);

    start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nInsertion Sort (tamVetor: %d, vetor ORDENADO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);

    insereVetorOrdenado(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nSelection Sort (tamVetor: %d, vetor ORDENADO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);        
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);

    insereVetorOrdenado(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nMerge Sort (tamVetor: %d, vetor ORDENADO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);   

    insereVetorOrdenado(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nQuick Sort (tamVetor: %d, vetor ORDENADO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor); 
    
    printf("\n### --------------------------------------------------------------------------------------------------- ###\n");

    copiarVet(vetor, vetorAleatorio, tamVetor);
    printf("\nOs testes a seguir serao realizados num vetor com ordem e valores ALEATORIOS de tam = %d. Segue o vetor: \n", tamVetor);
    imprimeVetor(vetor, tamVetor);

    start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nInsertion Sort (tamVetor: %d, vetor ALEATORIO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);

    copiarVet(vetor, vetorAleatorio, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nSelection Sort (tamVetor: %d, vetor ALEATORIO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);        
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);

    copiarVet(vetor, vetorAleatorio, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nMerge Sort (tamVetor: %d, vetor ALEATORIO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);   

    copiarVet(vetor, vetorAleatorio, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nQuick Sort (tamVetor: %d, vetor ALEATORIO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor); 

    printf("\n### --------------------------------------------------------------------------------------------------- ###\n");
}

int main(){
    srand(1);
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	//Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	//Veja um exemplo de alocação dinâmica a seguir
	int tamVetor = 50000;
    int *vetorAleatorio;
    vetorAleatorio = malloc(sizeof(int)*tamVetor);
	int* vetor = malloc(tamVetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	insereVetorOrdenado(vetor, tamVetor);
    insereVetorAleatorio(vetorAleatorio, tamVetor);
    
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
    printf("\n");
    printf("Para cada leva de testes, sera dito qual foi o tamanho considerado do vetor e como ele eh\nApos cada teste da leva, o vetor eh redefinido para o estado inicial passado antes do primeiro teste da atual leva\n");

    for (int i = 10; i <= 10000; i = i * 10)
        testesSorts(vetor, i, vetorAleatorio);

    testesSorts(vetor, 50000, vetorAleatorio);
    
    
    
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
    free(vetorAleatorio);
	return 0;
}
