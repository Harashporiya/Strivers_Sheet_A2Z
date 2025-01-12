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
Node* mergeLinkedList(Node* left, Node* right){
    Node* dummyNode = new Node(-1);
    Node* temp=dummyNode;
    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    if(left){
        temp->next=left;
    }else{
        temp->next=right;
    }
    return dummyNode->next;
}
Node* findMiddle(Node* head){
       
        Node* slow = head;
         Node* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
             slow=slow->next;
          fast=fast->next->next;
         
        }
        return slow;
}
Node* sortedList(Node* head){
      if (head == NULL || head->next == NULL) {
        return head;
       }
    Node* temp=head;
    Node* middle=findMiddle(head);
    Node* right=middle->next;
    middle->next=NULL;
     Node* left=head;

    left=sortedList(left);
    right=sortedList(right);

    return mergeLinkedList(left, right);
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
    head=sortedList(head);
    printLinked(head);
}