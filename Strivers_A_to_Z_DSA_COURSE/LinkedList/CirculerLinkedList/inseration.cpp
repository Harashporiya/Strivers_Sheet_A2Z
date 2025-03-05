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
Node* insertAtHead(Node* head, int value){
   Node* temp = head;

   Node* newNode = new Node(value);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
   while(temp->next!=head){
    temp=temp->next;
   }
   temp->next = newNode;
   newNode->next = head;
   head = newNode;

   return head;
}
Node* insertAtTail(Node* head, int value){
    Node* temp = head;

   Node* newNode = new Node(value);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    while(temp->next!=head){
    temp=temp->next;
   }
    temp->next = newNode;
   newNode->next = head;

   return head;
}
Node* insertAtNth(Node* head, int value, int k){
    Node* temp = head;

   Node* newNode = new Node(value);
    int cnt=1;
    while(temp->next!=head && cnt<k-1){
        temp=temp->next;
         cnt++;
    }
        if(cnt==k-1){
        newNode->next = temp->next;
        temp->next = newNode;
        }

    return head;
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
//    head = insertAtHead(head, 0);
//    head=insertAtTail(head,100);
   head =insertAtNth(head,100,3);
    printLinkedList(head);
}