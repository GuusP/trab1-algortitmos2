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
        v1[i] = v2[i];

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

    insereVetorDecrescente(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = heapSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nHeap Sort (tamVetor: %d, vetor em ordem decrescente): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
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

    insereVetorOrdenado(vetor, tamVetor);
    start = clock();//start recebe o "ciclo" corrente
	numComp = heapSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nHeap Sort (tamVetor: %d, vetor ORDENADO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
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
    start = clock();
	numComp = mergeSort(vetor, tamVetor);
	end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nMerge Sort (tamVetor: %d, vetor ALEATORIO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor);   

    copiarVet(vetor, vetorAleatorio, tamVetor);
    start = clock();
	numComp = quickSort(vetor, tamVetor);
	end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nQuick Sort (tamVetor: %d, vetor ALEATORIO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor); 

    copiarVet(vetor, vetorAleatorio, tamVetor);
    start = clock();
	numComp = heapSort(vetor, tamVetor);
	end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nHeap Sort (tamVetor: %d, vetor ALEATORIO): \nComparacoes = %d, Tempo = %f\n", tamVetor, numComp, total);
    printf("Vetor resultante: ");
    imprimeVetor(vetor, tamVetor); 

    printf("\n### --------------------------------------------------------------------------------------------------- ###\n");
}

void testesBuscas(int vetor[], int tamVetor, int elemento){
    int numComp = 0;
    int idxBusca;

    clock_t start, end;//variáveis do tipo clock_t
    double total;

    printf("\nTamanho vetor: %d - Elemento procurado: %d", tamVetor, elemento);
    start = clock();
    idxBusca = buscaBinaria(vetor, tamVetor, elemento, &numComp);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nBusca Binaria - Comparacoes = %d - Total = %f", numComp, total);
    numComp = 0;
    start = clock();
    buscaSequencial(vetor, tamVetor, elemento, &numComp);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nBusca Sequencial - Comparacoes = %d - Total = %f", numComp, total);
    printf("\nO elemento esta na posicao: %d\n\n", idxBusca);
}

int main(){
    srand(1);
	char nome[MAX_CHAR_NOME];
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

    for (int i = 10; i <= 10000; i = i * 10){
        insereVetorAleatorio(vetorAleatorio, i);
        testesSorts(vetor, i, vetorAleatorio);
    }
        
    insereVetorAleatorio(vetorAleatorio, 50000);
    testesSorts(vetor, 50000, vetorAleatorio);

    printf("\n\n----- TESTES DE BUSCA -----");
    printf("\n----- Nos testes a seguir, os elementos estao ordenados e os seus valores pertencem ao intervalo [1..TamVetor] onde nenhum elemento eh repetido ------");
    
    insereVetorOrdenado(vetor, 50000);
    for(int i = 10; i <= 10000; i = i * 10){
        testesBuscas(vetor, i, vetor[i - 1]);
        testesBuscas(vetor, i, vetor[0]);
        testesBuscas(vetor, i, vetor[i/2]);
    }
        
    testesBuscas(vetor, 50000, vetor[50000 - 1]);
    testesBuscas(vetor, 50000, vetor[0]);
    testesBuscas(vetor, 50000, vetor[25000]);

    testesBuscas(vetor, 50000, -1);
    testesBuscas(vetor, 50000, 100000);

    printf("\n\n------- Nos testes a seguir, o vetor eh aleatorio com valores entre [0..49999] e pode haver valores repetidos --------\n\n");
    for (int i = 0; i < 20; i++)
    {
        insereVetorAleatorio(vetor, 50000);
        mergeSort(vetor, 50000);
        testesBuscas(vetor, 50000, rand() % 60000);
    }
    

	free(vetor);
    free(vetorAleatorio);
	return 0;
}
