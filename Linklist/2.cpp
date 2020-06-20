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
			head = new  node[1];
			head->data = element;
			head->next = head;
		}
		else{
			node *temp = head;
			while (temp->next != head){
				temp = temp->next;
			}
			node *temp1 = new node[1];
			temp1->data = element;
			temp1->next = head;
			temp->next = temp1;

		}

	}
	void displaylist(){
		node *temp = head;
		while (temp->next!=head){
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << temp->data << endl;
	}

	bool deleteelement(int ele){
		if (head->next == head){
			return false;
		}
		else if (head->data == ele){
			node *temp = head;
			while (temp->next != head){
				if (temp->next->next == head){
					temp->next->next = head->next;
					break;
				}
				temp = temp->next;
			}
			temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		else {
			node *temp = head;
			while (temp->next != head){
				if (temp->next->data == ele){
					node *temp1 = temp->next;
					if (temp->next->next != head){
						temp->next = temp1->next;
						break;
					}
					else{
						temp->next = head;
						break;
					}
					delete temp1;
				}
				temp = temp->next;
			}
		}

	}
	void sortlist(){
		node *temp = head;
		node *temp1 = head;
		int count = 0;
		while (temp->next != head){
			temp = temp->next;
			count++;
		}
		
		for (int i = 0; i<count; i++){
			temp = temp1->next;
			for (int j = i ; j<count; j++){
				if (temp->data> temp1->data){
					swap(temp->data, temp1->data);
					temp1 = head;
					temp = temp1->next;
					i = 0;
					j = i;
				}
				else
				{
					temp = temp->next;
				}
				
			}
			temp1 = temp1->next;
		}
	}
					
	
};
int main(){
	linklist l;
	l.initialize();
	l.insertElement(1);
	l.insertElement(5);
	l.insertElement(3);
	l.sortlist();
	l.displaylist();
	system("pause");
}