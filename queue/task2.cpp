#include<iostream>
using namespace std;
template <typename T>
struct queue{
	T *arr;
	int csize;
	int msize;
	int front;
	void initialize(){
		msize = 20;
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
			cout << arr[i] << " ";
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
	queue <int>q;
	q.initialize();
	char a;
	int x;
	cout << "Enter input" << endl;
	while (1){
		cin >> a;
		if (a >= 48 && a <= 57){
			x = int(a - 48);
			if (x % 2 != 0){
				q.enque(x);
			}
			else{
				cout << "Even number entered" << endl;
			}
		}
		else if(a=='*'){
			if (!q.isEmpty()){
				cout << q.deque() << endl;
			}
			else{
				cout << "Stack empty" << endl;
			}
		}
		cout << "Queue: "; q.printqueue();
		cout << '\t' << "front = " << q.getfront() << endl;
		cout << endl;
	}

	system("pause");



}