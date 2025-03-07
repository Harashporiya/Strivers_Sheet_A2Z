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
Node* deleteAtHead(Node* head){
    Node* temp=head->next;
    Node* p = head->back;
    temp->back = p;
   
    p->next = temp;
    // head->back = head->next->next;
    delete head;
    return temp;
}
Node* deleteAttail(Node* head){
    Node* temp=head;
   Node* prev=NULL;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }

    Node* p = temp->next;
    prev->next = p;
    p->back = prev;
    delete temp;
    

    return head;
}
Node* deleteAtNth(Node* head, int k){
  Node* temp=head;
   int cnt=1;
    while(temp->next!=head && cnt<k-1){
        temp=temp->next;
        cnt++;
    }
    if(cnt==k-1){
        Node* p = temp->next;
        temp->next = p->next;
        p->back = temp;
        delete p;
    }
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

//   head=deleteAtHead(head);
    //  head=deleteAttail(head);
    head=deleteAtNth(head,3);
    printLinkedList(head);
}