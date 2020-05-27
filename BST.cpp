#include "BST.h"

BST::Node* BST::destruct(BST::Node* node){
	if (node != NULL){
		destruct( node -> Left );
		destruct( node -> Right );
		delete node;
	}
	return NULL;
}

BST::Node* BST::insert(BST::Node* node, int X){
	if (node == NULL){
		node = new BST::Node;
		node -> data = X;
		node -> Left = NULL;
		node -> Right = NULL;
	}
	else if (X > (node -> data) ) { node -> Right = insert(node -> Right, X); }
	else { node -> Left = insert(node -> Left, X); }
	return node;
}

BST::Node* BST::findMin(BST::Node* node){
	if (node == NULL){ return NULL; }
	while (node -> Left){ node = node -> Left; }
	return node;
}

BST::Node* BST::_delete(BST::Node* node, int X){
	if (node == NULL){ return NULL; }
	else if ( X > (node -> data) ){ node -> Right = _delete( node -> Right, X ); }
	else if ( X < (node -> data) ){ node -> Left = _delete( node -> Left, X); }
	else{
		if ((node -> Left) == NULL) {
			BST::Node *ret = node->Right;
			delete node;
			return ret;
		}
		if ((node -> Right) == NULL) {
			BST::Node *ret = node->Left;
			delete node;
			return ret;
		}
		int temp = findMin( node->Right ) -> data;
		node -> data =  temp;
		node -> Right = _delete( node -> Right, temp );
	}
	return node;
}


bool BST::isContains(BST::Node* node, int X){
	if (node == NULL){ return false; }
	else if (X == (node -> data) ) { return true; }
	else if (X > (node -> data) ) { return isContains(node -> Right, X); }
	else { return isContains(node -> Left, X); }
}


void BST::preorder(typename BST::Node* node){
	if (node == NULL){ return; }
	cout << node -> data << ' ';
	preorder( node -> Left );
	preorder( node -> Right );
}


BST::BST() {
	Root = NULL;
}


BST::~BST() {
	Root = destruct(Root);
}


void BST::insert(int X) {
	Root = insert(Root, X);
}


void BST::_delete(int X) {
	Root = _delete(Root, X);
}


void BST::clear() {
	Root = destruct(Root); Root = NULL;
}


bool BST::isContains(int X) {
	return isContains(Root, X);
}


bool BST::isEmpty() {
	return Root==NULL;
}


void BST::print() {
	cout << "Дерево: " << ' '; preorder(Root); cout << endl;
}
