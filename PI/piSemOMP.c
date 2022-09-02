#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define num_thread 1

static long num_steps = 1000000;
double step;

int main(){

double pi;
double sum = 0.0;
double tInicio , tFim;
double resultado[num_thread];
tInicio = omp_get_wtime();    
int qtd_threads = omp_get_num_threads();
omp_set_num_threads(num_thread);
step = 1.0/(double) num_steps;


int i;   
int id = omp_get_thread_num();
double x;


for ( i = id; i<num_steps;i= i+qtd_threads){
    x = (i+0,5)*step;
    resultado[id] = resultado[id] + 4.0/(1.0+x*x);
}
    

for(int p =0; p<qtd_threads ; p++){
    sum = sum + resultado[p];
}

pi = step * sum;
printf("%lf", pi);
tFim = omp_get_wtime();   
printf("\n%lf", tFim - tInicio);
return 0;

}

// gcc -fopenmp pragma.c
// ./a.out