/*Fazer um função que, dados dois vetores A e B
com números inteiros, gerar o vetor C que
consiste na união dos dois primeiros.
Nota: considerar que não existe repetição no
conjunto A, nem no conjunto B.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void preencherAleatorioVetorUsados(int vetor[], int tamanho, int limite)
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

void exibirVetor (int vetor[], int tamanho)
{
	int i;
		
	printf ("\n\nElementos do vetor: ");
	for (i=0;i<tamanho;i++)
	{
		printf ("%d ", vetor[i]);	
	}		
	
	printf ("\n\n");
}


void VetorC(int vetA[],int vetB[],int tam){
	int vetC[20];
	int i,j,a,b,aux=0;

	for(i=0;i<tam;i++){
		vetC[i] = vetA[i];
	}
	a=i;
	b=i;
	for(i=0;i<tam;i++){
		for(j=0;j<b;j++){
			if(vetC[j]==vetB[i]){
				aux = 1;
				break;
			}
		}
		if(aux==0){
			vetC[a] = vetB[i];
			a++;
		}	
		aux = 0;
	}
	exibirVetor(vetC,a);
}

int main(){
    int vetA[10];
    int vetB[10];
	srand (time(NULL));

	preencherAleatorioVetorUsados(vetA,10,15);
	preencherAleatorioVetorUsados(vetB,10,15);
	exibirVetor(vetA,10);
	exibirVetor(vetB,10);
    VetorC(vetA,vetB,10);

	return 0;
}