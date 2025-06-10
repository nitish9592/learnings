#include<iostream>>>
#include<climits>



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
void preorderPrint(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}
//FROM PREORDER since preorder's order is the sorted order of all the keys
Node* constructBST(int preorder[],int * preorderIdx,int key ,int min , int max, int n){
    if(*preorderIdx>=n){
        return NULL;
    }
    Node* root =NULL;
    if(key > min &&key <  max){
        root= new Node(key);
        *preorderIdx+=1;
        
        if(*preorderIdx < n){
            root->left = constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);

        }
        if(*preorderIdx < n){
            root->right = constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);

        }
        
    }
    return root;
}
int main(){
    int preorder[]={10,2,1,13,11};
    int n = 5;
    int preorderIdx =0;
    Node* root = constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    preorderPrint(root);
   

}