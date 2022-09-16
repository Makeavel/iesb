#include<stdio.h>
#include<omp.h>


int main(){

    int numThreadUsuario , numThreads , id_thread;
    printf("digite num threads desejadas:");
    scanf("%d" , &numThreadUsuario);
    omp_set_num_threads(numThreadUsuario);
    
#pragma omp parallel
{
    id_thread = omp_get_thread_num();
    
  

    printf("Eu sou a thread[%d]\n", id_thread);

    #pragma omp single
    {
        printf("Iniciando mundo paralelo\n");
    }
      #pragma omp master
    {
        printf("Fim - thread[%d]" , id_thread);
        
    }
}
    return 0;
}