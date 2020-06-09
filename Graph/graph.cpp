#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next=NULL;
};
class graph{
public:
    int number_of_vertices=0;
    node* list;
    graph(int n){
        number_of_vertices=n;
        list=(node*)malloc(n*sizeof(node));
        for(int i=0;i<n;i++)
            list[i].data=i;
    }
    void add_undirected_edge(int a,int b);
    void add_directed_edge(int a,int b);
    void print_graph();
};
void graph::add_undirected_edge(int a,int b)
{
    node* temp=&list[a];
    while(temp->next)
        temp=temp->next;
    temp->next=new node;
    temp->next->data=b;
    temp=&list[b];
    while(temp->next)
        temp=temp->next;
    temp->next=new node;
    temp->next->data=a;
}
void graph::add_directed_edge(int a,int b)
{
    node* temp=&list[a];
    while(temp->next)
        temp=temp->next;
    temp->next=new node;
    temp->next->data=b;
}
void graph::print_graph()
{
    for(int i=0;i<number_of_vertices;i++)
    {
        node* temp=&list[i];
        cout<<"The vertices connected to the node "<<temp->data<<" are ";
        while(temp)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int main(){
    graph g(5);
    g.add_undirected_edge(0,1);
    g.add_undirected_edge(0,4);
    g.add_undirected_edge(1,2);
    g.add_undirected_edge(1,3);
    g.add_undirected_edge(1,4);
    g.add_undirected_edge(2,3);
    g.add_undirected_edge(3,4);
    g.print_graph();
}