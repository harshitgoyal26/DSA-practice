// Problem Statement: Delete every N nodes

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

Node *deleteN(Node *head, int m, int n)
{
    if (head == NULL || m == 0)
    {
        return NULL;
    }
    Node *tail = head;

    while (tail != NULL)
    {
        for (int i = 1; i < m && tail != NULL; i++)
        {
            tail = tail->next;
        }
        Node *nextHead = tail->next;

        for (int i = 0; i < n && nextHead != NULL ; i++)
        {
            Node *a = nextHead ;
            nextHead = nextHead->next;
            delete a ;
        }
        tail->next = nextHead;
        tail = tail -> next ;
    }

    // tail -> next = NULL ;
    return head ;
}


int main()
{
    Node *head = takeInput() ;
    int m = 0 , n=0 ;
    cin>>m>>n ;
    print(head) ;

    head = deleteN(head , m , n) ;
    print(head) ;

    return 0;
}