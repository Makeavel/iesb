#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int qtd;
    struct lista * inicio;
}lista;

typedef struct elemento{
    int valor;
    struct registro * prox;
}elemento;
typedef struct vetice{
    int valor;
    int distancia;
    int visitado;  // = 0
    struct lista * lista_adj;
}vertice;
int qtd = 0;
lista * alocaLista(){
    lista * novo;
    novo = (lista*)malloc(sizeof(lista));
    novo -> inicio = NULL;
    return novo;
}
elemento * alocaElemento(){
    elemento * novo;
    novo = (elemento*)malloc(sizeof(elemento));
    novo -> prox = NULL;
    return novo;
}


void incluirFim(lista * l1 , int x){

    elemento * aux = NULL, *novo = NULL;

    novo = alocaElemento();
    novo -> valor = x;
    if(l1 -> inicio == NULL){
        l1-> inicio = novo;
    }
    else{
        aux = l1 -> inicio;
        while(aux-> prox != NULL){
            aux = aux->prox;
        }
        aux -> prox = novo;
        
    }
    l1-> qtd++;
}

void mostarLista(lista * l1){
    elemento * aux;
    if(l1 -> inicio == NULL){
        return ;
    }
    else{
        aux = l1-> inicio;
        while(aux != NULL){
            printf("%d " , aux->valor);
            aux = aux -> prox;
            //aux = aux -> prox;
        }
        //printf("\n");
    }
}

void dfs(vertice * vertices , int x , int distancia){
    elemento * aux;
    int i ;
    vertices[x].visitado=1;
    vertices[x].distancia = distancia;
    printf("%d \n", x);

    aux = vertices[x].lista_adj->inicio;

    while(aux != NULL){
        if(vertices[aux-> valor].visitado==0){
            dfs(vertices, aux->valor, distancia +1);
        }
        aux = aux -> prox;

    }
    //printf("\n");
}

void adicionaVertice(vertice * v1 , int x){
    if(v1->lista_adj == NULL){
        v1->lista_adj = alocaLista();
        incluirFim(v1->lista_adj, x);
    }
}


int main(){

    int qtdVertice = 0 , i = 0 , a , b;
    int q = 0;// qtd vertices
    int v =  q-1; // qtd de aresta
    int c = 0; // qtd consultas
    int aux=1 , count=0;

    lista * l1 = alocaLista();
    vertice * v1;

    printf("Num. Vertices:");
        scanf("%d", &qtdVertice);

    v1 = (vertice*)calloc(qtdVertice+1,sizeof(vertice));

    printf("\n junte os vertices\n");

    while(i < qtdVertice-1){
        scanf("%d %d", &a , &b);

        adicionaVertice(v1->lista_adj , a);
        adicionaVertice(v1->lista_adj , b);
    i++;

}
    printf("dfs\n");
        dfs(v1 , 1 , 0);

  

    return 0;
}

void mostrar_tudo (vertice * vertices, int qtd_vertices)
{
    int i,j;

    for(i=1;i<=qtd_vertices;i++)
    {
        printf("\n Vertice: %d",i);
        printf("\n Lista de adjacencias: ");

        for(j=0;j<vertices[i].lista_adj;j++)
        {
            printf("%d ",vertices[i].lista_adj[j]);
        }
    }
}