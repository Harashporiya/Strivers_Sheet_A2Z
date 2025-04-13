#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void printLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* firstEvenAllSecondOddAll(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* evenHead = new Node(-1);
    Node* oddHead =  new Node(-1);
    Node* even = evenHead;
    Node* odd = oddHead;
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
       cnt++;
       if(cnt%2==0){
        
        even->next = temp;
        temp->prev=even;
        even=even->next;
       }else if(cnt%2!=0){
      
        odd->next=temp;
        temp->prev=even;
        odd=odd->next;
       }
       temp=temp->next;
    }

    odd->next = NULL;
    if(evenHead->next!=NULL){
       even->next = oddHead->next;
       if(oddHead->next!=NULL){
        oddHead->next->prev=even;
       }
    }
    Node* newNode=evenHead->next;
    
    delete evenHead;
    delete oddHead;
    return newNode;
}
int main(){
    int n;
    cin>>n;
    Node* head = NULL;
    Node* temp=NULL;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        Node* newNode = new Node(value);
        if(head==NULL){
            head=newNode;
        }else{
           temp->next=newNode;
           newNode->prev=temp;
        }
        temp=newNode;

    }
   head = firstEvenAllSecondOddAll(head);
    printLinkedList(head);
}