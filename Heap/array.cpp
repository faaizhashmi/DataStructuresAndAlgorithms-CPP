#include<iostream>
using namespace std;
struct maxheap{
	int *arr;
	int msize;
	int csize;
	void initialize(int s){
		msize = s;
		csize = 0;
		if (msize < 16){
			msize = 16;
		}
		arr = new int[msize];

		for (int i = 0; i < msize; i++){
			arr[i] = 0;
		}
	}

	void print(){
		for (int i = 0; i < csize; i++){
			cout << arr[i] << ' ';
		}
	}
	void descending()
	{
		for (int i = 0; i < csize - 1; i++){
			for (int j = i + 1; j < csize; j++){
				if (arr[i]<arr[j]){
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	void insert(int d){
		if (csize <= msize){
			arr[csize] = d;
			csize++;
		}
		else{
			int *temp = arr;
			msize = msize + 10;
			arr = new int[msize];
			for (int i = 0; i < msize; i++){
				arr[i] = temp[i];
			}
			descending();
		}

	}
	void delet(){

		for (int i = 0, j = 1; i < csize; j++, i++){
			arr[i] = arr[j];
		}
		arr[csize] = 0;
		csize--;

	}
};
struct minheap{
	int *arr;
	int msize;
	int csize;
	void initialize(int s){
		msize = s;
		csize = 0;
		if (msize < 16){
			msize = 16;
		}
		arr = new int[msize];

		for (int i = 0; i < msize; i++){
			arr[i] = 0;
		}
	}
	void ascending(){
		for (int i = 0; i < csize - 1; i++){
			for (int j = i + 1; j < csize; j++){
				if (arr[i]>arr[j]){
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	void insert(int d){
		if (csize <= msize){
			arr[csize] = d;
			csize++;
		}
		else{
			int *temp = arr;
			msize = msize + 10;
			arr = new int[msize];
			for (int i = 0; i < msize;i++){
				arr[i] = temp[i];
		}
			
	}
		ascending();

}
	void delet(){
		
		for (int i = 0, j = 1; i < csize; j++,i++){
			arr[i] = arr[i+1];
		}
		csize--;
		arr[csize] = 0;
		
	}
	void print(){
		for (int i = 0; i < csize; i++){
			cout << arr[i] << ' ';
		}
	}
};
	int main(){
		minheap h;
		h.initialize(16);
		h.insert(1);
		h.insert(2);
		h.insert(3);
		h.insert(6);
		h.insert(4);
		h.insert(9);
		h.insert(0);
		h.insert(10);
		h.insert(23);
		h.insert(52);
		h.insert(18);
		h.insert(91);
		h.insert(122);
		h.insert(121);
		h.insert(193);
		h.insert(132);
		h.delet();
		h.print();
		system("pause");
}