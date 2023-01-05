//Problem Statement: Print i-th Node Data

#include<iostream>
using namespace std;

class Node {

    public:
    int data ;
    Node *next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

};

Node* takeInput()
{
    int data ;
    cin>>data;
    Node *head = NULL ;
    Node *tail = NULL ;

    while(data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode ;
            tail = newNode ;
        }
        else
        {
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin>>data;
    }
    return head;
}

int dataAt(Node *head , int pos)
{
    Node *temp = head;
    int i =0;

    while(temp != NULL)
    {
        if(i == pos)
        {
            return temp -> data ;
        }

        temp = temp -> next;
        i++;
    }
    return -1 ;
}


int main()
{
    int n;
    cin>>n;

    for(int i = 0 ; i<n ; i++)
    {
        Node *head = takeInput();
        int j;
        cin>>j;

        int k = dataAt(head , j);
        cout<<k<<endl;

    }

    


    return 0;
}