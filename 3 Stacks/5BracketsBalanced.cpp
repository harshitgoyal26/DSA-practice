#include<iostream>
#include<cstring>
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

bool isBalanced(char data[])
{
    Stack<char> s;
    int i = 0 ;
    while(data[i] != '\0')
    {
        if(data[i] == '(' || data[i] == '[' || data[i] == '{')
        {
            s.push(data[i]);
        }
        else if(data[i] == ')' || data[i] == ']' || data[i] == '}')
        {
            if((data[i] == ')' && s.top() == '(') || (data[i] == '}' && s.top() == '{') || (data[i] == ']' && s.top() == '[')  )
            {
                s.pop() ;
            }
            else
            {
            return false ;
            }
        }
        i++ ;
    }
    if(s.isEmpty())
    {
        return true ;
    }
    else
    {
        return false ;
    }
}


int main()
{
    Stack<int> s1 ;

    char c1[] = "{1+(-{+}+[+]+)-}"; 
    // cin>>c1;
    cout<<c1 ;

    cout<<isBalanced(c1)<<endl;
    return 0 ;
}