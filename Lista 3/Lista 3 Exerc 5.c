/*Implementar uma função que, dado um vetor
contendo números reais, determine o maior e o
segundo maior elementos.
Nota: considerar que não há repetição de
elementos no vetor.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void maiores(float vet[],int tam){
    float maior1=vet[0],maior2=vet[1];
    int i,j=0;

    if(maior2>maior1){
        maior1=vet[1];
        maior2=vet[0];
        j=1;
    }
    for(i=2;i<tam;i++){
        if(vet[i]> maior2){
            maior2 = vet[i];
            if(maior2>maior1){
                maior1 = vet[i];
                maior2 = vet[j];
                j = i;
            }
        }
    }
    printf("\nOs maiores são: %.2f e %.2f", maior1, maior2);
}

void preencherAleatorioVetorUsados(float vetor[], int tamanho, int limite)
{
    int i, numGerado;
    
    // Cria um vetor checklist inicializado com zeros (calloc faz isso).
    // Zero = não usado, Um = já usado.
    int *usados = (int*) calloc(limite, sizeof(int));
    
    for (i = 0; i < tamanho; i++)
    {
        do {
            numGerado = rand() % limite;
        } while (usados[numGerado] == 1); // Basta olhar no checklist, não precisa do loop interno!
        
        // Marca no checklist que esse número agora está em uso
        usados[numGerado] = 1;
        
        // Salva o número no vetor final
        vetor[i] = numGerado;
    }
    
    // Libera a memória do checklist
    free(usados);
}


void ExibirVetor(float vet[],int tamanho){
    int i;
    printf("\n");
    for(i=0;i<tamanho;i++){
        printf(" %.1f ", vet[i]);
    }
}

int main(){
    int tam = 10;
    float vet[tam];
    srand(time(NULL));

    preencherAleatorioVetorUsados(vet,tam,100);
    ExibirVetor(vet,tam);
    maiores(vet,tam);

    return 0;
}