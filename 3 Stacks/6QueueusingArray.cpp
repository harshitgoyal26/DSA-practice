#include<iostream>
using namespace std ;


template <typename T>
class QueueusingArray {
    T *data ;
    int nextIndex ;
    int firstIndex ;
    int size ;
    int capacity ;

    public:
    QueueusingArray(int s)
    {
        data = new T[s] ;
        nextIndex = 0 ;
        firstIndex = -1 ;
        size = 0 ;
        capacity = s;

    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0 ;
    }


    // Insert a element
    void enqueue(T element)
    {
        if(size == capacity)
        {
            // cout<<"Queue full" <<endl;
            // return ;

            T *newData = new T[2*capacity] ;
            int j = 0 ;
            for(int i = firstIndex ; i<capacity ; i++)
            {
                newData[j] = data[i];
                j++ ;
            }
            for(int i = 0 ; i<firstIndex ;i++)
            {
                newData[j] = data[i] ;
                j++;
            }
            delete [] data ;
            data = newData ;
            firstIndex = 0;
            nextIndex = capacity ;
            capacity = 2* capacity ;
        }
        data[nextIndex] = element ;
        nextIndex= (nextIndex +1 ) % capacity ;
        size ++ ;
        if(firstIndex == -1)
        {
            firstIndex = 0 ;
        }
    }

    T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl ;
            return 0 ;
        }
        return data[firstIndex] ;
    }

    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl ;
            return 0 ;
        }
        T ans = data[firstIndex] ;
        firstIndex = (firstIndex +1) % capacity;
        size -- ;
        return ans ;
    }

};


int main()
{
    QueueusingArray<int> q1(5) ; 
    
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