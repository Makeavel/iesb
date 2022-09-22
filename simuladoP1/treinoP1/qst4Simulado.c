#include<stdio.h>
#include<omp.h>

int main(){

    int qtdThreads , id ;

    printf("Digite a qtd de threads:");
        scanf("%d", &qtdThreads);
    omp_set_num_threads(qtdThreads);

#pragma omp parallel
{
    id = omp_get_thread_num();
    printf("Eu sou a Thread[%d]\n" , id);

    #pragma omp single
    {
        printf("Iniciando Mundo Paralelo\n");
    }
    #pragma omp barrier
    #pragma omp master
    {
    printf("FIM - thread[%d]\n" , id);
    }
}

    return 0;
}