#include<iostream>
using namespace std;
template<typename T>
struct node{
	int value;
	node *l;
	node *r;
};
template<typename T>

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

	void updateNode(int data, int newData){
		node *n = root;
		bool left = false;
		bool right = false;
		if (n != NULL){
			if (n->l != NULL){
				left = updateNode(n->l, child);
			}
			if (n->r = NULL){
				right = updateNode(n->r, child);
			}
			if (n->value == data){
				n->value=newData;
			}
			
				else{
					return NULL;
				}
			
		}
		else{
			cout << "Empty Input" << endl;
		}
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
	}void inorder(node *n){
		
		if (n->l != NULL){
			preorder(n->l);
		}if (n != NULL){
			cout << n->value << endl;
			return;
		}
		if (n->r != NULL){
			preorder(n->r);
		}
	}
	void postorder(node *n){
	
		if (n->l != NULL){
			preorder(n->l);
		}
		if (n->r != NULL){
			preorder(n->r);
		}
		if (n != NULL){
			cout << n->value << endl;
			return;
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
	node<T>* finddata(node *n, int child){
		bool left=false;
		bool right=false;
		if (n != NULL){
			if (n->l != NULL){
				left=finddata(n->l, child);
			}
			if (n->r = NULL){
				right=finddata(n->r, child);
			}
			if (n->value == child){
				return n;
			}
			else{
				if (n->l->value == child){
					return n->l;
				}
				if (n->r->value == child){
					return n->r;
				}
				else{
					return NULL;
				}
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
	bool findmax(int max){
		node *n = root;
		bool left = false;
		bool right = false;
		if (n != NULL){
			if (n->l != NULL){
				i++;
				left = find(max);
			}
			if (n->r = NULL){
				i++;
				right = find(max);
			}
			if (n->value == child){
				return true;
			}
			else if (right || left){
				return true;
			}
			else{
				if (max < i){
					max = i;
				}
				i--;
				return max;
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

	void insertright(int data, int child){
		if (isUnique(root, child)){
			cout << "Child Exists" << endl;
			return;
		}
		else{
			node *par = finddata(root, child);
			if (par == NULL){
				cout << "Data doesnt exists" << endl;
			}
			else if (par->r != NULL){
				cout << "right exists" << endl;
				return;
				par->r = new node();
				par->r->r = NULL;
				par->r->l = NULL;
				par->r->value = child;
			}
		}

	}
};
int main(){
	system("pause");
}
