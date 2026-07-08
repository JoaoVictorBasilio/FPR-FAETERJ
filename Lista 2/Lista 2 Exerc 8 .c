/*Dados um vetor de reais (cujos elementos
estão ordenados crescentemente) e um
número x, retornar a posição da primeira
ocorrência de x (caso encontre-se no vetor) ou
a posição na qual deveria estar (caso contrário).*/

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

int main(){
    float vet[10];
    float x;
    int pos;
    preencherAleatorioOrdenado(vet,10);
    ExibirVetor(vet,10);
    printf("\nDigite um valor: ");
    scanf("%f", &x);
    pos = Dashikawa(vet,x,10);
    if(achou == 0){
        printf("\nA posição que o número deveria estar é: %d.", pos);
    } else {
        printf("\nO número foi encontrado na posição: %d.",pos);
    }
    return 0;
}