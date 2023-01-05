#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int elem)
    {
        pq.push_back(elem);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];

        if (pq.size() == 1)
        {
            pq.pop_back();
            return ans;
        }

        int last = pq.size() - 1;
        pq[0] = pq[last];

        pq.pop_back();

        int parent = 0;
        int lci = 2 * parent + 1;
        int rci = 2 * parent + 2;

        while(lci < pq.size())
        {
            int minIndex = parent;

            if (pq[minIndex] > pq[lci])
            {
                minIndex = lci;
            }
            if (rci < pq.size() && pq[minIndex] > pq[rci])
            {
                minIndex = rci;
            }

            if(minIndex == parent)
            {
                break ;
            }

            int temp = pq[parent];
            pq[parent] = pq[minIndex];
            pq[minIndex] = temp;


            parent = minIndex ;
            lci = 2 * parent + 1;
            rci = 2 * parent + 2;
        }

        return ans ;
    }

    
};



int main()
{
    PriorityQueue p;

    p.insert(100) ;
    p.insert(10) ;
    p.insert(15) ;
    p.insert(4) ;
    p.insert(17) ;
    p.insert(21) ;
    p.insert(67) ;

    cout<<p.getSize() <<endl;
    cout<<p.getMin()<<endl<<endl;


    while(!p.isEmpty())
    {
        cout<<p.removeMin()<<endl;
    }
    cout<<endl;

    return 0 ;
}