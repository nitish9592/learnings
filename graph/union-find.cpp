#include <iostream>
#include <vector>
using namespace std;

// Union-Find (Disjoint Set Union) Class
class UnionFind {
private:
    vector<int> parent, rank;

public:
    // Constructor to initialize DSU
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Initial rank is 0
        for (int i = 0; i < n; ++i)
            parent[i] = i;  // Each element is its own parent
    }

    // Find the representative of set with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    // Union by rank, returns true if union happened (i.e., x and y were in different sets)
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false; // Already in the same set

        // Union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }

    // Check if two elements are in the same set
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    // Optional: count number of unique sets
    int countComponents() {
        int count = 0;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == i) count++;
        }
        return count;
    }
};

// Driver Code
int main() {
    int n = 7; // Number of elements (0 to 6)
    UnionFind uf(n);

    // Sample unions
    uf.unite(0, 1);
    uf.unite(1, 2);
    uf.unite(3, 4);
    uf.unite(5, 6);

    // Check connectivity
    cout << "Is 0 connected to 2? " << (uf.connected(0, 2) ? "Yes" : "No") << endl;
    cout << "Is 0 connected to 3? " << (uf.connected(0, 3) ? "Yes" : "No") << endl;

    // Connect more
    uf.unite(2, 4);

    cout << "Is 0 connected to 4 now? " << (uf.connected(0, 4) ? "Yes" : "No") << endl;

    // Count number of disjoint sets
    cout << "Number of connected components: " << uf.countComponents() << endl;

    return 0;
}

