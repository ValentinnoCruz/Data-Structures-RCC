/* 
 * 1. Traverse the graph with Breath First Search and Depth First Search
 * 2. Find minimum spanning tree
 * 3. shortest path between any 2 points
 */

#include "Graph.h"
Graph::Graph(int n) {
    nVert=n;
    adj=new list<pair<int,int> >[n];
    parent=new int[nVert];
    for(int i=0;i<nVert;i++)
        parent[i]=-1;
}

Graph::~Graph() {
    delete []adj;
    delete []parent;
}

void Graph::addEdge(int a, int b,int d) {
    //a --- First node
    //b --- Second node
    //d --- Distance between them
    adj[a].push_back(make_pair(b,d));
}

//Traverse the graph with Breath First Search
void Graph::BFS(int s) {
    //bool array for each node
    bool *visited=new bool[nVert];
    for(int i=0;i<nVert;i++) {
        visited[i]=false;
    }
    //create a queue fir BFS
    list<int> queue;
    
    //mark the current as visited
    visited[s]=true;
    queue.push_back(s);
    
    list<pair<int,int> >::iterator it;
    cout<<"Traverse with Breath First Search from 0: ";
    while(!queue.empty()) {
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(it=adj[s].begin();it!=adj[s].end();++it) {
            if(!visited[(*it).first]) {
                visited[(*it).first]=true;
                queue.push_back((*it).first);
            }
        }
    }
    cout<<endl<<endl;
    delete []visited;
}

//Traverse the graph with Depth  First Search
void Graph::DFS(int s) {
    //bool array for each node
    bool *visited=new bool[nVert];
    for(int i=0;i<nVert;i++) {
        visited[i]=false;
    }
    cout<<"Traverse with Depth  First Search from 0: ";
    //Traversal recursively
    DFS(s,visited);
    cout<<endl<<endl;
    delete []visited;
}

//DFS for recursion
void Graph::DFS(int s, bool *visited) {
    //mark the current as visited
    visited[s]=true;
    cout<<s<<" ";
    //create a iterator
    list<pair<int,int> >::iterator it=adj[s].begin();
    for(;it!=adj[s].end();++it) {
        //if the node is unread
        if(!visited[(*it).first]) {
            //DFS this node
            DFS((*it).first,visited);
        }
    }
    
}

//Kruskal’s Minimum Spanning Tree (MST)
void Graph::krusMST() {
    vector<pair< int, pair<int,int> > > ls;
//    int min=0,max=0;
    //sort all the edge
    //input the beginning vertex,end vertex, distance from the private list<int,int> adj
    list<pair<int,int> >::iterator it;
    for(int i=0;i<nVert;i++) {
        for(it=adj[i].begin();it!=adj[i].end();++it) {
            ls.push_back(make_pair((*it).second,make_pair(i,(*it).first)));
        }
    }
    sort(ls.begin(),ls.end());
    vector<pair< int, pair<int,int> > >::iterator it2=ls.begin();
    
    //output all the edge with vertices
//    for(;it2!=ls.end();++it2) {
//        int a,b,c;
//        a=(*it2).first;
//        b=(*it2).second.first;
//        c=(*it2).second.second;
//        cout<<a<<" "<<b<<" "<<c<<endl;
//    }
    int weight=0;//weight of the tree
    set<int> s;
//Get the minimum spanning tree
    cout<<"The minimum spanning tree: "<<endl;
    for(;it2!=ls.end();++it2) {
        //Determine create circle or not
        if(!isCycle((*it2).second.first,(*it2).second.second)) {
            weight+=(*it2).first;
            s.insert((*it2).second.first);
            s.insert((*it2).second.second);
            cout<<(*it2).second.first<<" --- "<<(*it2).second.second;
            cout<<"   "<<(*it2).first<<endl;
        }
    }
    cout<<"Weight: "<<weight<<endl;
}

//find the parent
int Graph::find(int x) {
    if(parent[x]==-1)
        return x;
    return find(parent[x]);
}

//Determine it creates circle after connect x and y node
bool Graph::isCycle(int x,int y) {
    // Iterate through all edges of graph, find subset of both
    // vertices of every edge, if both subsets are same, then 
    // there is cycle in graph.
    int xpar=find(x);
    int ypar=find(y);
    if(xpar==ypar) return true;
    unionVer(x,y);
    return false;
}

//put x and y into union
void Graph::unionVer(int x, int y) {
    int xset=find(x);
    int yset=find(y);
    parent[xset]=yset;
}

//   Prim’s Minimum Spanning Tree (MST)
void Graph::primMST() {
    
}

//shortest path between two points with Dijkstra's algorithm
void Graph::shortestPath(int x, int y) {
    struct Node {
        int order; //order
        int tempDis;
//        int name;
        int permDis;
        vector<pair<int,int> > neigbor;
        //pair(Distance of Edge, End Node)
    };
    list<pair<int,int> >::iterator it;
    Node *nodes=new Node[nVert];
    int currNode=x;
    for(int i=0;i<nVert;i++) {
        nodes[i].tempDis=0;
        nodes[i].permDis=0;
        nodes[i].order=0;
        it=adj[i].begin();
        for(;it!=adj[i].end();++it) {
            nodes[i].neigbor.push_back(make_pair((*it).second,(*it).first));
        }
        sort(nodes[i].neigbor.begin(),nodes[i].neigbor.end());
    }
//    _____________________
//    | Order# | Permanent |
//    | Number | Distance  |
//    ----------------------
//    |   Temp Distance    |
//    ----------------------
    int orderNum=0;
    nodes[currNode].order=(++orderNum);
    nodes[currNode].permDis=0;
    
    int *index=new int[nVert];
    for(int i=0;i<nVert;i++) {
        index[i]=i;
    }
    
    do {
//    for(int j=0;j<2;j++) {
        for(int i=0;i<nodes[currNode].neigbor.size();i++) {
            //set the temp distance to the node that doesn't have order number
            if(nodes[nodes[currNode].neigbor[i].second].order==0) {
    //            cout<<nodes[x].neigbor[i].second<<" "<<nodes[x].neigbor[i].first<<endl;
                int dis=nodes[currNode].neigbor[i].first+nodes[currNode].tempDis;
                if(nodes[nodes[currNode].neigbor[i].second].tempDis==0||
                        dis<nodes[nodes[currNode].neigbor[i].second].tempDis)
                    nodes[nodes[currNode].neigbor[i].second].tempDis=dis;
            }
        }
        //sort the temp distance and get the node with lowest distance
        for(int k=0;k<nVert-1;k++) {
            for(int h=k+1;h<nVert;h++) {
                if(nodes[index[k]].tempDis>nodes[index[h]].tempDis) {
                    int temp=index[k];
                    index[k]=index[h];
                    index[h]=temp;
                }
            }
        }
         
        //Finish the sort and get the node with lowest distance
        for(int k=0;k<nVert;k++) {
            if(nodes[index[k]].permDis==0&&nodes[index[k]].tempDis!=0) {
                currNode=index[k];
                break;
            }
        }
//        cout<<"Current Node is "<<currNode<<endl;
        nodes[currNode].order=(++orderNum);
        nodes[currNode].permDis=nodes[currNode].tempDis;
//        currNode=lowestNode;
        
//    }
    } while(nodes[y].permDis==0);
        
//    //Output the temp data
//    for(int i=0;i<nVert;i++) {
//        cout<<"#"<<i<<": "<<endl;
//        cout<<nodes[i].order<<endl;
//        cout<<nodes[i].permDis<<endl;
//        cout<<nodes[i].tempDis<<endl;
//        
//        for(int j=0;j<nodes[i].neigbor.size();j++) {
//            cout<<nodes[i].neigbor[j].second<<" "<<nodes[i].neigbor[j].first<<endl;
//        }
//        cout<<endl;
//    }
    int length=nodes[y].permDis;
    list<pair<pair<int,int>,int> > path;
    list<pair<pair<int,int>,int> >::iterator it2;
    do {
        for(int i=0;i<nodes[currNode].neigbor.size();i++) {
            if((length-nodes[currNode].neigbor[i].first)==nodes[nodes[currNode].neigbor[i].second].permDis) {
                path.push_front(make_pair(make_pair(nodes[currNode].neigbor[i].second,currNode),nodes[currNode].neigbor[i].first));
                length=nodes[nodes[currNode].neigbor[i].second].permDis;
                currNode=nodes[currNode].neigbor[i].second;
                break;
            }
        }
    } while(length>0);
    
    //Output the path and the length
    
    for(it2=path.begin();it2!=path.end();++it2) {
        cout<<(*it2).first.first<<" ----> "<<(*it2).first.second<<"   "<<(*it2).second<<endl;
    }
    cout<<"The shortest length: "<<nodes[y].permDis<<endl;
    delete []nodes;
}

