#ifndef H_AVLTree
#define H_AVLTree

#include "Tree.h"

template <typename T>
class AVLTree : public Tree<T>
{
public:
    AVLTree();
    // public functions.
    void insert(const T &) override;
    void remove(const T &) override;
    void displayInOrder() const override;
    void displayPreOrder() const override;
    void displayPostOrder() const override;
    void searchValue(const T &) const override;
    int getTreeHeight() const override;
    int getNodeHeight(const T &) const override;
    void getMin() const override;
    void getMax() const override;
    void getSuccessor(const T &) const;
    void getPredecessor(const T &) const;
    int getDiameter() const;
    ~AVLTree();

private:
    // private helper functions.
    void helpInsert(Node<T> *&, Node<T> *);
    void helpRemove(Node<T> *&, const T &);
    void inorder(Node<T> *) const;
    void preorder(Node<T> *) const;
    void postorder(Node<T> *) const;
    Node<T> *searchNode(Node<T> *, const T &) const;
    int nodeHeight(Node<T> *) const;
    void search(Node<T> *, const T &) const;
    int findBalanceFactor(Node<T> *) const;
    void leftRotate(Node<T> *&);
    void rightRotate(Node<T> *&);
    void leftRightRotate(Node<T> *&);
    void rightLeftRotate(Node<T> *&);
    void min(Node<T> *) const;
    void max(Node<T> *) const;
    Node<T> *successor(Node<T> *, const T &) const;
    Node<T> *predecessor(Node<T> *, const T &) const;
    int diameter(Node<T> *) const;
    void destroyTree(Node<T> *&);
};

// alias
template <typename T>
using AVL = AVLTree<T>;

#include "AVLTreeImpl.cpp"

#endif // H_AVLTree