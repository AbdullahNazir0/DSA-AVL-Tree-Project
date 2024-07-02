#include <iostream>
#include "AVLTree.h"

using namespace std;

void mainPanel();

int main()
{

    mainPanel();

    return (0);
}

void mainPanel()
{
    AVL<int> avlTree;
    int choice, value, valueTwo;
    char temp;

    while (!0)
    {
        system("cls");
        cout << "-------- Welcome to AVL Tree Implementation Menu --------\n";
        cout << "Enter 1 to insert a value.\n"
                "Enter 2 to delete a value.\n"
                "Enter 3 to search a value.\n"
                "Enter 4 to display inorder traversal.\n"
                "Enter 5 to display preorder traversal.\n"
                "Enter 6 to display postorder traversal.\n"
                "Enter 7 to find height of the tree.\n"
                "Enter 8 to find the maximum value in tree.\n"
                "Enter 9 to find the minimum value in tree.\n"
                "Enter 10 to find the diameter between two nodes.\n"
                "Enter 11 to find the predecessor of a node.\n"
                "Enter 12 to find the successor of a node.\n"
                "Enter 0 to terminate the program.\n"
                "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "-------- Welcome to Inserstion --------\n";
            cout << "Enter the value you want to insert: ";
            cin >> value;
            avlTree.insert(value);
            cout << "Insertion OP. Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 2:
        {
            system("cls");
            cout << "-------- Welcome to Deletion --------\n";
            cout << "Enter the value you want to delete: ";
            cin >> value;
            avlTree.remove(value);
            cout << "Deletion OP. Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 3:
        {
            system("cls");
            cout << "-------- Welcome to Search --------\n";
            cout << "Enter the value you want to search: ";
            cin >> value;
            avlTree.searchValue(value);
            cout << "Searching OP. Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 4:
        {
            system("cls");
            cout << "-------- Welcome to Inorder Traversal --------\n";
            cout << "The inorder traversal of tree is ";
            avlTree.displayInOrder();
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 5:
        {
            system("cls");
            cout << "-------- Welcome to Preorder Traversal --------\n";
            cout << "The preorder traversal of tree is ";
            avlTree.displayPreOrder();
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 6:
        {
            system("cls");
            cout << "-------- Welcome to Postorder Traversal --------\n";
            cout << "The postorder traversal of tree is ";
            avlTree.displayPostOrder();
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 7:
        {
            system("cls");
            cout << "-------- Welcome to Height Menu --------\n";
            cout << "The height of tree is ";
            avlTree.getTreeHeight();
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 8:
        {
            system("cls");
            cout << "-------- Welcome to Maximum Menu --------\n";
            cout << "The max of tree is ";
            avlTree.getMax();
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 9:
        {
            system("cls");
            cout << "-------- Welcome to Minimum Menu --------\n";
            cout << "The min of tree is ";
            avlTree.getMin();
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 10:
        {
            system("cls");
            cout << "-------- Welcome to Diameter Menu --------\n";
            int diameter = avlTree.getDiameter();
            if (diameter == -1)
                cout << "Error finding diameter, Tree is empty.\n";
            else
                cout << "The diameter is " << diameter << "\n";
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 11:
        {
            system("cls");
            cout << "-------- Welcome to Predecessor Menu --------\n";
            cout << "Enter the node value to find its predecessor: ";
            cin >> value;
            avlTree.getPredecessor(value);
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 12:
        {
            system("cls");
            cout << "-------- Welcome to Successor Menu --------\n";
            cout << "Enter the node value to find its successor: ";
            cin >> value;
            avlTree.getSuccessor(value);
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
        case 0:
            cout << "Terminating the program...\n";
            return;
        default:
            cout << "Invalid input, please choose between (0-12)\n";
            cout << "Press any key to continue...";
            temp = cin.get();
            cin.ignore(100000, '\n');
            break;
        }
    }
}