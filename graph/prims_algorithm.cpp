#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Alias for convenience: pair<weight, vertex>
typedef pair<int, int> PII;
//is nodes are also to be determined
void primMST(int n, vector<vector<PII>>& adj) {
    vector<int> key(n, INT_MAX);       // Minimum weight to connect to MST
    vector<int> parent(n, -1);         // Store MST structure
    vector<bool> inMST(n, false);      // Track nodes included in MST

    priority_queue<PII, vector<PII>, greater<PII>> pq;

    // Start from node 0
    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;

        for (auto [v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Output the MST and total weight
    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << "  (Weight: " << key[i] << ")\n";
        totalWeight += key[i];
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}
//if only  weight is to be determine
int primMSTwieght(int n, vector<vector<PII>>& adj) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    key[0] = 0;
    pq.push({0, 0});

    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;
        totalWeight += w;

        for (auto [v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({weight, v});
            }
        }
    }

    return totalWeight;
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<PII>> adj(n);

    // Add undirected edges (u, v, weight)
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

    primMST(n, adj);

    return 0;
}
