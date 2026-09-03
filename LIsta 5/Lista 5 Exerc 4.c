/*Desenvolver uma função que remova de uma
string s os caracteres compreendidos entre as
posições p1 e p2.
Caso p1 ou p2 seja uma posição inválida, a
função deverá retornar o valor 0 e a remoção de
caracteres solicitada não será realizada; caso
contrário, deverá retornar 1 e proceder com o
que foi pedido.*/

#include <stdio.h>
#include <string.h>

int Remover(char s[], int p1, int p2, int tam){
    int i = p1,j=p2 +1;

    if(p1 < 0 || p1 > tam || p2<p1 || p2 > tam){
        return 0;
    }
    while(s[j] != '\0'){
        s[i] = s[j];
        i++;
        j++;
    }
    s[i] = '\0';

    return 1;
}

int main(){
    char s[] = "On The Way";
    int p1 = 3,p2 = 6,tam;
    tam = strlen(s);

    printf("%s\n", s);
    Remover(s,p1,p2,tam);
    printf("%s\n", s);

    return 0;
}