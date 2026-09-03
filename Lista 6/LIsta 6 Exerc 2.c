/*Desenvolver uma função que, dada uma matriz
Mm×n, determine se um número X se encontra
na linha L da matriz.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ExibirMatriz(int m,int n,int M[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf(" %d ", M[i][j]);
        }
        printf("\n");
    }
}

int Buscar(int m,int n,int M[m][n],int x,int l){
    int i;

    if(l>m-1 || l<0){
        return -1;
    }
    for(i=0;i<n;i++){
        if(M[l][i] == x){
            return 1;
        }
    }

    return 0;
}

void PreencherMatrizAleatorio(int linha,int coluna,int M[linha][coluna],int limite){
    int i,j;
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            M[i][j] = rand()%limite;
        }
    }
}

int main(){
    int m=5,n=5,x=3,l=4,resp;
    int M[m][n];
    
    srand(time(NULL));
    PreencherMatrizAleatorio(m,n,M,10);
    resp = Buscar(m,n,M,x,l);
    ExibirMatriz(m,n,M);

    switch (resp)
    {
    case -1:
        printf("Valor de linha inválido!\n");
        break;

    case 1:
        printf("Valor encontrado!\n");
        break;
    
    default:
        printf("Valor não encontrado!\n");
        break;
    }

    return 0;
}