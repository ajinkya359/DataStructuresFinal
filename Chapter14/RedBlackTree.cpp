#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    int color; //0 for red and 1 for black  
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
    node* maximum(node* root);
    node* minimum(node* root);
    node* tree_successor(int key);
    node* tree_predecessor(int key);
    void delete_node(int key);
    void left_rotate(int key);
    void right_rotate(int key);
    void rb_insert(int key);
};
void Graph::rb_insert(int key){
    insertNode(key);
    node* x=search_iterative(key);
    x->color=0;
    while(x!=root&&x->parent->color==0)
    {
        if(x->parent==x->parent->parent->left)
        {
            node* y=x->parent->parent->left;
            if(y->color==0)
            {
                x->parent->color=1;
                y->color=1;
                x->parent->parent->color=0;
                x=x->parent->parent;
            }
            else if(x==x->parent->right)
            {
                x=x->parent;
                left_rotate(x->key);
            }
            else{
                x->parent->color=1;
                x->parent->parent->color=0;
                right_rotate(x->parent->parent->key);
            }
        }
        else{
            node* y=x->parent->parent->right;
            if(y->color==0)
            {
                x->parent->color=1;
                y->color=1;
                x->parent->parent->color=0;
                x=x->parent->parent;
            }
            else if(x==x->parent->left)
            {
                x=x->parent;
                right_rotate(x->key);
            }
            else{
                x->parent->color=1;
                x->parent->parent->color=0;
                left_rotate(x->parent->parent->key);
            }
        }
    }
    root->color=1;
}
void Graph::left_rotate(int key){
    node* x=search_iterative(key);
    if(x->right==NULL) return;
    node* y=x->right;
    if(y->left) x->right=y->left;//setting the left child of y as the rightt child of x
    y->left->parent=x;
    y->parent=x->parent;
    if(x->parent==NULL) root=y;
    else if (x==x->parent->left)
        x->parent->left=y;
    else
        x->parent->right=y;
    y->left=x;
    x->parent=y;
}
void Graph::right_rotate(int key){
    node* x=search_iterative(key);
    node* y=x->left;
    if(y==NULL) return;
    if(y->right)
        x->left=y->right;
    y->right->parent=x;
    y->right=x;
    y->parent=x->parent;
    if(x->parent==NULL)
        root=y;
    else if(x==x->parent->left)
        x->parent->left=y;
    else
        x->parent->right=y;
    x->parent=y;

    
}
void Graph::delete_node(int key){
    node* z=search_iterative(key);
    node* y;
    if(z->left==NULL||z->right==NULL)//means that z dont have both child
        y=z;
    else//means that z has both children
        y=tree_successor(key);
    //now we are sure that y will have atmost of one child only
    node* child;
    if(y->left!=NULL)
        child=y->left;
    else
        child=y->right;
    if(child!=NULL)//meansd that if the child exists, then you need to set its parent also
        child->parent=y->parent;
    if(y->parent==NULL)//it means that if y was a root
        root=child;
    else
    {    
        if(y==y->parent->left)
            y->parent->left=child;
        else
            y->parent->right=child;
    }
    if(y!=z)
        z->key=y->key;
}
node* Graph::tree_predecessor(int key){
    node* temp=search_iterative(key);
    if(temp==NULL) return NULL;
    if(temp->left) return maximum(temp->left);
    node* y=temp->parent;
    while(y&&temp==y->left)
    {
        temp=y;
        y=y->parent;
    }
    return y;
}
node* Graph::tree_successor(int key){
    node* n=search_iterative(key);
    if(n==NULL) return NULL;
    if(n->right) return minimum(n->right);
    node* y=n->parent;
    while(y&&y->right==n)
    {
        n=y;
        y=y->parent;
    }
    return y;
}
node* Graph::minimum(node* root){
    node* temp=root;
    if(!temp) return NULL;
    while(temp->left)
        temp=temp->left;
    return temp;
    
}
node* Graph::maximum(node* root){
    node* temp=root;
    if(!temp) return NULL;
    while(temp->right)
        temp=temp->right;
    return temp;
    
}
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
    G.rb_insert(1);
    G.rb_insert(2);
    G.rb_insert(3);
    G.rb_insert(4);
    G.rb_insert(5);
    G.rb_insert(6);
    G.rb_insert(7);
    G.rb_insert(8);
    for(int i=1;i<=8;i++)
    {
        node* temp=G.search_iterative(6)->parent;
        if(temp)
            cout<<"Key of parent of "<<i<<" is "<<temp->key<<endl;
        else
            cout<<i<<" is the root"<<endl;
    }
    cout<<G.search_iterative(5)->left->key<<endl;
    cout<<G.search_iterative(5)->right->key<<endl;
}