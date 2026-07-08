/*Fazer uma função que armazene em um vetor
os n primeiros termos da seguinte sequência:
S = 1, 2, 4, 7, 11, 16, ...

Nota: observem que a diferença entre o 1o e 2o
elementos é igual a 1, entre o 2o e 3o é igual a
2, entre o 3o e o 4o é igual a 3, e assim
sucessivamente.*/

#include <stdio.h>
#define MAX 1000


void PreenchendoVetor(int vet[], int n){
    int i, j=1, a=1;
    for(i=0;i<n;i++){
        vet[i] = j;
        j += a;
        a++;
    }
}

void ExibindoVetor(int vet[],int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        printf(" %d ", vet[i]);
    }
}

int main(){
    int n;
    int vet[MAX];
    printf("Digite quantos números quer salvar no vetor: \n");
    scanf("%d",&n);

    PreenchendoVetor(vet,n);
    ExibindoVetor(vet,n);

    return 0;
}