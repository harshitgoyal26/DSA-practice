#include <iostream>
#include <vector>
using namespace std;

void inplaceHeapSort(vector<int> &v)
{
    int s = v.size();
    for (int i = 1; i < s; i++)
    {
        int child = i;
        while (child > 0)
        {
            int parent = (child - 1) / 2;
            if (v[child] < v[parent])
            {
                int temp = v[child];
                v[child] = v[parent];
                v[parent] = temp;
            }
            else
            {
                break;
            }
            child = parent;
        }
    }

    int ourSize = s;

    for (int i = 0; i < s; i++)
    {
        int temp = v[0];
        v[0] = v[ourSize - 1];
        v[ourSize - 1] = temp;
        ourSize--;


        int parent = 0;
        int lci = 2 * parent + 1;
        int rci = 2 * parent + 2;


        while(lci < ourSize)
        {
            int minIndex = parent ;
            if(v[lci] < v[minIndex])
            {
                minIndex = lci ;
            }

            if(rci < ourSize && v[rci] < v[minIndex])
            {
                minIndex = rci ;
            }

            if(minIndex == parent)
            {
                break ;
            }

            int temp = v[parent] ;
            v[parent] = v[minIndex ] ;
            v[minIndex] = temp ;

            parent = minIndex ;
            lci = 2 * parent + 1;
            rci = 2 * parent + 2;
        }
    }
}



int main()
{
    vector<int> v;
    v.push_back(5) ;
    v.push_back(50) ;
    v.push_back(15) ;
    v.push_back(13) ;
    v.push_back(1) ;
    v.push_back(78) ;
    v.push_back(34) ;
    v.push_back(101) ;
    v.push_back(99) ;

    inplaceHeapSort(v) ;

    for(int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<"   ";
    }
    cout<<endl ;


    return 0 ;
}