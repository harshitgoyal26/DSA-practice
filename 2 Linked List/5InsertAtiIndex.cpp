// Insert a node at ith Index
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

Node* insertNode(Node *head , int i , int data)
{
    Node *newNode = new Node(data);
    Node *temp = head ;
    int count = 0;

    if(i == 0)
    {
        newNode -> next = head ;
        head = newNode ;
        return head;
    }

    while(temp != NULL && count < i-1)
    {
        temp = temp -> next ;
        count ++;
    }

    if(temp != NULL)
    {
        newNode -> next = temp -> next;
        temp -> next = newNode ;
    }

    return head;
    
}




int main()
{
    Node *head = takeInput();
    print(head) ;

    int i , data ;
    cin >> i >> data ;

    head = insertNode(head , i , data);
    print(head); 


    return 0;
}