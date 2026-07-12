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

void Preenchendo(int tam,int C[]){
    int i;
    for(i=0;i<tam;i++){
        printf("Digite um valor\n");
        scanf("%d", &C[i]);
    }
}

int Contido(int A[], int B[],int tamA,int tamB){
    int i,j,cont=0;
    if(tamA > tamB){
        for(i=0;i<tamA;i++){
            for(j=0;j<tamB;j++){
                if(B[j] == A[i]){
                    cont++;
                    break;
                }
            }
        }
        if(cont == tamB){
            return 2;
        }
    } else if(tamA < tamB){
        for(i=0;i<tamB;i++){
            for(j=0;j<tamA;j++){
                if(B[i] == A[j]){
                    cont++;
                    break;
                }
            }
        }
        if(cont == tamA){
            return 1;
        }
    }
        return 0;
    

}

int main(){
    int tamA,tamB;
    printf("Digite o tamanho de A e B\n");
    scanf("%d %d", &tamA,&tamB);

    int A[tamA];
    int B[tamB];

    Preenchendo(tamA,A);
    Preenchendo(tamB,B);
    int a;

    a= Contido(A,B,tamA,tamB);

        printf("%d\n",a);

        return 0;
}