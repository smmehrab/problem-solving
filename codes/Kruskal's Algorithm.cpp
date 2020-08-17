#include <bits/stdc++.h>
using namespace std;

class Edge{
	public:
	int src, dest, weight;
};

class Graph{
	public:
	int V, E;
	Edge* edge;
};

Graph* createGraph(int V, int E){
	Graph* graph = new Graph;

	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];



	return graph;
}

class Subset{
	public:
	int parent;
	int rank;
};

int findRoot(Subset subsets[], int i){
	if (subsets[i].parent != i)
		subsets[i].parent = findRoot(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y){
	int xRoot = findRoot(subsets, x);
	int yRoot = findRoot(subsets, y);

    if (subsets[xRoot].rank > subsets[yRoot].rank)
		subsets[yRoot].parent = xRoot;
	else if (subsets[xRoot].rank < subsets[yRoot].rank)
		subsets[xRoot].parent = yRoot;
	else{
		subsets[yRoot].parent = xRoot;
		subsets[xRoot].rank++;
	}
}

int myComp(const void* a, const void* b){
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->weight > b1->weight;
}

void findKruskalMST(Graph* graph){
	int V = graph->V;
	Edge result[V];

	int e = 0, i = 0, minCost = 0;

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

	Subset *subsets = new Subset[( V * sizeof(Subset) )];

	for (int v = 0; v < V; ++v){
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < V - 1 && i < graph->E){
		Edge next_edge = graph->edge[i++];

		int srcRoot = findRoot(subsets, next_edge.src);
		int destRoot = findRoot(subsets, next_edge.dest);

		if (srcRoot != destRoot){
			result[e++] = next_edge;
			minCost += next_edge.weight;
			unionSets(subsets, srcRoot, destRoot);
		}
	}

	/*
	for (i = 0; i < e; ++i)
		cout << result[i].src <<" -- " << result[i].dest <<"  "<< result[i].weight << endl;
    */
    cout << minCost << endl;
	return;
}

int main(){
	int V, E, src, dest, weight;

	cin >> V >> E;

	Graph* graph = createGraph(V, E);

	for(int i=0; i<E; i++){
        cin >> src >> dest >> weight;

        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight = weight;
	}


	findKruskalMST(graph);

	return 0;
}
