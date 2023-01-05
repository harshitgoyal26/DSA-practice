#include<unordered_map>
#include<iostream>
#include<cstdlib>
#include <vector>
#include<algorithm>
using namespace std ;


int main()
{
    unordered_map<string , int> ourmap ;
    ourmap["abc"] = 0; 
    ourmap["abc1"] = 1; 
    ourmap["abc2"] = 2; 
    ourmap["abc3"] = 3; 
    ourmap["abc4"] = 4; 
    ourmap["abc5"] = 5;


    unordered_map<string , int> :: iterator it = ourmap.begin() ;
    while(it != ourmap.end())
    {
        cout<<"Key: "<<it -> first<<"   Value: "<<it -> second<<endl;
        it++ ;
    } 


    vector<int> v ;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int> :: iterator it2 = v.begin() ;
    while(it2 != v.end())
    {
        cout<<*it2<<endl ;
        it2++ ;
    }

    return 0 ;
}