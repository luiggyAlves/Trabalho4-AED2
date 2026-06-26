# Trabalho4-AED2

* Grafo é um modelo matemático que representa as relações entre objetos de um dado conjunto 
* Um grafo G(V,A) possui um conjunto de vértices V, que são os itens que o grafo representará, e um conjunto A de arestas, que conecta dois vértices em virtude de algum critério pré estabelecido
* Conseguimos modelar em forma de grafos basicamente qualquer relacionamento entre objetos, a forma de modelar irá depender muito do contexto e da natureza do problema, mas eles configuram uma ferramenta muito útil para diversas áreas

### Representação por lista de adjascência
* Utiliza uma lista de vértices para descrever a relação entre os vértices. Um grafo que possui N vértices utiliza um array de ponteiros de N posições para armazenar os vértices do grafo.
* Para cada vértice é criada uma lista de arestas, onde cada posição da lista armazena tanto o indíce do vértice, quanto a qual vértice ele se conecta.
* Essa abordagem possui custo O(N+M), onde N é o número de vértices e M o número de arestas no grafo
* O uso de lista de adjascência é melhor quando temos muitos vértices e poucas arestas ligando esses vértices (esparsidade), conforme o número de arestas cresce, se for um grafo sem pesos, o uso de matriz de adjascência se torna mais eficiente, além disso, descobrir se dois vértices estão conectados é imediato na abordagem baseada em matriz.
