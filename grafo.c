#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo{
    int eh_ponderado; // define se as arestas tem peso ou não
    int nro_vert; // define o número de vértices que o grafo terá
    int Gmax; // define o grau de conectitivade máximo de cada vértices, ou seja, a quantidade de arestas que um grafo poderá possuir o conectando a outro
    int** arestas; // array de ponteiros onde a lista encadeada contendo as arestas será alocada
    float** pesos; // se o grafo for ponderado, aqui será alocados a matriz de pesos para cada aresta.
    int* grau; // vetor que armazenará a quantidade de arestas já alocadas naquele vértice (grau de conectividade)
};

// Criando e destruindo um grafo
Grafo* cria_Grafo(int nro_verts, int Gmax, int eh_ponderado){
    // alocando um grafo na memória
    Grafo* gr =  (Grafo*) malloc(sizeof(struct grafo));
    if(qr){ // verificando se a alocação deu certo
        // preenchendo as informações básicas do struct
        gr->nro_vert = nro_vert;
        gr->Gmax = Gmax;
        gr->eh_ponderado = (eh_ponderado!=0)?1:0; // se for diferente de 0, eh_ponderado recebe 1, senão, recebe 0;
        gr->grau = (int*)calloc(nro_vert,sizeof(int));
        gr->arestas = (int**)malloc(nro_vert*sizeof(int*));
        for(int i=0; i<nro_vert; i++){
            // Cada posição do vetor de arestas receberá o grau de conectividade máximo dos vértices (quantidade máxima de arestas que um vértice pode ter), basicamente tá virando uma lista onde a capacidade máxima é a quantidade de arestas que cada vértice pode possuir
            gr->arestas[i] = (int*) malloc(Gmax*sizeof(int));
        }
        
        // Caso o grafo seja ponderado
        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vert*sizeof(float*));
            for(int i=0; i<nro_vert; i++){
                gr->pesos[i] = (float*) malloc(Gmax*sizeof(float));
            }
        }
    }
    return gr;
}

// Destruindo um grafo
void libera_Grafo(Grafo* gr){
    if(qr){
        for(int i=0; i<gr->nro_vert; i++){
            free(gr->arestas[i]);
        }
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(int i=0; i<gr->nro_vert; i++){
                free(gr->pesos[i]);
            }
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

// Inserindo uma aresta

int insereAresta(Grafo* gr, int orig, int dest, int digrafo, float peso){
    // Verificando casos onde a inserção não é possível
    if(!gr) return 0;
    if(orig<0 || orig>=gr->nro_vert) return 0;
    if(dest<0 || dest>= gr->nro_vert) return 0;
    if(gr->grau[orig] == gr->Gmax) return 0;

    // Inserindo a aresta de fato
    gr->arestas[orig][gr->grau[orig]] = dest; // gr->gra[orig], atuará como um contador onde deve ser inserido o destino para explicitar a relação, pois ele guarda a quantidade de nós já inseridos, começando com 0 e indo até o grau de fato, onde a inserção irá falhar devido à verificação de exceções
    if(gr->eh_ponderado){
        gr->pesos[orig][gr->grau[orig]] = peso;
    }
    gr->grau[orig]++;
    if(!digrafo){
        // Se não for um digrafo, tanto destino se liga a origem quanto origem se liga a destino, é mutua a reolação
        return insereAresta(gr,dest,orig,1,peso);
    }
    return 1;
}
