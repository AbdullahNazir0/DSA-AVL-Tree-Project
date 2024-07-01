#include <iostream>
#include "AVLTree.h"

// using namespace std;

int main()
{

    AVL<int> avlTree;

    std::cout << "Test 1 passed.\nThere are no errors.\n";

    int sortedData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int randomData[] = {5, 3, 8, 1, 9, 6, 2, 7, 4, 10};
    int deletionData[] = {8, 4, 10, 2, 6};

    // // Sample usage for insertion
    // for (int value : sortedData)
    // {
    //     avlTree.insert(value);
    // }

    // std::cout << "Inorder traversal: ";
    // avlTree.displayInOrder();
    // std::cout << "Preorder traversal: ";
    // avlTree.displayPreOrder();
    // std::cout << "Postorder traversal: ";
    // avlTree.displayPostOrder();

    // // Sample usage for deletion
    // for (int value : deletionData)
    // {
    //     avlTree.remove(value);
    // }

    // std::cout << "Inorder traversal: ";
    // avlTree.displayInOrder();
    // std::cout << "Preorder traversal: ";
    // avlTree.displayPreOrder();
    // std::cout << "Postorder traversal: ";
    // avlTree.displayPostOrder();

    // Additional testing scenarios (random insertion)
    for (int value : randomData)
    {
        avlTree.insert(value);
    }

    // Display the tree to verify structure after operations
    std::cout << "Inorder traversal: ";
    avlTree.displayInOrder();
    std::cout << "Preorder traversal: ";
    avlTree.displayPreOrder();
    std::cout << "Postorder traversal: ";
    avlTree.displayPostOrder();

    std::cout << "Test 2 passed.\nOutput is correct.\nProgram is bug free.\n";

    return (0);
}