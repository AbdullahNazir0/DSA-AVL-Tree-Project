#ifndef H_AVLTree
#define H_AVLTree

#include "Tree.h"

template <typename T>
class AVLTree : Tree<T>
{
public:
    AVLTree();
    void insert(const T &) override;
    void remove(const T &) override;
    void displayInOrder() const override;
    void displayPreOrder() const override;
    void displayPostOrder() const override;
    void searchValue(const T &) const override;
    void getTreeHeight() const override;
    void getNodeHeight(const T &) const override;
    ~AVLTree();

private:
    void helpInsert(Node<T> *&, Node<T> *);
    void helpRemove(Node<T> *&, Node<T> *);
    void inorder(Node<T> *) const;
    void preorder(Node<T> *) const;
    void postorder(Node<T> *) const;
    void search(Node<T> *, const T &);
    void destroyTree(Node<T> *&);
};

// alias
template <typename T>
using AVL = AVLTree<T>;

#include "AVLTreeImpl.cpp"

#endif // H_AVLTree