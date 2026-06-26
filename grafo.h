typedef struct grafo Grafo;
Grafo* cria_Grafo(int nro_verts, int Gmax, int eh_ponderado );
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int digrafo);
void buscaProfundidade_Grafo(Grafo* gr, int ini, int *visitado);