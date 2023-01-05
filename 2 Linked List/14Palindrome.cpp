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

Node* reverse(Node *head)
{
    Node *temp = NULL;
    Node *temp2 = head ;

    while(head != NULL)
    {
        temp2 = head -> next;
        head -> next = temp ;
        temp = head;
        head = temp2 ; // head = head -> next ;  //OR// head = temp2 ;
    }

    head = temp ;
    return head ;
}


// bool palindrome(Node *head)
// {
//     Node *temp = head ;
//     Node *h2 = head;
//     int c = count(head);
//     int q = 0 , k=0;

//     if(c % 2 == 0)
//     {
//         q = c/2;
//         k = q;
//     }
//     else
//     {
//         q = (c/2 ) + 1    ;
//         k =q-1 ;
//     }

//     while(q != 0)
//     {
//         h2  = h2 -> next ;
//         q--;
//     }

//     h2 = reverse(h2) ;

//     while(temp -> next != NULL || h2 -> next != NULL)
//     {
//         if(temp ->  data == h2 -> data)
//         {
//             q++ ;
//         }
//         else
//         {
//             return false;
//         }
//         temp = temp -> next ;
//         h2 = h2 -> next ;
//     }

//         return true;


// }

Node* middle(Node *head)
{
    Node *slow = head ;
    Node *fast = head ;

    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }

    return slow ; 
}


bool palindrome(Node *head)
{
    if(head == NULL)
    {
        return true ;
    }

    Node *mid = middle(head) ;
    Node  *last = reverse(mid) ;

    Node *curr = head ;

    while(last != NULL )
    {
        if(last -> data != curr -> data)
        {
            return false;
        }

        last = last -> next ;
        curr = curr -> next ;
    }

    return true ;
}








int main()
{
    Node *head = takeinput() ;

    cout<<count(head)<<endl;
    print(head);
    cout<<endl;
    bool ans = palindrome(head); 
    cout<<ans <<endl;
    
    // head = reverse(head);

    print(head);


    return 0;
}