#include<iostream>
using namespace std;


class Node{
    public:
    int data ;
    Node *next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

};

Node *takeinput()
{
    int data ;
    cin >> data;

    Node *head = NULL ;
    Node *tail = NULL ;

    while(data != -1)
    {
        Node *newNode  = new Node(data);

        if(head == NULL)
        {
            head = newNode ; 
            tail = newNode ;
        }
        else
        {
            tail -> next = newNode ;
            tail = tail -> next;
        }
        cin >> data ;
    }

    return head;
}

int count(Node *head)
{
    Node *temp = head;
    int c = 0;

    while(temp != NULL)
    {
        temp = temp -> next ;
        c++;
    }

    return c;
}

// Count Length of Linked List Recursively

int countr(Node *head)
{
    Node *temp = head;
    
    if(head == NULL)
    {
        return 0;
    }

    else
    {
        return 1 + countr(temp -> next) ;
    }
}



int main()
{
    Node *head = takeinput() ;

    cout<<count(head)<<endl;
    cout<<countr(head)<<endl;


    return 0;
}