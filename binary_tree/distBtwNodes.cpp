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

Node* LCA(Node* root, int n1,int n2 ){//lowest common ancester
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1||root->data==n2){
        return root;
    }
    Node* left =LCA(root->left,n1,n2);
    Node* right =LCA(root->right,n1,n2);

    if(left!=NULL&&right!=NULL){// since n1 lies in right subtree and n2 lies in left subtree
        return root;
    }
    if(left==NULL&&right==NULL){//LCA doesnt exist
        return NULL;
    }
    if(left!=NULL){
        return LCA(root->left,n1,n2);//3RD CASE

    }
    
        return LCA(root->right,n1,n2);//4TH CASE

    

}
int findDist(Node* root , int k,int dist ){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dist;
    }

    int left =findDist(root->left,k,dist+1);
    if(left!= -1){
        return left;
    }


    return findDist(root->right,k,dist+1);
    
}

int distBtwNodes(Node* root,int n1,int n2){
    Node* lca =LCA(root,n1,n2);

    int d1 = findDist(lca,n1,0);//to find distance between first no and root(lca) ,0 is initial distance val

    int d2 = findDist(lca,n2,0);//to find distance between first no and root(lca) ,0 is initial distance val
    
    return d1+d2;//final distace between 2 no
}

int main(){
    /*      1
           /  \
          2    3
         /      \
        4        5 
    */
    
    Node* root =new Node(1);
    root->left =new Node(2);
    root->right =new Node(3);
    root->left->left =new Node(4);
    root->right->right =new Node(5);

    cout <<distBtwNodes(root,4,5);


}