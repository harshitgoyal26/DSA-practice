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

Node* appendLastN(Node *head , int i)
{
    Node *temp = head ;
    int count =0 ;

    while(temp != NULL)
    {
        temp = temp -> next;
        count ++ ;
    }

    temp = head;

    for(int j =0 ; j< count-i-1 ; j++)
    {
        temp = temp -> next ;
    }

    Node *a = temp -> next ;
    Node *b = temp -> next ;

    while(b -> next != NULL)
    {
        b = b -> next ;
    }

    b -> next = head ;
    head = a;
    temp -> next = NULL;

    return head ;

}



int main()
{
    int n ;
    cin>>n;

    for(int j = 0 ;j<n ;j++)
    {
        Node *head = takeInput();
        print(head);

        int i;
        cin>>i ;

        head = appendLastN(head , i);
        print(head);

    }




    Node *head = takeInput();
    print(head);

    int i;
    cin>>i ;

    head = appendLastN(head , i);
    print(head);
}
