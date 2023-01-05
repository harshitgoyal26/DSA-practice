// Delete a node at ith Index
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
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

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



Node *eliminateDuplicate(Node *head)
{
    Node *temp = head;
    Node *a = temp -> next ;

    if(head == NULL)
    {
        return head ;
    }
    

    while (a != NULL)
    {
        if (temp->data == a->data)
        {
            // while (temp->data == a->data)
            // {
                a = a->next;
                // delete a;
                // Node *a = temp -> next ;
                continue ;
            // }

        }
        
            temp -> next = a;
            temp = a;
            a = a-> next ;
    }

    temp -> next = NULL ;

    return head ;
}



int main()
{
    int n;
    cin >> n;

    for (int j = 0; j < n; j++)
    {
        Node *head = takeInput();
        print(head);

        // int i;
        // cin >> i;

        head = eliminateDuplicate(head) ;
        print(head);
    }

}
