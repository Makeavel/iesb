#include<stdio.h>
#include<omp.h>

void primo(int min , int max){
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

void ultimoPrimo(int min , int max){

}

void numPerfeito(int min , int max){

}



int main(){

    int numEntrada1 , numEntrada2 ;

    printf("Digite 2 numeros:");
        scanf("%d", &numEntrada1 , &numEntrada2);
    
#pragma omp parallel
{

    #pragma omp sections
    {
        #pragma omp section
            primo(numEntrada1 , numEntrada2);

    }

}

    return 0;
}