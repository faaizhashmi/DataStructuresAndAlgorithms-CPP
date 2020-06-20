#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	T data;
	T flag;
};


template<typename T>
class MinHeap
{
	Node<T> *data;
	int cap;
	int cur;

public:

	void initalize(int c)
	{
		if (c <= 0)
			c = 16;
		data = new Node<T>[c];
		cap = c;
		cur = 0;
		for (int i = 0; i < cap; i++)
			data[i].flag = 0;
	}

	void asc(Node<T>*d)
	{
		for (int i = 0; i < cur; i++)
		{
			for (int j = i + 1; j < cur; j++)
			{
				if (d[j].data < d[i].data)
				{
					swap(d[j], d[i]);
				}
			}
		}
	}

	void insert(int d)
	{

		if (cur == cap)
		{
			int new_size = cap * 2;
			Node<T>*temp = new Node<T>[new_size];
			for (int i = 0; i < cap; i++)
			{
				temp[i].data = data[i].data;
				temp[i].flag = data[i].flag;
			}

			delete[]data;
			data = temp;
			temp = NULL;
			cap = new_size;
		}

		data[cur].data = d;
		data[cur].flag = 1;
		cur++;

		asc(data);
	}

	int del()
	{
		int k = data[0].data;
		int j = 1;
		for (int i = 0; i < cur; i++)
		{
			data[i].data = data[j].data;
			j++;
		}
		data[cur].flag = 0;
		cur--;
		return k;
	}

	void printtop()
	{
		if (cur == 0)
		{
			cout << "empty" << endl;
			return;
		}
		cout << del() << endl;
	}

};


template<typename T>
struct Node1
{
	T data;
	T flag;
};


template<typename T>
class MaxHeap
{
	Node1<T> *data;
	int cap;
	int cur;

public:

	void initalize(int c)
	{
		if (c <= 0)
			c = 16;
		data = new Node1<T>[c];
		cap = c;
		cur = 0;
		for (int i = 0; i < cap; i++)
			data[i].flag = 0;
	}

	void dec(Node1<T>*d)
	{
		for (int i = 0; i < cur; i++)
		{
			for (int j = i + 1; j < cur; j++)
			{
				if (d[j].data > d[i].data)
				{
					swap(d[j], d[i]);
				}
			}
		}
	}

	void insert(int d)
	{

		if (cur == cap)
		{
			int new_size = cap * 2;
			Node1<T>*temp = new Node1<T>[new_size];
			for (int i = 0; i < cap; i++)
			{
				temp[i].data = data[i].data;
				temp[i].flag = data[i].flag;
			}

			delete[]data;
			data = temp;
			temp = NULL;
			cap = new_size;
		}

		data[cur].data = d;
		data[cur].flag = 1;
		cur++;

		dec(data);
	}

	int del()
	{
		int k = data[0].data;
		int j = 1;
		for (int i = 0; i < cur; i++)
		{
			data[i].data = data[j].data;
			j++;
		}
		data[cur].flag = 0;
		cur--;
		return k;
	}

	void printtop()
	{
		if (cur == 0)
		{
			cout << "empty" << endl;
			return;
		}
		cout << del() << endl;
	}
};


int main()
{
	int i = 0;
	MinHeap<int> min;
	MaxHeap<int> max;

	min.initalize(6);
	max.initalize(5);

	min.insert(50);
	min.insert(20);
	min.insert(5);
	min.insert(25);
	min.insert(1);
	min.insert(0);
	min.insert(40);
	min.insert(30);

	for (i = 0; i < 9; i++)
	{
		min.printtop();
	}
	
	max.insert(50);
	max.insert(20);
	max.insert(5);
	max.insert(25);
	max.insert(60);
	max.insert(0);
	max.insert(40);
	max.insert(30);

	for (i = 0; i < 9; i++)
	{
		max.printtop();
	}


	system("pause");
}