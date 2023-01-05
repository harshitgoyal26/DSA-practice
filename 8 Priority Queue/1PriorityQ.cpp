#include<iostream>
#include<vector> 
using namespace std ;


class PriorityQueue {
    vector<int> pq ;

    public :
    PriorityQueue()
    {

    }

    bool isEmpty()
    {
        return pq.size() == 0 ;
    }

    int getSize()
    {
        return pq.size() ;
    }

    int getMin()
    {
        if(isEmpty())
        {
            return 0 ;
        }
        return pq[0] ;
    }

    void insert(int elem)
    {
        pq.push_back(elem) ;

        int childIndex = pq.size() - 1 ;

        while(childIndex > 0)
        {
            int parentIndex = (childIndex - 1) /2 ;
            if(pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[parentIndex] ;
                pq[parentIndex] = pq[childIndex] ;
                pq[childIndex] = temp ;
            }
            else
            {
                break ;
            }

            childIndex = parentIndex ;
        }
    }

};