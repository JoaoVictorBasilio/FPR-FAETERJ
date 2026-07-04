/*Suyanne Pereira e João Victor Dourado*/

/*Considere um vetor contendo números inteiros, representando uma
expressão matemática, assim composto: os operandos estão armazenados
nas posições pares; por outro lado, as posições ímpares armazenam
um código que define a operação a ser realizada (1 - soma, 2 -subtração
3- multiplicação, 4 - divisão). Desenvolver uma função recursiva que
receba um vetor com este formato e retorne o valor final da expressão.

OBSERVAÇÕES:
1. Por exemplo, o vetor {7,2,3,3,4,4,2,1,3} equivale à expressão
7-3*4/2+3, com as operações realizadas da esquerda para a direita, sem
considerar as regras de precedência existentes entre os operadores na
matemática;
2. Considerem que o conteúdo do vetor é válido, representando uma
expressão conforme especificada no enunciado.*/


#include <stdio.h>

int calcular(int v[], int tam, int pos, int resultado){
    if (pos >= tam){
        return resultado;
    }

    switch (v[pos]){
        case 1: // soma
            resultado = resultado + v[pos + 1];
            break;

        case 2: // subtração
            resultado = resultado - v[pos + 1];
            break;

        case 3: // multiplicação
            resultado = resultado * v[pos + 1];
            break;

        case 4: // divisão
            resultado = resultado / v[pos + 1];
            break;
    }

    return calcular(v, tam, pos + 2, resultado);
}


int main(){
    int tam=9;
    int vet[] = {7, 2, 3, 3, 4, 4, 2, 1, 3};
    int valor;
    
    valor = calcular(vet,tam,1,vet[0]);

    printf("Resultado = %d\n", valor);

    return 0;
}
