#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	T value;
	Node*left;
	Node*right;
};

template<typename T>
class Tree
{
	Node<T>*root;

public:

	void initalize()
	{
		root = NULL;
	}

	void preOrder()
	{
		pre_Order(root);
		cout << endl;
	}

	void postOrder()
	{
		post_Order(root);
	}

	void inOrder()
	{
		in_Order(root);
	}

	void pre_Order(Node<T>*n)
	{
		if (n != NULL)
		{
			cout << n->value << " ";
			if (n->left != NULL)
				pre_Order(n->left);
			if (n->right != NULL)
				pre_Order(n->right);
		}
	}

	void post_Order(Node<T>*n)
	{
		if (n != NULL)
		{
			
			if (n->left != NULL)
				post_Order(n->left);
			if (n->right != NULL)
				post_Order(n->right);
			cout << n->value << endl;
		}
	}

	void in_Order(Node<T>*n)
	{
		if (n != NULL)
		{
			if (n->left != NULL)
				in_Order(n->left);

			cout << n->value << endl;

			if (n->right != NULL)
				in_Order(n->right);
		}
	}

	bool isUnique(Node<T>*n, int child)
	{
		bool left = false;
		bool right = false;


		if (n != NULL)
		{

			if (n->left != NULL)
				left = isUnique(n->left, child);

			if (n->right != NULL)
				right = isUnique(n->right, child);

			if (n->value == child)
				return true;
			else
			{
				if (right == true || left == true)
					return true;
				else
					return false;
			}

		}
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

	void insertroot(int r)
	{
		if (root != NULL)
		{
			cout << "Root already exist" << endl;
			return;
		}
		root = new Node<T>();
		root->value = r;
		root->left = NULL;
		root->right = NULL;
			

	}

	void insertleft(int data, int child)
	{
		if (isUnique(root, child)==true)
		{
			cout << "child already exist" << endl;
			return;
		}

		Node<T>* parent = findData(root, data);

		if (parent == NULL)
		{
			cout << "data not found" << endl;
			return;
		}

		if (parent->left != NULL)
		{
			cout << "child already exist" << endl;
			return;
		}

		parent->left = new Node<T>();
		parent->left->left = NULL;
		parent->left->right = NULL;
		parent->left->value = child;

	}


	void insertright(int data, int child)
	{
		if (isUnique(root, child)==true)
		{
			cout << "child already exist" << endl;
			return;
		}

		Node<T>* parent = findData(root, data);

		if (parent == NULL)
		{
			cout << "data not found" << endl;
			return;
		}

		if (parent->right != NULL)
		{
			cout << "child already exist" << endl;
			return;
		}

		parent->right = new Node<T>();
		parent->right->left = NULL;
		parent->right->right = NULL;
		parent->right->value = child;

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

	bool del2(Node<T>*n,int data)
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
				left= del2(n->left, data);
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
				right= del2(n->left, data);
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
				root=NULL;
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

	void update(int data, int newdata)
	{
		Node<T>* parent = findData(root, data);

		if (parent == NULL)
		{
			cout << "data not found" << endl;
			return;
		}

		parent->value = newdata;

	}

	int heightoftree()
	{
		return height(root)-1;

	}

	int max2(int x, int y)
	{
		if (x >= y)
			return x;
		else
			return y;
	}


	int height(Node<T> *p)
	{
		if (p == nullptr)
			return 0;
		else
			return 1 + max2(height(p->left), height(p->right));
	}

	int max()
	{
		int i = 0;

		if (root != NULL)
			i = 1;

		return max1(root,i);
	}

	int max1(Node<T>*n,int &count)
	{
		if (n != NULL)
		{

			if (n->left != NULL)
			{
				max1(n->left, ++count);
			}

			if (n->right != NULL)
			{
				max1(n->right, ++count);
			}

		}
		return count;
	}

	int noofchild()
	{
		int i = 0;
		return child(root,i);
	}

	int child(Node<T>*n,int &count)
	{
		int flag = 0;
		if (n != NULL)
		{

			if (n->left != NULL)
			{
				child(n->left,count);
				flag ++;
			}

			if (n->right != NULL)
			{
				child(n->right,count);
				flag++;
			}

		}
		if (flag == 1)
			count++;
		return count;
	}

};


int main()
{

	Tree<int>t;
	t.initalize();

	t.insertroot(1);
	t.insertleft(1,2);
	t.insertright(1, 3);
	t.insertleft(2, 4);
	t.insertright(2, 5);
	t.insertleft(4, 6);
	t.insertright(4, 7);
	/*t.insertright(3, 8);
	t.insertleft(5, 9);*/
	t.preOrder();

	cout<<t.heightoftree()<<endl;
	cout << t.max() << endl;
	cout << t.noofchild() << endl;

	t.deleteifnochild(6);
	t.deleteifnochild(4);
	t.preOrder();
	cout << t.heightoftree() << endl;
	cout << t.max() << endl;
	cout << t.noofchild() << endl;
	t.deleteAllNode(4);
	t.preOrder();

	system("pause");


}