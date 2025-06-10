#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *right, *left;
    Node(int val){
        data=val;
        right=NULL;
        left =NULL;
    }

};
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh =height(root->left); 
    int rh =height(root->right);
    return max(lh,rh)+1;
}
bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }

    int lh =height(root->left); 
    int rh =height(root->right);
    
    if(abs(lh-rh)<=1){
        return true;
    }
    else{return false;}


}
int main(){
    Node* root1= new Node(1);
    root1->left =new Node(2);
    root1->right =new Node(3);
    root1->left->left =new Node(4);
    root1->left->right=new Node(5);
    root1->right->left =new Node(6); 
    root1->right->right =new Node(7); 

    Node* root2 =new Node(1);
    root2->left=new Node(2);
    root2->left->left=new Node(3);

    
    if(isBalanced(root1)){
        cout<<"balaced BST"<<endl;
    }
    if(!isBalanced(root1)){
        cout<<"unbalaced BST"<<endl;
    }
    
    if(isBalanced(root2)){
        cout<<"balaced BST"<<endl;
    }
    if(!isBalanced(root2)){
        cout<<"unbalaced BST"<<endl;
    }


    return 0;
}