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
Node* insertAtLast(Node* head, int value){
    Node* newNode = new Node(value);
    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->back = temp;
    newNode->next = head;
    head->back = newNode;
    newNode=head;

    return head;
}
Node* insertAtNthNode(Node* head, int value, int k){
    Node* newNode = new Node(value);
    Node* temp = head;
    int cnt=1;
    while(temp->next!=head && cnt<k-1){
        temp=temp->next;
        cnt++;
    }
    if(cnt==k-1){
       newNode->next = temp->next;
       newNode->back = temp;
       temp->next = newNode;
    }

    return head;
}
Node* insertAtGivenValue(Node* head, int value, int k){
    Node* newNode = new Node(value);
    Node* temp = head;
    Node* p=NULL;
    while(temp->next!=head){
        if(temp->data == k){
            break;
        }
        p=temp;
        temp=temp->next;
    }
       p->next = newNode;
       newNode->next = temp;
       newNode->back = temp;
    //    temp->next = newNode;
    

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
         head->back = temp;
    }

    // head=insertAtFirst(head,100);
    // head=insertAtLast(head,100);
    // head=insertAtNthNode(head,100,4);
    head=insertAtGivenValue(head,100,4);
    printLinkedList(head);
}