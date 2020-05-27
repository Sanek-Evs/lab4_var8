#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class BST {

	struct Node {
		int data;
		struct Node* Right;
		struct Node* Left;
	};

private:

	struct Node* Root;
	Node* destruct(Node*);

	Node* insert(Node*, int);
	Node* findMin(Node*);
	Node* _delete(Node*, int);
	bool isContains(Node*, int);
	void preorder(Node*);

public:

	BST();
	~BST();

	void insert(int);
	void _delete(int);
	void clear();
	bool isContains(int);
	bool isEmpty();
	void print();
};


#endif //BST_H
