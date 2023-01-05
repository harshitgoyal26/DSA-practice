#include<iostream>
#include<climits>
using namespace std ;

template <typename T>
class StackUsingArray {
    T *data ;                  //dynamically created aaray to store values
    int nextIndex ;
    int capacity ;

    public:
    StackUsingArray()
    {
        data = new T[4] ;
        nextIndex = 0 ;
        capacity = 4 ;
    }

    // returns number of elements in stack
    int size()
    {
        return nextIndex ;
    }

    bool isEmpty()
    {
        // if(nextIndex == 0)
        // {
        //     return true ;
        // }
        // return false ;

        // OR

        return nextIndex == 0 ;
    }


    //to insert element
    void push(T element)
    {
        if(nextIndex == capacity)
        {
            // cout<<"Stack Full" <<endl ;
            // return ;
            capacity *= 2 ;
            T *newData = new T[capacity] ;
            for(int i =0 ; i< capacity/2 ; i++)
            {
                newData[i] = data[i] ;
            }
            delete [] data ;
            data = newData ;
        }
        data[nextIndex] = element ;
        nextIndex++ ; 
    }

    // Delete element
    T pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty" <<endl ;
            return 0;
        }
        nextIndex -- ;
        return data[nextIndex] ;
    }

    /// 
    T top()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty"<<endl ;
            return 0 ;
        }
        return data[nextIndex - 1] ;
    }

};


int main()
{
    StackUsingArray<char> s1 ;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout<<s1.top() <<endl ;
    cout<<s1.pop() <<endl ;
    cout<<s1.pop() <<endl ;
    cout<<s1.pop() <<endl ;

    cout<<s1.size() <<endl ;
    cout<<s1.isEmpty() <<endl ;

    return 0 ;
}