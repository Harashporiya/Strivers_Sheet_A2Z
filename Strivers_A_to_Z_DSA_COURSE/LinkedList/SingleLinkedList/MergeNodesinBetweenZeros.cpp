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
Node* mergeNode(Node* head){
    Node* temp=head->next;
    Node* res=head;
    int sum=0;
    while(temp!=NULL){
      if(temp->data==0){
        if(sum!=0){
            res->next->data = sum;
            res=res->next;
        }
        sum=0;
      }else{
        sum+=temp->data;
      }
      temp=temp->next;
    }
    res->next=NULL;
    return head->next;
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
  head=mergeNode(head);
    printLinked(head);
}