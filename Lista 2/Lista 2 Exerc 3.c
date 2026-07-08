/*Pede-se a implementação de uma função que,
dado um vetor contendo números reais,
determine se o mesmo encontra-se ordenado
de forma crescente.*/

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

int ordenado(int vetor[], int tamanho){
    int i=0;
    for(i=0;i<tamanho;i++){
        if(vetor[i]>vetor[i +1]){
            printf("O vetor não está ordenado");
            return 0;
        }
    }
    printf("O vetor está ordenado");
    return 1;
}

int main(){
    int tamanho = 10;
    float vet[tamanho];
    preencherAleatorio(vet[], tamanho, 10);
    exibirVetor(vet[], tamanho);
}