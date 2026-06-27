#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#define LINHA "+----------------------------------------------+"

int main(){
    // Questão 4
    // Criando um grafo (10 vértices) com arestas variadas para testar a busca de todos os caminhos
    int digrafo = 0; // Usarei um grafo não direcionado
    Grafo* gr;
    gr = cria_Grafo(10,6,0); // Gmax=6 dá margem para o vértice de maior grau (4,5 e 8 chegam a grau 4)

    insereAresta(gr,0,1,digrafo,0);
    insereAresta(gr,0,2,digrafo,0);
    insereAresta(gr,0,3,digrafo,0);
    insereAresta(gr,1,4,digrafo,0);
    insereAresta(gr,2,4,digrafo,0);
    insereAresta(gr,2,5,digrafo,0);
    insereAresta(gr,3,5,digrafo,0);
    insereAresta(gr,3,6,digrafo,0);
    insereAresta(gr,4,7,digrafo,0);
    insereAresta(gr,4,8,digrafo,0);
    insereAresta(gr,5,7,digrafo,0);
    insereAresta(gr,5,8,digrafo,0);
    insereAresta(gr,6,8,digrafo,0);
    insereAresta(gr,6,9,digrafo,0);
    insereAresta(gr,7,9,digrafo,0);
    insereAresta(gr,8,9,digrafo,0);

    // Aplicando a busca em profundidade para achar todos os caminhos possíveis de um nó inicial para um nó alvo.
    printf("\n%s\n", LINHA);
    printf(" Busca de todos os caminhos a partir do vertice 0\n");
    printf("%s\n\n", LINHA);

    for(int i=1; i<gr->nro_vert; i++){
        printf("%s\n", LINHA);
        printf(" Caminhos entre %d e %d\n", 0, i);
        printf("%s\n", LINHA);
        int total = buscaTodosCaminhos_Grafo(gr, 0, i);
        printf("%s\n", LINHA);
        printf(COR_VERDE " Total: %d caminho(s) encontrado(s)\n" COR_RESET, total);
        printf("%s\n\n", LINHA);
    }
    libera_Grafo(gr);

}