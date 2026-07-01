/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.*/

#include <stdio.h>
#include <ctype.h>

int ContarCaracteres(char *arquivo, char c){
    FILE *arq;
    int cont = 0, caractere;
    char c1,c2;

    c1 =toupper(c);
    c2 =tolower(c);
    
    arq =fopen(arquivo, "r");

    if(arq == NULL){
        printf("Erro: não foi possível abrir o arquivo '%s'.\n", arquivo);
        return -1;
    }

    while((caractere =fgetc(arq)) != EOF){
        if(caractere == c1 || caractere == c2){
        cont++;
        }
    }

    fclose(arq);

    return cont;
}

int main(){
    char *arq = "texto.txt";
    int total = 0;
    char c;
    printf("Digite o Caractere: \n");
    scanf("%c", &c);
    total = ContarCaracteres(arq,c);

    if(total < 0){
        return 0;
    }
    printf("O arquivo possui %d caracteres %c.\n", total, c);
    return 0;
}