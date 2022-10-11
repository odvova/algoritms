#pragma once
#include <cstddef>

struct Node {

	int key;

	Node* parent;

	Node* left;

	Node* right;

	Node* previous;

	void createTree(int data, Node*& pNode, int n);

	void showTree(Node* pNode, int L);

	void prefixOrder(Node*& pNode);

	void postfixOrder(Node*& pNode);

	void infixOrder(Node*& pNode);

	Node* SearchNodeBST(int data, Node* pNode, int k);

	void createRoot(int data, Node*& pNode);

	int insertNode(int data, Node*& pNode);

	Node* delNode(int data, Node*& pNode);

	Node* SuccessorNodeBST(Node* pNode, int key);

	Node* PredeccessorNodeBST(Node* pNode, int key);

	Node* maximum(Node* pNode);

	Node* minimum(Node* pNode);

};