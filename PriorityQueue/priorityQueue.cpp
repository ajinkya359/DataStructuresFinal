#include<bits/stdc++.h>
using namespace std;
struct minSequence
{
    bool operator()(int const& p1,int const& p2)
    {
        return p1>=p2;
    }
};
int main(){
    priority_queue<int,vector<int>,minSequence> q;
    q.push(10);
    q.push(3);
    q.push(4);
    q.push(20);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top();
}