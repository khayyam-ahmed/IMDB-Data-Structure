#pragma once
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

template <class Key, class Data>
class Node {
public:
	Key key;
	HashTable<string, Data>* data;
	Node<Key, Data>* left; //LC
	Node<Key, Data>* right; //RC
	int height;

	Node() {
		data = new HashTable<string, Data>;
		left = NULL;
		right = NULL;
		height = 1;
	}
	Node(Key key) {
		this->key = key;
		data = new HashTable<string, Data>;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

template <class Key, class Data>
class AVL_Tree {
public:
	Node<Key, Data>* root;
	AVL_Tree() {
		this->root = NULL;
	}

	Key max(Key a, Key b) {
		return a > b ? a : b;
	}

	int getHeight(Node<Key, Data>* node)
	{
		return node == NULL ? 0 : node->height;
	}

	int getBalanceFactor(Node<Key, Data>* node)
	{
		return node == NULL ? 0 : getHeight(node->left) - getHeight(node->right);
	}

	Node<Key, Data>* Right_Rotate(Node<Key, Data>* node)
	{
		Node<Key, Data>* leftChild = node->left;
		Node<Key, Data>* LeftsRightChild = leftChild->right;
		leftChild->right = node;
		node->left = LeftsRightChild;
		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
		leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;
		return leftChild;
	}

	Node<Key, Data>* leftRotate(Node<Key, Data>* node)
	{
		Node<Key, Data>* rightChild = node->right;
		Node<Key, Data>* RightsLeftChild = rightChild->left;

		// Perform rotation
		rightChild->left = node;
		node->right = RightsLeftChild;
		// Update heights
		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
		rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;
		// Return new root
		return rightChild;
	}

	Node<Key, Data>* add(Key key)
	{
		Node<Key, Data>* temp = found(key);
		if (temp == NULL) {
			root = add(root, key);
		}
		return found(root, key);
	}

	Node<Key, Data>* add(Node<Key, Data>* start, Key key) {
		if (start == NULL) {
			cout << "\t\t[WHEN start == NULL]";
			start = new Node<Key, Data>(key);
			return start;
		}
		if (key < start->key) {
			cout << "\t\t[" << key << " < " << start->key << "]" << " add(start->left, key)";
			start->left = add(start->left, key);
		}
		else if (key > start->key) {
			cout << "\t\t[" << key << " > " << start->key << "]" << " add(start->right, key)";
			start->right = add(start->right, key);
		}
		else {
			cout << "\t\t[" << key << " = " << start->key << "]" << " return start;";
			return start;
		}
		//Setting Height of Start
		start->height = max(getHeight(start->left), getHeight(start->right)) + 1;
		//Getting Balance Factor of START
		int balance = getBalanceFactor(start);
		// Case 1: Left Left Rotation
		if (getBalanceFactor(start) > 1 && key < start->left->key) {
			cout << endl << "\t\t[Right_Rotate]";
			start = Right_Rotate(start);
		}
		// Case 2: Right Right Rotation
		else if (getBalanceFactor(start) < -1 && key > start->right->key) {
			cout << "\n\t\t[Left_Rotate]";
			start = leftRotate(start);
		}
		// Case 3: Right Left Rotations
		else if (getBalanceFactor(start) > 1 && key > start->left->key) {
			cout << endl << "\t\t[LeftRight_Rotate]" << key;
			start->left = leftRotate(start);
			return Right_Rotate(start);
		}
		// Case 4: Left Right Rotation
		else if (getBalanceFactor(start) < -1 && key < start->right->key) {
			cout << endl << "\t\t[RightLeft_Rotate]" << key;
			start->right = Right_Rotate(start->right);
			return leftRotate(start);
		}
		return start;
	}

	Node<Key, Data>* found(Key key) {
		return found(root, key);
	}

	Node<Key, Data>* found(Node<Key, Data>* tptr, Key key) {
		if (tptr == NULL)
			return NULL;
		else if (key < tptr->key)
			return found(tptr->left, key);
		else if (key > tptr->key)
			return found(tptr->right, key);
		else if (tptr->key == key)
			return tptr;
		else
			return NULL;
	}

};