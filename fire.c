//Dada uma determinada entrada composta pela quantidade de funcionarios q e quantas relacoes
//de amizades F há entre eles, leia F pares de funcionarios correspondente a relação de amizade e diga
// quantas rotas de fuga são necessarias?
//quantas combinações de lideres são possíveis?
// existe 1 rota para cada grupo de amigos
//chefe de equipe é 1 pessoa escolhida dentre um grupo de amigos para orientalos
//ex:
// 6 3 
// 1 2
// 2 3
// 4 5

// saida
// 3 6

#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    struct lista *lista_adj;
} vertice;

typedef struct lista{
    int qtd;
    struct elemento *inicio;
} lista;

typedef struct elemento{
    int valor;
    struct elemento *prox;
} elemento;

int qtd=0;

vertice *aloca_vertice(){
  vertice *novo;
  novo = (vertice*)calloc(10000,sizeof(vertice));
  return novo;
}

lista *aloca_lista(){
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

elemento *aloca_elemento(){
    elemento *novo;
    novo = (elemento *)calloc(1, sizeof(elemento));
    return novo;
}

void incluir(lista *l, int x){
    elemento * novo;
    elemento *aux;
    novo = aloca_elemento();
    novo->valor = x;

    if (l->inicio==NULL){
        l->inicio = novo;
    }else{
        aux = l->inicio;
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
}

void add_vertice(vertice *v, int x){
    if (v->lista_adj == NULL)
        v->lista_adj = aloca_lista();
        incluir(v->lista_adj, x);
}

void dfs(vertice * vertices , int x){
    elemento * aux;
    vertices[x].visitado=1;
    qtd++;

    if (vertices[x].lista_adj==NULL){
        return;
    }
        
    aux = vertices[x].lista_adj->inicio;

    while(aux!=NULL){
        if (vertices[aux->valor].visitado==0){
            dfs(vertices,aux->valor); 
        }
        aux = aux->prox;
    }

}

void QuantidadeAmigos(vertice * vertices , int amigo ){
    elemento * aux;
    int count = 0;
    vertices[amigo].visitado = 1;
    qtd++;

    if(vertices[amigo].lista_adj == NULL){
        return;
    }
    
    aux = vertices[amigo].lista_adj -> inicio;

    while(aux != NULL){
        aux = aux->prox;
        count += 1;
    }

}

int main(){
    int qtd_vertices, qtd_arestas,i,a,b,cont=0;
    int aux=1;
    vertice * vertices;

    scanf("%d %d",&qtd_vertices,&qtd_arestas);
    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));

    i = 0;

    while(i<qtd_arestas){
        scanf("%d %d",&a,&b);
        add_vertice(&vertices[a],b);
        add_vertice(&vertices[b],a);
        i++;
    }
    
    for(i=1;i<=qtd_vertices;i++){
        if (vertices[i].visitado==0){
            dfs(vertices,i);
            aux = aux * qtd;
            cont++;
        } 
    }

    printf("%d ",cont);
    printf("\n");
    return 0;
}



