/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.*/

#include <stdio.h>

int ContarCaracteres(char nomeArquivo[]){
    FILE* arq;
    int cont = 0;
    char ch;
    
    arq =fopen(arquivo, "r");

    if(arq == NULL){
        printf("Erro: não foi possível abrir o arquivo '%s'.", arquivo);
        return -1;
    }

    while((caractere =fgetc(arq)) != EOF){
        cont++;
    }

    fclose(arq);

    return cont;
}

int main(){
    char nomeArquivo[30];
	int total = 0;
	
	printf ("Nome do arquivo: ");
	gets (nomeArquivo);
		
	total = ContarCaracteres (nomeArquivo);
    if(total < 0){
        return 0;
    }
    printf("O arquivo possui %d caracteres.", total);
    return 0;
}