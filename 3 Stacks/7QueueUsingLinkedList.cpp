#include<iostream>
using namespace std ;

template <typename T>
class Node {
    public:
    T data ;
    Node *next ;

    Node(T data)
    {
        this -> data = data ;
        next = NULL ;
    }
};

template <typename T>
class Queue {
    Node<T> *head ;
    Node<T> *tail ;
    int size ;

    public:

    Queue()
    {
        head = NULL ;
        tail = NULL ;
        size = 0 ;
    }

    int getSize()
    {
        return size ;
    }




    bool isEmpty()
    {
        return size == 0 ;
    }

    void  enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element) ;
        if(head == NULL)
        {
            head = newNode ;
            tail = newNode ;
            size++ ;
            return ;
        }
        tail -> next = newNode ;
        newNode -> next = NULL ;
        tail = newNode ;
        size++ ;
    }


    T front()
    {
        if(isEmpty())
        {
            return 0 ;
        }
        return head -> data ;
    }

    T dequeue()
    {
        if(isEmpty())
        {
            return 0 ;
        }
        Node<T> *temp = head ;
        head = head -> next ;
        T ans = temp -> data ;

        size-- ;
        delete temp ;
        return ans ;
    }
};


int main()
{
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);

    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl ;
    cout<<q1.dequeue()<<endl ;
    cout<<q1.dequeue()<<endl ;

    cout<<q1.getSize()<<endl;
    cout<<q1.isEmpty()<<endl ;
}