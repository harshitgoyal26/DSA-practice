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

class Pair {
    public:
    Node *head ;
    Node *tail ;
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

Pair reverseLL2(Node * head)
{
    if(head == NULL || head -> next == NULL)
    {
        Pair ans ;
        ans.head = head ;
        ans.tail = head ;
        return ans; 
    }

    Pair smallans = reverseLL2(head -> next) ;

    smallans.tail -> next = head ;
    head -> next = NULL ;

    Pair ans ;
    ans.head = smallans.head ;
    ans.tail = head ;
    return ans ;
}

Node* reverseLL_better(Node *head)
{
    return reverseLL2(head).head ;
}

int main()
{
    Node *head = takeInput();
    print(head);
    

    head = reverseLL_better(head) ;
    print(head);


    return 0 ;
}