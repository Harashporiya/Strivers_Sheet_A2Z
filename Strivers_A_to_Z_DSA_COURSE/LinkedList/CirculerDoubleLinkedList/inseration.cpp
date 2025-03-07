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
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
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
    printLinkedList(head);
}