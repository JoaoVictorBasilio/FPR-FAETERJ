/*Fazer uma função que calcule o MDC (máximo
divisor comum) entre dois números.*/

#include <stdio.h>

int MDC (int num1, int num2);

int main(){
    int num1,num2,resultado;
    printf("Digite dois números: ");
    scanf("%d %d", &num1, &num2);
    resultado=MDC(num1,num2);
    printf("O maior divisor comum é %d", resultado);

    return 0;
}

int MDC (int num1, int num2){
    int i, menor,MDC;
    if(num1<num2){
        menor=num1;
    }else {
        menor=num2;
    }
    for(i=1;i<=menor;i++){
        if(num1%i==0 && num2%i==0){
            MDC=i;
        }
    }
    return MDC;
}