#include<bits/stdc++.h>
#include "../Headers/graph.h"
using namespace std;

int main(){
    int v;
    cout<<"Enter the number of vertexes"<<endl;
    cin>>v;
    graph g;
    g.create_graph(v);
    int e;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g.add_directed_edge(u,v);
    }
    g.print_graph();
    
}