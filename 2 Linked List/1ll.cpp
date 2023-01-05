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
}

Node* takeInput()
{
    int data ;
    cin>> data;
    Node *head = NULL;

    while(data != -1)
    {
        Node *newNode  = new Node(data);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next ;
            }
            temp -> next = newNode ;
        }
        cin>>data;
    }
    return head ;
}

Node* takeInputBetter()
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



int main()
{
    // Node n1(1);
    // Node *head = &n1;

    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // print(head);




    //Dynamically

    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    Node *head = n1;
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;
    n5 -> next = n6;


    print(head);



    // Using takeInput Function 

    Node *head1 = takeInput();
    print(head1);

    Node *head2 = takeInputBetter();
    print(head2);

    
    return 0;
}