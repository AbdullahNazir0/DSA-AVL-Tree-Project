#include "AVLTree.h"
#include <iostream>

template <typename T>
AVLTree<T>::AVLTree()
{
    this->root = nullptr;
}

template <typename T>
void AVLTree<T>::insert(const T &value)
{
    Node<T> *valueNode = new Node<T>(value);

    if (!this->root)
    {
        this->root = valueNode;
        return;
    }

    helpInsert(this->root, valueNode);
}

template <typename T>
void AVLTree<T>::remove(const T &value)
{
    if (!this->root)
    {
        std::cout << "Cannot remove, AVL Tree is empty.\n";
        return;
    }

    helpRemove(this->root, value);
}

template <typename T>
void AVLTree<T>::displayInOrder() const
{
    if (!this->root)
    {
        std::cout << "AVL Tree is empty.\n";
        return;
    }

    inorder(this->root);
    std::cout << "\n";
}

template <typename T>
void AVLTree<T>::displayPreOrder() const
{
    if (!this->root)
    {
        std::cout << "AVL Tree is empty.\n";
        return;
    }

    preorder(this->root);
    std::cout << "\n";
}

template <typename T>
void AVLTree<T>::displayPostOrder() const
{
    if (!this->root)
    {
        std::cout << "AVL Tree is empty.\n";
        return;
    }

    postorder(this->root);
    std::cout << "\n";
}

template <typename T>
void AVLTree<T>::searchValue(const T &value) const
{
    if (!this->root)
    {
        std::cout << "Cannot search empty AVL Tree.\n";
        return;
    }

    search(this->root, value);
}

template <typename T>
int AVLTree<T>::getTreeHeight() const
{
    return (nodeHeight(this->root));
}

template <typename T>
int AVLTree<T>::getNodeHeight(const T &value) const
{
    if (!this->root)
        return (-1);

    Node<T> *node = searchNode(this->root, value);

    if (!node)
        return (-1);
    else
        return (nodeHeight(node));
}

template <typename T>
void AVLTree<T>::getMin() const
{
    if (!this->root)
    {
        std::cout << "No minimum, AVL Tree is empty.\n";
        return;
    }

    min(this->root);
}

template <typename T>
void AVLTree<T>::getMax() const
{
    if (!this->root)
    {
        std::cout << "No maximum, AVL Tree is empty.\n";
        return;
    }

    max(this->root);
}

template <typename T>
void AVLTree<T>::getSuccessor(const T &value) const
{
    Node<T> *successor = findSuccessor(this->root, value);
    if (successor)
        std::cout << "Successor of " << value << " is " << successor->data << ".\n";
    else
        std::cout << "No successor for " << value << " in AVL Tree.\n";
}

template <typename T>
void AVLTree<T>::getPredecessor(const T &value) const
{
    Node<T> *predecessor = findPredecessor(this->root, value);
    if (successor)
        std::cout << "Predecessor of " << value << " is " << predecessor->data << ".\n";
    else
        std::cout << "No predecessor for " << value << " in AVL Tree.\n";
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    if (!this->root)
        return;

    destroyTree(this->root);
}

// private functions definition
template <typename T>
void AVLTree<T>::helpInsert(Node<T> *&node, Node<T> *valueNode)
{
    if (!node)
    {
        node = valueNode;
        return;
    }

    if (node->data > valueNode->data)
        helpInsert(node->left, valueNode);
    else if (node->data < valueNode->data)
        helpInsert(node->right, valueNode);
    else
    {
        std::cout << "Cannot insert duplicate value in AVL Tree.\n";
        return;
    }

    int balanceFactor = findBalanceFactor(node);

    // left left case
    if (balanceFactor > 1 && valueNode->data < node->left->data)
        rightRotate(node);

    // right right case
    if (balanceFactor < -1 && valueNode->data > node->right->data)
        leftRotate(node);

    // left right case
    if (balanceFactor > 1 && valueNode->data > node->left->data)
        leftRightRotate(node);

    // right left case
    if (balanceFactor < -1 && valueNode->data < node->right->data)
        rightLeftRotate(node);
}

template <typename T>
void AVLTree<T>::helpRemove(Node<T> *&node, const T &value)
{
    if (!node)
        return;

    if (node->data > value)
        helpRemove(node->left, value);
    else if (node->data < value)
        helpRemove(node->right, value);
    else
    {
        if (!node->left && !node->right) // if leaf node
        {
            if (node == this->root)
                this->root = nullptr;
            delete (node);
            node = nullptr;
        }
        else if (node->left && !node->right) // if one child
        {
            if (node == this->root)
                this->root = node->left;
            Node<T> *nodeToDelete = node;
            node = node->left;
            delete (nodeToDelete);
        }
        else if (!node->left && node->right) // if one child
        {
            if (node == this->root)
                this->root = node->right;
            Node<T> *nodeToDelete = node;
            node = node->right;
            delete (nodeToDelete);
        }
        else // if two child
        {
            Node<T> *successor = node->right;
            while (successor->left)
                successor = successor->left;

            node->data = successor->data;
            helpRemove(node->right, successor->data);
        }
    }

    if (!node) // if tree had only one node.
        return;

    int balanceFactor = findBalanceFactor(node);

    // left left case
    if (balanceFactor > 1 && findBalanceFactor(node->left) >= 0)
        rightRotate(node);

    // right right case
    if (balanceFactor < -1 && findBalanceFactor(node->left) < 0)
        leftRotate(node);

    // left right case
    if (balanceFactor > 1 && findBalanceFactor(node->right) <= 0)
        leftRightRotate(node);

    // right left case
    if (balanceFactor < -1 && findBalanceFactor(node->right) > 0)
        rightLeftRotate(node);
}

template <typename T>
void AVLTree<T>::inorder(Node<T> *node) const
{
    if (!node)
        return;

    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

template <typename T>
void AVLTree<T>::preorder(Node<T> *node) const
{
    if (!node)
        return;

    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

template <typename T>
void AVLTree<T>::postorder(Node<T> *node) const
{
    if (!node)
        return;

    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

template <typename T>
Node<T> *AVLTree<T>::searchNode(Node<T> *node, const T &value) const
{
    if (!node)
        return (nullptr);

    if (node->data == value)
        return (node);
    else if (node->data > value)
        searchNode(node->left, value);
    else
        searchNode(node->right, value);
}

template <typename T>
int AVLTree<T>::nodeHeight(Node<T> *node) const
{
    if (!node)
        // if you want to calculate height acc to number of nodes instead of edges, return (0);
        return (-1);

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    if (leftHeight >= rightHeight)
        return (leftHeight + 1);
    else
        return (rightHeight + 1);
}

template <typename T>
void AVLTree<T>::search(Node<T> *node, const T &value) const
{
    if (!node)
        return;

    if (node->data == value)
        std::cout << value << " found in AVL Tree.\n";
    else if (node->data > value)
        search(node->left, value);
    else
        search(node->right, value);
}

template <typename T>
int AVLTree<T>::findBalanceFactor(Node<T> *node) const
{
    if (!node)
        return (0);

    return (nodeHeight(node->left) - nodeHeight(node->right));
}

template <typename T>
void AVLTree<T>::leftRotate(Node<T> *&node)
{
    if (!node)
        return;

    Node<T> *pivot = node->right;
    Node<T> *subTree = pivot->left;

    pivot->left = node;
    node->right = subTree;

    if (node == this->root)
        this->root = pivot;

    node = pivot;
}

template <typename T>
void AVLTree<T>::rightRotate(Node<T> *&node)
{
    if (!node)
        return;

    Node<T> *pivot = node->left;
    Node<T> *subTree = pivot->right;

    pivot->right = node;
    node->left = subTree;

    if (node == this->root)
        this->root = pivot;

    node = pivot;
}

template <typename T>
void AVLTree<T>::leftRightRotate(Node<T> *&node)
{
    if (!node)
        return;

    leftRotate(node->left);
    rightRotate(node);
}

template <typename T>
void AVLTree<T>::rightLeftRotate(Node<T> *&node)
{
    if (!node)
        return;

    rightRotate(node->right);
    leftRotate(node);
}

template <typename T>
void AVLTree<T>::min(Node<T> *node) const
{
    if (!node->left)
    {
        std::cout << "The minimum is " << node->data << "\n";
        return;
    }

    return (min(node->left));
}

template <typename T>
void AVLTree<T>::max(Node<T> *node) const
{
    if (!node->right)
    {
        std::cout << "The maximum is " << node->data << "\n";
        return;
    }

    return (max(node->right));
}

template <typename T>
Node<T> *AVLTree<T>::successor(Node<T> *node, const T &value) const
{
    if (!node)
        return (nullptr);

    if (node->data <= value)
        return (successor(node->right, value));
    else
    {
        Node<T> *leftSuccessor = successor(node->left, value);
        return (leftSuccessor ? leftSuccessor : node);
    }
}

template <typename T>
Node<T> *AVLTree<T>::predecessor(Node<T> *node, const T &value) const
{
    if (!node)
        return (nullptr);

    if (node->data >= value)
        return (predecessor(node->left, value));
    else
    {
        Node<T> *rightPredecessor = predecessor(node->right, value);
        return (rightPredecessor ? rightPredecessor : node);
    }
}

template <typename T>
void AVLTree<T>::destroyTree(Node<T> *&node)
{
    if (!node)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete (node);
    node = nullptr;
}