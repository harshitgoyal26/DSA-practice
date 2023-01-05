#include<iostream>
#include<queue>
using namespace std;


queue<int> reverse(queue<int> q)
{
    if(q.size() == 0 || q.size() == 1)
    {
        return q ;
    }

    int x = q.front();
    q.pop();
    q = reverse(q) ;

    q.push(x);

    return q;
}


int main()
{
    int n ,x;
    cin>>n;
    queue<int> q;

    for(int i =0 ; i < n ; i++)
    {
        cin>>x;
        q.push(x) ;
    }
    cout<<endl;

    q = reverse(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}