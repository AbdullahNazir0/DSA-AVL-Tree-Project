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
}

template <typename T>
void AVLTree<T>::getPredecessor(const T &value) const
{
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
        std::cout << "Cannot insert duplicate value in AVL Tree.\n";
}

template <typename T>
void AVLTree<T>::helpRemove(Node<T> *&node, const T &value)
{
    if (!node)
        return;

    if (node->data == value)
    {
        if (!node->left && !node->right) // if leaf node
        {
            delete (node);
            node = nullptr;
        }
        else if (node->left && !node->right) // if one child
        {
            Node<T> *nodeToDelete = node;
            node = node->left;
            delete (nodeToDelete);
        }
        else if (!node->left && node->right) // if one child
        {
            Node<T> *nodeToDelete = node;
            node = node->right;
            delete (nodeToDelete);
        }
        else // if two child
        {
            Node<T> *ancestor = node->left;
            Node<T> *current = node->right;
            while (current)
            {
                ancestor = current;
                current = current->left;
            }
        }
    }
    else if (node->data > value)
        helpRemove(this->root->left, value);
    else
        helpRemove(this->root->right, value);
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
void AVLTree<T>::successor(Node<T> *node, const T &value) const {}

template <typename T>
void AVLTree<T>::predecessor(Node<T> *node, const T &value) const {}

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