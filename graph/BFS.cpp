#include <iostream>
#include <set>
#include<queue>
#include <unordered_map>
#include <vector>
using namespace std;
class graph{
    public:
    unordered_map<int,set<int>> adj;//here we can also use list but with set we wil get sorted answer
    

    void addEdge(int u, int v, bool direction){
        //direction =0 -> undirected
        //direction =1 -> directed

        // created an edge from u to v
        adj[u].insert(v);//since in set we use insert in place of push_back
        if(direction ==0){

            adj[v].insert(u);

        }
    }
    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout << j<<" ,";
            }
            cout<<endl;
        }
    }
    
};
void makeAdjList(unordered_map<int, set<int>> &adjList,vector <pair<int, int>> &edges){//by ref since we have to send back the  org adjList to the prent function 
    for(size_t i=0;i<edges.size();i++){//comparing a signed int (i) with an unsigned type edges.size()
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs (unordered_map<int, set<int>>&adjList,unordered_map<int, bool>  &visited,vector<int> &ans,int node){
    queue <int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();//step 1

        //step2 storing frontNode into answer
        ans.push_back(frontNode);

        //treverse all neibours of frontNode
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1; 

            }
        }
        
    }
    
}

vector<int> BFS(int vertex, vector <pair<int, int>> edges){
    unordered_map<int, set<int>> adjList;
    vector <int> ans;
    unordered_map<int, bool> visited;

    makeAdjList(adjList, edges );


    //traverse all components of graph
    for(int i=0;i< vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i); 
        }
    }
    return ans   ;
}
int main(){
    int n;
    cout<<"enter no of nodes"<<endl;

    cin>>n;
    int m ;
    cout<<" enter the no of edges"<<endl; 
    cin>>m;

    graph g;
    vector<pair<int,int>> edges;


    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});//undirected
    }

    g.printAdjList();
    
    vector <int> ans =BFS(n,edges);
    
    cout<<"BFS treversel:"<<endl;

    for(auto i: ans){
        cout<<i<<" ";//the answerwill sart from zero since it is a unoiversel node
    }

    


    return 0;

}

