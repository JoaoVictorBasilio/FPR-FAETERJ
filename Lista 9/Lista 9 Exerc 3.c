/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ContarCaracteres(char *arquivo,char alfabeto[]){
    FILE *arq;
    int cont = 0, caractere;
    char c1,c2;
    
    
    arq =fopen(arquivo, "r");

    if(arq == NULL){
        printf("Erro: não foi possível abrir o arquivo '%s'.\n", arquivo);
        return -1;
    }

    while((caractere =fgetc(arq)) != EOF){
        for(int i=0;alfabeto[i] != '\0';i++){
            c1 = alfabeto[i];
            c2 = toupper(c1);
            if(caractere == c1 || caractere == c2){
                cont++;
            }
        }
    }

    fclose(arq);

    return cont;
}

int main(){
    char nomeArquivo[30];
    char alfabeto[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    int total;
    
    printf("Digite o nome do arquivo: \n");
    fgets(nomeArquivo,30,stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    total = ContarCaracteres(nomeArquivo,alfabeto);

    if(total == -1){
        return 0;
    }
    
    printf("O arquivo possui %d letras.\n", total);
    return 0;
}