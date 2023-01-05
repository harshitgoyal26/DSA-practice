#include<iostream>
using namespace std;

template <typename T>
class Node {
    public:
    T data ;
    Node<T> *next ;
    Node(T data)
    {
        this -> data = data ;
        next = NULL  ;
    }
};
 
template <typename T>
class Stack {
    Node<T> *head ;
    int size ;

    public:
    Stack()
    {
        head = NULL ;
        size = 0; 
    }

    int getSize()
    {
        return size ;
    }

    bool isEmpty()
    {
        return size == 0 ;
    }

    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element) ;
        
        newNode -> next = head ;
        head =newNode  ;
        size++ ;
    }


    T top()
    {
        if(isEmpty())
        {
            return 0 ;
        }
        return head -> data ;
    }

    T pop()
    {
        if(isEmpty())
        {
            return 0 ;
        }
        T ans = head -> data ;
        head = head -> next ;
        size -- ;
        return ans ;

    }
};


int main()
{
    Stack<int> s1 ;

    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    s1.push(10) ;
    s1.push(20) ;
    s1.push(30) ;
    s1.push(40) ;
    s1.push(50) ;
    s1.push(60) ;

    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;

    return 0 ;
}