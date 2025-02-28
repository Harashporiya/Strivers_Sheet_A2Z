#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next =NULL;
    }
};
void printLinked(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* shiftSmallLarge(Node* head){
  Node* minNode = head;
  Node* maxNode = head;
  Node* minPrev=NULL;
  Node* maxPrev=NULL;
  Node* prev = NULL;
  Node* temp = head;

  while(temp!=NULL){
    if(temp->data < minNode->data){
        minNode = temp;
        minPrev = prev;
    }
    if(temp->data > maxNode->data){
        maxNode = temp;
        maxPrev = prev;
    }
    prev = temp;
    temp=temp->next;
  }

  if(minNode!=NULL){
    minPrev->next = minNode->next;
    minNode->next = head;
    head = minNode;
  }
  if(maxPrev==minNode){
    maxPrev = minNode->next;
  }

  if(maxNode->next){
    maxPrev->next = maxNode->next;
    maxNode->next=NULL;

    Node* last = head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next = maxNode;
  }
  return head;

}

int main(){
    int n;
    cin>>n;
    Node *head = NULL;
    Node *temp=NULL;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        Node *newNode = new Node(value);
        if(head==NULL){
            head = newNode;
        }else{
            temp->next=newNode;
        }
        temp=newNode;
    }
   head=shiftSmallLarge(head);
    printLinked(head);
}