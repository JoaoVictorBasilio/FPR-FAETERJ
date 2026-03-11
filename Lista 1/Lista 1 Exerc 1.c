/*Desenvolver uma função que exiba os múltiplos
de N compreendidos no intervalo definido por
A e B.*/

#include <stdio.h>

void Multiplos(int A, int B, int N){
    int i;
    printf("Multiplos de N: ");
    if(A>B){
    for(i=A;i<=B;i++){
        if(i % N == 0){
            printf(" %d ", i);
        }
    }
} else {
    for(i=A;i<=B;i++){
        if(i % N == 0){
            printf(" %d ", i);
        }
    }
}
}

int main(){
    int A, B, N;
    printf("Digite os valores de 'A', 'B' e 'N': \n");
    scanf("%d %d %d",&A,&B,&N);

    Multiplos(A,B,N);

    return 0;

}