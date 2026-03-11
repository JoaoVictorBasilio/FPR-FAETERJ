/*Implementar uma função que converta
determinada temperatura em graus Celsius
para graus Fahrenheit.*/

#include <stdio.h>

int Temperatura(float Celsius){
    float conversao;
    conversao = (Celsius * 9)/5 +32;
    return conversao;
}

int main(){
    float Celsius, Fahreheint;
    printf("Digite a temperatura :\n");
    scanf("%f", &Celsius);
    Fahreheint = Temperatura(Celsius);
    printf("%.2f C é igual a %.2f F ", Celsius, Fahreheint);
    return 0;

}