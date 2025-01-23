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
Node* removeDuplicate(Node* head){
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextNode=temp->next;
        while(nextNode!=NULL && nextNode->data==temp->data){
            Node* duplicat = nextNode;
            nextNode=nextNode->next;
            delete duplicat;
        }
        temp->next=nextNode;
        if(nextNode!=NULL){
            nextNode->back=temp;
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
            newNode->back = temp;
        }
        temp=newNode;
    }
   head=removeDuplicate(head);
    printLinked(head);
}