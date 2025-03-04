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
int greatestCommonDivisore(int a, int b)
{
    int res = min(a, b);

    while (res > 1)
    {
        if (a % res == 0 && b % res == 0)
        {
            break;
        }
        res--;
    }

    return res;
}
Node *insertGreatestCommonDivisors(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        Node *ptr = temp;
        Node *nextTemp = temp->next;
        int gcd = greatestCommonDivisore(ptr->data, nextTemp->data);
        Node *newNode = new Node(gcd);
        ptr->next = newNode;
        newNode->next = nextTemp;

        temp = nextTemp;
    }

    return head;
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
  head=insertGreatestCommonDivisors(head);
    printLinked(head);
}