#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void printLinked(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    while (head != NULL) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummyNode = new Node(0);
    Node* temp = dummyNode;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }
    return reverseLinkedList(dummyNode->next);
}

Node* createLinkedList(vector<int>& values) {
    Node* head = NULL;
    Node* temp = NULL;
    for (int value : values) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> values1(n), values2;
    for (int i = 0; i < n; i++) cin >> values1[i];

    cin >> m;
    values2.resize(m);
    for (int i = 0; i < m; i++) cin >> values2[i];

    Node* l1 = createLinkedList(values1);

    Node* result = addTwoNumbers(reverseLinkedList(l1), reverseLinkedList(l2));
    printLinked(result);

    return 0;
}
