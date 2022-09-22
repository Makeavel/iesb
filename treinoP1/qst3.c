#include<stdio.h>
#include<omp.h>
#define  tamVetor 100

int Par(int idThread,int x){

    int i , somatorio= 0;

    #pragma omp for schedule(dynamic)
    for(i = 0; i< tamVetor ;i++){
        if(i % 2 == 0){
            somatorio += i;
            printf("Par: i:%d  %d [%d]\n",i, somatorio , idThread);
        }
    }
    
    
    return somatorio;
}

int Impar(int idThread){

    int i , somatorio = 0;

    #pragma omp for schedule(dynamic)
    for(i = 0 ; i < tamVetor ; i++){
        if(i % 2 != 0){
            somatorio = somatorio + i;   
        }
    }

    printf("Impar: i:%d  %d [%d]\n",i , somatorio , idThread);
    return somatorio;
}

int main(){

    int idThreads;
    omp_set_num_threads(2);

#pragma omp parallel
{
    int x;
    idThreads = omp_get_thread_num();
      
        
            Par(idThreads, x);
        
            Impar(idThreads);
    

}

    return 0;
}