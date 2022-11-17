// Gere um relatório de performance de uma solução sequencial
// e paralela para o seguinte problema:

// Mostre quais, quantos e o somatório de todos números primos entre 
// de 100 à 5000000

#include<stdio.h>
#include<omp.h>
#define min 100
#define max 50000 // 500000

void paralelismo(){
int somatorio = 0 , contador = 0 , numeros = 0 , contaDivisores = 0 , quantidadeRepeticao = 10;
    double timeInicio , timeFim;

for(int t=0; t < quantidadeRepeticao; t++){
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
        printf("----- %d -------------\n" , t+1);
        printf("Tempo de execucao: %lf \n" , timeFim - timeInicio);
        printf("somatorio: %d \n" , somatorio);
        printf("quantidade: %d\n" , contador);
        somatorio = 0 , contador = 0;
    }
    //printf("somatorio: %d \n" , somatorio);
    //printf("quantidade: %d\n" , contador);
    
}

int main(){


    paralelismo();
    
    return 0;
}