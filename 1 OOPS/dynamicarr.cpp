#include<iostream>
using namespace std;

class DynamicArray {
    int *data ; 
    int nextIndex ;
    int capacity ;                      //total size

    public:

    DynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(DynamicArray const &d)
    {
        // this -> data = d.data ;           //shallow copy
        
        //deep copy
        this -> data = new int[d.capacity];
        for(int i = 0 ; i<d.nextIndex ; i++)
        {
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex ;
        this -> capacity = d.capacity ;

    }

    void operator=(DynamicArray const &d)
    {
        this -> data = new int[d.capacity];
        for(int i = 0 ; i<d.nextIndex ; i++)
        {
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex ;
        this -> capacity = d.capacity ;
    }

    void print() const
    {
        for (int i = 0 ; i<nextIndex ; i++)
        {
            cout<<data[i] <<" ";
        }
        cout<<endl;
    }

    void add(int element)
    {
        if(nextIndex == capacity)
        {
            int *newData = new int[2*capacity];
            for(int i = 0 ; i< capacity ; i++)
            {
                newData[i] = data[i];
            }

            delete [] data ;
            data = newData ;
            capacity = 2*capacity ;
        }

        data[nextIndex] = element ;
        nextIndex++ ;
    }


    int get(int i) const
    {
        if(i < nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }
};


int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.print();
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();
}