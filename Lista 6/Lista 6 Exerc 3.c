/*Desenvolver uma função que gere uma matriz
Mnxn, nos moldes do exemplo apresentado a
seguir (que consiste em uma matriz de ordem
5)
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9*/

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

void PreencherMatrizAleatorio(int linha,int coluna, int M[linha][coluna],int limite){
    int i,j;

    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            M[i][j] = rand()%limite;
        }
    }
}


int main(){
    int n=5;
    int M[n][n];

    srand(time(NULL));

    PreencherMatrizAleatorio(n,n,M,10);
    ExibirMatriz(n,n,M);

    return 0;
}