#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// Criando e destruindo um grafo
Grafo* cria_Grafo(int nro_vert, int Gmax, int eh_ponderado){
    // alocando um grafo na memória
    Grafo* gr =  (Grafo*) malloc(sizeof(struct grafo));
    if(gr){ // verificando se a alocação deu certo
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
    if(gr){
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

// Remover uma aresta (depois)

// Busca em profundidade
// função recebe o grafo, o vértice inicial, um array que conterá o caminho dos vértices visitados e um contador que nos ajudará a medir quais vértices já foram visitados
void buscaProfundidade(Grafo* gr, int ini, int* visitado, int cont){
    visitado[ini] = cont; // vértice inicial marcado como visitado
    for(int i=0; i<gr->grau[ini]; i++){
        if(!visitado[gr->arestas[ini][i]]){ // irá chamar a função recursivamente para os vizinhos não visitados ainda
            buscaProfundidade(gr,gr->arestas[ini][i], visitado, cont+1);
        }
    }
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado){
    int cont = 1;
    for(int i=0; i<gr->nro_vert; i++) {visitado[i]=0;}
    buscaProfundidade(gr, ini, visitado, cont);
}

// Busca em profundidade adaptada para encontrar TODOS os caminhos entre um vértice inicial e um vértice alvo
// recebe o grafo, o vértice atual, o destino, o vetor de visitados, o vetor que guarda o caminho em construção, a posição atual nesse vetor e um contador de caminhos encontrados
void buscaTodosCaminhos(Grafo* gr, int atual, int destino, int* visitado, int* caminho, int pos, int* contador){
    visitado[atual] = 1; // marca o vértice como visitado apenas para este ramo da busca
    caminho[pos] = atual; // guarda o vértice atual na posição correspondente do caminho
    pos++;

    if(atual == destino){ // achou o destino, então o caminho construído até aqui é válido
        (*contador)++;
        printf("  %2d. ", *contador);
        for(int i=0; i<pos; i++){
            printf("%d", caminho[i]);
            if(i < pos-1) printf(" -> ");
        }
        printf("\n");
    } else {
        for(int i=0; i<gr->grau[atual]; i++){
            int vizinho = gr->arestas[atual][i];
            if(!visitado[vizinho]){ // só avança para vizinhos que não estão no caminho atual
                buscaTodosCaminhos(gr, vizinho, destino, visitado, caminho, pos, contador);
            }
        }
    }

    visitado[atual] = 0; // desmarca ao retornar (backtracking), permitindo que o vértice seja usado em outros caminhos
}

int buscaTodosCaminhos_Grafo(Grafo* gr, int ini, int destino){
    int* visitado = (int*) calloc(gr->nro_vert, sizeof(int));
    int* caminho = (int*) malloc(gr->nro_vert * sizeof(int));
    int contador = 0;
    buscaTodosCaminhos(gr, ini, destino, visitado, caminho, 0, &contador);
    if(contador == 0){
        printf("  (nenhum caminho encontrado)\n");
    }
    free(visitado);
    free(caminho);
    return contador;
}

