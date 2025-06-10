#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data =val;
        left =NULL;
        right =NULL;

    }


};

bool isBST(Node* root,Node* min, Node*max){//we are taking min max as node ptrs type so that we can pass root as min max wrather than int type
    if(root==NULL){
        return true;
    }
    
    if(min != NULL&& root->data <=min->data){
        return false;

    }
    if(max != NULL&& root->data >=max->data){
        return false;

    }

    bool leftValid =isBST(root->left ,min, root);
    bool rightValid =isBST(root->right ,root, max);
    return rightValid && leftValid;
}


int main (){
    Node* root =new Node(1);//not valid example
    root->left = new Node(2);
    root->right = new Node(3);
    
    cout<<isBST(root,NULL,NULL)<<endl;
    return 0;
}