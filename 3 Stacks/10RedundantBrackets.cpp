#include<iostream>
#include<stack>
using namespace std;


bool checkR(string arr)
{
    stack<char> s;
    for(int i = 0 ; i< arr.size() ; i++)
    {
        if(arr[i] == ')')
        {
            int count = 0;
            while(s.top() != '(')
            {
                s.pop();
                count++;
            }
            if(count ==0 || count == 1)
            {
                return true;
            }
        }
        else
        {
            s.push(arr[i]);
        }
    }

    return false;


}

int main()
{
    string arr ="(a+b)";

    cout<<checkR(arr);

    return 0;
}