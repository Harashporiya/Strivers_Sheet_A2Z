#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(int value){
    data = value;
    next = NULL;
  }
};
void printLinkedList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp==head){
            break;
        }
    }
    cout<<endl;
}
Node* deleteAtFirst(Node* head){
    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
   Node* p = head->next;
   temp->next = p;
   delete head;
    return p;
}
int main(){
    int n;
    cin>>n;
    Node* head= NULL;
    Node* temp = NULL;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        Node* newNode = new Node(value);
        if(head==NULL){
            head = newNode;
        }else{
            temp->next = newNode;
        }
        temp=newNode;
    }
    if(temp != NULL) {
        temp->next = head;
    }
    head=deleteAtFirst(head);
    printLinkedList(head);
}