#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// In-order DFS: Left, Root, Right
void inOrderDFS(Node* node) {
    if (node == nullptr) return;

    inOrderDFS(node->left);
    cout << node->data << " ";
    inOrderDFS(node->right);
}

// Pre-order DFS: Root, Left, Right
void preOrderDFS(Node* node) {
    if (node == nullptr) return;

    cout << node->data << " ";
    preOrderDFS(node->left);
    preOrderDFS(node->right);
}

// Post-order DFS: Left, Right, Root
void postOrderDFS(Node* node) {
    if (node == nullptr) return;

    postOrderDFS(node->left);
    postOrderDFS(node->right);
    cout << node->data << " ";
}

void BFS(Node* root) {

    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop(); 
        cout << node->data << " ";
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
        
    }
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);

    cout << "In-order DFS: ";
    inOrderDFS(root);

    cout << "\nPre-order DFS: ";
    preOrderDFS(root);
   
    cout << "\nPost-order DFS: ";
    postOrderDFS(root);
  
    cout << "\nLevel order: ";
    BFS(root);

    return 0;
}
