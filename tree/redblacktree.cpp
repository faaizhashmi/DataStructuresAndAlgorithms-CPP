#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	int val;
	Node*l;
	Node*r;
	Node*par;
	char clr;
};
template<typename T>
class BST
{
public:
	Node<T>*root;


	void colorspray(Node<T>*p){
		if (p->clr == 'b'){
			if (p->l != NULL){
				p->l->clr = 'b';
			}
			if (p->r != NULL){
				p->r->clr = 'b';
			}
			p->clr = 'r';
		}
		else if (p->clr == 'r'){
			if (p->l != NULL){
				p->l->clr = 'r';
			}
			if (p->r != NULL){
				p->r->clr = 'r';
			}
			p->clr = 'b';
		}
		if (p->par == NULL){
			p->clr = 'b';
			root = p;
		}
	}
	void childrotate3(Node<T>*n,Node<T>* p){
		Node<T>* gp = p->par;
		p->l = n->r;
		n->r = p;
		n->par = p->par;
		p->par = n;
		gp->r = n;
		if (p->l != NULL){
			p->l->par = p;
		}
	}
	void childrotate4(Node<T>*n, Node<T>* p){
		Node<T>* gp = p->par;
		p->r = n->l;
		n->l = p;
		n->par = p->par;
		p->par = n;
		gp->l = n;
		if (p->r != NULL){
			p->r->par = p;
		}
		
	}

	void rotateleft(Node<T>*n, Node<T>*p, Node<T>*gp, Node<T>*u, Node<T> *ggp){
		ggp = gp->par;
		gp->r = p->l;
		if (p->l != NULL){
			p->l->par = gp;
		}
		p->l = gp;
		p->par = ggp;
		gp->par = p;
		if (ggp != NULL){
			if (ggp->l == gp){
				ggp->l = p;
			}
			else{
				ggp->r = p;
			}
		}
	}
	void rotateright(Node<T>*&n, Node<T>*&p, Node<T>*&gp, Node<T>*&u, Node<T> *&ggp){
		ggp = gp->par;
		gp->l = p->r;
		if (p->r != NULL){
			p->r->par = gp;
		}
		p->r = gp;
		p->par = ggp;
		gp->par = p;
		if (ggp != NULL){
			if (ggp->l == gp){
				ggp->l = p;
			}
			else{
				ggp->r = p;
			}
		}
	}
	int checkstructure(Node<T>*&n,Node<T>*&npr,Node<T>*&gp,Node<T>*&u,Node<T>*&ggp){
		int type = 0;
		if (n->par == NULL){
			type = -1;
			return type;
		}
		if (n->par->par != NULL){
			npr = n->par;
			gp = npr->par;
			if (gp->par != NULL){
				ggp = gp->par;
			}
			if (gp->r == npr){
				u = gp->l;
				if (n->par->r == n){
					type = 1;
					return type;
				}
				else{
					type = 3;
					return type;
				}
			}
			if (gp->l == npr){
				u = gp->r;
				if (n->par->l == n){
					type=2;
					return type;
				}
				else{
					type=4;
					return type;
				}
			}
		}
		else{
			type = -1;
				return type;
		}
	}
	void check2red(Node<T>*&n){
		Node<T>*npr=new Node<T>();
		Node<T>*gp=new Node<T>();
		Node<T>*u=new Node<T>();
		Node<T>*ggp = new Node<T>();
		initalizenode(npr);
		initalizenode(gp);
		initalizenode(u);
		initalizenode(ggp);
		int type =checkstructure(n, npr, gp, u,ggp);
		if (type == -1){
			return;
		}
		if (type == 1){
				if (n->clr =='r'&& npr->clr=='r')
				{	
					
					if (u == NULL || u->clr == 'b' ){
						rotateleft(n, npr, gp, u,ggp);
						colorspray(npr);
					}
					else{
						colorspray(gp);
					}
				}
		}

		else if (type == 2){
			if (n->clr == 'r'&& npr->clr == 'r'){
				if (u == NULL || u->clr == 'b'){
					rotateright(n, npr, gp, u, ggp);
					colorspray(npr);
				}
				else{
					colorspray(gp);
				}
			
			}
		}

		else if (type == 3){
			childrotate3(n, npr);
			check2red(npr);
		}
		
		else if (type == 4){
			childrotate4(n, npr);
			check2red(npr);
		}
		
		if ((type==1||type==2)&&ggp != NULL){
			if (ggp->clr == 'r'&& ggp->l->clr == 'r'){
				check2red(ggp->l);
			}
			else if (ggp->clr == 'r'&& ggp->r->clr == 'r'){
				check2red(ggp->r);
			}
		}
	}

	void initalize()
	{
		root = NULL;
	}
	void initalizenode(Node<T>*n){
		n= new Node<T>();
		n->clr = NULL;
		n->val = NULL;
		n->l = NULL;
		n->r = NULL;
		n->par = NULL;
	}
	void insert(int data)
	{
		if (root == NULL)
		{
			root = new Node<T>();
			root->clr = 'b';
			root->val= data;
			root->l = NULL;
			root->r = NULL;
			root->par = NULL;
		}
		else
			_insert(root, data);
	}

	void _insert(Node<T>*&n, int data)
	{

		if (n->val== data)
		{
			cout << "already exist" << endl;
			return;
		}

		else if (n->val> data)
		{
			if (n->l!= NULL)
				_insert(n->l, data);
			else
			{
				n->l = new Node<T>();
				n->l->clr = 'r';
				n->l->val= data;
				n->l->l = NULL;
				n->l->r = NULL;
				n->l->par = n;
				check2red(n->l);
			}
		}
		else
		{
			if (n->r!= NULL)
				_insert(n->r, data);
			else
			{
				n->r= new Node<T>();
				n->r->val= data;
				n->r->clr = 'r';
				n->r->l= NULL;
				n->r->r= NULL;
				n->r->par = n;
				check2red(n->r);
			}
		}
		
	}

	void preOrder()
	{
		_preOrder(root);
	}

	void _preOrder(Node<T>*n)
	{
		if (n != NULL)
		{
			cout << n->val<< ' '<<n->clr<< endl;
			if (n->l!= NULL)
				_preOrder(n->l);
			if (n->r!= NULL)
				_preOrder(n->r);
		}

		else
			cout << "empty" << endl;
	}

	Node<T>* findData(Node<T>*n, int data)
	{
		Node<T>* left = NULL;
		Node<T>* right = NULL;
		if (n != NULL)
		{
			if (n->l!= NULL)
				left = findData(n->l, data);
			if (n->right != NULL)
				right = findData(n->r, data);

			if (n->val== data)
				return n;
			else
			{
				if (right != NULL)
					return right;
				else if (left != NULL)
					return left;
				else
					return NULL;
			}
		}

		return NULL;
	}

};



int main()
{
	BST<int> b;
	b.initalize();
	//condtion1
	/*b.insert(1);
	b.insert(2);
	b.insert(3);
	b.insert(4);*/

	/*condtion2*/
	/*b.insert(4);
	b.insert(3);
	b.insert(2);
	b.insert(1);*/

	/*condition3*/
	//b.insert(1);
	//b.insert(5);
	//b.insert(3);


	//condtion4

	/*b.insert(3);
	b.insert(5);
	b.insert(1);*/

	//condition 5
	//b.insert(1);
	//b.insert(2);
	//b.insert(3);
	//b.insert(4);
	//b.insert(5);
	//b.insert(6);
	//b.insert(7);
	//b.insert(8);

	//condition 5 reverse

	//b.insert(8);
	//b.insert(7);
	//b.insert(6);
	//b.insert(5);
	//b.insert(4);
	//b.insert(3);
	//b.insert(2);
	//b.insert(1);



	b.preOrder();
	system("pause");
}