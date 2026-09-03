/*Desenvolver uma função que, dada uma string s,
crie uma substring que inicie na posição p de s e
contenha n caracteres.
Observações: se p e/ou n forem inválidos, a
substring será vazia; 
ii) se s não possuir n
caracteres além de p, a substring a ser criada
começará em p e terminará no final de s.*/

#include <stdio.h>
#include <string.h>

void exibirstring(char s[]){
        printf("%s\n", s);
}

void substring(char s[], int p, int n){
    int i,cont=0,j=0;
    char s2[50];
    for(i=0;s[i]!='\0';i++){
        cont++;
    }
        for(i=p;s[i]!='\0';i++){
            if(cont>p && n>0 && j!=n){
            s2[j] = s[i];
            j++;
        }
    }
    s2[j] = '\0';
    exibirstring(s2);
}

int main(){
    char s[50] = "superteste";
    int p,n;

    printf("Digite o valor de p e n\n");
    scanf("%d %d", &p,&n);

    exibirstring(s);
    substring(s,p,n);

    return 0;
}