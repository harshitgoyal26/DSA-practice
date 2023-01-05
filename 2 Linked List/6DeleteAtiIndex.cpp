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

Node* deleteAt(Node *head , int i)
{
    Node *temp = head ;
    int count = 0;

    if(i == 0)
    {
        head = head -> next ;
        delete temp ;
        return head ;
    }

    while(temp != NULL & count < i-1)
    {
        temp = temp -> next ;
        count++ ;
    }

    if(temp != NULL)
    {
        Node *a = temp -> next ;
        temp -> next = a -> next ;
        delete a;
    }

    return head;

}



int main()
{
    Node *head = takeInput();
    print(head);

    int i;
    cin>>i ;

    head = deleteAt(head , i);
    print(head);
}
