#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int v){
        data = v;
        next = NULL;
        back = NULL;
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
Node* insertAtFirst(Node* head, int value){
    Node* newNode = new Node(value);
    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->back = temp;
    newNode->next = head;
    head->back = newNode;
    head=newNode;

    return head;
}
int main(){
    int n;
    cin>>n;
    Node* head = NULL;
    Node* temp = NULL;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        Node* newNode = new Node(v);
        if(head==NULL){
            head = newNode;
        }else{
            temp->next = newNode;
            newNode->back = temp;
        }
        temp=newNode;
    }
    if(temp != NULL) {
        temp->next = head;
    }

    head=insertAtFirst(head,100);
    printLinkedList(head);
}