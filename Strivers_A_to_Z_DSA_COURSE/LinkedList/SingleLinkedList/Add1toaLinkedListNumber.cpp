#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void printLinked(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reversedLinkedList(Node* head) {
    Node* prev = NULL;
    Node* temp = head;
    while (temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* addOneNumberLastNode(Node* head) {
    if (!head) return new Node(1); 

    Node* reversedHead = reversedLinkedList(head);
    Node* temp = reversedHead;

    int carry = 1;
    Node* prev = NULL;

    while (temp != NULL || carry) {
        int sum = (temp ? temp->data : 0) + carry;
        carry = sum / 10;
        if (temp) {
            temp->data = sum % 10;
            prev = temp;
            temp = temp->next;
        } else {
            prev->next = new Node(sum % 10);
            break;
        }
    }

    return reversedLinkedList(reversedHead);
}

int main() {
    int n;
    cin >> n;

    Node *head = NULL, *temp = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node *newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    head = addOneNumberLastNode(head);
    printLinked(head);

    return 0;
}
