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
	void reverse(stack &s1, stack &s2){
		int i = 0;
		int j = 0;
		for (i = 0,j=csize-1; i < csize; i++){
			s2.arr[i] = s1.arr[j];
			j--;
		}
	}
	void display(stack s){
		for (int i = 0; i < csize; i++){
			cout << s.arr[i] << " ";
		}
	}
};
int main(){
	stack<int>s1;
	stack<int>s2;
	cout << "Enter stack1" << endl;
	s1.initialize(3, 3);
	s2.initialize(3, 3);
	s1.reverse(s1,s2);
	s2.display(s2);
	system("pause");
}