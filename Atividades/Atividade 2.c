/*Dadas uma matriz Mmxn e uma coluna col,
desenvolver uma função que desloque todos os
elementos da coluna col para a última coluna
da matriz.
Consequentemente, as colunas col+1 à última
deverão serão deslocadas uma posição para a
esquerda, conforme ilustrado no exemplo
abaixo:

    1 5 7 1 4 6
    6 2 1 4 7 7
M = 3 6 9 7 0 1
    2 4 5 7 2 4
    2 4 8 9 1 2

    col = 1 (ou seja, a 2a coluna)

    1 7 1 4 6 5
    6 1 4 7 7 2
M = 3 9 7 0 1 6
    2 5 7 2 4 4
    2 8 9 1 2 4

Nota: se o valor de col for válido, a função
fará o que foi solicitado e retornará 1, ao
final; caso contrário, apenas retornará 0.

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
5. A atividade avalia o uso de matrizes
(vetores multidimensionais). Portanto,
a solução deve utilizar apenas
vetores/matrizes;
6. O arquivo .c com a solução da atividade
deve ser postado no Classroom até o
dia 12/04/2026, no local associado à
Atividade 2.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibirMatriz (int l, int c, int mat[l][c])
{
	int i, j;
	
	for (i=0;i<l;i++)
	{
		for (j=0;j<c;j++)
		{
			printf ("%3d ", mat[i][j]);
		}
		
		printf ("\n");
	}
}

void preencherMatrizAleatoria (int l, int c, int mat[l][c], int limite)
{
	int i, j;
	
	srand (time(NULL));
	
	for (i=0;i<l;i++)
	{
		for (j=0;j<c;j++)
		{
			mat[i][j] = rand()%limite;
		}
	}	
}

int deslocamento(int l, int c, int mat[l][c], int col){
    if(col>=c || col < 0){
        printf("Coluna não existente");
        return 0;
    }

    int i,j;
    int Maux[l][c];
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            Maux[i][j] = mat[i][j];
        }
    }
    for(i=0;i<l;i++){
        for(j=col;j<c;j++){
            if(j==c-1){
                mat[i][j] = Maux[i][col];
            } else {
                mat[i][j] = Maux[i][j+1];
            }
        }
    }
    return 1;
}

int main(){
    int m=5,n=6,col;
    int M[m][n];
    preencherMatrizAleatoria(m,n,M,10);
    printf("Antes: \n");
    exibirMatriz(m,n,M);
    printf("\nSelecione a coluna desejada: ");
    scanf("%d", &col);
    col -=1;
    deslocamento(m,n,M,col);
    printf("\nDepois: \n");
    exibirMatriz(m,n,M);

    return 0;
}