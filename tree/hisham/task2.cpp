#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	int value;
	Node*left;
	Node*right;
};


template<typename T>
class BST
{
	Node<T>*root;

public:

	void initalize()
	{
		root = NULL;
	}

	void insert(int data)
	{
		if (root == NULL)
		{
			root = new Node<T>();
			root->value = data;
			root->left = NULL;
			root->right = NULL;
		}
		else
			in_sert(root, data);
	}

	void in_sert(Node<T>*&n, int data)
	{

		if (n->value == data)
		{
			cout << "already exist" << endl;
			return;
		}

		else if (n->value > data)
		{
			if (n->left != NULL)
				in_sert(n->left, data);
			else
			{
				n->left = new Node<T>();
				n->left->value = data;
				n->left->left = NULL;
				n->left->right = NULL;
			}
		}

		else
		{
			if (n->right != NULL)
				in_sert(n->right, data);
			else
			{
				n->right = new Node<T>();
				n->right->value = data;
				n->right->left = NULL;
				n->right->right = NULL;
			}
		}

	}

	void preOrder()
	{
		pre_Order(root);
	}

	void pre_Order(Node<T>*n)
	{
		if (n != NULL)
		{
			cout << n->value << endl;
			if (n->left != NULL)
				pre_Order(n->left);
			if (n->right != NULL)
				pre_Order(n->right);
		}

		else
			cout << "empty" << endl;
	}

	Node<T>* searchForDelete(Node<T>*n,int data)
	{

		if (n->value > data)
		{
			if (n->left != NULL)
			{
				if (n->left->value == data)
				{
					return n;
				}
				return searchForDelete(n->left, data);
			}
			else
				return NULL;
		}

		else
		{

			if (n->right != NULL)
			{
				if (n->right->value == data)
				{
					return n;
				}
				return searchForDelete(n->right, data);
			}
			else
				return NULL;

		}

	}

	Node<T>* findMinNode(Node<T>*n,Node<T>*&p)
	{
		Node<T>*m=NULL;
		while (n != NULL)
		{
			m = n;
			n = n->left;
			if (n != NULL)
				p = n;
		}
		return m;
		
	}

	void deleteNodeleft(Node<T>*n)
	{
		if (n->left->left == NULL && n->left->right == NULL)
		{
			delete n->left;
			n->left = NULL;
		}


		else if (n->left->left != NULL && n->left->right != NULL)
		{
			Node<T>*p=n->left;
			Node<T>*m = findMinNode(n->left->right,p);
			swap(m->value, n->left->value);
			delete[]m;
			p->left = NULL;

		}

		else if (n->left->left != NULL)
		{

			Node<T>*m= n->left;
			n->left = m->left;
			delete m;
		}

		else
		{
			Node<T>*m = n->left;
			n->left = m->right;
			delete m;
		}

	}

	void deleteNoderight(Node<T>*n)
	{
		if (n->right->left == NULL && n->right->right == NULL)
		{
			delete n->right;
			n->right = NULL;
		}


		else if (n->right->left != NULL && n->right->right != NULL)
		{
			Node<T>*p = n->right;
			Node<T>*m = findMinNode(n->right->right, p);
			swap(m->value, n->right->value);
			delete[]m;
			p->left = NULL;

		}

		else if (n->right->left != NULL)
		{

			Node<T>*m = n->right;
			n->right = m->left;
			delete m;
		}

		else
		{
			Node<T>*m = n->right;
			n->right = m->right;
			delete m;
		}

	}

	void deleteNode(int data)
	{
		Node<T>*parent = searchForDelete(root, data);

		if (parent == NULL)
		{
			cout << "not Found" << endl;
			return;
		}

		if (parent->left->value == data)
		{
			deleteNodeleft(parent);
		}

		else
		{
			deleteNoderight(parent);
		}


	}

	bool search(Node<T>*n, int data)
	{
		if (n->value == data)
			return true;
		else if (n->value>data)
		{
			if (n->left != NULL)
				return search(n->left, data);
			else
				return false;
		}
		else
		{
			if (n->right != NULL)
				return search(n->right, data);
			else
				return false;
		}

	}

	void update(int data, int data1)
	{
		if (search(root, data) == true)
		{
			deleteNode(data);
			insert(data1);
			
		}
		else
			cout << "Not found" << endl;
	}

	Node<T>* findData(Node<T>*n, int data)
	{
		Node<T>* left = NULL;
		Node<T>* right = NULL;


		if (n != NULL)
		{

			if (n->left != NULL)
				left = findData(n->left, data);

			if (n->right != NULL)
				right = findData(n->right, data);

			if (n->value == data)
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

	void deleteAllNode(int data)
	{
		Node<T>*n = findData(root, data);

		if (n == NULL)
		{
			cout << "Data not found" << endl;
			return;
		}

		del(n->left);
		del(n->right);

		n->left = NULL;
		n->right = NULL;
	}

	void del(Node<T>*n)
	{
		if (n == NULL)
			return;
		del(n->left);
		del(n->right);
		delete n;
	}

	bool del2(Node<T>*n, int data)
	{
		bool left = false;
		bool right = false;

		if (n != NULL)
		{
			if (n->left != NULL)
			{
				if (n->left->value == data)
				{
					if (n->left->left == NULL && n->left->right == NULL)
					{
						delete n->left;
						n->left = NULL;
						return true;
					}
					return false;
				}
				left = del2(n->left, data);
			}
			if (n->right != NULL)
			{
				if (n->right->value == data)
				{
					if (n->right->left == NULL && n->right->right == NULL)
					{
						delete n->right;
						n->right = NULL;
						return true;
					}
					return false;
				}
				right = del2(n->left, data);
			}
		}

		if (right == true || left == true)
			return true;
		else
			return false;


	}

	void deleteifnochild(int data)
	{
		if (root->value == data)
		{
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
				cout << "deleted" << endl;
				return;
			}
			cout << "not fount or have child" << endl;
		}

		if (del2(root, data) == true)
			cout << "deleted" << endl;
		else
			cout << "Not found or have child" << endl;
	}

};



int main()
{
	BST<int>b;
	b.initalize();

	b.insert(50);
	b.insert(20);
	b.insert(1);
	b.insert(2);
	b.insert(7);
	b.insert(100);
	b.insert(70);
	b.insert(55);
	b.insert(60);

	b.preOrder();

	b.update(70, 80);

	b.preOrder();


	system("pause");
}