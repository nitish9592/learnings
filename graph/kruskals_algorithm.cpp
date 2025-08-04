#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric> // for iota

using namespace std;
typedef tuple<int, int, int> Edge; // (weight, u, v)

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        if (rank[xr] < rank[yr]) parent[xr] = yr;
        else if (rank[xr] > rank[yr]) parent[yr] = xr;
        else { parent[yr] = xr; rank[xr]++; }
        return true;
    }
};
//for return mst + min weight
void kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // sort by weight
    DSU dsu(n);
    int totalWeight = 0;

    cout << "Edges in MST:\n";
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            totalWeight += w;
            cout << u << " - " << v << " (Weight: " << w << ")\n";
        }
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}
//for only weight
int kruskalWeightOnly(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int totalWeight = 0;

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            totalWeight += w;
        }
    }
    return totalWeight;
}
int main() {
    int n = 5; // number of vertices
    vector<Edge> edges = {
        {2, 0, 1},
        {6, 0, 3},
        {3, 1, 2},
        {8, 1, 3},
        {5, 1, 4},
        {7, 2, 4}
    };

    kruskalMST(n, edges); // With edge output

    // If only total weight needed:
    // int totalWeight = kruskalWeightOnly(n, edges);
    // cout << "MST Weight: " << totalWeight << endl;

    return 0;
}
