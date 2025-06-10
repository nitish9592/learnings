#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == curr) {
            return i;
        }
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end) {
    static int inx = 0;
    if (start > end) {
        return NULL;
    }

    int curr = preorder[inx];
    inx++;

    Node* node = new Node(curr);
    if (start == end) {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

void inorderPrint(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    int preorder[] = {4,2,5,3,1};
    int inorder[] = {4, 2, 1, 5, 3};

    Node* root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);  // Should print: 4 2 1 5 3

    return 0;
}
