#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int qtd;
    struct lista * inicio;
}lista;
typedef struct elemento{
    int valor;
    struct lista * prox;
}elemento;
typedef struct vertice{
    int valor;
    int visitado;
    int distancia;
    struct lista * lista_adj;
}vertice;

lista * alocaLista(){
    lista * novo;
    novo = (lista*)calloc(1,sizeof(lista));
    novo -> qtd = 0;
    novo -> inicio = NULL;
    return novo;
}
elemento * alocaElemento(){
    elemento * novo;
    novo = (elemento*)calloc(1,sizeof(elemento));
    novo -> valor = 0;
    novo -> prox = NULL;
    return novo;
}

void inserirLista(lista * l1 , int x){
    elemento * aux ,* novo;
    
    novo = alocaElemento();
    novo -> valor = x;
    if(l1 -> inicio == NULL){
        l1 -> inicio = novo;
    }
    else{
        aux = l1->inicio;
        while(aux -> prox != NULL){
            aux = aux -> prox;
        }
    }
    l1 -> qtd++;
}

void mostrarLista(lista * l1){
    elemento * aux;
    aux = l1->inicio;
    while(aux -> prox != NULL){
        printf("%d ", aux->valor);
        aux = aux -> prox;
    }
    
}


void dfs(vertice * v1 , int valor ){
    elemento * aux;

    v1[valor].visitado = 1;
    aux = v1[valor].lista_adj->inicio;
    printf("%d" , valor);
    while(aux != NULL){
        if(v1[aux->valor].valor == 0){
            dfs(v1,aux ->valor);
        }
        aux = aux->prox;
    }
}

void addVertice(vertice * v1 , int x){
    if(v1->lista_adj == NULL){
        v1->lista_adj = alocaLista();
        inserirLista(v1->lista_adj , x);
    }
}

void mostarVertices(vertice * v1 , int tam){

    int i , j;

    for(i = 0; i<tam ; i++){
        printf("vertice: %d" , i );
        printf("lista adjacencia:");

        for(j=0; v1[i].lista_adj;j++){
            printf("%d", v1[i].lista_adj[j]);
        }

    }
}

int main(){

    int qtdVertice = 0, i = 0;
    int a , b ,c;
    lista * l1 = alocaLista();
    vertice * v1;

    printf("Num de vertices:");
        scanf("%d", &qtdVertice);
    

    
    v1 = (vertice*)calloc(qtdVertice+1,sizeof(vertice));
    
    while(i < qtdVertice -1){
        scanf("%d %d", &a , &b);

        addVertice(v1->lista_adj , a);
        addVertice(v1->lista_adj, b);
        i++;
    }
    

    return 0;
}

