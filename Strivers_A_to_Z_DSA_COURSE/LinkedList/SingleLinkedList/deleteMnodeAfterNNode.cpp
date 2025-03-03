// Delete N nodes after M nodes of a linked list
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
Node* linkdelete(Node* head, int n, int m){
  Node* temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
   
    if(count==m){
         Node* ptr = temp;
        for(int i=0;i<n;i++){
            if(ptr->next!=NULL){
                ptr=ptr->next;
            }
        }
        temp->next = ptr->next;
        count=0;
    }
    temp=temp->next;
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
   head=linkdelete(head, 1,2);
    printLinked(head);
}
