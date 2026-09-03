/*Dada uma string s, desenvolver uma função que
determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa.*/

#include <stdio.h>
#include <string.h>

int palindromo(char origem[]){
    char destino[50];
    int i,j;

    j = strlen(origem) -1;
    for(i=0;origem[i] != '\0';i++){
        destino[i] = origem[j];
        j--;
    }

    for(i=0;origem[i] != '\0';i++){
        if(origem[i] != destino[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str[50];
    int p;

    printf("Digite uma palavra: \n");
    scanf("%s", str);

    p = palindromo(str);

    if(p == 0){
        printf("A palavra não é um palíndromo\n");
    } else {
        printf("A palavra é um palíndromo\n");
    }

    return 0;
}