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
Node* deleteNode(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* prev = head;
    head=head->next;

    head->back=NULL;
    prev->next=NULL;

    delete prev;
    return head;
}
Node* deleteLastNode(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    Node* prev;
    while(temp->next!=NULL){
         temp=temp->next;
    }
    prev=temp->back;
    prev->next=NULL;
    temp->back=NULL;

    delete temp;
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
   //head=deleteNode(head);
   head=deleteLastNode(head);
    printLinked(head);
}