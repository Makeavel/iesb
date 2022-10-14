#include<stdio.h>
#include<omp.h>

int primo(int x){

    int i , j , z;
    double t1 , t2;
    t1 =  omp_get_wtime();    
    for(i = 0;i<10000;i++){
        for(j = 0; j<10000;j++){
            z = 1;
        }
    }
    if((x==0) || (x==1) ){
        return 0;
        int div;
        for(div = 2; div < x ; div++){
            if(x % div == 0){
                return 0;
            }
        }
    }
    t2 =  omp_get_wtime(); 
    printf("tempo: %lf\n" , t2-t1);
    return 1;
}

int main(){

    int i = 0 ,tamVetor;

    printf("Digite o tam do vetor:");
        scanf("%d" , &tamVetor);

    for(i = 0; i < tamVetor ; i++){
        int vetorUsuario[i];
    }
    int qtd_threads = omp_get_num_threads();
    int id_thread;
    id_thread = omp_get_thread_num();
#pragma omp parallel 
{
    
}

    
 #pragma omp for schedule(dynamic)
    for(int j = id_thread; j<tamVetor-1 ; j= j+id_thread){
        printf("Thread[%d] ----- \n", id_thread);
        primo(j);
    }
    

    return 0;
}