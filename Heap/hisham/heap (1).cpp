#include<iostream>
using namespace std;

class heap
{
public:
	int *data;
	int capacity;
	int current;
	
	void initalize(int c)
	{
		if (c <= 0)
			c = 16;
		data = new int[c];
		capacity = c;
		current = 0;
		data[0] = 1;
	}

	void insert(int num)
	{
		int index = data[0];
		data[0]++;
		if (index >= capacity)
		{
			int new_size = capacity * 2;
			int*temp= new int[new_size];
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = data[i];
				temp[i] = data[i];
			}

			delete[]data;
			data = temp;
			temp = NULL;
			capacity = new_size;
		}

		data[index] = num;

		while (1)
		{
			if (index <= 1)
			{
				break;
			}

			if (data[index] < data[index / 2])
			{
				swap(data[index], data[index / 2]);
			}
			index = index / 2;
		}


	}

	void fun(int index)
	{
		if ((index * 2) >= data[0] && ((index * 2) + 1) >= data[0])
			return;

		if (data[0] == 3)
		{
			if (data[1]>data[2])
				swap(data[1], data[2]);
			return;
		}

		if (data[index * 2]<data[(index * 2) + 1])
		{
			if (data[index] > data[index * 2])
			{
				swap(data[index], data[index * 2]);
				fun(index * 2);
			}
			return;
		}
		else
		{
			if (data[index] > data[(index * 2) + 1])
			{
				swap(data[index], data[(index * 2) + 1]);
				fun((index * 2) + 1);
			}
			return;
		}


		if (data[index] > data[index * 2])
		{
			swap(data[index], data[index * 2]);
			fun(index * 2);
		}
		else if (((index * 2) + 1) >= data[0])
			return;
		else if (data[index] > data[(index * 2)+1])
		{
			swap(data[index], data[(index * 2)+1]);
			fun((index * 2)+1);
		}
		return;

	}

	void getMin()
	{
		if (data[0] == 1)
		{
			cout << "empty" << endl;
			return;
		}
		if (data[0] == 2)
		{
			cout << data[1] << endl;
			data[0]--;
			return;
		}


		cout << data[1] << endl;
		swap(data[1], data[data[0]-1]);
		data[0]--;

		fun(1);
	}


};

int main()
{
	heap h;
	h.initalize(10);

	h.insert(5);
	h.insert(9);
	h.insert(11);
	h.insert(15);
	h.insert(6);
	h.insert(3);

	for (int i = 1; i < h.data[0]; i++)
		cout << h.data[i] << endl;
	cout << endl;

	h.getMin();

	cout << endl;
	for (int i = 1; i < h.data[0]; i++)
		cout << h.data[i] << endl;



	system("pause");
}