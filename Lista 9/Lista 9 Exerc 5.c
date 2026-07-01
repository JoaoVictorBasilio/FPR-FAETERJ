/*Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição.*/

#include <stdio.h>
#include <string.h>

void OrdenarVetor (float vet[], int cont)
{
	int i, j;
	float aux;

	for (i = 0; i < cont - 1; i++)
	{
		for (j = 0; j < cont - 1 - i; j++)
		{
			if (vet[j] < vet[j+1])
			{
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
		}
	}
}

void CriarArquivo (char nomeArquivo[], char ArquivoOrdenado[])
{
	FILE* arq1;
	FILE* arq2;
	float numero;
	int i = 0, cont = 0;
	float vet[100];

	arq1 = fopen (nomeArquivo, "r");
	arq2 = fopen (ArquivoOrdenado, "w");
	
	if (!arq1 || !arq2)
	{
		printf ("Nao foi possivel abrir arquivo.\n");
		
		if (arq1) fclose (arq1);
		if (arq2) fclose (arq2);
	}
	else
	{
		while (fscanf (arq1, "%f", &numero) != EOF)
		{
			vet[cont] = numero;
			cont++;
		}
		
		OrdenarVetor (vet, cont);
		
		if (cont > 0)
		{
			fprintf (arq2, "%.2f\n", vet[0]);
			
			for (i = 1; i < cont; i++)
			{
				if (vet[i] != vet[i-1])
				{
					fprintf (arq2, "%.2f\n", vet[i]);
				}
			}
		}
		
		fclose (arq1);
		fclose (arq2);
		
		printf ("\nArquivo B gerado e ordenado com sucesso!\n");
	}
}

int main ()
{
	char nomeArquivo[30];

	printf ("Digite o nome do Arquivo: \n");
	fgets (nomeArquivo, 30, stdin);

	nomeArquivo[strcspn (nomeArquivo, "\n")] = '\0';

	CriarArquivo (nomeArquivo, "ArquivoOrdenado.txt");
	
	return 0;
}