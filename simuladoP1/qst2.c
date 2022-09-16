#include<stdio.h>
#include<omp.h>

void funcaoPar(){
    printf("par: 2,4,6,8,10\n");
   
}
void funcaoImpar(){
    printf("impar: 1,3,5,7,9\n");
}
void funcaoPrimo(){
    printf("primo: 2,3,5,7\n");
}
int main(){

    int idThread ; 
    omp_set_num_threads(2);

#pragma omp parallel
{

    #pragma omp sections
    {
        #pragma omp section
        {
            funcaoPar();
        }
        #pragma omp section
        {
            funcaoImpar();
        }
        #pragma omp section
        {
            funcaoPrimo();
        }
    }
}


    return 0;
}