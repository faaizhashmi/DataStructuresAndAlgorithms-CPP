#include<iostream>
#include<fstream>
using namespace std;
void _strcpy(char *&n, char *n1){

	int i = 0;
	int l = strlen(n1);
	n = new char[strlen(n1) + 1];
	for (i = 0; i < l; i++)
	{
		n[i] = n1[i];
	}
	n[i] = '\0';
}
struct std1{
	int reg;
	char *name;
	void insertstdval(int _reg, char *_name1){
		reg = _reg;
		_strcpy(name, _name1);
	}
};
struct bnode{
	int isbn;
	char *name;
	char *category;
	char *date;
	char *deadline;
	bnode *next;
	void insertbookval(int _isbn, char *_name, char *_category, char *_date, char *_deadline){
		isbn = _isbn;
		_strcpy(name, _name);
		_strcpy(category, _category);
		_strcpy(date, _date);
		_strcpy(deadline, _deadline);
	}

};
struct bookdll{
	bnode *headb;
	void insertbooknode(int _isbn, char *_name, char *_category, char *_date, char *_deadline){
		if (headb == NULL){
			bnode *temp = new  bnode[1];
			temp->insertbookval(_isbn, _name, _category, _date, _deadline);
			temp->next = NULL;
			headb = temp;
		}
		else{
			bnode *temp = headb;
			while (temp->next != NULL){
				temp = temp->next;		
			}							
			bnode *temp1 = new bnode[1];
			temp1->insertbookval(_isbn, _name, _category, _date, _deadline);
			temp1->next = NULL;
			temp->next = temp1;
		}
	}
	void displaybooks(){
		bnode *temp = headb;
		while (temp->next != NULL){
			cout <<"\nisbn:"<< temp->isbn << "\n title" << temp->name << "\nCategory:" << temp->category << "\ndate:" << temp->date << "\n deadline:" << temp->deadline << '\n';
			temp = temp->next;

		}
		cout << "\nisbn:" << temp->isbn << "\n title" << temp->name << "\nCategory:" << temp->category << "\ndate:" << temp->date << "\n deadline:" << temp->deadline << '\n';
	}
	void writebooks(){
		ofstream fout;
		fout.open("data1.txt", ios::app);
		bnode *temp = headb;
		while (temp->next != NULL){
			fout << "\nisbn:" << temp->isbn << "\n title" << temp->name << "\nCategory:" << temp->category << "\ndate:" << temp->date << "\n deadline:" << temp->deadline << '\n';
			temp = temp->next;

		}
		fout << "\nisbn:" << temp->isbn << "\n title" << temp->name << "\nCategory:" << temp->category << "\ndate:" << temp->date << "\n deadline:" << temp->deadline << '\n';
	}
	bool deleteelement(int _isbn){
		if (headb == NULL){
			return false;
		}
		else if (headb->isbn == _isbn){
			bnode *temp = headb;
			headb = headb->next;
			delete temp;
			return true;
		}
		else {
			bnode *temp = headb;
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
	std1 s;
	bookdll *d;
	node *next;
	node *prev;
};
struct management{
	node *head;
	node *tail;
	void initialize(){
		head = NULL;
		tail = NULL; 
	}
	void insertstudent(int _reg, char *_name){
		if (head == NULL){
			node *temp = new  node[1];


			temp->s.insertstdval(_reg, _name);
			temp->next = NULL;
			temp->prev = NULL;
			temp->d = new bookdll[1];
			temp->d->headb = NULL;


			head = temp;
			tail = temp;
			
		}
		else{
			node *temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			node *temp1 = new node[1];
			temp1->s.insertstdval(_reg, _name);
			temp1->next = NULL;
			temp1->d = new bookdll[1];
			temp1->d->headb = NULL;
			temp1->prev = temp;
			temp->next = temp1;
			tail = temp1;
		}

	}
	void insertbook(int _isbn, char *_name, char *_category, char *_date, char *_deadline){

		node *temp = head;
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->d->insertbooknode(_isbn, _name, _category, _date, _deadline);

	}
	void displaylistfhead(){
		node *temp = head;
		if (isempty() == 1){
			cout << "no data found" << endl;
		}
		else{

			while (temp->next != NULL){

				cout << "\t\t\tname:"<<temp->s.name <<"\treg:"  << temp->s.reg << ' ';
				temp->d->displaybooks();
				cout << endl<<endl;
				temp = temp->next;

			}
			cout << "\t\t\tname:" << temp->s.name << "\treg:" << temp->s.reg << ' '; 
			temp->d->displaybooks();
			cout << endl << endl;
		}
	}
	bool deleteelement(int _reg){
		if (head == NULL){
			return false;
		}
		else if (head->s.reg == _reg){
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
	}
	bool isempty(){
		if (head == NULL){
			return 1;
		}
		else{
			return 0;
		}
	}
	int getsize(){
		int size=1;
		node *temp = head;
		if (head == NULL){
			return 0;
		}
		else{
			while (temp->next != NULL){
				temp = temp->next;
				size++;
			}
			return size;
		}
	}
	void clearsystem(){
		node*temp1 = head;
		if (head == NULL){
		}
		else{
			while (temp1->next != NULL){
				node *temp = head;
				head = head->next;
				temp1 = head;
				delete temp;		
			}
			node *temp = head;
			head = head->next;
			temp1 = head;
			delete temp;
		}
	}
	void insertaftername(char *_name,int _reg,char* _name1,char* _name2,int _isbn,char* _category,char* _date,char* _deadline){
		
			node *temp = head;
			
			while (temp->next != NULL){
				if (strcmp(temp->s.name,_name)==0){
					
					
					
					
					
					node *temp1 = new node[1];
					node *temp2 = temp->next->next;
					temp1->s.insertstdval(_reg, _name1);

					temp1->next = NULL;
					temp1->prev = NULL;
					temp1->d = new bookdll[1];
					temp1->d->headb = NULL;
					temp1->d->insertbooknode(_isbn, _name2, _category, _date, _deadline);
					temp1->next = temp2;
					temp1->prev = temp;
					temp->next = temp1;
					temp2->prev = temp1;
				}
				temp = temp->next;
			}
			
		}
	void readfromfile(){
		int reg;
		char *name = new char[20];
		int isbn;
		char *name1 = new char[20];
		char *category = new char[20];
		char *date = new char[20];
		char *deadline = new char[20];



		ifstream fin1;
		fin1.open("data.txt");

		while (!fin1.eof()){
			char stop = '\0';
			fin1.getline(name, 10, ',');
			fin1 >> reg;

			insertstudent(reg, name);

			while (stop != ':'){

				fin1 >> isbn;
				fin1.ignore();
				fin1.getline(name1, 20, ',');
				fin1.getline(category, 10, ',');
				fin1.getline(date, 10, ',');
				fin1.getline(deadline, 10, ',');
				fin1 >> stop;
				fin1.ignore();

				insertbook(isbn, name1, category, date, deadline);
			}



		}
	}
	void removebeforename(char *_name){
		node *temp = head;
		node *temp1 = temp->next;
		node *temp2 = temp->next->next;
		if (isempty() == 1||head->next==NULL){
			cout << "link list is too small" << endl;
		}
		if (strcmp(head->s.name, _name) == 0){
			
			head = head->next;
			head->prev = NULL;
			delete[] temp;
		}
		else {
			while (temp1 != NULL){
				temp1 = temp->next;
				temp2 = temp->next->next;
				if (strcmp(temp1->s.name, _name) == 0){
					temp->next = temp2;
					if (temp2 != NULL){
						temp2->prev = temp;
					}
					else {
						temp->next = NULL;
					}
					delete[]temp1;
				}
				temp = temp->next;
			}
		}

	}
	void replaceviaisbn(int sisbn, int _reg, char* _name1, char* _name2, int _isbn, char* _category, char* _date, char* _deadline){
		node *temp = head;

		while (temp->next != NULL){
			bnode *b = temp->d->headb;
			while (b->next != NULL){

				if (sisbn==b->isbn){
					temp->s.insertstdval(_reg, _name1);
					b->insertbookval(_isbn, _name2, _category, _date, _deadline);
					break;
				}
				b = b->next;
			}
			temp = temp->next;
		}
	}
	void retrievek(int k){
		node *temp = head;
		int x = 0;
		while (temp->next != NULL){
			if (x == k){
				displaylistfhead();
			}

			temp = temp->next;
		}

	}
	void searchprintreg(int _reg){
		node *temp = head;
		while (temp->next != NULL){
			if (temp->s.reg == _reg){
				displaylistfhead();
			}

			temp = temp->next;
		}

	}
	void write(){
		ofstream fin1;
		fin1.open("data1.txt");
		node *temp = head;
		if (isempty() == 1){
			cout << "no data found" << endl;
		}
		else{

			while (temp->next != NULL){

				fin1 << "\t\t\tname:" << temp->s.name << "\treg:" << temp->s.reg << ' ';
				temp->d->displaybooks();
				fin1 << endl << endl;
				temp = temp->next;

			}
			fin1 << "\t\t\tname:" << temp->s.name << "\treg:" << temp->s.reg << ' ';
			temp->d->writebooks();
			fin1 << endl << endl;

		}
	}
	void descendsortlist(){
		node *temph = head;
		int count = 1;
		while (temph->next != NULL){
			bnode *b = temph->d->headb;
			bnode *tempb = b;
			bnode *temp1b = b;
			count = 0;
			while (b->next != NULL){

				count++;
				b = b->next;
			}
				for (int i = 0; i < count; i++){
				tempb = temp1b->next;
				for (int j = i; j<count; j++){
					if (tempb->isbn > temp1b->isbn){

						//int _isbn, char *_name, char *_category, char *_date, char *_deadline
						swap(tempb->isbn, temp1b->isbn);
						swap(tempb->name, temp1b->name);
						swap(tempb->category, temp1b->category);
						swap(tempb->date, temp1b->date);
						swap(tempb->deadline, temp1b->deadline);
						temp1b = temph->d->headb;
						tempb = temp1b->next;
						i = 0;
						j = i;
					}
					else
					{
						tempb = tempb->next;
					}

				}
				temp1b = temp1b->next;
			}
			temph = temph->next;
		}
		displaylistfhead();
	}
	void assendsortlist(){
		node *temph = head;
		int count = 1;
		while (temph->next != NULL){
			bnode *b = temph->d->headb;
			bnode *tempb = b;
			bnode *temp1b = b;
			count = 0;
			while (b->next != NULL){
				count++;
				b = b->next;
			}
			for (int i = 0; i < count; i++){
				tempb = temp1b->next;
				for (int j = i; j<count; j++){
					if (tempb->isbn < temp1b->isbn){
						swap(tempb->isbn, temp1b->isbn);
						swap(tempb->name, temp1b->name);
						swap(tempb->category, temp1b->category);
						swap(tempb->date, temp1b->date);
						swap(tempb->deadline, temp1b->deadline);
						temp1b = temph->d->headb;
						tempb = temp1b->next;
						i = 0;
						j = i;
					}
					else
					{
						tempb = tempb->next;
					}
				}
				temp1b = temp1b->next;
			}
			temph = temph->next;
		}
		displaylistfhead();
	}
};
int main(){
		 int reg;
		 char *name = new char[20];
		 char *name2 = new char[20];
		 int isbn;
		 char *name1 = new char[20];
		 char *category = new char[20];
		 char *date = new char[20];
		 char *deadline = new char[20];
		management *m = new management[1];
		m->initialize(); ifstream fin;
		fin.open("student.txt", ios::in);
		while (!fin.eof()){
			char stop = '\0';
			fin.getline(name, 10, ',');
			fin >> reg;
			m->insertstudent(reg, name);
			while (stop != ':'){
				fin >> isbn;
				fin.ignore();
				fin.getline(name1, 20, ',');
				fin.getline(category, 10, ',');
				fin.getline(date, 10, ',');
				fin.getline(deadline, 10, ',');
				fin >> stop;
				fin.ignore();
				m->insertbook(isbn, name1, category, date, deadline);
			}
		}
		fin.close();

		 int ch = 0;
		 cout << "Enter your choice" << endl;
		 cout << "1. Determine whether your System is empty." << endl;
		 cout << "2. Determine the size of the System." << endl;
		 cout << " 3. Destroy, or clear, the System." << endl;
		 cout << " 4. Insert an item in the System after the specified name." << endl;
		 cout << " 5. Insert data into System from a file(name of file must be “data.txt”)" << endl;
		 cout << "6. Remove data from the Issuance System before the specified name." << endl;
		 cout << " 7. Replace data against the specified ISBN number with another set of data." << endl;
		 cout << " 8. Retrieve Book Name, Issuance Date, Return Deadline Date and Student Reg ID in the System from the kth location. (You are not allowed to use an array here)" << endl;
		 cout << " 9. Search and print the data for a given “Student Reg ID”." << endl;
		 cout << "10. Print all the books issued by one student either in ascending order." << endl;
		 cout << "11. Print all the books issued by one student either in descending order." << endl;
		 cout << "12. When the program terminates, write the data in the address book to a disk using filing." << endl;
		 cin >> ch;

		 while (1){

			 if (ch == 0){
				 m->write();
				 break;
			 }
			 if (ch == 1){
				 cout << m->isempty()<< endl;
			 }
			 if (ch == 2){
				 cout << m->getsize() << endl;
			 }
			 if (ch == 3){
				 m->clearsystem();
			 }
			 if (ch == 4){
				 cout << "insert student's name after which to insert another student's data" << endl;
				 cin >> name;
				 cout << "new student's name" << endl;
				 cin >> name1;
				 cout << "registeration" << endl;
				 cin >> reg;
				 cout << "book name" << endl;
				 cin >> name2;
				 cout << "isbn" << endl;
				 cin >> isbn;
				 cout << "category" << endl;
				 cin >> category;
				 cout << "date" << endl;
				 cin >> date;
				 cout << "deadline" << endl;
				 cin >> deadline;
				 m->insertaftername(name, reg, name1, name2, isbn, category, date, deadline);
			 }
			 if (ch == 5){
				 cout << "reading file" << endl;
				 ifstream fin;
				 fin.open("student.txt", ios::in);
				 while (!fin.eof()){
					 char stop = '\0';
					 fin.getline(name, 10, ',');
					 fin >> reg;
					 m->insertstudent(reg, name);
					 while (stop != ':'){
						 fin >> isbn;
						 fin.ignore();
						 fin.getline(name1, 20, ',');
						 fin.getline(category, 10, ',');
						 fin.getline(date, 10, ',');
						 fin.getline(deadline, 10, ',');
						 fin >> stop;
						 fin.ignore();
						 m->insertbook(isbn, name1, category, date, deadline);
					 }
				 }
				 fin.close();
			 }
			 if (ch ==6 ){
				 cout << "enter name" << endl;
				 cin >> name2;
				 m->removebeforename(name2);
			 }
			 if (ch ==7 ){
				 cout << "Enter isbn" << endl;
				 cin >> isbn;
				 cout << "insert student's name after which to insert another student's data" << endl;
				 cin >> name;
				 cout << "new student's name" << endl;
				 cin >> name1;
				 cout << "registeration" << endl;
				 cin >> reg;
				 cout << "book name" << endl;
				 cin >> name2;
				 cout << "isbn" << endl;
				 cin >> isbn;
				 cout << "category" << endl;
				 cin >> category;
				 cout << "date" << endl;
				 cin >> date;
				 cout << "deadline" << endl;
				 cin >> deadline;
				 m->replaceviaisbn(isbn, reg, name1, name2, isbn, category, date, deadline);
			 }
			 if (ch == 8){
				 cout << "Enter location of node from which to show data" << endl;
				 char k;
				 cin >> k;
				 m->retrievek(k);
			 }
			 if (ch == 9){
				 cout << "Enter student reg" << endl;
				 cin >> reg;
				 m->searchprintreg(reg);
			 }
			 if (ch == 10){
				 cout << "Print by ascending" << endl;
				 m->assendsortlist();
			 }
			 if (ch ==11 ){
				 cout << "print descending" << endl;
				 m->descendsortlist();
			 }
			 cout << "Enter your choice" << endl;
			 cout << "Enter your choice" << endl;
			 cout << "1. Determine whether your System is empty." << endl;
			 cout << "2. Determine the size of the System." << endl;
			 cout << " 3. Destroy, or clear, the System." << endl;
			 cout << " 4. Insert an item in the System after the specified name." << endl;
			 cout << " 5. Insert data into System from a file" << endl;
			 cout << "6. Remove data from the Issuance System before the specified name." << endl;
			 cout << " 7. Replace data against the specified ISBN number with another set of data." << endl;
			 cout << " 8. Retrieve Book Name, Issuance Date, Return Deadline Date and Student Reg ID in the System from the kth location." << endl;
			 cout << "10. Print all the books issued by one student either in ascending order." << endl;
			 cout << "11. Print all the books issued by one student either in descending order." << endl;
			 cout << "12. When the program terminates, write the data in the address book to a disk using filing." << endl;
			 cin >> ch;
		 }
		 system("pause");
}
//	 void deleteNode(node *n){
//	 	node* temp1 = n->next;
//	 	if (n == NULL){
//	 		cout << "Link list empty" << endl;
//	 	}
//	 	else if (n->next == NULL){
//	 		n->data = NULL;
//	 		n->next = NULL;
//	 	}
//	 	else if (n->next != NULL){
//	 		n->data = temp1->data;
//	 		n->next = temp1->next;
//	 		delete[]temp1;
//	 	}
//	 }
//
//	 node *temp = head;
//	 int count = 0;
//	 while (temp->next != NULL){
//	 temp = temp->next;
//	 count++;
//	 }
//
//	 for (int i = 0; i<count; i++){
//	 	temp = temp1->next;
//	 	for (int j = i; j<count; j++){
//	 		if (temp->d->count> temp1->d->count){
//	 				swap(temp->data, temp1->data);
//	 				temp1 = head;
//	 				temp = temp1->next;
//	 				i = 0;
//	 				j = i;
//	 		}
//	 		 else
//	 		 {
//	 		 temp = temp->next;
//	 		 }
//
//	 	 }
//	 temp1 = temp1->next;
//	 }
//	 }
//	 
//	 void asssortlist(){
//	 node *temp = head;
//	 node *temp1 = head;
//	 int count = 0;
//	 while (temp->next != NULL){
//	 temp = temp->next;
//	 count++;
//	 }
//
//	 for (int i = 0; i<count; i++){
//	 temp = temp1->next;
//	 for (int j = i; j<count; j++){
//	 if (temp->data< temp1->data){
//	 swap(temp->data, temp1->data);
//	 temp1 = head;
//	 temp = temp1->next;
//	 i = 0;
//	 j = i;
//	 }
//	 else
//	 {
//	 temp = temp->next;
//	 }
//
//	 }
//	 temp1 = temp1->next;
//	 }
//	 }
//
//
//void displaylistftail(){
//node *temp = tail;
//while (temp->prev != NULL){
//cout << temp->data << endl;
//temp = temp->prev;
//
//}
//cout << temp->data << endl;
//}
