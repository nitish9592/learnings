#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

// Function to insert a new node in the binary tree
Node* insert(Node* root, int key) {
    // If the tree is empty, create the root node
    if (root == nullptr) {
        root = new Node(key);
        return root;
    }
    // Create a queue for level order traversal
    queue<Node*> q;
    q.push(root);

    // Do level order traversal until we find an empty place
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // If left child is empty, insert the new node here
        if (temp->left == nullptr) {
            temp->left = new Node(key);
            break;
        } else {
            q.push(temp->left);
        }
        // If right child is empty, insert the new node here
        if (temp->right == nullptr) {
            temp->right = new Node(key);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4) ; 
    root->left->left = new Node(5);
  
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 6;
    root = insert(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}
