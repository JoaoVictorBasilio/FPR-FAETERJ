/*Implementar uma função que, dado um vetor
de reais, troque o primeiro e o segundo elementos, em
seguida o terceiro e o quarto elementos e assim
sucessivamente, até se chegar ao final do vetor.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherAleatorio (int vetor[], int tamanho, int limite)
{
	int i;
	
	srand (time(NULL));
	
	for (i=0;i<tamanho;i++)
	{
		vetor[i] = rand()%limite;	
	}	
}

void exibirVetor (int vetor[], int tamanho)
{
	int i;
		
	printf ("\n\nElementos do vetor: ");
	for (i=0;i<tamanho;i++)
	{
		printf ("%d ", vetor[i]);	
	}		
	
	printf ("\n\n");
}

void trocatroca(int tamanho, int vetor[]){
    int i = 0, aux;
    for(i=0; i+1<tamanho; i += 2){
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
    }
}
int main(){
    int tamanho = 10;
    int vet[tamanho];
    preencherAleatorio(vet, tamanho, 10);
    exibirVetor(vet, tamanho);
    trocatroca(tamanho,vet);
    exibirVetor(vet,tamanho);

    return 0;
}