/*Elaborar uma função que, dado um conjunto de
300 valores inteiros, distribua-os em 2 vetores
conforme forem pares ou ímpares.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 300

void PreencherVetorAleatorio(int vet[],int limite){
    int i;
	
	srand (time(NULL));
	
	for (i=0;i<MAX;i++)
	{
		vet[i] = rand()%limite;	
	}	
}

void ExibindoVetor(int vet[],int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        printf(" %d ", vet[i]);
    }
}

void DividindoVetores(int vet[], int vetP[], int vetI[], int *a, int *b){
    int i=0;
    for(i=0;i<MAX;i++){
        if(vet[i]%2==0){
            vetP[*a] = vet[i];
            (*a)++;
        } else {
            vetI[*b] = vet[i];
            (*b)++;
        }
    }
    
}

int main(){
    int vet[MAX];
    int vetP[MAX];
    int vetI[MAX];
    int a=0;
    int b=0;

    PreencherVetorAleatorio(vet,100);
    DividindoVetores(vet,vetP,vetI,&a,&b);
    printf("\nvetor: \n");
    ExibindoVetor(vet,MAX);
    printf("\npares: \n");
    ExibindoVetor(vetP,a);
    printf("\nimpares: \n");
    ExibindoVetor(vetI,b);

    return 0;
}