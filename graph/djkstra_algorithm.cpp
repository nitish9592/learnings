#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Type alias for a pair of (distance, node)
typedef pair<int, int> pii;

// Dijkstra function
vector<int> dijkstra(int V, vector<vector<pii>>& adj, int src) {
    // Min-heap: (distance, node)
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Distance array initialized to infinity
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip if we already found a better path
        if (currDist > dist[u])
            continue;

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
int main() {
    int V = 5; // number of vertices
    vector<vector<pii>> adj(V);

    // Sample undirected weighted graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    int src = 0;
    vector<int> distances = dijkstra(V, adj, src);

    // Output shortest distances from source
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To node " << i << " -> " << distances[i] << "\n";
    }

    return 0;
}
