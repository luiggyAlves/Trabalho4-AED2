#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    // Questão 4
    // Criando um grafo para os testes de busca
    int digrafo = 0 // Usarei um grafo não direcionado
    Grafo* gr = cria_Grafo(5,5,0);
    insereAresta(gr,0,1,digrafo,0);
    insereAresta(gr,1,3,digrafo,0);
    insereAresta(gr,1,2,digrafo,0);
    insereAresta(gr,2,4,digrafo,0);
    insereAresta(gr,3,0,digrafo,0);
    insereAresta(gr,3,4,digrafo,0);
    insereAresta(gr,4,1,digrafo,0);

    // Aplicando a busca em profundidade para achar todos os caminhos possíveis de um nó inicial para um nó alvo.

    lbera_grafo(gr);

}