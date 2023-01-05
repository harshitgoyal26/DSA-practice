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



void printReverse(Node *head)
{
    Node *temp = head ;

    if(temp == NULL)
    {
        return ;
    }

    printReverse(temp -> next) ;

    
        cout<<temp -> data <<" -> ";


}



int main()
{
    Node *head = takeinput() ;

    cout<<count(head)<<endl;
    
    printReverse(head);


    return 0;
}