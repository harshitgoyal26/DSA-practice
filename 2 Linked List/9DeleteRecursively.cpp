// Delete a node at ith Index
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



Node* insertAtR(Node *head , int i , int data)
{
    Node *temp  = head ;
    Node *newNode = new Node(data) ;

    if(temp == NULL)
    {
        return temp ;
    }

    if(i == 1)
    {
        if( temp != NULL)
        {
            newNode -> next = temp -> next ;
            temp -> next = newNode ;
        }
        return temp ;
    }

    temp -> next = insertAtR(temp -> next , i-1 , data);
    return temp ;
} 



Node* insertRandom(Node *head, Node*newNode, int pos)
{
    if (pos == 1) 
    {
        if (head != NULL)
         {
            newNode -> next = head -> next;
            head->next = newNode ;
        }
        return head;
    }

    if (head == NULL) 
    {
        return head;
    }
    head->next = insertRandom(head->next, newNode , pos-1);
    return head;
}


Node* deleteAtR(Node *head , int i)
{
    Node *temp = head;

    if(temp == NULL)
    {
        return temp ;
    }

    if(i == 1 )
    {
        if(temp != NULL)
        {
            Node *a = temp -> next;
            temp -> next = a -> next;
            delete a;
        }
        return temp ;
    }

    temp -> next = deleteAtR(temp -> next , i-1);
    return temp;
}


int main()
{
    Node *head = takeInput();
    print(head);

    int i , data;
    cin>> i ;
    cin>> data;

    Node *newNode = new Node(data);

    // head = insertAtR(head , i , data);
    // head = insertRandom(head , newNode , i) ;
    print(head);

    head = deleteAtR(head , i);
    print(head) ;


    return 0;
}
