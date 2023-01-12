#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

void insereVetor(int vetor[], int tam){
    for(int i = 0; i < tam; i++)
        vetor[i] = i + 1;
    
}

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp = 0;

	//Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	//Veja um exemplo de alocação dinâmica a seguir
	int tamVetor = 10000;
	int* vetor = malloc(tamVetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	//Depois de alocado, o vetor pode ser utilizado normalmente
	//Não esqueça de desalocar no final do programa via free
		
	insereVetor(vetor, tamVetor);

    /*
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
    */

	//Para medir o tempo, inclua time.h, e siga o exemplo:
	clock_t start, end;//variáveis do tipo clock_t
    double total;

	start = clock();//start recebe o "ciclo" corrente
	//numComp = insertionSort(vetor, 3);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	/*total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f", total);

	numComp = selectionSort(vetor, 3);
	numComp = mergeSort(vetor, 3);
	numComp = quickSort(vetor, 3);*/

	for(int i=0; i < tamVetor; i++){
        if( i < 10 || tamVetor - i < 11)
		    printf("%d ", vetor[i]);

        if(i == 10)
            printf("... ");
	}
	idxBusca = buscaBinaria(vetor, tamVetor, 9999, &numComp);
    printf("\n%d %d", idxBusca, numComp);
	//idxBusca = buscaBinaria(vetor, 3, 10, &numComp);

	
	printf("\n");

	//É obrigatório que você libere a memória alocada dinâmicamente via fee
	free(vetor);

	return 0;
}
