typedef struct grafo{
    int eh_ponderado; // define se as arestas tem peso ou não
    int nro_vert; // define o número de vértices que o grafo terá
    int Gmax; // define o grau de conectitivade máximo de cada vértices, ou seja, a quantidade de arestas que um grafo poderá possuir o conectando a outro
    int** arestas; // array de ponteiros onde a lista encadeada contendo as arestas será alocada
    float** pesos; // se o grafo for ponderado, aqui será alocados a matriz de pesos para cada aresta.
    int* grau; // vetor que armazenará a quantidade de arestas já alocadas naquele vértice (grau de conectividade)
}Grafo;

// Código ANSI usado para destacar o total de caminhos encontrados no terminal
#define COR_VERDE    "\x1b[32m"
#define COR_RESET    "\x1b[0m"

Grafo* cria_Grafo(int nro_vert, int Gmax, int eh_ponderado );
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int digrafo);
void buscaProfundidade_Grafo(Grafo* gr, int ini, int *visitado);
int buscaTodosCaminhos_Grafo(Grafo* gr, int ini, int destino);