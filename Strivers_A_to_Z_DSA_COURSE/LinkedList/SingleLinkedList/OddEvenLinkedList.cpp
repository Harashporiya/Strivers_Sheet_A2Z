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
Node* oddAndEvenLinkedList(Node* head){
    Node* oddHead = new Node(-1);
    Node* evenHead = new Node(-1);

    Node* odd = oddHead;
    Node* even = evenHead;
    Node* temp = head;

    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt%2!=0){
            odd->next=temp;
            odd=odd->next;
        }else{
          even->next=temp;
          even=even->next;
        }
        temp=temp->next;
    }

    odd->next = (evenHead->next) ? (evenHead->next) : (odd->next=NULL);
    even->next=NULL;

    Node* newNode = oddHead->next;
    delete oddHead;
    delete evenHead;

    return newNode;
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
   head=oddAndEvenLinkedList(head);
    printLinked(head);
}