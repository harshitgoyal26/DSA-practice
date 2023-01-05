//Problem Statement: Find a node in LL (recursive)

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

int findNode(Node *head , int k)
{
    if(head == NULL)
    {
        return -1 ;
    }
    static int i =0 ;

    if(head -> data == k)
    {
        return  i;
    }
    i++ ;

    return findNode(head -> next , k) ;

}


int main()
{
    Node *head = takeInput() ;
    int k =0 ;
    cin>>k ;
    print(head) ;

    cout<<findNode(head , k) ;

    return 0 ;
}
