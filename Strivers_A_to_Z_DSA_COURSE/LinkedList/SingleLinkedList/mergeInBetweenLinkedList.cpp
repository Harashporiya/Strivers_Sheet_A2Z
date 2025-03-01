#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void printLinked(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* mergeInBetween(Node* list1, int a, int b, Node* list2) {
    Node* temp = list1;
    Node* t = list2;
    int count = 0;

    while (temp != NULL) {
        count++;
        if (count == a) {
            Node* ptr = temp;
            for (int i = a; i < b; i++) {
                if (ptr->next != NULL) {
                    ptr = ptr->next;
                }
            }
            temp->next = t;
            while (t != NULL && t->next != NULL) {
                t = t->next;
            }
            // if (ptr->next->next != NULL) {
                t->next = ptr->next->next;
                break;
            // }
        }
        temp = temp->next;
    }
    return list1;
}

int main() {
    int n;
    cin >> n;
    Node* head = NULL;
    Node* temp = NULL;
    Node* head1 = NULL;
    Node* temp1 = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }


    for (int i = 0; i < n; i++) {
        int value1;
        cin >> value1;
        Node* newNode1 = new Node(value1);
        if (head1 == NULL) {
            head1 = newNode1;
        } else {
            temp1->next = newNode1;
        }
        temp1 = newNode1;
    }
    head = mergeInBetween(head, 3, 4, head1);
    printLinked(head);

    return 0;
}
