#include<stdio.h>
#include<omp.h>

void funPesada(){
    int i , j;
    for(i = 0; i<1000000 ; i++){
        for(j = 0 ; j<10000;j++){

        }
    }
}

int main(){

    int numeroThreads , idThreads ;
    printf("Digite a quantidade de threads:");
        scanf("%d" , &numeroThreads);
    omp_set_num_threads(numeroThreads);
    
#pragma omp parallel
{
    idThreads = omp_get_thread_num();
    printf("Eu sou a thread [%d]\n" , idThreads);
    #pragma omp single
    {
       printf("Iniciando mundo paralelo\n");
    }
    #pragma omp barrier
    #pragma omp master
    {
        printf("Final [%d]", idThreads);
    }

}

    return 0;
}