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
Node* findNode(Node* head, int k){
    int cnt=1;
    while(head!=NULL){
        if(cnt==k) return head;
        cnt++;
         head=head->next;
    }
    return head;
}
Node* rotateList(Node* head, int k){
    int len=1;
    Node* tail = head;
    while(tail->next!=NULL){
        tail=tail->next;
        len+=1;
    }
    if(k%len==0) return head;
    k=k%len;

    tail->next=head;
    Node* nextNode = findNode(head, len-k);
    head=nextNode->next;
    nextNode->next=NULL;

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
   head=rotateList(head,4);
    printLinked(head);
}