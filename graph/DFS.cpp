#include <iostream>
#include <vector>
using namespace std;
void dfs(int node,vector<int> adj[],vector<bool> &visited){
    cout<<node<<" ";// Process the node (print it)

    visited[node]=true;// Mark the node as visited

     // Visit all adjacent nodes
    for(int neighbor:adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor,adj,visited);
        }

    }

}

int main(){
    int vertices;
    cout<<"enter no of vertices"<<endl;

    cin>>vertices;
    int edges ;
    cout<<" enter the no of edges"<<endl; 
    cin>>edges;

    vector<int> adj[vertices];//creating adjList
    cout<<"Enter edges \n";
    


    for(int i=0;i<edges;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);//undirected
    }

    vector<bool> visited(vertices,false);

    cout<<"BFS treversel:"<<endl;
    //handle disconnected components

    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            cout<<"components starting from node"<<i<<":";
            dfs(i,adj,visited);
            cout<<endl;
        }
    }
    


    return 0;

}