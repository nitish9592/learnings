#include <iostream>//FINDING INTERSECTION OF TOW LL
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
int length(node* &head){//NOTE:FINDING LENGTH OF LL
    int l=0;
    node* temp = head;
    while( temp!=NULL){
        temp=temp-> next;
        l++; 
    }
    return l;
}

int intersection(node* &head1 , node* &head2){
    int l = length(head1);
    int r = length(head2);
    node* ptr1;
    node* ptr2;
    int count =0;
    int d=0;
    if(l>r){
        d=l-r;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=r-l;
        ptr1=head2;
        ptr2=head1;
    }
    
    while(ptr1!=NULL||ptr2!=NULL){
        if(count<d){
            ptr1=ptr1->next;
            count++;
        }
        else{
            if(ptr1->data==ptr2->data){//appending the ptr to longer LL untill it reaches same pos as head of smaller LL
                return ptr1->data;
            }
            else{//now appending both LL untill we found intersection
                ptr1=ptr1->next;
                ptr2=ptr2->next;
                count++;
            }
        }
    }
    return -1;//if no intersection is found;
}

int main(){
    node* head1=NULL;
    node* head2 =NULL;
    
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
  
    insertAtTail(head2,7);
    insertAtTail(head2,8);
    insertAtTail(head2,9);
    insertAtTail(head2,10);
    
    
    display(head1);
    display(head2);
    cout<<intersection(head1, head2);

}
