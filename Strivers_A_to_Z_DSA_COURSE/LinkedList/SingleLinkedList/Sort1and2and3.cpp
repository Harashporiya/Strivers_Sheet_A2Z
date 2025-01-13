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
Node* sortOneAndTwoandZero(Node* head){
 // int zeroCnt=0,oneCnt=0,twoCnt=0;
//   Node* temp=head;
//   while(temp!=NULL){
//     if(temp->data==0){
//         zeroCnt++;
//     }else if(temp->data==1){
//         oneCnt++;
//     }else if(temp->data==2){
//         twoCnt++;
//     }
//     temp=temp->next;
//   }
//   temp=head;
//   while(temp!=NULL){
//     if(zeroCnt){
//         temp->data=0;
//         zeroCnt--;
//     }else if(oneCnt){
//         temp->data=1;
//         oneCnt--;
//     }else if(twoCnt){
//         temp->data=2;
//         twoCnt--;
//     }
//     temp=temp->next;

//   }
//   return head;
   Node* zeroHead = new Node(-1);
   Node* oneHead = new Node(-1);
   Node* twoHead = new Node(-1);
   Node* zero = zeroHead;
   Node* one = oneHead;
   Node* two = twoHead;
   Node* temp = head;
   while(temp!=NULL){
    if(temp->data==0){
        zero->next=temp;
        zero=zero->next;
    }else if(temp->data==1){
        one->next=temp;
        one=one->next;
    }else{
        two->next=temp;
        two=two->next;
    }
    temp=temp->next;
   }
   zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
   one->next = twoHead->next;
   twoHead->next = NULL;

   Node* newHead = zeroHead->next;

   delete zeroHead;
   delete oneHead;
   delete twoHead;

   return newHead;

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
   head=sortOneAndTwoandZero(head);
    printLinked(head);
}