/*Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição.*/

#include <stdio.h>
#include <string.h>

void OrdenarVetor(float vet[],int cont){
    int i;
    float aux;

    for(i=0;i<cont;i++){
        if(vet[i]<vet[i+1]){
            aux = vet[i];
            vet[i] = vet [i+1];
            vet [i+1] = aux;
            i=-1;
        }
    }
}

void CriarArquivo(char nomeArquivo[],char ArquivoOrdenado[]){
    FILE* arq1;
    FILE* arq2;
    int numero,i=0,cont=0;
    float vet[100];

    arq1 = fopen(nomeArquivo, "r");
    arq2 = fopen(ArquivoOrdenado, "w");
    if(!arq1 || !arq2){
        printf("Não foi possível abrir arquivo.\n");
    } else {
        while(fscanf(arq1,"%d",&numero) != EOF){
            vet[i] = numero;
            i++;
            cont++;
        }
    }
    OrdenarVetor(vet,cont);
    i=0;
    do {
        fprintf(arq2, "%.2f", vet[i]);
        while(vet[i] == vet[i+1]){
            i++;
        }
    } while(i<cont);
    fclose(arq1);
    fclose(arq2);
}

int main(){
    char nomeArquivo[30];

    printf("Digite o nome do Arquivo: \n");
    fgets(nomeArquivo,30,stdin);

    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    CriarArquivo(nomeArquivo,"ArquivoOrdenado.txt");
}
