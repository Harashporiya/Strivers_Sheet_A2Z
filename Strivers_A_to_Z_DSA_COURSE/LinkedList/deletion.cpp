#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void printLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
Node* removeHead(Node* head){
    if(head==NULL){
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* lastNodeRemove(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}
int main(){
   int n;
   cin>>n;
   Node* head=NULL;
   Node* temp=NULL;
   for(int i=0;i<n;i++){
    int value;
    cin>>value;
    Node* newNode = new Node(value);
    if(head==NULL){
        head=newNode;
    }else{
        temp->next=newNode;
    }
    temp=newNode;
   }
   printLinkedList(head);
   cout<<endl;
//   head=removeHead(head);
    head=lastNodeRemove(head);
  printLinkedList(head);
}