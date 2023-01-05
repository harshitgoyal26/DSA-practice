#include<iostream>
using namespace std ;

class Node
{

    public:
    int data ;
    Node *next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL ;
    }
};

Node* takeInput()
{
    int data ;
    cin>> data;

    Node *head = NULL;
    Node *tail = NULL ;

    while( data != -1)
    {
        Node *newNode = new Node(data);

        if(head == NULL)
        {
            head = newNode ;
            tail = newNode ;
        }
        else
        {
            tail -> next = newNode ;
            tail = tail -> next ;
        }
        cin >> data;
    }
    return head ;
}

int findNode(Node *head , int d)
{
    Node *temp = head;
    int i =  0 ;

    while(temp != NULL)
    {
        if(temp -> data == d)
        {
            return i ;
        }

        i++ ;
        temp = temp -> next ;
    }

    return -1 ;
}


int main()
{
    Node *head = takeInput();
    int i ;
    cin >> i;

    cout<<findNode(head , i)<<endl;


    return 0;
}