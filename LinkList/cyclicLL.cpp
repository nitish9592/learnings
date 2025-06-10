#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;//node type ptr adress is of node

    node(int val){//creating new node
        data =val;//data part of node
        next=NULL;//next part is kept null as node has been created but not inserted yet
    }

};

void insertAtHead(node* &head,int val){
    node* newNode= new node(val);
    node* temp=head;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    head=newNode;
}
void insertAtTail(node* & head, int val){

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node * newNode= new node( val);
    node* temp = head;

    while( temp->next!=head){
        temp= temp->next;

    }

    temp->next =newNode;
    newNode-> next=head;
}
void display(node* head){
    node* temp =head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;

    }while(temp!=head);
    cout<<endl;
}



int main(){
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtHead(head,1);
    display(head);
} 
