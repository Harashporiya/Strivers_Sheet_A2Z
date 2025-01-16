#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printLinked(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// Node* mergeLinkedList(Node* left, Node* right){
//  Node* dummyNode = new Node(-1);
//  Node* temp=dummyNode;
//   while(left!=NULL && right!=NULL){
//     if(left->data < right->data){
//         temp->next=left;
//         temp=left;
//         left=left->next;
//     }else{
//         temp->next=right;
//         temp=right;
//         right=right->next;
//     }
//   }
//    if(left){
//         temp->next=left;
//     }else{
//         temp->next=right;
//     }
//     return dummyNode->next;
// }
// Node* findMiddleLinkedList(Node* head){
//     Node* temp=head;
//     Node* slow=head;
//     Node* fast=head->next;
//     while(fast!=NULL && fast->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     return slow;
// }
// Node* sortLinkedList(Node* head){
//     if (!head || !head->next) {
//     return head;
// }
//    Node* temp=head;
//   Node* middle= findMiddleLinkedList(head);
//   Node* right=middle->next;
//   middle->next=NULL;
//   Node* left=head;

//   left=sortLinkedList(left);
//   right=sortLinkedList(right);

//   return mergeLinkedList(left, right);
// }
// Node *multiLinkedlistOnlyOneLinkedListPrint(vector<Node *> &lists)
// {
//     Node *mergedHead = NULL;
//     Node *mergedTail = NULL;

//     for (Node* list : lists)
//     {
//         if (mergedHead == NULL)
//         {
//             mergedHead = list;
//             mergedTail = list;
//             while (mergedTail->next != NULL)
//             {
//                 mergedTail = mergedTail->next;
//             }
//         }
//         else
//         {
//             mergedTail->next = list;
//             while (mergedTail->next != NULL)
//             {
//                 mergedTail = mergedTail->next;
//             }
//         }
//     }
//      return sortLinkedList(mergedHead);
// }
Node* mergedK(vector<Node*> lists){
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> minHeap;
    for(int i=0;i<lists.size();i++){
        if(lists[i]){
            minHeap.push({lists[i]->data, lists[i]});
        }
    }
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(!minHeap.empty()){
        auto it = minHeap.top();
        minHeap.pop();
        if(it.second->next){
            minHeap.push({it.second->next->data,it.second->next});
        }
        temp->next=it.second;
        temp=temp->next;
    }
    return dummyNode->next;
}
Node *createLinkedList(vector<int> &values)
{
    Node *head = NULL;
    Node *temp = NULL;
    for (int value : values)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

int main()
{
    int k;
    cin >> k; // Number of linked lists
    vector<Node *> lists;

    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n; // Size of the current linked list
        vector<int> values(n);
        for (int j = 0; j < n; j++)
        {
            cin >> values[j];
        }
        lists.push_back(createLinkedList(values));
    }
    Node* mergedList = mergedK(lists);
    printLinked(mergedList); 


    return 0;
}
