

#ifndef GRAPH_H
#define	GRAPH_H

#include <iostream>
#include <list>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    private:
        int nVert;//number of vertices
        int *parent;
        list<pair<int,int> > *adj;
        void DFS(int,bool *);
        void unionVer(int,int);
        bool isCycle(int,int);
        int find(int);
    public:
        Graph(int);//constructor
        ~Graph();
        void addEdge(int,int,int);
        void BFS(int);//Traverse the graph with Breath First Search
        void DFS(int);//Traverse the graph with Depth  First Search
        void primMST();//   Prim’s Minimum Spanning Tree (MST)
        void krusMST();//Kruskal’s Minimum Spanning Tree (MST)
        void shortestPath(int,int);//shortest path between two points with Dijkstra's algorithm
};

#endif	/* GRAPH_H */

