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

node* merge(node* head1, node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* dummy=new node(-1);
    node* ptr3=dummy;
    while(ptr1!=NULL&&ptr2 !=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;

        }
        ptr3=ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return dummy->next;
}
node* mergeRecursion(node* head1, node* head2){//using recursion
    if(head1==NULL){//base case
        return head2;
    }
    
    if(head2==NULL){//base case
        return head1;
    }
    node* result;
    if( head1->data<head2->data){
        result=head1;
        result->next =mergeRecursion(head1->next,head2);// pting next element
        
    }
    else{
        result =head2;
        result->next= mergeRecursion(head1,head2->next);// pting next element
    }

}
int main(){
    node* head1= NULL;
    node* head2 =NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,7);
    insertAtTail(head2,2);
    insertAtTail(head2,5);
    insertAtTail(head2,6);
    insertAtTail(head2,8);
    node* newHead=mergeRecursion(head1,head2);
    display(newHead);

}