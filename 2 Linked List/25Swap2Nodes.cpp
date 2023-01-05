// Problem Statement: Swap two Nodes of LL

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next; // OR// tail = newNode ;
        }
        cin >> data;
    }
    return head;
}

int count(Node *head)
{
    int c = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

Node *swap(Node *head, int m, int n)
{
    if (head == NULL)
    {
        return head;
    }

    Node *temp = head;
    if (m == 0)
    {
        temp = temp->next;
        Node *a = head ;
        Node *aglaa = temp;

        for (int i = 1; i <  m-1; i++)
        {
            temp = temp->next;
        }
        Node *prevb = temp;
        Node *b = prevb->next;
        Node *aglab = b->next;

        if (n - m == 1)
        {
            a->next = aglab;
            b->next = a;
            return b;
        }

        b->next = aglaa;
        prevb->next = a;
        a->next = aglab;

        return b;
    }

    for (int i = 0; i < m - 1; i++)
    {
        temp = temp->next;
    }
    Node *preva = temp;
    Node *a = preva->next;
    Node *aglaa = a->next;

    for (int i = 0; i < n - m; i++)
    {
        temp = temp->next;
    }
    Node *prevb = temp;
    Node *b = prevb->next;
    Node *aglab = b->next;

    if (n - m == 1)
    {
        preva->next = b;
        a->next = aglab;
        b->next = a;

        return head;
    }

    preva->next = b;
    b->next = aglaa;
    prevb->next = a;
    a->next = aglab;

    return head;
}

int main()
{
    Node *head = takeInput();
    int m = 0, n = 0;
    cin >> m >> n;
    print(head);

    head = swap(head, m, n);
    print(head);

    return 0;
}