#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
struct linklist{
	node *head;
	void initialize(){
		head = NULL;
	}
	void insertElement(int element){
		if (head == NULL){
			node *temp = new  node[1];
			temp->data = element;
			temp->next = NULL;
			head = temp;
		}
		else{
			node *temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			node *temp1 = new node[1];
			temp1->data = element;
			temp1->next = NULL;
			temp->next = temp1;
			
		}

	}
	void displaylist(){
		node *temp = head;
		while (temp->next != NULL){
			cout << temp->data << endl;
			temp = temp->next;
			
		}
		cout << temp->data << endl;
	}
};
int main(){
	linklist l;
	l.initialize();
	l.insertElement(1);
	l.insertElement(2);
	l.insertElement(3);
	l.displaylist();
	system("pause");
}