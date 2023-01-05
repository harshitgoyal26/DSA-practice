//Minimum bracket Reversal

#include<iostream>
#include<stack>
using namespace std;

int reversals(string arr)
{
    stack<char> s ;
    if(arr.size() % 2 != 0)
    {
        return -1;
    }

    for(int i = 0 ; i < arr.size() ; i++)
    {
        if(arr[i] == '{')
        {
            s.push(arr[i]);
        }
        else
        {
            if(s.empty())
            {
                s.push(arr[i]);
            }
            else if(!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else if(!s.empty() && s.top() == '}')
            {
                s.push(arr[i]);
            }
        }
    }

    if(s.size() %2 != 0)
    {
        return -1 ;
    }
    int count = 0;

    while(!s.empty())
    {
        char c1 = s.top();
        s.pop();
        char c2 = s.top();

        if(c1 == c2)
        {
            s.pop();
            count++;
        }
        else if(c1 == '{' && c2 == '}')
        {
            s.pop();
            count +=2;
        }
    }
    return count ;
}

int main()
{
    string arr = "{{}}}}{{";
    cout<<reversals(arr);

    return 0;
}