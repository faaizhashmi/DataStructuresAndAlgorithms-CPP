#include<iostream>
#include<fstream>
using namespace std;
struct std{
	int reg;
	char *name;
	void insertelement(int _reg, char *_name){
		reg = _reg;
		strcpy(name, _name);
	}
};
struct bnode{
	int isbn;
	char *name;
	char *category;
	char *date;
	char *deadline;
	bnode *next;
	void insertvalue(int _isbn, char *_name, char *_category, char *_date, char *_deadline){
		isbn = _isbn;
		strcpy(name,_name );
		strcpy(category,_category );
		strcpy(date,_date);
		strcpy(deadline,_deadline);
	}
	
};
struct bookdll{
	bnode *head;
	void initialize(){
		head = NULL;
	}
	void insertElement(int _isbn, char *_name, char *_category, char *_date, char *_deadline){
		if (head == NULL){
			bnode *temp = new  bnode[1];
			temp->insertvalue(_isbn, _name, _category, _date, _deadline);
			temp->next = NULL;
			head = temp;
		}
		else{
			bnode *temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			bnode *temp1 = new bnode[1];
			temp1->insertvalue(_isbn, _name, _category, _date, _deadline);
			temp1->next = NULL;
			temp->next = temp1;
			
		}

	}

	void displaybooks(){
		bnode *temp = head;
		while (temp->next != NULL){
			cout << temp->isbn << '\t' << temp->name << '\t' << temp->category << '\t' << temp->date << '\t' << temp->deadline << '\t' ;
			temp = temp->next;

		}
		cout << temp->isbn << '\t' << temp->name << '\t' << temp->category << '\t' << temp->date << '\t' << temp->deadline << '\t';
	}

	bool deleteelement(int _isbn){
		if (head == NULL){
			return false;
		}
		else if (head->isbn==_isbn){
			bnode *temp = head;
			head = head->next;
			delete temp;
			return true;  
		}
		else {
			bnode *temp = head;
			while (temp->next != NULL){
				bnode *temp1 = temp->next;
				if (temp->isbn, _isbn){
			
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


struct node{
	std s;
	bookdll *d;
	node *next;
	node *prev;
}; struct std{
	int reg;
	char *name;
	void insertelement(int _reg, char *_name){
		reg = _reg;
		strcpy(name, _name);
	}
};
struct management{
	node *head;
	node *tail;
	void initialize(){
		head = NULL;
		head->d->initialize();
		tail = NULL;
	}
	void insertElementtail(int _isbn,int _reg,	char *_name,char *_date,	char *_deadline,  char *_category){
		if (head == NULL){
			head->s.reg = 0;
			node *temp = new  node[1]; 
			temp->s.insertelement(_reg,_name);
			temp->d->insertElement(_isbn, _name, _category, _date, _deadline);
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
			tail = temp;
		}
		else{
			node *temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			node *temp1 = new node[1];
			temp1->s.insertelement(_reg, _name);
			temp1->d->insertElement(_isbn, _name, _category, _date, _deadline);
			temp1->next = NULL;
			temp1->prev = temp;
			temp->next = temp1;
			tail = temp1;
		}

	}
	void insertElementhead(int _isbn, int _reg, char *_name, char *_date, char *_deadline, char *_category){
		node *temp = new node[1];
		temp->s.insertelement(_reg, _name);
		temp->d->insertElement(_isbn, _name, _category, _date, _deadline);
		temp->prev = NULL;
		temp->next = head;
		head = temp;
	}
	void displaylistfhead(){
		node *temp = head;
		while (temp->next != NULL){
			temp->d->displaybooks();
			cout << temp->s.name<<'\t'<<temp->s.reg << endl;
			temp = temp->next;

		}
		temp->d->displaybooks();
		cout << temp->s.name << '\t' << temp->s.reg << endl;
	}/*
	void displaylistftail(){
		node *temp = tail;
		while (temp->prev != NULL){
			cout << temp->data << endl;
			temp = temp->prev;

		}
		cout << temp->data << endl;
	}*/
	bool deleteelement(int _reg){
		if (head == NULL){
			return false;
		}
		else if (head->s.reg ==_reg){
			node *temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		else {
			node *temp = head;
			while (temp->next != NULL){
				if (temp->next->s.reg == _reg){
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
	}/*
	void dessortlist(){
		node *temp = head;
		node *temp1 = head;
		int count = 0;
		while (temp->next != NULL){
			temp = temp->next;
			count++;
		}

		for (int i = 0; i<count; i++){
			temp = temp1->next;
			for (int j = i; j<count; j++){
				if (temp->d->count> temp1->d->count){
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

	void asssortlist(){
		node *temp = head;
		node *temp1 = head;
		int count = 0;
		while (temp->next != NULL){
			temp = temp->next;
			count++;
		}

		for (int i = 0; i<count; i++){
			temp = temp1->next;
			for (int j = i; j<count; j++){
				if (temp->data< temp1->data){
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
	}*/
};
//void deleteNode(node *n){
//	node* temp1 = n->next;
//	if (n == NULL){
//		cout << "Link list empty" << endl;
//	}
//	else if (n->next == NULL){
//		n->data = NULL;
//		n->next = NULL;
//	}
//	else if (n->next != NULL){
//		n->data = temp1->data;
//		n->next = temp1->next;
//		delete[]temp1;
//	}
//}
