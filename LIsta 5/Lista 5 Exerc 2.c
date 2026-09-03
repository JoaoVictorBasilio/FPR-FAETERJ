/*Implementar uma função que, dadas duas
strings s1 e s2, crie uma nova string – s3 –
contendo todos os caracteres de s1 que não
estejam em s2.
Nota: em s3, não devem existir caracteres
repetidos.*/

#include <stdio.h>
#include <string.h>

void preenchendoString(char s1[],char s2[],char s3[]){
    int check[26] = {0};
    int i,j,igual,pos,a=0;
    char letra;
    for(i=0;s1[i]!='\0';i++){
        igual =0;
        for(j=0;s2[j]!='\0';j++){
            if(s1[i]==s2[j]){
                igual++;
            }
        }
        if(igual == 1){
            igual --;
            continue;
        }
        letra = s1[i];
        pos = letra - 'a';
        if(check[pos] == 0){
            s3[a] = s1[i];
            a++;
            check[pos]++;
        }
    }
}

int main(){
    char s1[] = "Rimuru Tempest";
    char s2[] = "Veldora Tempest";
    char s3[50];

    preenchendoString(s1,s2,s3);

    printf("%s\n", s3);

    return 0;
}