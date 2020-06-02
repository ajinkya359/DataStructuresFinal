#include<bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    node* next;
};
class graph
{
    int v;
    node* arr;//contains all the edges;
public:
    void create_graph(int);
    void add_directed_edge(int u,int v);
    void print_graph();
};
void graph::print_graph(){
    for(int i=0;i<v;i++)
    {
        node* temp=&arr[i];
        cout<<i<<"--> ";
        while(temp){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
void graph::create_graph(int vi){
    v=vi;
    arr=(node*)malloc(v*sizeof(node));
    for(int i=0;i<v;i++)
    {
        arr[i].next=NULL;
        arr[i].value=i;
    }
}
void graph::add_directed_edge(int u,int v){
    node* temp=&arr[u];
    while (temp->next)
        temp=temp->next;
    temp->next=(node*)malloc(sizeof(node));
    temp=temp->next;
    temp->value=v;
    temp->next=NULL;
}