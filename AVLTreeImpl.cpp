#include "AVLTree.h"

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
}

template <typename T>
void AVLTree<T>::searchValue(const T &value) const
{
    if (!this->root)
    {
        std::cout << "Cannot search empty AVL Tree.\n";
        return;
    }
}

template <typename T>
void AVLTree<T>::getTreeHeight() const
{
}

template <typename T>
void AVLTree<T>::getNodeHeight(const T &value) const
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
        helpInsert(this->root->left, valueNode);
    else if (node->data < valueNode->data)
        helpInsert(node->right, valueNode);
    else
        std::cout << "Cannot insert duplicate value in AVL Tree.\n";
}

template <typename T>
void AVLTree<T>::helpRemove(Node<T> *&node, Node<T> *valueNode)
{
    if (!node)
        return;

    if (node->data == valueNode->data)
    {
        if (!node->left && !node->right) // if leaf node
        {
            delete (node);
            node = nullptr;
        }
        else if (node->left && !node->right) // if one child
        {
            Node<T> *nodeToDelete = node;
            node = nodle->left;
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
    else if (node->data > valueNode->data)
        helpRemove(this->root->left, valueNode);
    else
        helpRemove(this->root->right, valueNode);
}

template <typename T>
void AVLTree<T>::inorder(Node<T> *node) const
{
    if (!node)
        return;

    inorder(node->left);
    cout << node->data << "\n";
    inorder(node->right);
}

template <typename T>
void AVLTree<T>::preorder(Node<T> *node) const
{
    if (!node)
        return;

    cout << node->data << "\n";
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
    cout << node->data << "\n";
}

template <typename T>
void AVLTree<T>::search(Node<T> *node, const T &value)
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
void AVLTree<T>::destroyTree(Node<T> *&node)
{
    if (!node)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete (node);
    node = nullptr;
}