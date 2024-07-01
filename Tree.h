#ifndef H_Tree
#define H_Tree

#include "Node.h"

template <typename T>
class Tree
{
public:
    Tree() {}
    virtual void insert(const T &) = 0;
    virtual void remove(const T &) = 0;
    virtual void displayInOrder() const = 0;
    virtual void displayPreOrder() const = 0;
    virtual void displayPostOrder() const = 0;
    virtual void searchValue(const T &) const = 0;
    virtual int getTreeHeight() const = 0;
    virtual int getNodeHeight(const T &) const = 0;
    virtual void getMin() const = 0;
    virtual void getMax() const = 0;
    ~Tree() {}

protected:
    Node<T> *root;
};

#endif // H_Tree