#include <iostream>//REVERSE A LINKLIST USING ITRATION METHOD & RECURSION//NORE;; this not similer to letecode qustion as here multiple of k type LL is taken
using namespace std;

class node{
    public:
    int data;
    node* next;//node type ptr adress is of node

    node(int val){//creating new node
        data =val;//data part of node
        next=NULL;//next part is kept null as node has been created but not inserted yet
    }

};//DONT FORGET TO PUT ";" here

void insertAthead(node* &head,int val){
    node* newNode =new node(val);
    if(head==NULL){
        head =newNode;
        return;
    }
    newNode->next =head;
    head =newNode;

}

void display(node* head){
    node*temp=head;

    while(temp!=NULL){
        cout<<temp->data<< "->";
        temp=temp->next;
    
    }
    cout<<"NULL"<<endl;
}
node*reversek(node* &head,int k){
    
    node*pre=NULL;
    node*curr=head;
    node*nxt;

    int count=0;
while(curr!=NULL&&count<k){//for reverseing k nodes itrativly
    nxt=curr->next;
    curr->next=pre;
    pre=curr;
    curr=nxt;
    count++;
}
if(nxt!=NULL){//last node then we skip recusive call and return to pre to privious call 
head->next=reversek(nxt,k);
}
return pre;

}

int main(){
    node* head=NULL;
    insertAthead(head,4);
    insertAthead(head,3);
    insertAthead(head,2);
    insertAthead(head,1);
    display(head);
    int k=2;
    node*newHead=reversek(head,k);
    
    display(newHead);

    
}
