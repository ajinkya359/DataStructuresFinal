#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    node* left;
    node* right;
    node* parent;
};
class Graph{
public:
    node* root=NULL;
    void insertNode(int key);
    void inorder(node* start);
    void postorder(node* start);
    void preorder(node* start);
    void inorderStack();
    node* search(node* root,int key);
    node* search_iterative(int key);
};
node* Graph::search_iterative(int key){
    node* temp=root;
    while(temp){
        if(temp->key==key)
            return temp;
        else if(key>=temp->key)
            temp=temp->right;
        else
            temp=temp->left;
    }
    return temp;
}
node* Graph::search(node* root,int key){
    if(root==NULL||root->key==key)
        return root;
    else if(key>=root->key)
        return search(root->right,key);
    else
        return search(root->left,key);
    
}
void Graph::inorderStack(){
    stack<node*> s;
    if(!root) return;
    node* current=root;
    do{
        if(current==NULL)
        {
            current=s.top();
            s.pop();
            cout<<current->key<<endl;
            current=current->right;
        }
        else{
            s.push(current);
            current=current->left;
        }
    }while(!s.empty()||current!=NULL);
}
void Graph::inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}
void Graph::postorder(node* root){
    if(root){
        inorder(root->left);
        inorder(root->right);
        cout<<root->key<<endl;
    }
}
void Graph::preorder(node* root){
    if(root){
        cout<<root->key<<endl;
        inorder(root->left);
        inorder(root->right);
    }
}
void Graph::insertNode(int key){
    node* temp=new node;
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL){
        temp->parent=NULL;
        root=temp;
    }
    else{
        node* current=root;
        node* parent=root->parent;
        while(current){
            parent=current;
            if(key>=current->key)
                current=current->right;
            else
                current=current->left;
        }
        if(key>=parent->key)
            parent->right=temp;
        else
            parent->left=temp;
        temp->parent=parent;
    }
}
int main(){
    Graph G;
    G.insertNode(5);
    G.insertNode(7);
    G.insertNode(3);
    G.insertNode(8);
    G.insertNode(2);
    G.insertNode(5);
    cout<<(G.search_iterative(10))<<endl;
}