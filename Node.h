#ifndef H_Node
#define H_Node

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(const T &value) : data(value), left(nullptr), right(nullptr) {}
};

#endif // H_Node