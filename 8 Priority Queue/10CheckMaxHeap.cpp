#include<iostream>
#include<queue>
using namespace std ;


bool checkMaxHeap(int arr[] , int n)
{
    int parent = 0 ;
    int lci = 2*0 +1 ;
    int rci = 2*0 +2 ;

    for(int i = 0 ; i < n && lci < n; i++)
    {
        if(lci>n)
        {
            break;
        }
        if(arr[lci] > arr[parent])
        {
            return false ;
        }
        if(rci > n)
        {
            break;
        }
        if(arr[rci] > arr[parent])
        {
            return false ;
        }

        parent = i+1 ;
        lci = 2*parent +1 ;
        rci = 2*parent +2 ;
    }

    return true ;
}


int main()
{
    int n = 7 ;
    int arr [] = {42,20,18,6,14,11,9,4 } ;
    cout<<checkMaxHeap(arr , n)<<endl ;
    return 0 ;
}