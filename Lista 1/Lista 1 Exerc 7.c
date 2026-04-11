/*Implementar uma função que, dado um
número inteiro n, e o intervalo definido pelos
números a e b, determine quantos valores do
intervalo possuem divisores (sendo estes
diferentes de 1) que também sejam divisores
de n.
Exemplo:
n = 6
a = 10 e b = 20
Resposta = 7 (pois os números 10, 12, 14,
15, 16, 18 e 20 possuem divisores em
comum com o número 6).*/

#include <stdio.h>

int NComuns(int n, int a, int b){
    int menor, maior,resp=0;
    if(a<b){
        menor = a;
        maior = b;
    } else {
        menor = b;
        maior = a;
    }
    for(int i=menor;i<=maior;i++){
        for(int j=2;j<n;j++){
            if(n%j==0 && i%j==0){
                resp++;
                break;
            }
        }
    }
    return resp;
}

int main(){
    int n,a,b,cont;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("\nDigite os valores que farão o intervalo: ");
    scanf("%d %d", &a, &b);
    cont = NComuns(n,a,b);
    printf("\n%d valores tem divisores em comum com %d", cont,n);
    return 0;
}