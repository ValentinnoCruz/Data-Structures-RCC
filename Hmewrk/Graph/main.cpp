

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

#include "Graph.h"

int main(int argc, char** argv) {
    cout<<"Create a graph from 1.png in the folder"<<endl;
    cout<<"The node A,B,C,D... in the picture are node 0,1,2,3..."<<endl<<endl;
    Graph g(7);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 7);
    g.addEdge(1, 0, 4);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 5, 4);
    g.addEdge(2, 0, 3);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 0, 7);
    g.addEdge(3, 1, 1);
    g.addEdge(3, 2, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 2);
    g.addEdge(3, 6, 7);
    g.addEdge(4, 2, 5);
    g.addEdge(4, 3, 2);
    g.addEdge(4, 6, 2);
    g.addEdge(5, 1, 4);
    g.addEdge(5, 3, 2);
    g.addEdge(5, 6, 4);
    g.addEdge(6, 3, 7);
    g.addEdge(6, 4, 2);
    g.addEdge(6, 5, 4);
    g.BFS(0);
    g.DFS(0);
    cout<<"The shortest path between A and G (0 and 6):"<<endl;
    g.shortestPath(0,6);
    
    cout<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Create another graph from 2.png in the folder"<<endl;
    cout<<"The node A,B,C,D... in the picture are node 0,1,2,3..."<<endl<<endl;
    Graph gg(6);
    gg.addEdge(0, 1, 3);
    gg.addEdge(0, 4, 4);
    gg.addEdge(0, 5, 7);
    gg.addEdge(1, 0, 3);
    gg.addEdge(1, 2, 5);
    gg.addEdge(1, 5, 8);
    gg.addEdge(2, 1, 5);
    gg.addEdge(2, 3, 4);
    gg.addEdge(2, 5, 6);
    gg.addEdge(3, 2, 4);
    gg.addEdge(3, 4, 2);
    gg.addEdge(3, 5, 8);
    gg.addEdge(4, 0, 4);
    gg.addEdge(4, 3, 2);
    gg.addEdge(4, 5, 5);
    gg.addEdge(5, 0, 7);
    gg.addEdge(5, 1, 8);
    gg.addEdge(5, 2, 6);
    gg.addEdge(5, 3, 8);
    gg.addEdge(5, 4, 5);
    gg.krusMST();
    return 0;
}

