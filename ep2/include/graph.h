#ifndef GRAPH_H
#define GRAPH_H
#define max_edges(N) ( (N) * (N-1) / 2 )

typedef struct
{
  int u;
  int v;
  float weigth;
} edge;

typedef struct
{
  int V; 
  int E;
  edge *edges;
  int allocatedSize;
} graph;

void init_graph(graph *g, int V, int maxEdges);
void destroy_graph(graph *g);
int compare_edge(const void *a, const void *b);
void init_edge(edge *e, int u, int v, float weigth);
void add_edge(graph *g, int u, int v, float weigth);
void print_edge(edge *e);
#endif
