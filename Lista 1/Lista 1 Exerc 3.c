/*Desenvolver uma função que calcule o n-ésimo
termo da sequência de Fibonacci.*/

#include <stdio.h>

int Fibonacci(int n){
    int i =2,a=0,b=1,conta;
    if(n == 0){
        return 0;
    } 
    if (n == 1){
        return 1;
    }
    else {
        while(i<=n){
            conta = a + b;
            a=b;
            b=conta;
            i++;
        }
    }
    return conta;
}

int main(){
    int n, resposta;
    printf("Digite o valor de n: \n");
    scanf("%d", &n);
    resposta = Fibonacci(n);
    printf("O termo correspondente a %d é %d ", n,resposta);
}