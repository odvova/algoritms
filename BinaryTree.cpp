#include "Tree.h"

#include <iostream>

using namespace std;

int main()

{

    int n, num,
        var, k;

    Node* pNode = NULL;

    Node* pNode2 = NULL;

    int numbs[100];

    cout << "Input N: " << endl;
   // cin >> n;
    while (!(cin >> n))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Incorrect input " << endl;
        cout << "Input a digit ";
    }
       
    cout << "Choose part: input 1 (preorders) or 2 (insertion/extraction)" << endl;

    while (!(cin >> var))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Incorrect input " << endl;
        cout << "Input a digit ";
    }

    switch (var) {

    case 1: {

        numbs[0] = 0;

        pNode->createTree(numbs[10], pNode, n);

        pNode->showTree(pNode, 5);

        cout << "infixOrder:" << endl; // left to right

        pNode->infixOrder(pNode);

        cout << "\nPostifxOrder:" << endl; // downside to upside left to right

        pNode->postfixOrder(pNode);

        cout << "\nPrefixOrder:" << endl; // upside to downside

        pNode->prefixOrder(pNode);

    }
          break;

    case 2: {

        for (int i = 0; i < n; i++) {

            cout << " num" << i << ":" << endl;

            while (!(cin >> numbs[i]))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Incorrect input " << endl;
                cout << "Input a digit ";
            }

            if (i != 0)

                pNode->insertNode(numbs[i], pNode);

            else

                pNode->createRoot(numbs[i], pNode);

        }

    mark1:

        pNode->showTree(pNode, 5);

        cout << "1. Delete\n" << "2. Insert\n" << "3. Successor & Prodecessor of node" << endl;

        while (!(cin >> var))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Incorrect input " << endl;
            cout << "Input a digit ";
        }

        switch (var) {

        case 1: {

            cout << "Type key" << endl;

            while (!(cin >> num))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Incorrect input " << endl;
                cout << "Input a digit ";
            }

            pNode->delNode(num, pNode);

        }
              break;

        case 2: {

            cout << "Type key" << endl;

            while (!(cin >> num))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Incorrect input " << endl;
                cout << "Input a digit ";
            }

            pNode->insertNode(num, pNode);

        }
              break;

        case 3: {

            cout << "Type key" << endl;

            while (!(cin >> num))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Incorrect input " << endl;
                cout << "Input a digit ";
            }

            pNode->SearchNodeBST(num, pNode, 1);

        }

        }

        goto mark1;

    }
          break;

    }

}
