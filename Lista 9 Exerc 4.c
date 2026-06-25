/*Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.*/

#include <stdio.h>
#include <limits.h>
#include <string.h>

int VerificarOrdenado(char nomeArquivo[]){
    FILE* arq;
    int numero,anterior = INT_MIN;

    arq = fopen(nomeArquivo, "r");
    if(!arq){
        return -1;
    } else {
        while(fscanf(arq,"%d",&numero) != EOF){
            if(numero < anterior){
                fclose(arq);
                return 0;
            }
            anterior = numero;
        }
    }
    fclose(arq);
    return 1;
}

int main(){
    char nomeArquivo[30];
    int a;

    printf("Digite o nome do Arquivo: \n");
    fgets(nomeArquivo,30,stdin);

    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    a = VerificarOrdenado(nomeArquivo);
    if(a == -1){
        printf("não foi possível abrir o arquivo.\n");
    } else if(a == 0){
        printf("Não está ordenado.\n");
    } else if(a == 1){
        printf("Está ordenado.\n");
    }

    return 0;
}