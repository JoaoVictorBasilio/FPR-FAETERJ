/*Considere a existência de dois conjuntos
numéricos A e B contendo n1 e n2 elementos,
respectivamente. Pede-se o desenvolvimento
de uma função que determine se um dos
conjuntos está contido no outro, retornando os
seguintes códigos:
 1, se A estiver contido em B;
 2, se B estiver contido em A;
 0, caso contrário.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ValorAleatorio(int limite){
    int a;
    a = rand()%limite+1;
    return a;
}

void PreencherAleatorio(int vetor[],int limite,int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        vetor[i] = rand()%limite;
    }
}

void ExibirMatriz(int vetor[],int tamanho){
    printf("\n");
    int i;
    for(i=0;i<tamanho;i++){
        printf(" %d ",vetor[i]);
    }
}

int Contida(int vet1[], int vet2[], int t1, int t2){
    int i, j, achou;
    int AemB = 1;
    int BemA = 1;

    // Verifica se A está contido em B
    for(i = 0; i < t1; i++){
        achou = 0;
        for(j = 0; j < t2; j++){
            if(vet1[i] == vet2[j]){
                achou = 1;
                break;
            }
        }
        if(achou == 0){
            AemB = 0;
            break;
        }
    }

    // Verifica se B está contido em A
    for(i = 0; i < t2; i++){
        achou = 0;
        for(j = 0; j < t1; j++){
            if(vet2[i] == vet1[j]){
                achou = 1;
                break;
            }
        }
        if(achou == 0){
            BemA = 0;
            break;
        }
    }

    if(AemB) return 1;
    if(BemA) return 2;
    return 0;
}

int main(){
    //int a=0;
    srand(time(NULL));
    //while(a<=100){
    int x,y,n;
    x = ValorAleatorio(15);
    y = ValorAleatorio(15);
    int vet1[x];
    int vet2[y];
    PreencherAleatorio(vet1,10,x);
    PreencherAleatorio(vet2,10,y);
    ExibirMatriz(vet1,x);
    ExibirMatriz(vet2,y);
    n = Contida(vet1,vet2,x,y);
    switch (n)
    {
    case 1:
        printf("\nVetor 1 está contido em Vetor 2");
        break;
    case 2:
    printf("\nVetor 2 está contido em Vetor 1");
    break;

    case 0:
    printf("\nNenhum dos vetores estão contidos no outro");
        break;
    }
    //a++;}
    return 0;
}