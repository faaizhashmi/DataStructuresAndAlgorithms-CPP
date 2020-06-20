#include<iostream>
using namespace std;

class tree
{

	int *data;
	int capacity;
public:

	void initialize(int size)
	{
		capacity = size;
		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = -999;
		}
	}
	void insert_root(int input)
	{
		if (data[0] == -999)
		{
			data[0] = input;
		}
		else
		{
			cout << "root is not empty" << endl;
		}
	}
	void insert_left(int search,int left)
	{
		int counter = 0;
		for (int i = 0; i < capacity; i++)
		{
			if (data[i] == search)
			{
				data[(2*i) + 1] = left;
				counter = 1;
				break;
			}
			else
			{
				counter = 0;
			}
		}
		if (counter == 0)
		{
			cout << "not found" << endl;
		}
	}
	void insert_right(int search, int right)
	{
		int counter = 0;
		for (int i = 0; i < capacity; i++)
		{
			if (data[i] == search)
			{
				data[(2*i) + 2] = right;
				counter = 1;
				break;
			}
			else
			{
				counter = 0;
			}
		}
		if (counter == 0)
		{
			cout << "not found" << endl;
		}
	}
	bool search_node(int input)
	{

		bool counter = 0;
		for (int i = 0; i < capacity; i++)
		{
			if (data[i] == input)
			{
				counter = 1;
				break;
			}
			else
			{
				counter = 0;
			}
		}
		if (counter == 0)
		{
			cout << "not found" << endl;
			return counter;
		}
		return counter;
	}
	void update_node(int search,int update)
	{
		int counter = 0;
		for (int i = 0; i < capacity; i++)
		{
			if (data[i] == search)
			{
				data[i] = update;
				counter = 1;
				break;
			}
			else
			{
				counter = 0;
			}
		}
		if (counter == 0)
		{
			cout << "not found" << endl;	
		}
	}
	void print()
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << data[i] << endl;
		}
	}
	void deletnode(int node)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (i == node)
			{
				if (data[node] == -999)
				{
					cout << "node donot exist" << endl;
					break;
				}
				else
				{
					if ((data[(2*node) + 1] == -999) && (data[(2*node) + 2] == -999))
					{
						data[node] = -999;
						cout << "deleted" << endl;
					}
					else
					{
						cout << "cannot delete data" << endl;
						break;
					}
				}
			}
		}
	}
	void particular_left_delete(int node)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (i == node)
			{
				if (data[node] != -999)
				{
					while (data[(2 * node) + 1] != -999)
					{
						if (node >= capacity)
						{
							break;
						}
						data[(2*node)+1] = -999;
						node = (node * 2) + 1;
					}
				}
				else
				{
					cout << " not exist" << endl;
				}
			}
		}
	}
	void particular_right_delete(int node)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (i == node)
			{
				if (data[node] != -999)
				{
					while (data[(2 * node) + 2] != -999)
					{
						if (node >= capacity)
						{
							break;
						}
						data[(node*2)+2] = -999;
						node = (node * 2) + 2;
					}
				}
				else
				{
					cout << " not exist" << endl;
				}
			}
		}
	}
};




int main()
{
	tree t;

	int x = 0;
	int size = 0;
	cout << "size you want to make tree" << endl;
	cin >> size;
	t.initialize(size);
	while (1)
	{
		cout << " enter 1 to insert root" << endl;
		cout << "enter 2 to insert left" << endl;
		cout << "enter 3 to insert right" << endl;
		cout << "enter 4 to delete node" << endl;
		cout << "enter 5 to update node" << endl;
		cout << "enter 6 to search node" << endl;
		cout << "enter 7 to delete left sub node" << endl;
		cout << "enter 8 to delete right sub node" << endl;
		cout << "enter 9 to print" << endl;
		cout << "enter 10 to exit" << endl;
		cin >> x;

		if (x == 1)
		{
			int value=0;
			cout << "enter value you want to enter at root" << endl;
			cin >> value;
			t.insert_root(value);
		}
		else if (x==2)
		{
			int value = 0;
			int value1 = 0;
			cout << "enter value you want to enter as left for" << endl;
			cin >> value;
			cout << "enter value you want to search" << endl;
			cin >> value1;
			t.insert_left(value1, value);
		}
		else if (x == 3)
		{
			int value = 0;
			int value1 = 0;
			cout << "enter value you want to enter as right for" << endl;
			cin >> value;
			cout << "enter value you want to search" << endl;
			cin >> value1;
			t.insert_right(value1, value);
		}
		else if (x == 4)
		{
			int value1 = 0;
			cout << "enter node you want to delete" << endl;
			cin >> value1;
			t.deletnode(value1);
		}
		else if (x == 5)
		{
			int value = 0;
			int value1 = 0;
			cout << "enter value you want to search" << endl;
			cin >> value;
			cout << "enter value you to update" << endl;
			cin >> value1;
			t.update_node(value,value1);
		}
		else if (x == 6)
		{
			int value = 0;
			cout << "enter value you want to search" << endl;
			cin >> value;
			if (t.search_node(value) == 1)
			{
				cout << "found" << endl;
			}
			else
			{
				cout << "not found" << endl;
			}
		}
		else if (x == 7)
		{
			int value = 0;
			cout << "enter node you want to delete from left all" << endl;
			cin >> value;
			t.particular_left_delete(value);
		}
		else if (x == 8)
		{
			int value = 0;
			cout << "enter node you want to delete from right all" << endl;
			cin >> value;
			t.particular_right_delete(value);
		}
		else if (x == 9)
		{
			t.print();
		}
		else if (x == 10)
		{
			cout << "exit" << endl;
			break;
		}
		else
		{
			cout << "wrong input" << endl;
		}
	}
	return 0;
}