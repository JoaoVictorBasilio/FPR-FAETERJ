/*Faça uma função que, dado um vetor de reais,
altere todas as ocorrências do número A pelo
número B.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PreencherVetorAleatorio(float vet[], int limite,int tamanho){
    int i;

    srand (time(NULL));

    for(i=0;i<tamanho;i++){
        vet[i] = rand()%limite;
    }
}

void ExibirVetor(float vet[],int tamanho){
    int i;
    printf("\n");
    for(i=0;i<tamanho;i++){
        printf(" %.1f ", vet[i]);
    }
}

void AlterarValores(float vet[],float A,float B,int tamanho){
    for(int i=0;i<tamanho;i++){
        if (vet[i] == A){
            vet[i] = B;
        }
    }
}

int main(){
    float vet[10];
    float A, B;

    PreencherVetorAleatorio(vet,10,10);
    ExibirVetor(vet,10);
    printf("\nEscolha qual número será alterado: ");
    scanf("%f", &A);
    printf("\nEscolha qual valor será colocado no lugar: ");
    scanf("%f", &B);
    AlterarValores(vet,A,B,10);
    ExibirVetor(vet,10);

    return 0;
}