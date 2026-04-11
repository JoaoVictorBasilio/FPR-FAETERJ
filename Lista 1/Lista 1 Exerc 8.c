/*Desenvolver uma função que exiba todos os
números primos inferiores a determinado valor
inteiro N.*/

#include <stdio.h>

void Clara(int n){
    for(int i=2;i<n;i++){
        for(int j=2;j<=i;j++){
            if(i%j==0 && j!=i){
                break;
            } else if (i%j==0 && j==i){
                printf(" %d ", i);
                break;
            }
            
        }
    }
}

int main(){
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    Clara(n);
    return 0;
}