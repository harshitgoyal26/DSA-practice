#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue
{
    vector<int> pq;

public:
    int getSize()
    {
        return pq.size();
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getMax()
    {
        if (isEmpty())
        {
            return INT16_MIN;
        }
        return pq[0];
    }

    void insert(int elem)
    {
        pq.push_back(elem);
        int child = pq.size() - 1;

        while (child > 0)
        {
            int parent = (child - 1) / 2;

            if (pq[child] > pq[parent])
            {
                int temp = pq[child];
                pq[child] = pq[parent];
                pq[parent] = temp;
            }
            else
            {
                break;
            }

            child = parent;
        }
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return INT16_MIN;
        }
        int res = pq[0];
        int last = pq.size() - 1;

        pq[0] = pq[last];
        pq.pop_back();

        int parent = 0;
        int lci = 2 * parent + 1;
        int rci = 2 * parent + 2;

        while (lci < pq.size())
        {
            int maxIndex = parent;

            if (pq[maxIndex] < pq[lci])
            {
                maxIndex = lci;
            }
            if (rci < pq.size() && pq[maxIndex] < pq[rci])
            {
                maxIndex = rci;
            }

            if (maxIndex == parent)
            {
                break;
            }

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parent];
            pq[parent] = temp;

            parent = maxIndex;

            lci = 2 * parent + 1;
            rci = 2 * parent + 2;
        }
        return res ;
    }
};



int main()
{
    MaxPriorityQueue p;

    p.insert(100) ;
    p.insert(10) ;
    p.insert(15) ;
    p.insert(4) ;
    p.insert(17) ;
    p.insert(21) ;
    p.insert(67) ;

    cout<<p.getSize() <<endl;
    cout<<p.getMax()<<endl<<endl;


    while(!p.isEmpty())
    {
        cout<<p.removeMax()<<endl;
    }      
    cout<<endl;

    return 0 ;
}