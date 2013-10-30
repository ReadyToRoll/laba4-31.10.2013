#ifndef TREE_H
#define TREE_H

struct node;

class Set
{
private:
    class Tree;
    Tree *pimpl;
    Set(const Tree &other);
public:
    Set();
    Set(int t);
    ~Set();
    void push(int data);
    void show();
    bool is_empty();
    bool check(int key);
    Set& operator = (const Set &ob);
    Set operator+(Set &b);
    Set operator-(Set &b);
    Set operator*(Set &b);
    void nextDatum(bool firstTime, bool ch, bool rootCh, int &datum) const;
};

#endif // TREE_H
