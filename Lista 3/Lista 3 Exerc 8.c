/*Faça uma função que, dado um vetor de
números inteiros, exiba para cada um de seus
elementos a quantidade de vezes que o mesmo
aparece no vetor.
Exemplo:
Vetor = {3,5,1,3,2,5,7,3,4,7,6,1}
Saída:
3: 3 vezes
5: 2 vezes
1: 2 vezes
2: 1 vez
7: 2 vezes
4: 1 vez
6: 1 vez*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void PreencherVetorAleatorio(int vet[], int limite,int tamanho){
    int i;

    srand (time(NULL));

    for(i=0;i<tamanho;i++){
        vet[i] = rand()%limite;
    }
}

void ExibirVetor(int vet[],int tamanho){
    int i;
    printf("\n");
    for(i=0;i<tamanho;i++){
        printf(" %d ", vet[i]);
    }
}

void Função(int vet[],int tam){
    int i,j,tamU=0,flag,cont,pos=0;
    int usados[tam];
    for(i=0;i<tam;i++){
        flag =0;
        cont = 0;
        if(tamU != 0){
            for(j=0;j<tamU;j++){
                if(vet[i] == usados[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                continue;
            }
        }
        for(int a=i;a<tam;a++){
            if(vet[a] == vet[i]){
                cont++;
            }
        }
        tamU++;
        usados[pos] = vet[i];
        pos++;
        printf("\n%d: %d vez(es)",vet[i],cont);
    }
}

int main(){
    int tam=10;
    int vet[tam];

    PreencherVetorAleatorio(vet,10,tam);
    ExibirVetor(vet,tam);
    Função(vet,tam);

    return 0;
}
