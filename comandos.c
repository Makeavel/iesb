#include<stdio.h>
#include<omp.h>
#define numFor 4

void funPesada(){
    int x , y , j;

    for(x = 0 ; x > 5000000;x++){
        for(y=0; y> 4999999;y++){
            for(j = 0 ; j< 10000000;j++){}
        }
    }
}

int main(){

    int numThreadsDisponiveis , qtdThreads = 4 ;
    double tInicio , tFim ;

    numThreadsDisponiveis = omp_get_num_threads(); // retorna quantas threads existem para se utilizar
    printf("O numero de threads inicialmente disponíveis [%d]\n" , numThreadsDisponiveis);

    omp_set_num_threads(qtdThreads); // define a quantidade de threads que serão utilizadas

    tInicio = omp_get_wtime(); // inicia a contagem de tempo
    funPesada();
    tFim = omp_get_wtime(); // termina a contagem de tempo
    printf("tempo: %lf\n", tFim - tInicio);

#pragma omp parallel   //inicializa o paralelismo
{
    int atomic , idThread = omp_get_thread_num(); //retorna o numero da thread executando o bloco de código
    printf("Sou a thread [%d]\n", idThread);

    #pragma omp barrier // comando para dar um break em todas as threads para todas partirem ao mesmo tempo desse ponto
        //printf("Sou a barrier e parei a thread [%d] aqui\n" , idThread);
    #pragma omp critical // apenas uma thread pode executar o comando abaixo por vez
        funPesada();
        printf("Sou a thread [%d] e rodei a funPesada()\n", idThread);

    #pragma omp atomic // promove a atualização de algo na memória (exemplo: atomic)
        atomic += 1;

    #pragma omp for // comando para realizar um laço for em cada thread
        for(int i = 0; i<numFor ; i++){
            funPesada();
            printf("Entrei no for - thread[%d]\n" , idThread);
        }
    #pragma omp for schedule(dynamic) // quando uma thread termina uma execução já pega outro elemento para rodar
        for(int i = 0; i<numFor ; i++){
            funPesada();
        }
    #pragma omp for collapse(2) // usado quando temos for dentro de for.
        for(int i = 0; i<numFor ; i++){
            for(int i = 0; i<numFor ; i++){
                funPesada();
            }
        }
    #pragma omp for nowait // ao por nowait tira do bloco for a barreira implícita que havia. resumindo, executou e passa reto
        for(int i = 0; i<numFor ; i++){
            funPesada();
        }

    #pragma omp master // aqui só entra a thread 0 , a primária. Obs. Possui barrier implicito 
    {
        printf("Sou a thread de menor indice(master) [%d]\n", idThread);
    }

    #pragma omp single //(nowait)// apenas a 1º thread que bater aqui vai executar essa função Obs. Possui barrier implícito
    {
        printf("A primeira thread que entrar aqui roda [%d]\n", idThread);
    }

    #pragma omp sections //divide o trabalho entre as threads, onde cada uma executa uma função separada. Obs possui barrier implícito
    {
        #pragma omp section
            printf("Sou a thread[%d] rodando uma section\n" , idThread);
        #pragma omp section
            printf("Sou a thread[%d] rodando uma section\n" , idThread);
        #pragma omp section
            printf("Sou a thread[%d] rodando uma section\n" , idThread);
    }

}
    return 0;
}