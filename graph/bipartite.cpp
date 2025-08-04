#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class BipartiteChecker {
private:
    vector<vector<int>> adj;
    vector<int> color;
    int V;

public:
    BipartiteChecker(int vertices) {
        V = vertices;
        adj.resize(V);
        color.assign(V, -1); // -1: unvisited, 0 and 1: two colors
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // BFS approach
    bool isBipartiteBFS() {
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfs(i)) return false;
            }
        }
        return true;
    }

    // DFS approach
    bool isBipartiteDFS() {
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0)) return false;
            }
        }
        return true;
    }

private:
    bool bfs(int start) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : adj[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(int node, int c) {
        color[node] = c;
        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - c)) return false;
            } else if (color[neighbor] == color[node]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    BipartiteChecker graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0); // this makes it not bipartite (odd-length cycle)

    cout << "Using BFS: " << (graph.isBipartiteBFS() ? "Bipartite" : "Not Bipartite") << endl;

    // Resetting for DFS
    BipartiteChecker graph2(5);
    graph2.addEdge(0, 1);
    graph2.addEdge(1, 2);
    graph2.addEdge(2, 3);
    graph2.addEdge(3, 4);
    graph2.addEdge(4, 0);

    cout << "Using DFS: " << (graph2.isBipartiteDFS() ? "Bipartite" : "Not Bipartite") << endl;

    return 0;
}
