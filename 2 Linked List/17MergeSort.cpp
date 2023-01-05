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


void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

Node* mergeSorted(Node *h1 , Node *h2)
{
    Node *fHead = NULL ;
    Node *fTail = NULL ;

    if(h1 -> data <= h2 -> data)
    {
        fHead = h1 ;
        fTail = h1;
        h1 = h1 -> next ;
    }
    else
    {
        fHead = h2 ;
        fTail = h2 ;
        h2 = h2 -> next ;
    }

    while(h1 != NULL && h2 != NULL)
    {
        if(h1 -> data <= h2 -> data)
        {
            fTail -> next = h1 ; 
            fTail = fTail -> next ;
            h1 = h1 -> next ;
        }
        else
        {
            fTail -> next = h2 ; 
            fTail = fTail -> next ;
            h2 = h2 -> next ;
        }
    }


    if(h2 == NULL)
    {
        fTail -> next = h1;
    }
    else if( h1 == NULL)
    {
        fTail -> next = h2 ;
    }

    return fHead ;

}

Node* middle(Node *head)
{
    Node *slow = head ;
    Node *fast = head ;
    Node *temp = slow;

    while(fast != NULL && fast -> next != NULL)
    {
        temp = slow ;
        slow = slow -> next ;
        fast = (fast -> next) -> next ;
    }
    temp -> next = NULL ;
    return slow ; 
}


Node* mergeSort(Node *head )
{
    if(head == NULL || head -> next == NULL)
    {
        return head ;
    }
    

    Node *temp = head ;
    Node *mid = middle(head) ;


    return mergeSorted(mergeSort(head) ,mergeSort(mid) ) ;

}




int main()
{
    Node *h1 =takeinput() ;
    print(h1);

    h1 = mergeSort(h1);

    print(h1) ;


    return 0;
}