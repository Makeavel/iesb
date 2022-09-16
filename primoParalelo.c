#include<stdio.h>
#include<omp.h>
#define min 100
#define max 500000
#define contFor = 10

void paralelismo(){
int somatorio = 0 , contador = 0 , numeros = 0 , contaDivisores = 0 , quantidadeRepeticao = 10;
    double timeInicio , timeFim;
    int id;
    id = omp_get_thread_num();
    timeInicio = omp_get_wtime();
    for(int i=min; i<max;i++){
        for(int j=1; j<i; j++){
            if(i % j == 0){
                contaDivisores +=1;
            }
        }
        if(contaDivisores == 1){
            //printf("Numero: %d\n" , i);
            somatorio += i;
            contador += 1;
        }
        contaDivisores = 0;
    } 
    timeFim = omp_get_wtime();
        printf(" thread[%d] -------------\n" , id );
        printf("Tempo de execucao: %lf \n" , timeFim - timeInicio);
        printf("somatorio: %d \n" , somatorio);
        printf("quantidade: %d\n" , contador);
        somatorio = 0 , contador = 0;
    
    //printf("somatorio: %d \n" , somatorio);
    //printf("quantidade: %d\n" , contador);
    
}


int main(){

#pragma omp parallel 
{   int contFor2 = 2 ;
    int i = 0;

#pragma omp sections nowait
{
#pragma omp section 
    paralelismo();
#pragma omp section 
    paralelismo();

}
}
 return 0;
}
