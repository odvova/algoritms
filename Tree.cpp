#include "Tree.h"

#include <iostream>

using namespace std;

int n_left;

int n_right;

void Node::createTree(int data, Node*& pNode, int n) {

    if (n == 0) {

        pNode = NULL;

    }
    else {

        cout << " Type key " << endl;

        while (!(cin >> data))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Incorrect input " << endl;
            cout << "Input a digit ";
        }

        pNode = new Node;

        pNode->key = data;

        pNode->left = NULL;

        pNode->right = NULL;

        createTree(data, pNode->left, n / 2);

        createTree(data, pNode->right, n - n / 2 - 1);

    }

}

void Node::showTree(Node* pNode, int L) {

    if (pNode)

    {

        showTree(pNode->right, L + 5);

        for (int i = 0; i < L; i++) cout << " ";

        cout << pNode->key << endl;

        showTree(pNode->left, L + 5);

    }

}

void Node::prefixOrder(Node*& pNode) {

    if (pNode != NULL) {

        cout << " " << pNode->key << " ";

        prefixOrder(pNode->left);

        prefixOrder(pNode->right);

    }

}

void Node::postfixOrder(Node*& pNode) {

    if (pNode != NULL) {

        postfixOrder(pNode->left);

        postfixOrder(pNode->right);

        cout << " " << pNode->key << " ";

    }

}

void Node::infixOrder(Node*& pNode) {

    if (pNode != NULL) {

        infixOrder(pNode->left);

        cout << " " << pNode->key << " ";

        infixOrder(pNode->right);

    }

}

Node* Node::SearchNodeBST(int data, Node* pNode, int k) {

    if (pNode != NULL) {

        if (pNode->key == data) {

            if (k == 1) {

                SuccessorNodeBST(pNode, data);

                PredeccessorNodeBST(pNode, data);

            }

            return pNode;

        }
        else

            if (pNode->key > data) {

                SearchNodeBST(data, pNode->left, k);

            }
            else {

                SearchNodeBST(data, pNode->right, k);

            }

    }
    else {

        return NULL;

    }

}

void Node::createRoot(int data, Node*& pNode) {

    if (!pNode) {

        pNode = new Node;

        pNode->key = data;

        pNode->left = NULL;

        pNode->right = NULL;

        pNode->parent = NULL;

        return;

    }

}

int Node::insertNode(int data, Node*& pNode) {

    if (SearchNodeBST(data, pNode, 0) != NULL) {

        cout << "node already exist" << endl;

        return 0;

    }
    else if (!pNode) {

        pNode = new Node;

        pNode->key = data;

        pNode->left = NULL;

        pNode->right = NULL;

        pNode->parent = NULL;

        return 1;

    }

    if (pNode != NULL) {

        previous = pNode;

        if (pNode->key > data)

        {

            insertNode(data, pNode->left);

        }
        else

        {

            insertNode(data, pNode->right);

        }

    }

    return 1;

}

Node* Node::delNode(int data, Node*& pNode) {

    if (pNode == NULL)

        return pNode;

    if (data < pNode->key)

        pNode->left = delNode(data, pNode->left);

    else if (data > pNode->key)

        pNode->right = delNode(data, pNode->right);

    else if (pNode->left != NULL && pNode->right != NULL) {

        pNode->key = minimum(pNode->right)->key;

        pNode->right = delNode(pNode->key, pNode->right);

    }
    else {

        if (pNode->left != NULL)

            pNode = pNode->left;

        else if (pNode->right != NULL)

            pNode = pNode->right;

        else

            pNode = NULL;

    }

    return pNode;

}

Node* Node::SuccessorNodeBST(Node* pNode, int key) {

    Node* current = this;
    Node* successor = NULL;

    while (current != NULL) {

        if (current->key > key) {

            successor = current;

            current = current->left;

        }
        else {

            current = current->right;

        }

    }

    if (successor != NULL) {

        cout << "Successor: " << successor->key << endl;

        return successor;

    }
    else

        cout << " Successor is not exist! " << endl;

}

Node* Node::PredeccessorNodeBST(Node* pNode, int key) {

    Node* current = this;
    Node* successor = NULL;

    while (current != NULL) {

        if (current->key < key) {

            successor = current;

            current = current->right;

        }
        else {

            current = current->left;

        }

    }

    if (successor != NULL) {

        cout << "Predeccessor: " << successor->key << endl;

        return successor;

    }
    else

        cout << " Predeccessor is not exist! " << endl;

}

Node* Node::maximum(Node* pNode) {

    if (pNode->right == NULL)

        return pNode;

    maximum(pNode->right);

}

Node* Node::minimum(Node* pNode) {

    if (pNode->left == NULL)

        return pNode;

    minimum(pNode->left);

}