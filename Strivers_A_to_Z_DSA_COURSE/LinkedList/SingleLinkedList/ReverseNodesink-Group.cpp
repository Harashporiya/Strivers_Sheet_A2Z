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
Node* reverseLinkedList(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* getKthNode(Node* head, int k){
    k-=1;
    while(head!=NULL && k>0){
        k--;
        head=head->next;
    }
    return head;
}
Node* reverseNodeKNumber(Node* head, int k){
    Node* temp=head;
    Node* prevsNext=NULL;
    while(temp!=NULL){
       Node* kthNode = getKthNode(temp,k);
       if(kthNode==NULL){
        if(prevsNext){
            prevsNext->next=temp;
            break;
        }
       }
       Node* nextNode=kthNode->next; 
       kthNode->next=NULL;
       reverseLinkedList(temp);
       if(temp==head){
        head=kthNode;
       }else{
        prevsNext->next=kthNode;
       }

       prevsNext=temp;
       temp=nextNode;
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
  head=reverseNodeKNumber(head,2);
    printLinked(head);
}