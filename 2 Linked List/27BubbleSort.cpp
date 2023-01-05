// Problem Statement: Bubble Sort (Iterative) LinkedList

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

Node *bubbleSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int n = count(head);
    Node *curr = head;
    Node *agla = head;
    Node *prev = head;

    for (int i = 0; i < n ; i++)
    {
        curr = head;
        agla = head->next;
        prev = head;
        if (head->data > (head->next)->data)
        {
            curr = head;
            agla = curr->next;
            curr->next = agla->next;
            agla->next = curr;
            head = agla;
        }
        // else

        for (int j = 0; j < n; j++)
        {
            if (curr -> next != NULL && curr->data > (curr->next)->data)
            {
                if(agla == head)
                {
                    prev = agla ;
                }
                else if (curr == head -> next)
                {
                    prev = head;
                }
                else
                {
                    prev = prev -> next ;
                }
                agla = curr->next;
                curr->next = agla->next;
                agla->next = curr;
                prev->next = agla;
            }
            else
            {
                if(curr -> next != NULL)
                {
                    curr = curr->next;
                }
                if (curr == head -> next)
                {
                    prev = head;
                }
                if(curr -> next != NULL)
                {
                    agla = agla->next;
                }

            }
            print(head) ;
        }
    }

    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);

    head = bubbleSort(head);
    print(head);

    return 0;
}