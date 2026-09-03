/*A empresa ParkRio necessita de um sistema que gerencie o estacionamento de um edifício garagem composto por 10 andares, cada qual com
80 vagas, podendo estas serem alocadas a clientes do rotativo ou mensalistas.
Cada vaga do estacionamento possui uma identificação única, composta pelo andar e por suas “coordenadas” dentro do andar. Por exemplo,
a vaga B0104 encontra-se no andar B (segundo andar), sendo a 4a da primeira fila.
Ao chegar no estacionamento, o motorista escolherá, através do sistema, o tipo de vaga de interesse – rotativo ou mensalista – e informará a
placa do veículo. Se for mensalista, o sistema deve informar a vaga que está associada ao carro;
caso seja rotativo, deve ser retornada ao motorista a vaga disponível mais próxima (sabendo-se que os 4 primeiros andares são reservados aos
mensalistas).
Ao receber o número da placa, o sistema deve buscá-la em seus registros:
 Caso trate-se de um mensalista, se a placa não for localizada no sistema, deve-se fazer o cadastro do carro, pois consiste em um novo
cliente. Deve, então, ser solicitado um telefone de contato, e registrada a data de cadastro  (dd/mm/aaaa). Esta data será o vencimento do
mês e, portanto, a cada mês (inclusive no dia do cadastro), no dia dd, o sistema deve cobrar do motorista o valor de R$ 500,00. Assim como
no rotativo, deve ser associada ao carro a vaga disponível mais próxima;
 Por outro lado, caso seja um cliente do rotativo e o sistema identifique que um carro com a placa informada já encontra-se estacionado,
deve ser exibida uma mensagem de erro e solicitada nova placa.
Como informado anteriormente, o valor da mensalidade será de R$ 500,00 para clientes com vagas reservadas. Já o estacionamento rotativo
seguirá a seguinte tabela:

Tempo Valor
Até 30 minutos R$ 6,00
Até 1 hora R$ 10,00
Até 2 horas R$ 15,00
Até 4 horas R$ 25,00
Até 6 horas R$ 35,00
Até 8 horas R$ 50,00
Até 24 horas R$ 100,00
Da 2a diária em diante R$ 50,00/dia
Dessa forma, o sistema deve controlar tanto a entrada quanto a saída de carros do estacionamento.
Observações:
a. Uma vaga se tornará disponível nas seguintes situações: 
i) na saída de um cliente rotativo; ou ii) quando não for registrado o pagamento de uma vaga de mensalista no dia previsto em seu cadastro;
b. O cadastro dos clientes/vagas estará, inicialmente, armazenado em arquivo. Ao iniciar a execução do programa, este será 
carregado para uma matriz (tridimensional) de structs. Ao final da execução, os dados da matriz deverão ser 
retornados ao arquivo de origem para que estejam disponíveis/salvos para a próxima execução;
c. O sistema deve estar devidamente modularizado (uso de funções);
d. O trabalho pode ser feito em dupla ou individualmente. Em hipótese alguma, será tolerada a entrega de trabalhos iguais/similares;
e. O trabalho deve ser postado no Classroom, na atividade Trabalho II, até o dia 24/05/2026.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANDARES 10
#define FILAS 8
#define COLUNAS 10
#define ANDARES_MENSALISTA 4

typedef struct
{
    int ocupada;
    char placa[8];
    char tipo;
    char telefone[20];
    int diaCadastro;
    int mesCadastro;
    int anoCadastro;
    int diaEntrada;
    int horaEntrada;
    int minutoEntrada;
    char identificacao[6];
    char andar;
    int fila;
    int coluna;
} TVaga;

void gerarIdentificacoes(
    TVaga estacionamento[ANDARES][FILAS][COLUNAS]
)
{
    int i, j, k;

    for(i = 0; i < ANDARES; i++)
    {
        for(j = 0; j < FILAS; j++)
        {
            for(k = 0; k < COLUNAS; k++)
            {
                estacionamento[i][j][k].andar = 'A' + i;

                estacionamento[i][j][k].fila = j + 1;

                estacionamento[i][j][k].coluna = k + 1;

                estacionamento[i][j][k].identificacao[0] = estacionamento[i][j][k].andar;

                estacionamento[i][j][k].identificacao[1] =((j + 1) / 10) + '0';

                estacionamento[i][j][k].identificacao[2] =((j + 1) % 10) + '0';

                estacionamento[i][j][k].identificacao[3] =((k + 1) / 10) + '0';

                estacionamento[i][j][k].identificacao[4] =((k + 1) % 10) + '0';

                estacionamento[i][j][k].identificacao[5] ='\0';
            }
        }
    }
}

void inicializar(
    TVaga estacionamento[ANDARES][FILAS][COLUNAS]
)
{
    int i, j, k;

    gerarIdentificacoes(estacionamento);

    for(i = 0; i < ANDARES; i++)
    {
        for(j = 0; j < FILAS; j++)
        {
            for(k = 0; k < COLUNAS; k++)
            {
                estacionamento[i][j][k].ocupada = 0;

                strcpy(estacionamento[i][j][k].placa,"LIVRE");

                strcpy(estacionamento[i][j][k].telefone,"N/A");

                estacionamento[i][j][k].tipo = 'L';

                estacionamento[i][j][k].diaCadastro = 0;
                estacionamento[i][j][k].mesCadastro = 0;
                estacionamento[i][j][k].anoCadastro = 0;

                estacionamento[i][j][k].diaEntrada = 0;

                estacionamento[i][j][k].horaEntrada = 0;
                estacionamento[i][j][k].minutoEntrada = 0;
            }
        }
    }
}

void salvarArquivo(TVaga estacionamento[ANDARES][FILAS][COLUNAS])
{
    FILE *arquivo;

    int i, j, k;

    arquivo = fopen("estacionamento.txt","w");

    if(arquivo == NULL)
    {
        printf("Erro no arquivo!\n");
        return;
    }

    for(i = 0; i < ANDARES; i++)
    {
        for(j = 0; j < FILAS; j++)
        {
            for(k = 0; k < COLUNAS; k++)
            {
                fprintf(arquivo,"%d %s %c %s %d %d %d %d %d %d\n",estacionamento[i][j][k].ocupada,estacionamento[i][j][k].placa,estacionamento[i][j][k].tipo,estacionamento[i][j][k].telefone,estacionamento[i][j][k].diaCadastro,estacionamento[i][j][k].mesCadastro,estacionamento[i][j][k].anoCadastro,estacionamento[i][j][k].diaEntrada,estacionamento[i][j][k].horaEntrada,estacionamento[i][j][k].minutoEntrada);
            }
        }
    }

    fclose(arquivo);
}

void carregarArquivo(TVaga estacionamento[ANDARES][FILAS][COLUNAS])
{
    FILE *arquivo;

    int i, j, k;

    arquivo = fopen("estacionamento.txt","r");

    if(arquivo == NULL)
    {
        inicializar(estacionamento);
        return;
    }

    gerarIdentificacoes(estacionamento);

    for(i = 0; i < ANDARES; i++)
    {
        for(j = 0; j < FILAS; j++)
        {
            for(k = 0; k < COLUNAS; k++)
            {
                fscanf(arquivo,"%d %7s %c %19s %d %d %d %d %d %d",&estacionamento[i][j][k].ocupada,estacionamento[i][j][k].placa,&estacionamento[i][j][k].tipo,estacionamento[i][j][k].telefone,&estacionamento[i][j][k].diaCadastro,&estacionamento[i][j][k].mesCadastro,&estacionamento[i][j][k].anoCadastro,&estacionamento[i][j][k].diaEntrada,&estacionamento[i][j][k].horaEntrada,&estacionamento[i][j][k].minutoEntrada);
            }
        }
    }

    fclose(arquivo);
}

int procurarPlaca(TVaga estacionamento[ANDARES][FILAS][COLUNAS],char placa[],int *andar,int *fila,int *coluna)
{
    int i, j, k;

    for(i = 0; i < ANDARES; i++)
    {
        for(j = 0; j < FILAS; j++)
        {
            for(k = 0; k < COLUNAS; k++)
            {
                if(estacionamento[i][j][k].ocupada == 1&&strcmp(estacionamento[i][j][k].placa,placa) == 0)
                {
                    *andar = i;
                    *fila = j;
                    *coluna = k;

                    return 1;
                }
            }
        }
    }

    return 0;
}

int buscarVagaLivre(TVaga estacionamento[ANDARES][FILAS][COLUNAS],char tipo,int *andar,int *fila,int *coluna)
{
    int inicio;
    int fim;

    int i, j, k;

    if(tipo == 'M')
    {
        inicio = 0;
        fim = ANDARES_MENSALISTA;
    }
    else
    {
        inicio = ANDARES_MENSALISTA;
        fim = ANDARES;
    }

    for(i = inicio; i < fim; i++)
    {
        for(j = 0; j < FILAS; j++)
        {
            for(k = 0; k < COLUNAS; k++)
            {
                if(estacionamento[i][j][k].ocupada == 0)
                {
                    *andar = i;
                    *fila = j;
                    *coluna = k;

                    return 1;
                }
            }
        }
    }

    return 0;
}

float calcularValor(int minutos)
{
    int dias;

    if(minutos <= 30)
        return 6;

    else if(minutos <= 60)
        return 10;

    else if(minutos <= 120)
        return 15;

    else if(minutos <= 240)
        return 25;

    else if(minutos <= 360)
        return 35;

    else if(minutos <= 480)
        return 50;

    else if(minutos <= 1440)
        return 100;

    else
    {
        dias = (minutos - 1) / 1440;

        return 100 + (dias * 50);
    }
}

void entradaMensalista(TVaga estacionamento[ANDARES][FILAS][COLUNAS])
{
    char placa[8];

    int a, f, c;

    printf("Placa: ");

    scanf("%7s", placa);

    if(
        procurarPlaca(estacionamento,placa,&a,&f,&c)
    )
    {
        printf("Cliente encontrado!\n");

        printf("Vaga: %s\n",estacionamento[a][f][c].identificacao);

        return;
    }

    if(
        buscarVagaLivre(estacionamento,'M',&a,&f,&c) == 0)
    {
        printf("Sem vagas!\n");

        return;
    }

    estacionamento[a][f][c].ocupada = 1;

    strcpy(estacionamento[a][f][c].placa,placa);

    estacionamento[a][f][c].tipo = 'M';

    printf("Telefone: ");

    scanf("%19s",estacionamento[a][f][c].telefone);

    printf("Dia cadastro: ");

    scanf("%d",&estacionamento[a][f][c].diaCadastro);

    printf("Mes cadastro: ");

    scanf("%d",&estacionamento[a][f][c].mesCadastro);

    printf("Ano cadastro: ");

    scanf("%d",&estacionamento[a][f][c].anoCadastro);

    printf("Vaga reservada: %s\n",estacionamento[a][f][c].identificacao);
}

void entradaRotativo(TVaga estacionamento[ANDARES][FILAS][COLUNAS])
{
    char placa[8];
    int a, f, c;
    int repetido;

    do
    {
        repetido = 0;

        printf("Placa: ");

        scanf("%7s", placa);

        if(
            procurarPlaca(estacionamento,placa,&a,&f,&c))
        {
            printf("Carro ja estacionado!\n");

            repetido = 1;
        }

    } while(repetido == 1);

    if(
        buscarVagaLivre(estacionamento,'R',&a,&f,&c) == 0)
    {
        printf("Sem vagas!\n");

        return;
    }

    estacionamento[a][f][c].ocupada = 1;

    strcpy(estacionamento[a][f][c].placa,placa);

    estacionamento[a][f][c].tipo = 'R';

    printf("Dia entrada: ");

    scanf("%d",&estacionamento[a][f][c].diaEntrada);

    printf("Hora entrada: ");

    scanf("%d",&estacionamento[a][f][c].horaEntrada);

    printf("Minuto entrada: ");

    scanf("%d",&estacionamento[a][f][c].minutoEntrada);

    printf("Vaga: %s\n",estacionamento[a][f][c].identificacao);
}

void saidaVeiculo(TVaga estacionamento[ANDARES][FILAS][COLUNAS])
{
    char placa[8];
    int a, f, c;
    int diaSaida;
    int horaSaida;
    int minutoSaida;
    int entrada;
    int saida;
    int total;
    float valor;

    printf("Placa: ");

    scanf("%7s", placa);

    if(
        procurarPlaca(estacionamento,placa,&a,&f,&c) == 0)
    {
        printf("Veiculo nao encontrado!\n");

        return;
    }

    if(estacionamento[a][f][c].tipo == 'M')
    {
        printf("Mensalista liberado!\n");

        return;
    }

    printf("Dia saida: ");

    scanf("%d", &diaSaida);

    printf("Hora saida: ");

    scanf("%d", &horaSaida);

    printf("Minuto saida: ");

    scanf("%d", &minutoSaida);

    entrada =(estacionamento[a][f][c].diaEntrada* 1440)+(estacionamento[a][f][c].horaEntrada* 60)+estacionamento[a][f][c].minutoEntrada;

    saida =(diaSaida * 1440)+(horaSaida * 60)+minutoSaida;

    total = saida - entrada;

    valor = calcularValor(total);

    printf("Tempo: %d minutos\n",total);

    printf("Valor: %.2f\n",valor);

    estacionamento[a][f][c].ocupada = 0;

    strcpy(estacionamento[a][f][c].placa,"LIVRE");

    strcpy(estacionamento[a][f][c].telefone,"N/A");

    estacionamento[a][f][c].tipo = 'L';
}

void verificarMensalistas(TVaga estacionamento[ANDARES][FILAS][COLUNAS])
{
    int diaAtual;
    int mesAtual;
    int i, j, k;

    printf("Dia atual: ");
    scanf("%d", &diaAtual);

    printf("Mes atual: ");
    scanf("%d", &mesAtual);

    for(i = 0; i < ANDARES_MENSALISTA; i++)
    {
        for(j = 0; j < FILAS; j++)
        {
            for(k = 0; k < COLUNAS; k++)
            {
                if(estacionamento[i][j][k].ocupada&&estacionamento[i][j][k].tipo == 'M')
                {
                    if(mesAtual >estacionamento[i][j][k].mesCadastro||(mesAtual ==estacionamento[i][j][k].mesCadastro&&diaAtual >estacionamento[i][j][k].diaCadastro))
                    {
                        printf("Mensalista removido: %s\n",estacionamento[i][j][k].placa);

                        estacionamento[i][j][k].ocupada = 0;

                        strcpy(estacionamento[i][j][k].placa,"LIVRE");

                        strcpy(estacionamento[i][j][k].telefone,"N/A");

                        estacionamento[i][j][k].tipo = 'L';
                    }
                }
            }
        }
    }
}

void mostrarVagas(TVaga estacionamento[ANDARES][FILAS][COLUNAS])
{
    int i, j, k;

    for(i = 0; i < ANDARES; i++)
    {
        printf("\n======= ANDAR %c =======\n",'A' + i);

        for(j = 0; j < FILAS; j++)
        {
            for(k = 0; k < COLUNAS; k++)
            {
                printf("%s",estacionamento[i][j][k].identificacao);

                if(estacionamento[i][j][k].ocupada)
                {
                    printf("[X] ");
                }
                else
                {
                    printf("[ ] ");
                }
            }

            printf("\n");
        }
    }
}

int main()
{
    TVaga estacionamento[ANDARES][FILAS][COLUNAS];

    int opcao;

    carregarArquivo(estacionamento);

    do
    {
        printf("\n===== PARKRIO =====\n");

        printf("1 - Entrada mensalista\n");

        printf("2 - Entrada rotativo\n");

        printf("3 - Saida veiculo\n");

        printf("4 - Mostrar vagas\n");

        printf("5 - Verificar mensalistas\n");

        printf("0 - Sair\n");

        printf("Opcao: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:

                entradaMensalista(estacionamento);

                break;

            case 2:

                entradaRotativo(estacionamento);

                break;

            case 3:

                saidaVeiculo(estacionamento);

                break;

            case 4:

                mostrarVagas(estacionamento);

                break;

            case 5:

                verificarMensalistas(estacionamento);

                break;

            case 0:

                salvarArquivo(estacionamento);

                printf("Sistema encerrado!\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}