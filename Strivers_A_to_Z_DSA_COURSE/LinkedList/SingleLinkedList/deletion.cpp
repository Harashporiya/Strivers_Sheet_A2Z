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
Node* removek(Node* head, int k){
    if(head==NULL){
        return head;
    }
    Node* temp=head;
    int count=0;
    Node* prevs = NULL;
    while(temp!=NULL){
        count++;
        if(count==k){
          prevs->next=prevs->next->next;
          free(temp);
          break;
        }
        prevs=temp;
        temp=temp->next;
    }
    return head;
}

Node* removeElement(Node* head, int el){
    if(head==NULL){
        return head;
    }
    Node* temp=head;
    Node* prevs = NULL;
    while(temp!=NULL){
        if(temp->data==el){
          prevs->next=prevs->next->next;
          free(temp);
          break;
        }
        prevs=temp;
        temp=temp->next;
    }
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
  //  head=lastNodeRemove(head);
    //head=removek(head,2);
    head = removeElement(head,3);
  printLinkedList(head);
}