#include<iostream>
using namespace std;
struct node{
	int value;
	node *l;
	node *r;
};
class tree{
	node *root;
	void initialize(){
		root = NULL;
	}
	void insertroot(int r){
		if (root != NULL){
			cout << "Root exists" << endl;
			return;
		}
		root = new node();
		root->value = r;
		root->l = NULL;
		root->r = NULL;
	}
	void preorder(node *n){
		if (n != NULL){
			cout << n->value << endl;
			return;
		}
		if (n->l != NULL){
			preorder(n->l);
		}
		if (n->r != NULL){
			preorder(n->r);
		}
	}
	void deleteallnodes(node *n){
		_delete (n->l);
		_delete(n->r);
		n->l = NULL;
		n->r = NULL;
	}
	void _delete(node *n){
		if (n == NULL){
			return;
		}
		_delete(n->l);
		_delete(n->r);
		n->l = NULL;
		n->r = NULL;
		delete n;
	}
	node *finddata(node *n, int child){
		node *left;
		node *right;
		if (n != NULL){
			if (n->l != NULL){
				finddata(n->l, child);
			}
			if (n->r = NULL){
				finddata(n->r, child);
			}
			if (n->value==child){
				return n;
			}
			
			else{
				return;
			}
		}
		else{
			cout << "Empty Input" << endl;
		}
	}
	bool isUnique(node *n, int child){
		bool left = false;
		bool right = false;
		if (n != NULL){
			if (n->l != NULL){
				left = isUnique(n->l,child);
			}
			if (n->r = NULL){
				right = isUnique(n->r, child);
			}
			if (n->value == child){
				return true;
			}
			else if (right || left){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			cout << "Empty Input" << endl;
		}
	}
	void insertleft(int data, int child){
		if (isUnique(root,child)){
			cout << "Child Exists" << endl;
			return;
		}
		else{
			node *par = finddata(root, child);
			if (par == NULL){
				cout << "Data doesnt exists" << endl;
			}
			if (par->l != NULL){
				cout << "left exists" << endl;
				return;
				par->l = new node();
				par->l->r = NULL;
				par->l->l = NULL;
				par->l->value = child;
			}
		}

	}
};
