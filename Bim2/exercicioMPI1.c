/*
Com base na estrutura aluno abaixo realize seguintes operações: 
a) O processo 0 deverá alocar um vetor e preencher um vetor de N alunos digitados 
pelo usuário. 
b) O Processo 1 deverá ler 1/3 (primeira parte) das matrículas e devolver para o 
processo 0. 
c) O processo 2 deverá ler 1/3 (segunda parte) das matrículas e devolver para o 
processo 0. 
d) O processo 3 deverá ler 1/3 (terceira parte) das matrículas e devolver para o 
processo 0. 
e) Cada processo (0-3) deverá ler uma das notas de cada aluno. 
f) O processo 0 deverá mostrar na tela qual o aluno com o maior média.*/
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define alunos 3


void preencheMatricula(int * matricula);

int main(){

    int idProcesso;
    int qtdProcessos;
    int * matricula ; 
    printf("asdawud\n");
    MPI_Init(NULL , NULL);

    MPI_Comm_rank(MPI_COMM_WORLD, &idProcesso);
    MPI_Comm_size(MPI_COMM_WORLD, &qtdProcessos);

    if(idProcesso == 0){
        matricula = (int*)calloc(qtdProcessos,sizeof(int));
    
    
    }

    




    MPI_Finalize();

    return 0;
}

void preencheMatricula(int * vetor){

    for(int i = 0; i < alunos ; i++){
        vetor[i] = i+1;
    }
}