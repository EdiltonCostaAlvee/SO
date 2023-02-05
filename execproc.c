/* Escalonador de processos CPU-bound em modo usuário*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Estrutura do processo */
struct Processo
{
    int id;                   /* id do processo*/
    int tempoDuracaoProcesso; /* Tempo de duração do processo*/
    int prioridade;           /* Nível de prioridade alta, média e baixa*/
    int tempoExecucao;        /* Tempo de execução do processo*/
    int tempoEspera;          /* Tempo de espera do processo*/
    struct Processo *proximo;
};

/* Declarações de Protótipo de função */
struct Processo *iniciarProcesso(int id, int tempoDuracaoProcesso, int prioridade);
void primeiroProcessoChega(struct Processo *proc);
void listaProcessos(struct Processo *proc);
void prioridade(struct Processo *proc);
void roundRobin(struct Processo *proc, int quantum);
void processoFinal(struct Processo *proc);

int main(void)
{

    struct Processo *listaProcesso, *processoTemporario;
    int contador = 1;
    int numProcesso = 0;
    int numPrioridadeProcesso = 5;
    int timeMileSegundos = 3000;
    int qtdMaximaProcesso = 0;

    printf("\nInforme a quantidade máxima de processos, lembrando que a quantidade máxima vai até 10 processos: ");
    scanf("%d", &qtdMaximaProcesso);
    if (qtdMaximaProcesso == 0 || qtdMaximaProcesso > 10)
    {
        printf("\nA quantidade máxima deve ser entre 1 e 10, tente novamente: ");
        exit(1);
    }

    if (qtdMaximaProcesso == 1)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
    }

    if (qtdMaximaProcesso == 2)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        // processoTemporario = listaProcesso->proximo;
    }

    if (qtdMaximaProcesso == 3)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = listaProcesso->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        // processoTemporario = processoTemporario->proximo;
    }

    if (qtdMaximaProcesso == 4)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = listaProcesso->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        // processoTemporario = processoTemporario->proximo;
    }

    if (qtdMaximaProcesso == 5)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = listaProcesso->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        // processoTemporario = processoTemporario->proximo;
    }

    if (qtdMaximaProcesso == 6)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = listaProcesso->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        // processoTemporario = processoTemporario->proximo;
    }

    if (qtdMaximaProcesso == 7)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = listaProcesso->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        // processoTemporario = processoTemporario->proximo;
    }

    if (qtdMaximaProcesso == 8)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = listaProcesso->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        // processoTemporario = processoTemporario->proximo;
    }

    if (qtdMaximaProcesso == 9)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = listaProcesso->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        // processoTemporario = processoTemporario->proximo;
    }

    if (qtdMaximaProcesso == 10)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = listaProcesso->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        // processoTemporario = processoTemporario->proximo;
    }

    /*while (contador <= qtdMaximaProcesso)
    {
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        if (contador == 1)
        {
            listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        }
        else
        {
            listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        }

        contador++;
    }*/

    /*
        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        listaProcesso->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = listaProcesso->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        processoTemporario = processoTemporario->proximo;

        printf("\nInforme o número do processo: ");
        scanf("%d", &numProcesso);
        printf("\nInforme a prioridade do processo %d:", numProcesso);
        scanf("%d", &numPrioridadeProcesso);
        processoTemporario->proximo = iniciarProcesso(numProcesso, timeMileSegundos, numPrioridadeProcesso);
        */

    /*
    listaProcesso = iniciarProcesso(1, 3000, 2);
    listaProcesso->proximo = iniciarProcesso(2, 3000, 1);
    processoTemporario = listaProcesso->proximo;
    processoTemporario->proximo = iniciarProcesso(3, 3000, 3);
    processoTemporario = processoTemporario->proximo;
    processoTemporario->proximo = iniciarProcesso(4, 3000, 3);
    processoTemporario = processoTemporario->proximo;
    processoTemporario->proximo = iniciarProcesso(5, 3000, 1);
    processoTemporario = processoTemporario->proximo;
    processoTemporario->proximo = iniciarProcesso(6, 3000, 3);
    processoTemporario = processoTemporario->proximo;
    processoTemporario->proximo = iniciarProcesso(7, 3000, 2);
    processoTemporario = processoTemporario->proximo;
    processoTemporario->proximo = iniciarProcesso(8, 3000, 2);
    processoTemporario = processoTemporario->proximo;
    processoTemporario->proximo = iniciarProcesso(9, 3000, 1);
    processoTemporario = processoTemporario->proximo;
    processoTemporario->proximo = iniciarProcesso(10, 3000, 2);
    */

    /* iniciar simulação*/
    listaProcessos(listaProcesso);
    primeiroProcessoChega(listaProcesso);
    processoFinal(listaProcesso);
    prioridade(listaProcesso);
    roundRobin(listaProcesso, qtdMaximaProcesso);

    while (listaProcesso != NULL)
    {
        processoTemporario = listaProcesso;
        listaProcesso = listaProcesso->proximo;
        free(processoTemporario);
    };
    return (0);
};

/* Iniciar processo*/
struct Processo *iniciarProcesso(int id, int tempoDuracaoProcesso, int prioridade)
{
    struct Processo *processo;
    processo = (struct Processo *)malloc(sizeof(struct Processo));
    if (processo == NULL)
    {
        printf("Erro: Falha na alocação de memória.\nFim.\n");
        exit(1);
    };
    processo->id = id;
    processo->tempoDuracaoProcesso = tempoDuracaoProcesso;
    processo->prioridade = prioridade;
    processo->tempoExecucao = 0;
    processo->tempoEspera = 0;
    processo->proximo = NULL;
    return (processo);
};

/* Lista processos*/
void listaProcessos(struct Processo *processo)
{
    struct Processo *temporario = processo;
    printf("\tLISTA DE PROCESSOS\n");
    printf("\n");
    while (temporario != NULL)
    {
        printf("Processo: %d\tPrioridade: %d\tTempo em mile segundos: %d\n", temporario->id, temporario->prioridade, temporario->tempoDuracaoProcesso);
        temporario = temporario->proximo;
    };
    printf("\n");
};

/* Escala de Processos por Prioridade
 * Exemplo: prioridade 1 é maior que prioridade 2 e assim por diante
 */
void prioridade(struct Processo *processo)
{
    int tempo, inicio, fim, maior;
    struct Processo *copia, *processoTemporario, *temporario, *maiorPrimeiro;
    printf("\tESCALA DE PRIORIDADE\n");
    printf("\n");

    /* Criando replica de Processos*/
    processoTemporario = processo;
    copia = temporario = NULL;
    while (processoTemporario != NULL)
    {
        if (copia == NULL)
        {
            copia = iniciarProcesso(processoTemporario->id, processoTemporario->tempoDuracaoProcesso, processoTemporario->prioridade);
            temporario = copia;
        }
        else
        {
            temporario->proximo = iniciarProcesso(processoTemporario->id, processoTemporario->tempoDuracaoProcesso, processoTemporario->prioridade);
            temporario = temporario->proximo;
        };
        processoTemporario = processoTemporario->proximo;
    };

    /* Loop de de processos para verificar prioridades */
    clock_t t1, t2;
    t1 = clock();
    tempo = t1;
    while (copia != NULL)
    {
        /* Localiza o próximo processo */
        maiorPrimeiro = NULL;
        maior = copia->prioridade;
        temporario = copia->proximo;
        processoTemporario = copia;
        while (temporario != NULL)
        {
            if (temporario->prioridade < maior)
            {
                maior = temporario->prioridade;
                maiorPrimeiro = processoTemporario;
            };
            processoTemporario = temporario;
            temporario = temporario->proximo;
        };
        if (maiorPrimeiro == NULL)
        {
            /* Verifica se o primeiro tem a prioridade maior*/
            inicio = tempo;
            tempo += copia->tempoDuracaoProcesso;
            fim = tempo;
            printf("Processo: %d\tTempo em mile segundos: %d\tInício: %d\tFim: %d\n", copia->id, tempo, inicio, fim);
            processoTemporario = copia->proximo;
            free(copia);
            copia = processoTemporario;
        }
        else
        {
            /* Verifica se o primeiro processo não tem a prioridade maior*/
            temporario = maiorPrimeiro->proximo;
            inicio = tempo;
            tempo += temporario->tempoDuracaoProcesso;
            fim = tempo;
            printf("Processo: %d\tTempo em mile segundos: %d\tInício: %d\tFim: %d\n", temporario->id, tempo, inicio, fim);
            maiorPrimeiro->proximo = temporario->proximo;
            free(temporario);
        };
        // pega esse
        // t2 = clock();
        // mile segundos
        // float diff = (((float)t2 - (float)t1) / 1000000.0F);
        // printf("Tempo em mile segundos: %f", diff);
    };

    printf("\n:::::::::::::::::::::::::::: Fim :::::::::::::::::::::::::::::\n");
    printf("\n");
    // exit(1);
};

/* Escalando o primeiro processo que chega
/* é o primeiro processo ao sair */
void primeiroProcessoChega(struct Processo *processo)
{
    int tempo = 0, inicio, fim;
    struct Processo *temporario = processo;
    printf("\tESCALANDO O PRIMEIRO PROCESSO QUE CHEGA\n");
    printf("\n");
    clock_t t1;
    t1 = clock();
    tempo = t1;
    while (temporario != NULL)
    {
        inicio = tempo;
        tempo += temporario->tempoDuracaoProcesso;
        fim = tempo;
        printf("Processo: %d\tTempo em mile segundos: %d\tInício: %d\tFim: %d\n", temporario->id, tempo, inicio, fim);
        temporario = temporario->proximo;
    };
    printf("\n");
};

/* Escalando Round-Robin*/
void roundRobin(struct Processo *processo, int quantum)
{
    int permanece, passa;
    struct Processo *copia, *copiaTemporaria, *temporario, *suporte;
    printf("\tESCALANDO ROUND-ROBIN - QUANTUM: (%d)\n", quantum);
    printf("\n");
    copiaTemporaria = processo;
    copia = temporario = NULL;
    while (copiaTemporaria != NULL)
    {
        if (copia == NULL)
        {
            copia = iniciarProcesso(copiaTemporaria->id, copiaTemporaria->tempoDuracaoProcesso, copiaTemporaria->prioridade);
            temporario = copia;
        }
        else
        {
            temporario->proximo = iniciarProcesso(copiaTemporaria->id, copiaTemporaria->tempoDuracaoProcesso, copiaTemporaria->prioridade);
            temporario = temporario->proximo;
        };
        copiaTemporaria = copiaTemporaria->proximo;
    };

    /* Análise de prioridade*/
    permanece = 2;
    suporte = NULL;
    while (permanece)
    {
        permanece = 0;
        /* Aloca o próximo processo selecionado*/
        if (suporte == NULL)
        {
            suporte = copia;
            permanece = 2;
        }
        else
        {
            passa = 0;
            do
            {
                if (suporte->proximo == NULL)
                {
                    passa++;
                    suporte = copia;
                }
                else
                {
                    suporte = suporte->proximo;
                };
            } while (passa <= 3 && suporte->tempoDuracaoProcesso == suporte->tempoExecucao);
            if (passa <= 3)
            {
                permanece = 2;
            };
        };

        temporario = copia;
        while (temporario != NULL)
        {
            if (temporario->tempoDuracaoProcesso > temporario->tempoExecucao)
            {
                if (temporario == suporte)
                {
                    temporario->tempoExecucao += quantum;
                }
                else
                {
                    temporario->tempoEspera += quantum;
                };
            };
            temporario = temporario->proximo;
        };
    };

    /* Mostra resultado e elimina as replicas */
    temporario = copia;
    while (temporario != NULL)
    {
        printf("Processo: %d\tTempo em mile segundos: %d\tInício: %d\tFim: %d\n", temporario->id, temporario->tempoDuracaoProcesso, temporario->tempoEspera, temporario->tempoExecucao + temporario->tempoEspera);
        copiaTemporaria = temporario;
        temporario = temporario->proximo;
        free(copiaTemporaria);
    };
    printf("\n");
};

/* Escalando processo final*/
void processoFinal(struct Processo *processo)
{
    int tempo, inicio, fim, testeRapido;
    struct Processo *copia, *copiaTemporaria, *processoTemporario, *temporario;
    printf("\tESCALA FINAL\n");
    printf("\n");

    /* Lista de processos replicada*/
    copiaTemporaria = processo;
    copia = processoTemporario = NULL;
    while (copiaTemporaria != NULL)
    {
        if (copia == NULL)
        {
            copia = iniciarProcesso(copiaTemporaria->id, copiaTemporaria->tempoDuracaoProcesso, copiaTemporaria->prioridade);
            processoTemporario = copia;
        }
        else
        {
            processoTemporario->proximo = iniciarProcesso(copiaTemporaria->id, copiaTemporaria->tempoDuracaoProcesso, copiaTemporaria->prioridade);
            processoTemporario = processoTemporario->proximo;
        };
        copiaTemporaria = copiaTemporaria->proximo;
    };

    clock_t t1;
    t1 = clock();
    tempo = t1;
    while (copia != NULL)
    {
        /* Encontra próximo processo*/
        temporario = NULL;
        testeRapido = copia->tempoDuracaoProcesso;
        processoTemporario = copia->proximo;
        copiaTemporaria = copia;
        while (processoTemporario != NULL)
        {
            if (processoTemporario->tempoDuracaoProcesso < testeRapido)
            {
                testeRapido = processoTemporario->tempoDuracaoProcesso;
                temporario = copiaTemporaria;
            };
            copiaTemporaria = processoTemporario;
            processoTemporario = processoTemporario->proximo;
        };

        /* Executa processo e remove ráplica da lista de processos*/
        if (temporario == NULL)
        {
            /* Se o primeiro processo for menor será alocado*/
            inicio = tempo;
            tempo += copia->tempoDuracaoProcesso;
            fim = tempo;
            printf("Processo: %d\tTempo em mile segundos: %d\tInício: %d\tFim: %d\n", copia->id, tempo, inicio, fim);
            copiaTemporaria = copia;
            copia = copia->proximo;
            free(copiaTemporaria);
        }
        else
        {
            /* Se não houver outro processo menor o primeiro será alocado*/
            processoTemporario = temporario->proximo;
            inicio = tempo;
            tempo += processoTemporario->tempoDuracaoProcesso;
            fim = tempo;
            printf("Processo: %d\tTempo em mile segundos: %d\tInício: %d\tFim: %d\n", processoTemporario->id, tempo, inicio, fim);
            temporario->proximo = processoTemporario->proximo;
            free(processoTemporario);
        }
    }

    system("read -p '\n\n\tPRESSIONE ENTER PARA EXECUTAR O ESCALONAMENTO ROUND-ROBIN\n\n' var");
}