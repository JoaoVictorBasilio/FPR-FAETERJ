/*Faça uma função que, dada uma matriz Mm×n de
reais, gere a matriz Mt, sua transposta.*/

#include <stdio.h>

void exibirMatriz(int matriz[2][2]){
    int i,j;

    printf("\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

void tranz(int matriz[2][2]){
    int tranz[2][2];
    int i,j;

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            tranz[i][j] = matriz[j][i];
        }
    }

    exibirMatriz(tranz);
}


int main (){
    int matriz[2][2] = {
        {1, 2},
        {3, 4}
    };

    exibirMatriz(matriz);
    tranz(matriz);

    return 0;
}