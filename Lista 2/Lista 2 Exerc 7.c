/*Desenvolver uma função que remova
determinado elemento (todas as suas
ocorrências) de um vetor de float. Ao final,
retornar o número de remoções realizadas.*/

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

int Remover(float vet[],int *tamanho,float n){
    int i,cont=0;
    for(i=0;i<*tamanho;i++){
        if(vet[i] == n){
            for(int j=i;j<*tamanho;j++){
                vet[j] = vet[j+1];
            }
            cont++;
            i--;
        }
    }
    *tamanho = *tamanho - cont;
    return cont;
}

int main(){
    int tamanho=10,ocorrencias;
    float n;
    float vet[tamanho];
    PreencherVetorAleatorio(vet,10,tamanho);
    ExibirVetor(vet,10);
    printf("\nDigite qual número quer remover: ");
    scanf("%f", &n);
    ocorrencias = Remover(vet,&tamanho,n);
    ExibirVetor(vet,tamanho);
    printf("\nNúmero de remoções foi %d", ocorrencias);
    return 0;
}