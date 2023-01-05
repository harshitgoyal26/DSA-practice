#include<iostream>
#include<queue>
using namespace std ;

int *kSmallest(int *arr , int n , int k)
{
    priority_queue<int> pq ;
    for(int i = 0 ; i < k ; i++)
    {
        pq.push(arr[i]) ;
    }

    for(int i = k ; i < n ;i++)
    {
        if(pq.top() > arr[i])
        {
            pq.pop() ;
            pq.push(arr[i]) ;
        }
    }

    int *res = new int[k] ;
    int j = 0 ;

    while(!pq.empty())
    {
        res[j] = pq.top() ;
        pq.pop() ;
        j++ ;
    }
    return res ;
}

int main()
{
    int n = 13 ;
    int k =4 ;
    int arr[] = {2 ,12 ,9 ,16 ,10 ,5 ,3 ,20 ,25 ,11 ,1 ,8 ,6} ;

    int *res = kSmallest(arr , n , k) ;

    for(int i = 0 ; i < k  ; i++)
    {
        cout<<res[i]<<"  ";
    }

    return 0 ;
}