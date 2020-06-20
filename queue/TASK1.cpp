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
			arr[csize+front] = n;
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
			return arr[front-1];
		}
		else{
			cout << "Empty" << endl;
		}
		
	}
	T gettop(){
		return arr[front];
	}
	T getfront(){
		return front;
	}
	void printqueue(){
		for (int i = front; i < csize+front; i++){
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
	int arr[20] = { 1, 3, 5, 7, 9, 11, 13, 15 };
	q.initialize();
	q.copy(arr, 8);
	q.deque();
	q.deque();
	q.enque(17);
	cout << q.front << endl;
	q.printqueue();
	system("pause");
}