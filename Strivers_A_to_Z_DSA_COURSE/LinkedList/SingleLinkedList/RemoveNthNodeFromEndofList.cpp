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
Node *reverseLinkedList(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node *removeNthFromEnd(Node *head, int n)
{
    if (head == NULL)
    {
        return head;
    }

    Node *reversedHead = reverseLinkedList(head);
    Node *temp = reversedHead;
    Node *prev = NULL;
    int cnt = 1;
    if (n == 1)
    {
        reversedHead = reversedHead->next;
        delete temp;
    }
    else
    {
        while (temp != NULL)
        {
            if (cnt == n)
            {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
            cnt++;
        }
    }
    return reverseLinkedList(reversedHead);
}
int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    Node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
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
    head = removeNthFromEnd(head,2);
    printLinked(head);
}