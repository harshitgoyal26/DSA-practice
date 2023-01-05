// Problem Statement: kReverse

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

Node *kReverse(Node *head, int k)
{
    int n = count(head);
    if (head == NULL || k == 0) // || n< k)
    {
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    Node *curr = head;
    Node *agla = head;

    for (int i = 0; i < k && curr != NULL; i++)
    {
        agla = curr->next;
        curr->next = prev;
        prev = curr;
        curr = agla;
    }

    temp->next = curr;
    head = prev;
    prev = temp ;
    Node *temp2 = temp ;

    while (curr != NULL)
    {
        temp =curr ;
        for (int i = 0; i < k && curr != NULL; i++)
        {
            agla = curr->next;
            curr->next = prev;
            prev = curr;
            curr = agla;
        }
        temp2 -> next = prev ;
        temp -> next = curr ;
        prev = temp ;
        temp2 = temp ;
    }

    return head ;
}

int main()
{
    Node *head = takeInput();
    int m = 0, n = 0;
    cin >> m;
    print(head);

    head = kReverse(head, m);
    print(head);

    return 0;
}