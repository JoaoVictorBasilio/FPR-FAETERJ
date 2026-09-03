/*Desenvolver uma função que, dada uma string
s, retorne um vetor de structs que armazene,
em cada uma de suas posições, um caracter
distinto de s e a quantidade de ocorrências
deste caracter na string.
Observações:
1. Ao incluir um novo caracter no vetor de
structs, deve-se buscar a posição apropriada,
de forma que o vetor fique ordenado
crescentemente em função dos caracteres;
2. Pelo que foi descrito no enunciado,
repetições de caracteres não são permitidas
no vetor.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char c;
    int quant;
} Tstruct;

int preencher(Tstruct vet[], char str[]) {
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        char ch = str[i];

        if (ch != ' ') {
            int j;
            for (j = 0; j < count; j++) {
                if (vet[j].c == ch) {
                    vet[j].quant++;
                    break;
                }
            }

            if (j == count) {
                int pos = 0;
                while (pos < count && vet[pos].c < ch) {
                    pos++;
                }
                for (int k = count; k > pos; k--) {
                    vet[k] = vet[k-1];
                }
                vet[pos].c = ch;
                vet[pos].quant = 1;
                count++;
            }
        }
    }

    return count;
}

int main() {
    char str[100] = "tres pratos de trigo para tres tigres tristes";
    Tstruct vet[100];
    int n = preencher(vet, str);

    printf("String: %s\n", str);
    printf("Caracteres distintos e suas ocorrencias:\n");
    for (int i = 0; i < n; i++) {
        printf("%c: %d\n", vet[i].c, vet[i].quant);
    }

    return 0;
}