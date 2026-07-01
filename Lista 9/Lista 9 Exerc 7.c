/*Desenvolver uma função que, dados dois
arquivos textos arqA e arqB, crie um novo
arquivo arqC, considerando que:
 arqA e arqB contém números reais,
um por linha, ordenados
crescentemente e sem repetição no
arquivo;
 arqC deve conter apenas os números
comuns aos dois arquivos originais;
 Assim como arqA e arqB, arqC
também não possuirá repetições de
elementos e estes deverão estar
ordenados de forma crescente.*/

#include <stdio.h>
#include <string.h>

int OrdenarVetor (float vet1[], float vet2[], int cont)
{
	int i, j;
	float aux;

	for (i = 0; i < cont - 1; i++)
	{
		for (j = 0; j < cont - 1 - i; j++)
		{
			if (vet1[j] > vet1[j+1])
			{
				aux = vet1[j];
				vet1[j] = vet1[j+1];
				vet1[j+1] = aux;
			}
		}
	}

	if (cont == 0)
	{
		return 0;
	}

	vet2[0] = vet1[0];
	j = 1;

	for (i = 1; i < cont; i++)
	{
		if (vet1[i] != vet1[i-1])
		{
			vet2[j] = vet1[i];
			j++;
		}
	}

	return j;
}

void CriarArquivo (char Arquivo1[], char Arquivo2[], char Arquivo3[])
{
	FILE* arqA;
	FILE* arqB;
	FILE* arqC;
	float vet1[200];
	float vet2[200];
	float numero1,numero2;
	int i = 0, cont = 0, tamanhoVet2 = 0;

	arqA = fopen (Arquivo1, "r");
	arqB = fopen (Arquivo2, "r");
	arqC = fopen (Arquivo3, "w");

	if (!arqA || !arqB || !arqC)
	{
		printf ("Nao foi possivel abrir os arquivos.\n");
		
		if (arqA) fclose (arqA);
		if (arqB) fclose (arqB);
		if (arqC) fclose (arqC);
	}
	else
	{
		while (fscanf (arqA, "%f", &numero1) != EOF)
		{
			

		while (fscanf (arqB, "%f", &numero2) != EOF)
		{
            if(numero1 == numero2){
			vet1[cont] = numero1;
			cont++;
            }
		}
    }

		tamanhoVet2 = OrdenarVetor (vet1, vet2, cont);

		for (i = 0; i < tamanhoVet2; i++)
		{
			fprintf (arqC, "%.2f\n", vet2[i]);
		}

		fclose (arqA);
		fclose (arqB);
		fclose (arqC);

		printf ("\nArquivo C gerado com sucesso!\n");
	}
}

int main(){
    char Arquivo1[30];
    char Arquivo2[30];
    char Arquivo3[30] = "texto3.txt";

    printf("Digite o nome do primeiro arquivo: \n");
    fgets(Arquivo1,30,stdin);
    Arquivo1[strcspn(Arquivo1, "\n")] = '\0';

    printf("Digite o nome do segundo arquivo: \n");
    fgets(Arquivo2,30,stdin);
    Arquivo2[strcspn(Arquivo2, "\n")] = '\0';

    CriarArquivo(Arquivo1,Arquivo2,Arquivo3);

    return 0;
}