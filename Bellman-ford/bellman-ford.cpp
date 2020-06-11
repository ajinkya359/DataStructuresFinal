#include<bits/stdc++.h>
using namespace std;
struct vertex
{
    int data;
    vector<pair<vertex*,int>> neighbours;
    vertex* parent=NULL;
    long long distance=INT_MAX;
};
class graph{
public:
    int number_of_vertices=0;
    vertex* real_graph;
    graph(int n)
    {
        number_of_vertices=n;
        real_graph=(vertex*)malloc(sizeof(vertex)*n);
        for(int i=0;i<n;i++)
            real_graph[i].data=i;
    }
    void add_undirected_edge(int a,int b,int weight);
    void add_directed_edge(int a,int b,int weight);
    void print_graph();
    bool bellman_ford(vertex* start);
    void print_shortest_path(vertex* start,vertex* end);
    void print_shortest_path_util(vertex* start,vertex* end);
};
void graph::print_shortest_path_util(vertex* start,vertex* end)
{
    if(start==end)
        cout<<start->data<<endl;
    else if(end->parent==NULL)
        cout<<"No path exists"<<endl;
    else
    {
        print_shortest_path_util(start,end->parent);
        cout<<end->data<<endl;
    }
    
}
void graph::print_shortest_path(vertex* start,vertex* end)
{
    if(bellman_ford(start));
        print_shortest_path_util(start,end);
}
bool graph::bellman_ford(vertex* start)
{
    for(int i=0;i<number_of_vertices;i++)
    {
        real_graph[i].distance=INT_MAX;
        real_graph[i].parent=NULL;
    }
    start->distance=0;
    for(int i=0;i<number_of_vertices;i++)
    {
        for(int j=0;j<number_of_vertices;j++)
        {
            for(auto x:real_graph[j].neighbours)
            {
                if(real_graph[j].distance+x.second<x.first->distance)
                {
                    x.first->distance=real_graph[j].distance+x.second;
                    x.first->parent=&real_graph[j];   
                }
            }
        }
    }
    bool ans=true;
    for(int i=0;i<number_of_vertices;i++)
    {
        for(auto x:real_graph[i].neighbours)
        {
            if(real_graph[i].distance+x.second<x.first->distance)
             {   
                 ans= false;
                 x.first->distance=INT_MIN;
             }

        }
    }
    return true;
}
void graph::print_graph(){
    for(int i=0;i<number_of_vertices;i++)
    {
        cout<<"Neighbours of "<<real_graph[i].data<<" are ";
        for(auto x:real_graph[i].neighbours)
            cout<<x.first->data<<" ";
        cout<<endl;
    }
}
void graph::add_undirected_edge(int a,int b,int weight){
    real_graph[a].neighbours.push_back(make_pair(&real_graph[b],weight));
    real_graph[b].neighbours.push_back(make_pair(&real_graph[a],weight));
}
void graph::add_directed_edge(int a,int b,int weight){
    real_graph[a].neighbours.push_back(make_pair(&real_graph[b],weight));
}
int main(){
    graph g(5);
    g.add_directed_edge(0,1,6);
    g.add_directed_edge(0,4,7);
    g.add_directed_edge(1,2,5);
    g.add_directed_edge(1,3,-4);
    g.add_directed_edge(1,4,8);
    g.add_directed_edge(2,1,-2);
    g.add_directed_edge(3,0,2);
    g.add_directed_edge(3,2,4);
    g.add_directed_edge(4,3,9);
    g.add_directed_edge(4,2,-3);
    if(g.bellman_ford(&g.real_graph[0]))
        cout<<g.real_graph[4].distance<<endl;
    else
        cout<<"Graph has a negative cycle"<<endl;
    cout<<g.real_graph[4].distance<<endl;
    for(int i=0;i<g.number_of_vertices;i++)
    {
        if(g.real_graph[i].distance==INT_MIN)
            cout<<g.real_graph[i].data<<endl;
    }
}