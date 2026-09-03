/*Implementar uma função que, dada uma string
s, determine a quantidade de caracteres
distintos em s.*/

#include <stdio.h>
#include <ctype.h>

int contagem(char s[]){
    int i,cont=0,pos;
    int s2[26] = {0};
    char letra;
    for(i=0;s[i]!='\0';i++){
        letra = s[i];
        letra = tolower(letra);
        pos = letra - 'a';
        if(s2[pos] == 0){
        cont++;
        s2[pos]++;
        }
    }
    return cont;
}

int main(){
    char s[] = "Hatsune Miku";
    int cont;

    cont = contagem(s);

    printf("A palavra tem %d caracteres distintos\n", cont);

    return 0;
}