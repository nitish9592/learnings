#include <iostream>//returning the sum at kth level of a tree
#include <queue>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data =val;
        left =NULL;
        right =NULL;

    }


};

int sumAtK(node* root,int k){
    if (root== NULL)
    {
        /* code */
        return -1;
    }
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level =0;
    int sum=0;

    while (!q.empty())
    {
    node*Node = q.front();
    q.pop();
    if(Node!=NULL){
        if(level ==k){
            sum+=Node->data;
        }
        if(Node->right){
            q.push(Node->right);
        }
        if(Node->left){
            q.push(Node->left);
        }
    }
    else if(!q.empty()){
        q.push(NULL);
        level++;
    }
}
return sum;
    


    
}
int main(){
/*
        1
       / \
      2   3
     / \ /  \  
    4  5 6   7
*/
struct node* root=new node(1);

    root->left = new node(2);
    root->right = new node(3);

   

    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    cout<<sumAtK(root,1);

};

