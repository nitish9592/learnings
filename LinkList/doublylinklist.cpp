#include <iostream>
using namespace std;

class node{
    
    public:
    int data ;
    node* next;
    node* prev;

    node (int val){
        data =val;
        next = NULL;
        prev = NULL;
    }

};

void insertAtHead(node* &head, int val){
    node* newNode= new node(val);
    
    newNode->next=head;
    if(head!=NULL){
        head->prev = newNode;
    }
    head=newNode;
}
void insertAtTail (node* &head,int val){
    if (head ==NULL){
        insertAtHead(head,val);
        return;
    }
    node*temp=head;
    node*newNode= new node(val);
    while(temp->next!=NULL){
        temp =temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;

}
void deleteAtHead(node* &head){
    node* temp= head;
    if(head->next ==NULL){
        head =NULL;
        return;
    }
    head=head->next;
    head->prev=NULL;
    delete temp;
}
void deletion(node* &head, int pos){
    if(head==NULL){
        cout<<"empty LL"<<endl;
        return ;
    }
    if(pos==1){
        deleteAtHead(head);
    }
    node* temp=head;
    int count =1;
    while(temp!=NULL&&count!=pos){
        temp= temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;


}

void display(node* head){
    node* temp =head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head,3);
    display(head);
    deleteAtHead(head);    
    deleteAtHead(head);
    deleteAtHead(head);
    deleteAtHead(head);
    display(head);
}