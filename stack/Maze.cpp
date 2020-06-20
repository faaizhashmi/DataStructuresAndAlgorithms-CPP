#include<iostream>
using namespace std;

template <typename T>
struct stack{
	T *arr;
	int csize;
	int msize;
	void copy(char *arr1, int _msize){

		arr = new T[_msize];
		for (int i = 0; i < _msize; i++){
			arr[i] = arr1[i];
		}
		msize = _msize;
		csize = _msize;
	}
	void initialize(int _msize){
		arr = new T[_msize];
		msize = _msize;
		csize = 0;
	}
	void push(T n){
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
	bool checkstack(int _x, int _y){
		for (int i = 0; i < csize; i=i+2){
			int row=arr[i];
			int col=arr[i+1];
			if (row == _x && col==_y){
				return 1;
			}			
		}
		return 0;
	}
}; 
int main(){
	stack<int>s1;
	s1.initialize(30);
	int maze[4][4] = { 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1 };
	int row;
	int col;
	int x = 0;
	int y = 0;


	while (x!=3 || y != 3){
		s1.push(x);
		s1.push(y);
		maze[x][y] = -1;
		if (maze[x - 1][y] == 1 && !s1.checkstack(x - 1, y)){
			x--;
		}
		else if (maze[x + 1][y] == 1 && !s1.checkstack(x + 1, y)){
			x++;
		}
		else if (maze[x][y + 1] == 1 && !s1.checkstack(x, y + 1)){
			y++;
		}
		
		else if (maze[x][y - 1] == 1 && !s1.checkstack(x, y - 1)){
			y--;
		}
		else{

			y = s1.pop();
			x = s1.pop();
			
		}
	}

	maze[x][y] = -1;

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			cout << maze[i][j]<<' ';
		}
		cout << endl;
	}
	system("pause");
}