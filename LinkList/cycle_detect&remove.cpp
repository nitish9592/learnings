/*PROBLEM STATEMENT
-->we need to find weather if theris a cyle present in a LL  or not
--> algorithem used:Floyd's tortoise and hare algorithm moves two pointers 
at different speeds through the sequence of values until they both point to equal values.
Alternatively, Brent's algorithm is based on the idea of exponential search

-->we have also used makeCycle funtn to make a cycle 
-->TO REMEOVE THE CYCLE  
if we again take the two ptr tortoise(slow) and hare(fast)
and made the jump again and  they meet at a pt in loop
->now according to floyid law the distance to this pt is same from the head by tow branches so formed is same

->now we move one of the ptr(say fasr) to head make them move one step ( note with thier privious speed )at a time
until thier ->next is equal( which is the pt where we marked while making the cycle)
-> that pt we put the ptr which was in the loop (here slow) therefor we will put slow-> next =NULL
*/
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
void makeCycle(node* &head , int pos){
    node* temp=head;
    node* flag;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            flag=temp;//we mark the element to which we want to attach tail and make a cycle
        }
        temp=temp->next;
        count++;
    }
    temp->next=flag;//connecting tail to the marked elment

}
bool detectCycle(node* &head){//we can also make boolean function
    node*fast=head;
    node*slow=head;//we will not initialize from head as it will become equal
    while(fast!=NULL&&fast->next!=NULL){//note first check for fast then for fast->next
        
        slow=slow->next;//JUMPS 1 STEPS+
        fast=fast->next->next;//JUMPS 2 STEPS
        if(fast==slow){
            
            return true;
        }
    }        
    return false;
}


void removeCycle(node*&head){//assuming cycle is present
    node*fast=head;
    node*slow=head;

    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);

    fast=head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;  
}



int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    
    makeCycle(head, 3);
    if (detectCycle(head)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    removeCycle(head);
    if (detectCycle(head)) {
        cout << "Cycle detected after removal" << endl;
    } else {
        cout << "No cycle detected after removal" << endl;
    }

    display(head);
    return 0;

}
