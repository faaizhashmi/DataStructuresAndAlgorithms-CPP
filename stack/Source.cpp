#include<iostream>
using namespace std;
template <typename T>
struct stack{
	T *arr;
	int csize;
	int msize;
	void initialize(int _msize, int _csize){
		int n = 0;
		if (_msize <= 0){
			_msize = 10;
		}
		arr = new T[_msize];
		for (int i = 0; i < _csize; i++){
			cin >> n;
			arr[i] = n;
		}
		msize = _msize;
		csize = _csize;
	}
	void push(int n){
		if (!isFull()){
			arr[csize] = n;
			csize++;
		}
		else{
			cout << "stack full" << endl;
		}
	}
	T pop(){
		if (!isEmpty()){
			csize--;
			return arr[csize];
		}
		else{
			cout << "Stack Empty" << endl;
		}
	}
	T gettop(){
		return arr[csize - 1];
	}
	void display(){
		for (int i = 0; i < csize; i++){
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
	stack<int> s;
	int size = 0;
	int c = 0;
	cout << "Enter size of data" << endl;
	cin >> size;
	cout << "Enter capacity" << endl;
	cin >> c;
	s.initialize(size, c);
	cout << endl;
	s.display();
	s.pop();
	s.pop();
	s.push(14);
	cout << endl;
	s.gettop();
	cout << endl;
	s.display();
	system("pause");
	return 0;
}
