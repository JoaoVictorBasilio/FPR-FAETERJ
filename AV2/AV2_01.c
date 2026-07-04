/*Suyanne Pereira e João Victor Dourado*/


/*Pede-se a implementação de uma função que remova todas as ocorrências de um
conjunto de caracteres de um arquivo texto, retornando a quantidade de remoções realizdas.
Os caracteres a serem removidos estarão armazenados em uma string.
Por exemplo, se a string armazenar a sequência BKPI, deverão ser removidas do arquivo dao todas
as ocorrências B,K,P e I.
as alterações devem ser feitas no primeiro arquivo*/

#include <stdio.h>
#include <string.h>

int AlterarArquivo(char remover[])
{
    FILE *arq;
    FILE *novo;
    char letra;
    int cont = 0;
    int apagar;

    arq = fopen("Remover.txt", "r");
    novo = fopen("Novo.txt", "w");

    if (arq == NULL || novo == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");

        if (arq != NULL)
            fclose(arq);

        if (novo != NULL)
            fclose(novo);

        return -1;
    }

    while (fscanf(arq, "%c", &letra) != EOF){
        apagar = 0;
	  int i;
        for(i = 0; remover[i] != '\0'; i++){
            if (letra == remover[i]){
                apagar = 1;
                break;
            }
        }

        if (apagar != 0){
            cont++;
        }
        else{
            fprintf(novo, "%c", letra);
        }
    }

    fclose(arq);
    fclose(novo);

    return cont;
}


int main(){
    char remover[100];
    int total;

    printf("Digite os caracteres que deseja remover: \n");
    fgets(remover, 100, stdin);
    remover[strcspn(remover, "\n")] = '\0';

    total = AlterarArquivo(remover);

    if (total == -1){
        printf("Erro ao abrir o arquivo!\n");
    }
    else if (total == 0){
        printf("Nenhuma remocao foi feita.\n");
    }
    else{
        printf("Foram feitas %d remocoes.\n", total);
    }

    return 0;
}

