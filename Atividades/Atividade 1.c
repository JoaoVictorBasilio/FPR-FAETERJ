/*Desenvolver uma função que, dada uma string
str, substitua uma substring s1 de str (definida
pelas posições inicial e final) por outra string,
s2.

Exemplo:
str originalmente:
e   a i ,   v c   v e  m  ?
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

Substituir a substring s1 de str,
definida pelas posições
inicial (=6) e final (=7)
pela string s2 igual a “você”

str após a substituição:
e   a i ,   v o c e    v  e  m  ?
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

Observações:
1. O programa deve ser feito utilizando a
linguagem C;
2. As soluções apresentadas poderão
utilizar apenas as estruturas estudadas
em aula;
3. A atividade pode ser feita
individualmente ou em dupla;
4. Caso seja observada cópia de soluções,
todos os alunos envolvidos ficarão sem
nota;
5. A atividade avalia o uso de strings.
Portanto, a solução deve utilizar apenas
este tipo de estrutura;
6. O arquivo .c com a solução da atividade
deve ser postado no Classroom até o
dia 12/04/2026, no local associado à
Atividade 1.*/

#include <stdio.h>

void substituir(char str[], int inicio, int fim, char s2[]){
    char nova[100];
    int i, j, pos = 0;

    for(i = 0; i < inicio; i++){
        nova[pos++] = str[i];
    }
    for(j = 0; s2[j] != '\0'; j++){
        nova[pos++] = s2[j];
    }
    for(i = fim + 1; str[i] != '\0'; i++){
        nova[pos++] = str[i];
    }
    nova[pos] = '\0';
    for(i = 0; nova[i] != '\0'; i++){
        str[i] = nova[i];
    }
    str[i] = '\0';
}

int main(){
    char str[100] = "e ai, vc vem?";
    char s2[] = "voce";
    int inicio = 6, fim = 7;

    printf("Antes: %s\n", str);
    substituir(str, inicio, fim, s2);
    printf("Depois: %s\n", str);

    return 0;
}