#include<bits/stdc++.h>
using namespace std;
struct vertex
{
    int data;
    vector<vertex*> neighbours;
    int color=0;//0 means white,1 means gray and 2 means black
    vertex* parent=NULL;
    int distance;
    int start_time;
    int end_time;
};
class graph{
public:
    int number_of_vertices=0;
    vertex* real_graph;
    
    int time=0;
    graph(int n)
    {
        number_of_vertices=n;
        real_graph=(vertex*)malloc(sizeof(vertex)*n);
        for(int i=0;i<n;i++)
            real_graph[i].data=i;
        
    }
    void add_undirected_edge(int a,int b);
    void add_directed_edge(int a,int b);
    void print_graph();
    void bfs(vertex* start);
    void find_path(vertex* start,vertex* end);
    void dfs(vertex* start);
    void dfs_visit(vertex* v);
};
void graph::dfs_visit(vertex* v){
    v->color=1;
    cout<<v->data<<endl;
    v->start_time=time;
    time++;
    for(auto x:v->neighbours)
    {
        if(x->color==0)
        {
            x->parent=v;
            dfs_visit(x);
        }
    }
    v->color=2;
    v->end_time=time;
    time++;
}
void graph::dfs(vertex* start){
    time=0;
    for(int i=0;i<number_of_vertices;i++)
    {
        real_graph[i].parent=NULL;
        real_graph[i].color=0;
    }
    dfs_visit(start);
    for(int i=0;i<number_of_vertices;i++)
    {
        if(real_graph[i].color==0)
            dfs_visit(&real_graph[i]);
    }
}
void graph::find_path(vertex* start,vertex* end)//You must be done with bfs earlier
{    if(start==end)
        cout<<start->data<<endl;
    else if(end->parent==NULL)
        cout<<"No path from "<<start->data<<" to "<<end->data<<endl;
    else
    {
        find_path(start,end->parent);
        cout<<end->data<<endl;
    }
       
}
void graph::bfs(vertex* start){
    for(int i=0;i<number_of_vertices;i++)
    {
        real_graph[i].color=0;
        real_graph[i].parent=NULL;
        real_graph[i].distance=INT_MAX;
    }
    start->color=1;
    start->parent=NULL;
    start->distance=0;
    queue<vertex*> q;
    q.push(start);
    while(!q.empty())
    {
        vertex* temp=q.front();
        cout<<temp->data<<endl;
        q.pop();
        for(auto x:temp->neighbours)
        {
            if(x->color==0)
            {
                x->color=1;
                q.push(x);
                x->parent=temp;
                x->distance=temp->distance+1;
            }
        }
        temp->color=2;
    }
}
void graph::print_graph(){
    for(int i=0;i<number_of_vertices;i++)
    {
        cout<<"Neighbours of "<<real_graph[i].data<<" are ";
        for(auto x:real_graph[i].neighbours)
            cout<<x->data<<" ";
        cout<<endl;
    }
}
void graph::add_undirected_edge(int a,int b){
    real_graph[a].neighbours.push_back(&real_graph[b]);
    real_graph[b].neighbours.push_back(&real_graph[a]);
}
void graph::add_directed_edge(int a,int b){
    real_graph[a].neighbours.push_back(&real_graph[b]);
}
int main(){
    graph g(5);
    g.add_undirected_edge(0,1);
    g.add_undirected_edge(0,4);
    g.add_undirected_edge(1,3);
    g.add_undirected_edge(1,4);
    g.add_undirected_edge(3,4);
    g.dfs(&g.real_graph[4]);
    
}