#include<unordered_map>
#include<iostream>
#include<cstdlib>
#include <vector>
#include<algorithm>
using namespace std ;


vector<int> removeDuplicate(int *a , int size)
{
    vector<int> output ;
    unordered_map<int , bool> seen ;
    for(int i = 0 ; i < size ; i++)
    {
        if(seen.count(a[i]) > 0)
        {
            continue ;
        }
        seen[a[i]] = true ;
        output.push_back(a[i]) ;
    }

    return output ;

}


int maxFreq(int *arr , int size)
{
    int max = -1;
    int maxVal = 0; 
    unordered_map<int , int> myMap ;
    for(int i = 0 ; i < size ; i++)
    {
        myMap[arr[i]]++ ;
        if(max < myMap[arr[i]])
        {
            max = myMap[arr[i]] ;
            maxVal = arr[i] ;
        }
    }

    return maxVal ;
}


vector<int> arrIntersection(int *arr1 , int n , int *arr2 , int m)
{
    vector<int> output ;
    unordered_map<int , int> myMap ;

    for(int i = 0 ; i<n ; i++)
    {
        myMap[arr1[i]]++ ;
    }

    for(int i = 0 ; i < m ; i++)
    {
        if(myMap.count(arr2[i]) > 0)
        {
            output.push_back(arr2[i]);
            myMap[arr2[i]]-- ;
        }
    }

    sort(output.begin() , output.end()) ;
    return output ;
}

int pairSumZero(int *arr , int size)
{
    int count  = 0 ;
    unordered_map<int , int> myMap ;

    for(int i = 0 ; i<size ; i++)
    {
        myMap[arr[i]]++ ;
    } 

    for(int i = 0 ; i<myMap.size() ; i++)
    {
        if(myMap.count(-1 * i) > 0 )
        {
            int freq = myMap[-1 * i] ;
            count = count + (freq * myMap[i]) ;
        }
    }

    return count ;
}


int main()
{
    // int arr[] = {1,2,3,2,4,3,1,6,3,5,5,1};
    // vector<int> output = removeDuplicate(arr , 12);

    // for(int i = 0 ; i< output.size() ; i++)
    // {
    //     cout<<output[i] <<endl ;
    // }


    // int arr[] = {1,2,3,2,4,3,1,6,3,5,5,1,5,5};
    // cout<<maxFreq(arr , 14)<<endl ;


    // int arr1[] = {2,6,8,5,4,3} ;
    // int n = 6 ;


    // int arr2[] = {2,3,4,7} ;
    // int m = 4 ;

    // // int arr1[] = {10,10} ;
    // // int n = 2 ;


    // // int arr2[] = {10} ;
    // // int m = 1 ;

    // int arr1[] = {2,6,1,2} ;
    // int n = 4 ;


    // int arr2[] = {1,2,3,4,2} ;
    // int m = 5 ;

    // vector<int> output = arrIntersection(arr1 , n , arr2 , m) ;
    // for(int i = 0 ; i < output.size() ; i++)
    // {
    //     cout<<output[i]<<endl ;
    // }


    int arr[] = {2,1,-2,2,3} ;
    int arr1[] = {5} ;
    cout<<pairSumZero(arr1 , 1) ;

    return 0 ;
}