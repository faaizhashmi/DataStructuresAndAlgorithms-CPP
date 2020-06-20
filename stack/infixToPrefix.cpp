#include<iostream>
using namespace std;
template <typename T>
struct stack{
	T *arr;
	int csize;
	int msize;
	void copy(char *arr1,int _msize){
	
		arr = new T[_msize];
		for (int i = 0; i < _msize; i++){
			arr[i] = arr1[i];
		}
		msize = _msize;
		csize = _msize;
	}
	void initialize(int _msize){
		int n = 0;
		if (_msize <= 0){
			_msize = 10;
		}
		arr = new T[_msize];
		msize = _msize;
		csize = 0;
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
	char arr[100];
	cin >> arr;
	stack <char> inp,st,res;
	inp.copy(arr, strlen(arr));
	st.initialize(20);
	res.initialize(20);
	for (int i = 0; i < strlen(inp.arr); i++){
		if (inp.arr[i] >= 65 && inp.arr[i] <= 90 || inp.arr[i] >= 91 && inp.arr[i] <= 122){

		}
		else if (inp.arr[i] == 40 || inp.arr[i] == 41 || inp.arr[i] == 123 && inp.arr[i]==125){

		}

	}
	system("pause");
}