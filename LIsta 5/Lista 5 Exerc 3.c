/*Desenvolver uma função, em C, que, dada uma
string s e dada uma posição p desta string, crie duas
novas strings: s1 com os caracteres de s das
posições 0 a p-1; e s2 com os caracteres de s da
posição p à última.
Nota: Caso p seja uma posição inválida, a função
deverá retornar o valor 0; caso contrário,
procederá com a criação das duas strings e
retornará o valor 1.*/

#include <stdio.h>
#include <string.h>

int GloriaAoImperio(char s[], int p, int tam){
    char s1[20];
    char s2[20];
    int i,j;

    if(p > tam || p < 0){
        return 0;
    }
    for(i=0;i<p;i++){
        s1[i] = s[i];
    }
    s1[i] = '\0';
    for(j=0;s[i]!='\0';j++){
        s2[j] = s[i];
        i++;
    }
    s2[j] = '\0';
    printf("%s\n%s\n%s\n", s, s1, s2);

    return 1;
}

int main(){
    char s[] = "Psicopata Americano";
    int p,tam;

    tam = strlen(s);

    printf("Digite o valor de P: \n");
    scanf("%d", &p);

    GloriaAoImperio(s,p,tam);

    return 0;
}