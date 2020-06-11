#include<bits/stdc++.h>
#include "../Headers/disjointsets.h"
using namespace std;
struct vertex
{
    int data;
    vector<pair<vertex*,int>> neighbours;
    vertex* parent=NULL;
    long long distance=INT_MAX;
};
struct minSequence
{
    bool operator()(vertex* const& p1,vertex* const& p2)
    {
        return p1->distance>=p2->distance;
    }
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
    void dijkstra(vertex* s);
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
    dijkstra(start);
    print_shortest_path_util(start,end);
}
void graph::dijkstra(vertex* s)
{
    for(int i=0;i<number_of_vertices;i++)
    {
        real_graph[i].distance=INT_MAX;
        real_graph[i].parent=NULL;
    }
    s->distance=0;
    priority_queue<vertex*,vector<vertex*>,minSequence> q;
    for(int i=0;i<number_of_vertices;i++)   
        q.push(&real_graph[i]);
    while(!q.empty()){
        vertex* temp=q.top();
        q.pop();
        for(auto x:temp->neighbours)
        {
            if(temp->distance+x.second<x.first->distance)
            {
                x.first->distance=temp->distance+x.second;
                x.first->parent=temp;
            }
        }
    }
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
    graph g(7);
    g.add_directed_edge(0,1,10);
    g.add_directed_edge(0,4,5);
    g.add_directed_edge(1,2,1);
    g.add_directed_edge(1,4,2);
    g.add_directed_edge(2,3,4);
    g.add_directed_edge(3,2,6);
    g.add_directed_edge(3,0,7);
    g.add_directed_edge(4,1,3);
    g.add_directed_edge(4,2,9);
    g.add_directed_edge(4,3,2);
    //Vertex 6 and vertex 7 are in different component
    g.add_directed_edge(6,7,1);
    g.dijkstra(&g.real_graph[0]);
    g.print_shortest_path(&g.real_graph[0],&g.real_graph[7]);
}