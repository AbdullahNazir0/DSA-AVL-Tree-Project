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
    virtual void getTreeHeight() const = 0;
    virtual void getNodeHeight(const T &) const = 0;
    ~Tree() {}

protected:
    Node<T> *root;
};

#endif // H_Tree