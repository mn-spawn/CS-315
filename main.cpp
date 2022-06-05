#include <iostream>
#include <list>
#include <tuple>
using namespace std;

//structs for graph parts
struct Edge
{
    int source;
    int destination;
    int weight;
    tuple<int, int> pair;

    Edge(int s, int d, int wt)
    {
        source = s;
        destination = d;
        weight = wt;
        pair = make_tuple(source, destination);
    }

    friend std::ostream& operator<<(ostream& print, const Edge &edge);

   // ~Edge();
};
std::ostream& operator<<(ostream& print, const Edge &edge)
{
    print << '|' << edge.source << '|' << edge.destination << '|' << edge.weight << "\n";
    return print;
}
struct Graph
{
    int nodes = 0;
    list<Edge> adjacency;

    Graph(int n)
    {
        nodes = n;
    }

    //~Graph();
};

//make graph
void makeGraph(int edges, Graph &);
void addEdge(int u, int v, int weight, Graph &);

//helpers
void printGraph(Graph);
bool isEdge(Graph graph, int i, int j, int &weight);

//algorithms
int longestPath(const Graph &, int &);
int countLongestPath(int, const Graph &, int []);

int main() {

    //make graph section
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes);
    makeGraph(edges, graph);


    //find the longest path algorithms
    int count = 0;
    int length = longestPath(graph, count);

    //final output
    cout << "longest path: " << length << "\n";
    cout << "number of longest paths: " << count << "\n";
}

void makeGraph(int edges, Graph &graph)
{
    int u,v,weight;
    for(int i = 0; i < edges; i++)
    {
       std::cin >> u >> v >> weight;
       addEdge(u,v,weight, graph);
    }
}

void addEdge(int u, int v, int weight, Graph &graph)
{
    Edge edge(u,v,weight);
    graph.adjacency.push_back(edge);
}

void printGraph(Graph graph)
{
    std::cout << "Adjacency list in |source|destination|weight| format: " << "\n";
    for (list<Edge>::iterator i = graph.adjacency.begin(); i != graph.adjacency.end(); i++)
    {
       cout << *i;
    }
}

int longestPath(const Graph &graph, int & count)
{
    //set the longest path property for each node
    int lPath[graph.nodes];
    lPath[0] = 0;

    for (int i = 1; i <= graph.nodes; i++)
    {
        lPath[i] = 0;
    }

    int weight = 0;

    for (int i = 1; i < (graph.nodes+1); i++)
    {
        for (int j = i+1; j < (graph.nodes+1); j++)
        {
            if (isEdge(graph, i, j, weight))
            {
                lPath[j] = std::max(lPath[j], (lPath[i] + weight));
            }
        }
    }

    count = countLongestPath(lPath[graph.nodes-1], graph, lPath);
    return lPath[graph.nodes];
}

int countLongestPath(int length, const Graph &graph, int lPath[])
{
    return 0;
}

bool isEdge(Graph graph, int i, int j, int &weight)
{
    for(list<Edge>::iterator l = graph.adjacency.begin(); l != graph.adjacency.end(); l++)
    {
        tuple<int,int> ij;
        ij = make_tuple(i,j);

        if(ij == l->pair)
        {
            weight = l->weight;
            return true;
        }
    }
    return false;
}