#include <iostream>
#include <stdlib.h>
#include "tree.h"

using namespace std;

struct node
{
    int n;
    node*left,*right;
    node(int n): n(n), left(0), right(0) {}
    node(): n(0), left(0), right(0) {}
    ~node()
    {
        n = 0;
        left = 0;
        right = 0;
    }
};

class Set::Tree
{
private:
    node*root;
    void Union(node*wer,Tree &buf);
    void difference(node*wer,Tree &buf, Tree &tr2);
    void intersection(node*wer,Tree &buf, Tree &tr2);
    void intersection(node*wer,Tree &buf, node*root);
    void copyTree(node *&rootnew, node *rootold);
    void delTree(node *wer);
    void push(node*&wer,int data);
    void show(node*wer);
    bool check(node*wer,int key);
public:
    Tree operator+(Tree &b);
    Tree operator-(Tree &b);
    Tree operator*(Tree &b);
    Tree();
    Tree(int t);
    Tree (const Tree &ob);
    ~Tree();
    void push(int data);
    void show();
    bool check(int key);
    bool is_empty();
    Tree& operator = (const Tree &ob);
    bool nextDatum(bool start, int &datum) const;
};

Set &Set::operator= (const Set &ob)
{
pimpl->operator=(*ob.pimpl);
return *this;
}

Set::Set(const Tree &other)
{
    pimpl=new Tree(other);
}

Set Set::operator+ (Set &b)
{
    Set c(pimpl->operator+(*b.pimpl));
    return c;
}

Set Set::operator- (Set &b)
{
    Set c(pimpl->operator-(*b.pimpl));
    return c;
}

Set Set::operator* (Set &b)
{
    Set c(pimpl->operator*(*b.pimpl));
    return c;
}

bool Set:: check(int key)
{
    return pimpl->check(key);
}

void Set::push(int data)
{
    pimpl->push(data);
}
bool Set::is_empty()
{
    pimpl->is_empty();
    return 0;
}
void Set::show()
{
    pimpl->show();
}


Set::Set() : pimpl( new Tree ) {}

Set::Set(int t)
{
    pimpl=new Tree(t);
}

Set::Tree::Tree(int t)
{
    root=0;
    for(int i=0; i<t; i++)
    {
        int k=rand()%100;
        if(check(root,k)==0)
            push(root,k);
        else
            t++;
    }
}

Set::~Set()
{
    delete pimpl;
    pimpl = 0;
}

Set::Tree& Set::Tree::operator=(const Tree &ob)
{
    if(this==&ob)
        return *this;
    delTree(root);
    copyTree(root,ob.root);
    return *this;
}

Set::Tree::Tree (const Tree &ob)
{
    if (ob.root==0)
        root=0;
    else
    {
        root=new node;
        root->n=ob.root->n;
        root->left=0;
        root->right=0;
        copyTree(root, ob.root);
    }
}

void Set::Tree::copyTree(node *&rootnew, node *rootold)
{
    if (rootold->left!=0)
    {
        push(rootnew, (rootold->left)->n);
        copyTree(rootnew, rootold->left);
    }
    if (rootold->right!=0)
    {
        push(rootnew, (rootold->right)->n);
        copyTree(rootnew, rootold->right);
    }
}
bool Set::Tree::check(int key)
{
    if(root==0) return false;
    else if(key<root->n) return check(root->left,key);
    else if(key>root->n) return check(root->right,key);
    else return true;
}

bool Set::Tree::check(node*wer,int key)
{
    if(wer==0) return false;
    else if(key<wer->n) return check(wer->left,key);
    else if(key>wer->n) return check(wer->right,key);
    else return true;
}

Set::Tree::Tree()
{
    root=0;
}

Set::Tree::~Tree()
{
    delTree(root);
}

Set::Tree Set::Tree::operator+(Tree &tr2)
{
    Tree buf;
    Union(root,buf);
    Union(tr2.root,buf);
    return buf;
}

void Set::Tree::Union(node*wer,Tree &buf)
{
    if(wer!=0)
    {
        Union(wer->left,buf);
        push(buf.root,wer->n);
        Union(wer->right,buf);
    }
}

Set::Tree Set::Tree::operator-(Tree &tr2)
{
    Tree buf;
    difference(root,buf,tr2);
    return buf;
}

void Set::Tree::difference(node*wer,Tree &buf,Tree &tr2)
{
    if(wer!=0)
    {
        difference(wer->left,buf,tr2);
        if(tr2.check(tr2.root,wer->n)==0)
            buf.push(wer->n);
        difference(wer->right,buf,tr2);
    }
}

Set::Tree Set::Tree::operator*(Tree &tr2)
{
    Tree buf;
    intersection(root,buf,tr2);
    intersection(tr2.root,buf,root);
    return buf;
}

void Set::Tree::intersection(node*wer,Tree &buf,Tree &tr2)
{
    if(wer!=0)
    {
        intersection(wer->left,buf,tr2);
        if(tr2.check(tr2.root,wer->n)!=0)
            push(buf.root,wer->n);
        intersection(wer->right,buf,tr2);
    }
}

void Set::Tree::intersection(node*wer,Tree &buf,node*root)
{
    if(wer!=0)
    {
        intersection(wer->left,buf,root);
        if(check(root,wer->n)!=0)
            push(buf.root,wer->n);
        intersection(wer->right,buf,root);
    }
}

void Set::Tree::delTree(node *wer)
{
    if(wer==0)return;
    else if((wer->left==0)&&(wer->right==0))
    {
        if(wer->left!=0)delTree(wer->left);
        if(wer->right!=0)delTree(wer->right);
        delete wer;
    }
}
void Set::Tree::push(node*&wer,int data)
{
    if(wer==0)
    {
        wer=new node;
        wer->n=data;
        wer->left=0;
        wer->right=0;
    }
    else if(data<wer->n)push(wer->left,data);
    else if(data>wer->n)push(wer->right,data);
}

void Set::Tree::push(int data)
{
    if(root==0)
    {
        root=new node;
        root->n=data;
        root->left=0;
        root->right=0;
    }
    else if(data<root->n)push(root->left,data);
    else if(data>root->n)push(root->right,data);
}

void Set::Tree::show()
{
    if(root!=0)
    {
        show(root->left);
        cout<<root->n<<" ";
        show(root->right);
    }
}

bool Set::Tree::is_empty()
{
    if(root==0)
        return true;
    else
        return false;
}

void Set::Tree::show(node*root)
{
    if(root!=0)
    {
        show(root->left);
        cout<<root->n<<" ";
        show(root->right);
    }
}

bool Set::Tree::nextDatum(bool start, int &datum) const
{
    static Node *cur;
    if (start)
        cur=root;
    bool result=cur!=0;
    if (result)
    {
        datum=cur->datum;
        cur=cur->left;
        cur=cur->right;
    }
    return result;
}
