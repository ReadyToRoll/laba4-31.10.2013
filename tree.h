#ifndef TREE_H
#define TREE_H

struct node;

class Set
{
    private:
        class Tree;
    Tree *pimpl;
    public:
        Set();
        Set(int t);
        ~Set();
    void push(int data);
    bool is_empty();
    void show();
    node* check(int key);
    Set operator*(Set &b);
    Set& operator = (const Set &ob);
   /*   Tree operator+(Tree &b);
      Tree operator-(Tree &b);
    Tree operator*(Tree &b);*/
};

#endif // TREE_H
