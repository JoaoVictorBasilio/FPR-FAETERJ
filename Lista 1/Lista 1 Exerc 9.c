/*Implementar uma função que, dado um
número inteiro, calcule (e retorne) a soma e a
média de seus divisores.*/

#include <stdio.h>

int soma(int n){
    int i,soma = 0;
    for(i=1;i<=n;i++){
        if(n%i==0){
            soma += i;
        }
    }
    return soma;
}

float media(int n){
    int i,soma = 0, cont = 0;
    float media;
    for(i=1;i<=n;i++){
        if(n%i==0){
            soma += i;
            cont++;
        }
    }
    media = (float)soma/cont;
    return media;
}

int main(){
    int n,s;
    float m;
    printf("Digite um número: ");
    scanf("%d", &n);
    s = soma(n);
    m = media(n);

    printf("\nA soma e a média dos divisores de %d é: %d e %.2f",n,s,m);

    return 0;
}