#include<iostream>
using namespace std;
int sum(int i){
	if (i ==0 ){
		return 0;
	}
	else{
		return i+sum(i -1 );
	}
}
int fibo(int num){
	if (num == 0||num==1){
		return 1;
	}
	else{
		return fibo( num-1)+fibo(num-2);
	}
}
int dectobin(int num){
	if (num == 0 || num == 1){
		return 1;
	}
	else{
		num = num / 2;
		if (num % 2 != 0){
			cout << 1;
		}
		else{
			cout << 0;
		}
		
		return dectobin(num);
	}
}
int count(int num,int i){
	if (num == 0 || num == 1){
		return i;
	}
	else{
		
		i++;
		num = num / 10;
		return count(num,i);
	}
}
int sum(int num, int i){
	if (num == 0 )
	{
		return i;
	}
	else{
		i = i + (num % 10);
		num = num / 10;
		return  sum(num, i);
	}
}
int greater7(int num, int i){
	if (num == 0)
	{
		return i;
	}
	else{
		if ((num % 10) > 7){
			i++;
		}
		num = num / 10;
		return  greater7(num, i);
	}
}
int reverse(int num){
	if (num == 0)
	{
		cout << endl;
		return 0;
	}
	else{
		cout << num % 10;
		num = num / 10;
		return  reverse(num);
	}
}
int gcd(int num1, int num)
{
	if (num1 == 0 || num == 0)
		return 0;
	if (num1 == num)
		return num1;

	if (num1 > num)
		return gcd(num1 - num, num);
	else{

		return gcd(num1, num - num1);

	}
}
//int factorial(int num){
//	if (num == 1){
//		return 1;
//	}
//	else{
//		return num*factorial(num - 1);
//	}
//}
int main(){
	int input = 0, input1 = 0;
	int num = 0;
	cout << "Input:";
	cin >> input;
	cin >> input1;
	cout << gcd(input,input1);
	system("pause");
}