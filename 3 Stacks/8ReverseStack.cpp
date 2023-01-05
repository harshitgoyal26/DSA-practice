#include<iostream>
#include<stack>
using namespace std;

stack<int> reverse(stack<int> s1 , stack<int> s2)
{
    if(s1.size() == 0 || s1.size() == 1)
    {
        return s1;
    }

    int s = s1.top() ;
    s1.pop();

    s1 = reverse(s1 ,  s2) ;

    while(!s1.empty())
    {
        int x = s1.top();
        s1.pop() ;
        s2.push(x);
    }

    s1.push(s);
    while(!s2.empty())
    {
        int x = s2.top();
        s2.pop();
        s1.push(x);
    }
    return s1;
}


int main()
{
    int n ,x;
    cin>>n;
    stack<int> s1 , s2;

    for(int i =0 ; i < n ; i++)
    {
        cin>>x;
        s1.push(x) ;
    }
    cout<<endl;

    s1 = reverse(s1 , s2);
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    return 0;
}