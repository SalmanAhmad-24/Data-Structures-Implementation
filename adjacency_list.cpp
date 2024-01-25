#include <iostream>
#include <vector>
using namespace std;

class graph
{
private:
    int v;            //--> no. of vertices
    vector<int> *adj; // adj list(vector of vector of integers)

public:
    graph(int v)
    {
        this->v = v;
        adj = new vector<int>[v];
    }

    // now adding an edge between two vertices
    void addEdge(int s, int d)
    {
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    void printGraph()
    {
        // Iterate through the vertices
        for (int i = 0; i < v; ++i)
        {
            cout << "\n Vertex " << i << ":";
            // Print the list of neighbors for each vertex
            for (int j = 0; j < adj[i].size(); j++)
                cout << "-> " << adj[i][j];
            printf("\n");
        }
    }
};

int main()
{
    graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 3);

    // g.print();
    g.printGraph();
}