/*Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.*/

#include <stdio.h>
#include <string.h>


void mystrlen(char origem[]){
    int i,cont=0;
    for(i=0;origem[i] != '\0';i++){
        cont++;
    }
    printf("strlen: A palavra %s tem %d letras\n", origem,cont);
}

void mystrcpy(char origem[]){
    char destino[20];
    int i;
    for(i=0;origem[i]!='\0';i++){
        destino[i] = origem[i];
    }
    destino[i] = '\0';

    printf("strcpy: %s\n", destino);
}

void mystrcat(char origem[]){
    char destino[20] = "feito";
    int i,j;

    j= strlen(destino);
    destino[j] = ' ';
    j++;
    for (i = 0; origem[i]!='\0'; i++){
        destino[j+i] = origem[i];
    }

    printf("strcat: %s\n", destino);
    
}

void mystrcmp(char origem[]){
    char destino[20] = "teste";
    int comp=0, i,tam1,tam2;

    tam1 = strlen(origem);
    tam2 = strlen(destino);
    if(tam1 == tam2){
    for(i=0;origem[i] != '\0' && destino[i] != '\0';i++){
        if(origem[i] != destino[i]){
            if(origem[i] > destino[i]){
                comp = 1;
            } else {
                comp = -1;
            }
            break;
        }
    }
} else{
    comp = 1;
}

    if(comp == 0){
        printf("strcmp: As palavras são iguais\n");
    } else{
        printf("strcmp: As palavras são diferentes\n");
    }
}

int main(){
    char str[] = "teste";

    mystrlen(str);
    mystrcpy(str);
    mystrcat(str);
    mystrcmp(str);

    return 0;
}