#include<iostream>
#include "../Headers/disjointsets.h"
using namespace std;

int main(){
    int v;
    cout<<"Enter the number of vertexes"<<endl;
    cin>>v;
    int arr[v];
    for(int i=0;i<v;i++)
        cin>>arr[i];
    disjointset* f[v];
    for(int i=0;i<v;i++)
        f[i]=make_disjointset(arr[i]);
    int e;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        if(find_disjointset(f[u])!=find_disjointset(f[v]))
            Union(f[u],f[v]);
    }
    for(int i=0;i<v;i++)
        cout<<"Representative of "<<f[i]->value<<" is "<<f[i]->representative->value<<endl;

}