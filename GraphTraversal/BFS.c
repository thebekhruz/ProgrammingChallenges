#include <stdio.h>
#include <stdbool.h>

#define MAXV 100        // maximum number of verticies 
#define MAXDEGREE 50    // maximum vertex outdegree


typedef struct {
    int edges[MAXV+1][MAXDEGREE];
    int degree[MAXV+1];
    int nverticies;
    int nedges;
}graph;

 
void initialize_graph(graph *g){
    int i;

    g-> nverticies = 0;
    g -> nedges = 0;

    for (i=1; i<=MAXV; i++) g->degree[i] = 0;
}
void insertEdge(graph *g, int x, int y, bool directed){
    if(g->degree[x] > MAXDEGREE){
        printf("Warning: insertion(%d, %d) exceeds max degree\n",x,y);
    }
    g->edges[x][g->degree[x]] = y;
    g->degree[x]++;

    if(directed==false) {
        insertEdge(g,y,x,true);
    } else {
        g->nedges ++;}

}
void readGraph(graph *g, bool directed){
    int i;      // counter 
    int m;      // number of edges 
    int x,y;    // verticies in edge from x to y (x,y)
    initialize_graph(g);

    scanf("%d %d", &(g->nverticies), &m);

    for (i=1; i<=m; i++) {
        scanf("%d %d",&x,&y);
        insertEdge(g, x, y,directed);
    }
}  



void printGraph(graph *g){
    int i,j;

    for (i=1; i<=g->nverticies; i++) {
        printf("%d ",i);
        for (j=0; j<=g->degree[i]; j++) {
            printf("%d ",g->edges[i][j]);
        }
        printf("\n");
    }
}


int main() {
    graph g;
    bool directed = true;

    // Test case 1: empty graph
    initialize_graph(&g);
    printGraph(&g);

    // Test case 2: add one edge to the graph
    readGraph(&g, directed);
    printGraph(&g);

    // Test case 3: add multiple edges to the graph
    readGraph(&g, directed);
    printGraph(&g);

    // Test case 4: add an edge that exceeds the maximum degree
    insertEdge(&g, 1, 2, directed);
    printGraph(&g);

    // Test case 5: create an undirected graph
    directed = false;
    readGraph(&g, directed);
    printGraph(&g);

    return 0;
}
