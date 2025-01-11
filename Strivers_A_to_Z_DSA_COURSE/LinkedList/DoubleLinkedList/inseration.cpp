#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node* back;
    Node(int val){
        data = val;
        next = NULL;
        back = NULL;
    }
    Node(int val, Node* next1, Node* back1){
        data = val;
        next = next1;
        back = back1;
    }
};
void printLinked(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val);
    newHead->next=head;
    newHead->back=NULL;
    head->back=newHead;

    return newHead;
}
Node* insertTail(Node* head, int val){
    Node* newTail = new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newTail;
    newTail->next=NULL;
    newTail->back=temp;

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
            newNode->back = temp;
        }
        temp=newNode;
    }
   //head=insertBeforeHead(head,0);
   head=insertTail(head,0); 
    printLinked(head);
}