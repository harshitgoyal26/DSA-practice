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
        cin>> data;
    }
    return head;
}



void print(Node *head)
{
    Node *temp = head ;

    while(temp != NULL)
    {
        cout<< temp -> data <<" -> ";
        temp = temp -> next ;
    }
    cout<<endl;
}



Node* reverseLL(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head ;
    }

    Node *smallans = reverseLL(head -> next) ;

    Node *temp = smallans ;

    while(temp -> next != NULL)
    {
        temp = temp -> next ;
    }

    temp -> next = head ;
    head -> next = NULL ;

    return smallans ;
}



int main()
{
    Node *head = takeInput();
    print(head);
    

    head = reverseLL(head) ;
    print(head);


    return 0 ;
}