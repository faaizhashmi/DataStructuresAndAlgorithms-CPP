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

	bool deleteelement(int ele){
		if (head == NULL){
			return false;
		}
		else if (head->data == ele){
			node *temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		else {
			node *temp = head;
			while (temp->next != NULL){
				if (temp->next->data == ele){
					node *temp1 = temp->next;
					if (temp->next->next == NULL){
						temp->next = NULL;
						delete temp1;
						break;
					}
					else{
						temp->next = temp1->next;
					}
					delete temp1;
				}
				temp = temp->next;
			}
			return false;
		}
	}
};
void deleteNode(node *n){
	node* temp1 = n->next;
	if (n == NULL){
		cout << "Link list empty" << endl;
	}
	else if (n->next == NULL){
		n->data=NULL;
		n->next = NULL;
	}
	else if (n->next != NULL){
		n->data = temp1->data;
		n->next = temp1 -> next;
		delete[]temp1;
	}
}
int main(){
	linklist l;
	l.initialize();
	l.insertElement(1);
	l.insertElement(2);
	l.insertElement(3);
	
	deleteNode(l.head->next);
	l.displaylist();
	system("pause");
}