//Problem Statement: Even after Odd LinkedList

#include<iostream>
using namespace std;

class Node {

    public:
    int data ;
    Node *next;

    Node(int data)
    {
        this -> data = data ;
        this -> next = NULL ;
    }
};

void print(Node *head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout<< temp -> data <<" -> ";
        temp = temp -> next ;
    }
    cout<<endl;
}


Node* takeInput()
{
    int data ;
    cin>> data;
    Node *head = NULL;
    Node *tail = NULL ;

    while(data != -1)
    {
        Node *newNode  = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode ;
        }
        else
        {
            tail -> next = newNode ;
            tail = tail -> next ;   //OR// tail = newNode ;
        }
        cin>>data;
    }
    return head ;
}

int count(Node *head)
{
    int c=0 ;
    Node *temp = head ;
    while(temp != NULL)
    {
        temp =temp -> next ;
        c++ ;
    }
    return c ;
}

Node* evenOdd(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head ;
    }
    Node *temp = head ;
    Node *head1 = head  ;
    int n = count(head) ;
    int *arro = new int[n] {0} ;
    int *arre = new int[n] {0} ;
    int i = 0 , o = 0 , e = 0;
    Node *temp2 = temp -> next ;
    while(temp != NULL)
    {
        if(temp -> data % 2 == 0)
        {
            arre[e] = temp -> data ;
            e++ ;
        }
        else
        {
            arro[o] = temp -> data ;
            o++ ;
        }
        temp = temp -> next ;
        i++ ;
    }

    head1 = new Node(0) ;
    temp = head1 ;

    for(int i = 0 ; i< o ; i++)
    {
        Node *newNode = new Node(arro[i]);
        head1 -> next = newNode ;
        head1 = head1 -> next ;
    }
    for(int i = 0 ; i< e ; i++)
    {
        Node *newNode = new Node(arre[i]);
        head1 -> next = newNode ;
        head1 = head1 -> next ;
    }

    head1 -> next = NULL ;
    return temp -> next ;
}


int main()
{
    Node *head = takeInput() ;
    print(head) ;

    head = evenOdd(head) ;
    print(head) ;

    return 0 ;
}