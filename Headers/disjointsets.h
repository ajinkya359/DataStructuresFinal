#include<iostream>
using namespace std;
struct disjointset{
    int value;
    disjointset* next;
    disjointset* representative;
};
disjointset* make_disjointset(int value){
    disjointset* temp=(disjointset*)malloc(sizeof(disjointset));
    temp->value=value;
    temp->representative=temp;
    temp->next=NULL;
    return temp;
}
disjointset* find_disjointset(disjointset* t){
    return t->representative;
}
void Union(disjointset* u,disjointset* v){
    disjointset* vrep=v->representative;
    disjointset* urep=u->representative;
    disjointset* temp=urep;
    while (temp->next!=NULL)
        temp=temp->next;
    temp->next=vrep;
    temp=vrep;
    while(temp){
        temp->representative=urep;
        temp=temp->next;
    }
}