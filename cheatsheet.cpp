************************DLL**********************************
#include<iostream>
#include<fstream>
using namespace std;
struct node{
	int data;
	node *next;
	node *prev;
};
struct linklist{
	node *head;
	node *tail;
	void initialize(){
		head = NULL;
		tail = NULL;
	}
	void insertElementtail(int element){
		if (head == NULL){
			node *temp = new  node[1];
			temp->data = element;
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
			tail = temp;
		}
		else{
			node *temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			node *temp1 = new node[1];
			temp1->data = element;
			temp1->next = NULL;
			temp1->prev = temp;
			temp->next = temp1;
			tail = temp1;
		}

	}
	void insertElementhead(int element){
		node *temp = new node[1];
		temp->data = element;
		temp->prev = NULL;
		temp->next = head;
		head = temp;
	}
	void displaylistfhead(){
		node *temp = head;
		while (temp->next != NULL){
			cout << temp->data << endl;
			temp = temp->next;

		}
		cout << temp->data << endl;
	}
	void displaylistftail(){
		node *temp = tail;
		while (temp->prev != NULL){
			cout << temp->data << endl;
			temp = temp->prev;

		}
		cout << temp->data << endl;
	}
	bool deleteelement(int ele){
		if (head == NULL){
			return false;
		}
		else if (head->data == ele){
			node *temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		else {
			node *temp = head;
			while (temp->next != NULL){
				if (temp->next->data == ele){
					node *temp1 = temp->next;
					if (temp->next->next == NULL){
						temp->next = NULL;
						delete temp1;
						break;
					}
					else{
						temp->next = temp1->next;
					}
					delete temp1;
				}
				temp = temp->next;
			}
			return false;
		}
	}
	void dessortlist(){
		node *temp = head;
		node *temp1 = head;
		int count = 0;
		while (temp->next != NULL){
			temp = temp->next;
			count++;
		}

		for (int i = 0; i<count; i++){
			temp = temp1->next;
			for (int j = i; j<count; j++){
				if (temp->data> temp1->data){
					swap(temp->data, temp1->data);
					temp1 = head;
					temp = temp1->next;
					i = 0;
					j = i;
				}
				else
				{
					temp = temp->next;
				}

			}
			temp1 = temp1->next;
		}
	}

	void asssortlist(){
		node *temp = head;
		node *temp1 = head;
		int count = 0;
		while (temp->next != NULL){
			temp = temp->next;
			count++;
		}

		for (int i = 0; i<count; i++){
			temp = temp1->next;
			for (int j = i; j<count; j++){
				if (temp->data< temp1->data){
					swap(temp->data, temp1->data);
					temp1 = head;
					temp = temp1->next;
					i = 0;
					j = i;
				}
				else
				{
					temp = temp->next;
				}

			}
			temp1 = temp1->next;
		}
	}
};
void deleteNode(node *n){
	node* temp1 = n->next;
	if (n == NULL){
		cout << "Link list empty" << endl;
	}
	else if (n->next == NULL){
		n->data=NULL;
		n->next = NULL;
	}
	else if (n->next != NULL){
		n->data = temp1->data;
		n->next = temp1 -> next;
		delete[]temp1;
	}
}
int main(){
	int x = 0;
	ifstream fin;
	fin.open("data.txt", ios::in);
	linklist l;
	l.initialize();
	while (!fin.eof()){
		fin >> x;
		l.insertElementtail(x);
	}
	l.asssortlist();
	l.displaylistfhead();
		system("pause");
}


















****************************CLL*********************************
#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
struct linklist{
	node *head;
	void initialize(){
		head = NULL;
	}
	void insertElement(int element){
		if (head == NULL){
			head = new  node[1];
			head->data = element;
			head->next = head;
		}
		else{
			node *temp = head;
			while (temp->next != head){
				temp = temp->next;
			}
			node *temp1 = new node[1];
			temp1->data = element;
			temp1->next = head;
			temp->next = temp1;

		}

	}
	void displaylist(){
		node *temp = head;
		while (temp->next!=head){
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << temp->data << endl;
	}

	bool deleteelement(int ele){
		if (head->next == head){
			return false;
		}
		else if (head->data == ele){
			node *temp = head;
			while (temp->next != head){
				if (temp->next->next == head){
					temp->next->next = head->next;
					break;
				}
				temp = temp->next;
			}
			temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		else {
			node *temp = head;
			while (temp->next != head){
				if (temp->next->data == ele){
					node *temp1 = temp->next;
					if (temp->next->next != head){
						temp->next = temp1->next;
						break;
					}
					else{
						temp->next = head;
						break;
					}
					delete temp1;
				}
				temp = temp->next;
			}
		}

	}
	void sortlist(){
		node *temp = head;
		node *temp1 = head;
		int count = 0;
		while (temp->next != head){
			temp = temp->next;
			count++;
		}
		
		for (int i = 0; i<count; i++){
			temp = temp1->next;
			for (int j = i ; j<count; j++){
				if (temp->data> temp1->data){
					swap(temp->data, temp1->data);
					temp1 = head;
					temp = temp1->next;
					i = 0;
					j = i;
				}
				else
				{
					temp = temp->next;
				}
				
			}
			temp1 = temp1->next;
		}
	}
					
	
};
int main(){
	linklist l;
	l.initialize();
	l.insertElement(1);
	l.insertElement(5);
	l.insertElement(3);
	l.sortlist();
	l.displaylist();
	system("pause");
}








*******************************factorial recursion************
#include<iostream>
using namespace std;
int factor(int num){
	if (num == 1){
		return 1;
	}
	else{
		return num*factor(num - 1);
	}

}
int main(){
	cout << factor(5) << endl;
	system("pause");
}

*************************link link recusion************
#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
struct linklist{
	node *head;
	void initialize(){
		head = NULL;
	}
	void insertElement(int element){
		if (head == NULL){
			node *temp = new  node[1];
			temp->data = element;
			temp->next = NULL;
			head = temp;
		}
		else{
			node *temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			node *temp1 = new node[1];
			temp1->data = element;
			temp1->next = NULL;
			temp->next = temp1;

		}

	}
	void displaylist(){
		node *temp = head;
		while (temp->next != NULL){
			cout << temp->data << endl;
			temp = temp->next;

		}
		cout << temp->data << endl;
	}


	bool deleteelement(int ele){
		if (head == NULL){
			return false;
		}
		else if (head->data == ele){
			node *temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		else {
			node *temp = head;
			while (temp->next != NULL){
				if (temp->next->data == ele){
					node *temp1 = temp->next;
					if (temp->next->next == NULL){
						temp->next = NULL;
						delete temp1;
						break;
					}
					else{
						temp->next = temp1->next;
					}
					delete temp1;
				}
				temp = temp->next;
			}
			return false;
		}
	}
};
void displayrec(node *head){
	if (head == NULL){
		return;
	}
	else{
		cout << head->data << endl;
		displayrec(head->next);
	}
}
void displayrecrev(node *head){
	if (head == NULL){
		return;
	}
	else{
		displayrecrev(head->next);
		cout << head->data << endl;
	}
}
void deleteNode(node *n){
	node* temp1 = n->next;
	if (n == NULL){
		cout << "Link list empty" << endl;
	}
	else if (n->next == NULL){
		n->data = NULL;
		n->next = NULL;
	}
	else if (n->next != NULL){
		n->data = temp1->data;
		n->next = temp1->next;
		delete[]temp1;
	}
}
int main(){
	linklist l;
	l.initialize();
	l.insertElement(1);
	l.insertElement(2);
	l.insertElement(3);

	displayrecrev(l.head);
	system("pause");
}















****************************BST*********************
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