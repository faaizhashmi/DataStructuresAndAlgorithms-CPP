#include<iostream>
using namespace std;
template <typename T>
struct queue{
	T *arr;
	int csize;
	int msize;
	int front;
	void initialize(int _msize){
		msize = _msize;
		arr = new T[msize];
		csize = 0;
		front = 0;
	}
	void copy(T *_arr, int _csize){
		for (int i = 0; i < _csize; i++){
			arr[i] = _arr[i];
		}
		csize = _csize;
	}
	void enque(int n){
		if (!isFull()){
			arr[csize + front] = n;
			csize++;

		}
		else{
			cout << "stack full" << endl;
		}
	}
	T deque(){
		if (!isEmpty()){
			csize--;
			front++;
			return arr[front - 1];
		}
		else{
			cout << "Empty" << endl;
		}

	}

	T getfront(){
		if (!isEmpty()){
			return arr[front];
		}
	}
	void printqueue(){
		for (int i = front; i < csize + front; i++){
			cout << "PLOT "<<i+1<<" owner: " ;
			cout << arr[i] <<endl;
		}
	}
	bool isFull(){
		if (csize == msize){
			return 1;
		}
		return 0;
	}
	bool isEmpty(){
		if (csize == 0){
			return 1;
		}
		return 0;
	}
};
int main(){
	queue <int>q, q1;
	int m = 0;
	cout << "Enter total memberships" << endl;
	cin >> m;
	q.initialize(m);
	int x = 0;
	cout << "Enter employees id" << endl;
	for (int i = 0; i < m; i++){
		cin >> x;
		q.enque(x);
	}
	cout << "Employees with memberships" << endl;
	q.printqueue();

	system("pause");



}