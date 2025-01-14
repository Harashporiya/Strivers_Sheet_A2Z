#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node* back;
    Node(int val) {
        data = val;
        next = NULL;
        back = NULL;
    }
    Node(int val, Node* next1, Node* back1) {
        data = val;
        next = next1;
        back = back1;
    }
};

void printLinked(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* findTail(Node* head) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

vector<pair<int, int>> findPairOfSum(Node* head, int t) {
    vector<pair<int, int>> ans;
    Node* left = head;
    Node* right = findTail(head);

    while (left != NULL && right != NULL && left != right && left->data < right->data) {
        int sum = left->data + right->data;
        if (sum == t) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        } else if (sum < t) {
            left = left->next;
        } else {
            right = right->back;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    Node *head = NULL;
    Node *temp = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node *newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
            newNode->back = temp;
        }
        temp = newNode;
    }

    vector<pair<int, int>> ans = findPairOfSum(head, 7);

    for (auto& p : ans) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    printLinked(head);
}
