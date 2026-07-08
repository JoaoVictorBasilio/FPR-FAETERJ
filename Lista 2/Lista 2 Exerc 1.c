/*Desenvolver uma função que determine o
número de ocorrências de um número inteiro x
em um vetor A.*/

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

int ocorrecias(int a[10], int x){
    int i, cont = 0;
    for(i = 0; i < 10; i++){
        if(a[i] == x){
            cont++;
        }
    }
    return cont;
}

int main(){
    int a[10];
    int x, contador;
    printf("Digite o valor de x: \n");
    scanf("%d", &x);
    preencherAleatorio(a,10,10);
    exibirVetor(a,10);
    contador = ocorrecias(a,x);
    printf("\nForam encontrar %d Ocorrencias", contador);
    return 0;
}