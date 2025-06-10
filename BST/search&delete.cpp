#include<iostream>

using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data =val;
        left=NULL;
        right=NULL;
    }
};
Node* insertBST(Node *root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
void inorderPrint(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
    
}

//SEARCH
bool searchBST(Node *root, int key){
    if(root ==NULL)return false;
    if(root->data==key)return true;

    if(root->data>key){
        return searchBST(root->left,key);
    }
    else{
        return searchBST(root->right,key);
    }
    
}
Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;


}
Node* deleteBST(Node* root, int key){
    if(key<root->data){
        deleteBST(root->left,key);
    }
    else if(key>root->data){//else if since if first condition fullfilled no need to go in this
        deleteBST(root->right,key);
    }
    else{//data==key
        //CASE 1&2
        if(root->left==NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //CASE 3 
        Node *temp =inorderSucc(root->right);
        root->data = temp->data;
        root->right =  deleteBST(root->right, temp->data);
        

    }
    return root;
    
}
int main(){
    Node *root = new Node(5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    inorderPrint(root);
    cout<<endl;
    root= deleteBST(root,5);
    inorderPrint(root);



}