/*Fazer uma função que calcule o MMC (mínimo
múltiplo comum) entre dois números.*/

#include <stdio.h>

int MMC (int num1, int num2);

int main(){
    int num1,num2,resultado;
    printf("Digite dois números: ");
    scanf("%d %d", &num1, &num2);
    resultado=MMC(num1,num2);
    printf("O mínimo múltiplo comum é %d", resultado);

    return 0;
}

int MMC (int num1, int num2){
    int i, MMC=1, maior;
    if(num1 > num2){
        maior = num1;
    } else {
        maior = num2;
    }
    
    for(i=2;i<=maior;i++){
        while(num1%i==0 || num2%i==0){
            MMC= MMC *i;
            if(num1%i==0){
                num1 = num1 / i;
                
            }
            if(num2%i==0){
                num2 = num2 / i;
                
               
            }
        }
    }
    return MMC;
}