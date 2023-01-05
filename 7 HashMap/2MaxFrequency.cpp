#include<unordered_map>
#include<iostream>
#include<cstdlib>
#include <vector>
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
int main()
{
    // int arr[] = {1,2,3,2,4,3,1,6,3,5,5,1};
    // vector<int> output = removeDuplicate(arr , 12);

    // for(int i = 0 ; i< output.size() ; i++)
    // {
    //     cout<<output[i] <<endl ;
    // }




    int arr[] = {1,2,3,2,4,3,1,6,3,5,5,1,5,5};

    cout<<maxFreq(arr , 14)<<endl ;


    return 0 ;
}