#include <iostream>//REVERSE A LINKLIST USING ITRATION METHOD & RECURSION
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
//REVERSE A LINKLIST USING IRATION METHOD
node* reverse(node* head){//here node* at start means this fn will reaturn a node type elment that is new head after reverse
    node*curr =head;//pointing the current element
    node*pre=NULL;//pointing the previous element
    node*nxt;//pointing the next element//we wan't diclar nxt here 
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nxt;
    }
    
    return pre;
}
node* reverseRecursion(node*&head){//USING RECURSION
    
    if (head==NULL||(head->next==NULL))//head ==NULL for empty LL
    {

        return head;//base case last element
    }
    
    node*newHead=reverseRecursion(head->next);//recursive call for each element->;
    head->next->next=head;//for second element connecting to first element
    head->next=NULL;//for fisrt element's next to pointing NULLtherefor creating it last element;

  return newHead;//


};

int main(){
    node* head=NULL;
    insertAthead(head,1);
    insertAthead(head,2);
    insertAthead(head,3);
    insertAthead(head,4);
    display(head);
    node* newHead=reverseRecursion(head);
    
    display(newHead);

    
}
