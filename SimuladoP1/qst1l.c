#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int qtd;
  struct lista *inicio;
}lista;

typedef struct registro{
  int valor;
  struct registro *prox;
}registro;

typedef struct vertice{
  int distancia;
  int visitado;
  int valor;
  struct lista *lista_adj;
}vertice;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_fim(lista *l, int x);
void mostrar_lista(lista *l);
void dfs(vertice *v, int x, int distancia);
void add_vertice(vertice *v, int x);

int qtd =0;

int main() {

  vertice *vertices;
  int Q = 0; //qtd de vertices
  int V = Q-1; // qtd de vertices
  int C = 0; //qtd de consultas
  int a,b = 0;
  int i = 0;
  int aux =1;

  printf("\nDigite a quantidade de vertices\n");
  scanf("%d", &Q);

  vertices = (vertice*)calloc(Q+1,sizeof(vertice));

  printf("\nUna os vertices:.\n\n");

  while (i<Q-1) {
    scanf("%d %d", &a, &b);
    add_vertice(&vertices[a], b);
    add_vertice(&vertices[b], a);
    i++;
  }

  printf("\n Digite a quantidade de consultas: \n");
  scanf("%d", &C);

  int x1,y1 =0;
  int x2,y2 =0;
  int x3,y3 =0;


  scanf("%d %d", &x1, &y1);
  scanf("%d %d", &x2, &y2);
  scanf("%d %d", &x3, &y3);

  dfs(vertices, 1, 0);
  for(i=1;i<=Q;i++)
  {
      printf("\n %d possui distancia %d\n",i,vertices[i].distancia);
  }


  return 0;
}

void add_vertice(vertice *v, int x){
  if (v->lista_adj == NULL)
    v->lista_adj = aloca_lista();

  incluir_no_fim(v->lista_adj, x);
}

lista *aloca_lista(){
  lista *novo;
  novo = (lista*)calloc(1,sizeof(lista));
  return novo;
}

registro *aloca_registro(){
  registro *novo;
  novo = (registro*)calloc(1,sizeof(registro));
  return novo;
}

void incluir_no_fim(lista *l, int x){
  registro *aux, *novo = NULL;

  novo = aloca_registro();
  novo->valor = x;

  if (l->inicio == NULL) {
    l->inicio = novo;
  }
  else{
    aux = l->inicio;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
  l->qtd++;
}

void mostrar_lista(lista *l){
  registro *aux = NULL;

  if(l->inicio == NULL) return;

  aux = l->inicio;

  while (aux != NULL) {
      printf("\n -> %d", aux->valor);
      aux = aux->prox;
  }
}

void dfs(vertice *v, int x, int distancia){
  registro *aux;
  v[x].visitado = 1;
  v[x].distancia = distancia;

//  printf("\t%d\n\n", x);

  aux = v[x].lista_adj->inicio;

  while (aux != NULL) {
    if(v[aux->valor].visitado == 0){
      dfs(v, aux->valor, distancia+1);
    }
    aux = aux->prox;
  }
}
