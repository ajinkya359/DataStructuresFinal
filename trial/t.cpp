#include<bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    node* next;
};

int main(){
    int v;
    cin>>v;
    int* arr=(int* )malloc(v*sizeof(int));
    for(int i=0;i<v;i++)
        arr[i]=i;
    
}