/*Implementar a função de inserção de
determinado elemento em um vetor ordenado
crescentemente (dica: utilizar a função do item
08 para auxiliar).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherAleatorioOrdenado (float vetor[], int tamanho){
	int i;
	
	srand (time(NULL));
	
	vetor[0] = rand()%10;
	
	for (i=1;i<tamanho;i++)
	{
		vetor[i] = vetor[i-1] + rand()%5;
	}	
}

void ExibirVetor(float vet[],int tamanho){
    int i;
    printf("\n");
    for(i=0;i<tamanho;i++){
        printf(" %.1f ", vet[i]);
    }
}

int Dashikawa(float vet[],float x,int tamanho){
    int i;

    for(i=0;i<tamanho;i++){
        if(vet[i] == x){
            return i+1;
        }
        if (vet[i] > x){
            return i+1;
        }
        
    }
    return 0;
}

void inserir(float vet[], float x, int tamanho, int pos){
    int i,aux;
    for(i=pos;i<tamanho;i++){
        aux = vet[i];
        vet[i]
    }
}

int main(){
    float vet[10];
    float x;
    int pos;
    preencherAleatorioOrdenado(vet,10);
    ExibirVetor(vet,10);
    printf("\nDigite um valor: ");
    scanf("%f", &x);
    pos = Dashikawa(vet,x,10);
    return 0;
}