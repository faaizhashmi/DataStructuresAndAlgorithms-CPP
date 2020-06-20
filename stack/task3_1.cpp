#include<iostream>
#include<cmath>
using namespace std;
template <typename T>
struct stack{
	T *arr;
	int csize;
	int msize;
	void initialize(int _msize){
		int n = 0;
		if (_msize <= 0){
			_msize = 5;
		}
		arr = new T[_msize];
		for (int i = 0; i <= _msize; i++){
			cin >> n;
			arr[i] = n;
		}
		msize = _msize;
	}
	int binaryToDecimal(){
		int power = 0;
		int digit = 0;
		int sum = 0;
		for (int i = msize - 1; i>=0; i--){
			digit=int(pow(2, power));
			if (arr[i] == 1){
				sum = sum + digit;
			}power++;
			
		}
		return sum;
	}
};
int main(){
	int size = 0;
	stack<int>s1;
	cout << "Enter size of binary" << endl;
	cin >> size;
	cout << "\n Now enter in 1's and 0's" << endl;
	s1.initialize(size);
	cout<<s1.binaryToDecimal();

	system("pause");

}