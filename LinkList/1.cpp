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

};//DONT FORGET TO PUT ";" here

void insertAtTail(node* &head,int val){//here we are taking the value of head by refrence since we have to modify the value
    node* newNode =new node(val);
    if(head==NULL){//or we can write nullptr
        head=newNode;//if list has no element
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next =newNode;
}
void display(node* head){
    node*temp=head;

    while(temp!=NULL){
        cout<<temp->data<< "->";
        temp=temp->next;
    
    }
    cout<<"NULL"<<endl;
}
void insertAthead(node* &head,int val){
    node* newNode =new node(val);
    if(head==NULL){
        head =newNode;
        return;
    }
    newNode->next =head;
    head =newNode;

}

void search(node* head,int key){
    node* temp =head;
    while(temp->next!=NULL){
        if(temp->data==key){
            cout<<"found"<<endl;
            return ;
        }
        
        temp=temp->next;
    }
    
        cout<<"not found"<<endl;
    
}
void deleteAtHead(node* &head){
    node* todelete =head;
    head=head->next;
    delete todelete;//we have delete this or else there will be memory leak

}
void deletion(node*head , int val){//we are deleting the value either way is by position
    if(head==NULL){
        return;//if list is empty
    }
    if(head->next==NULL){//if list has only one element
        deleteAtHead(head);
    }
    
    node* temp =head;
    while(temp->next->data!=val){//deletion can be done by one node erliar to the node to be deleted
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;//linking the node privious to the deleted node to the node next to the deleted node
    delete todelete;//we have delete this or else there will be memory leak
}


int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAthead(head,4);
    display(head);
    search(head,5);
    search(head,4);   
    deletion(head,2);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtHead(head);
    display(head);


    
    
}
