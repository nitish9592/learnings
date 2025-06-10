#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int data) : key(data), left(NULL), right(NULL) {}
};

// Function to insert a node in the first available position
Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if (!temp->left) {
            temp->left = new Node(key);
            break;
        } else q.push(temp->left);
        
        if (!temp->right) {
            temp->right = new Node(key);
            break;
        } else q.push(temp->right);
    }
    return root;
}

// Function to delete the deepest node
void deleteDeepest(Node* root, Node* d_node) {
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete d_node;
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete d_node;
                return;
            } else q.push(temp->right);
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete d_node;
                return;
            } else q.push(temp->left);
        }
    }
}

// Function to delete a node in a binary tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;
    
    if (root->left == NULL && root->right == NULL) {
        if (root->key == key) return NULL;
        else return root;
    }
    
    queue<Node*> q;
    q.push(root);
    Node* key_node = NULL, *temp;
    
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->key == key) key_node = temp;
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    
    if (key_node != NULL) {
        int x = temp->key;
        deleteDeepest(root, temp);
        key_node->key = x;
    }
    return root;
}

// Function for in-order traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 30);
    cout << "Inorder traversal after deleting 30: ";
    inorder(root);
    cout << endl;

    return 0;
}
