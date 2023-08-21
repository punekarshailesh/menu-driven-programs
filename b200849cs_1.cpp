#include <iostream>
using namespace std;

class node{
	
public:
	char ch;
	node * next;


	// creating constructor
	node(char input){
		this->ch = input;
		this->next = NULL;
	}
};

node* list_search(node* &List, char y){
	if(List == NULL){
		return NULL;
	}

	node* temp = List;

	while(temp != NULL){
		if(temp->ch == y){
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

void list_insert_front(node* &List , char ip){
	
	if(List == NULL){
		List = new node(ip);
		return ;
	}

	node* newnode = new node(ip);
	newnode->next = List;
	List = newnode;
}	


void list_insert_tail(node* &List, char ip){
	if(List == NULL){
		List = new node(ip);
	}

	node* temp = List;

	while(temp->next != NULL){
		temp = temp->next;
	}

	node* newnode = new node(ip);
	temp->next = newnode;
	temp = newnode;

}

void list_insert_after(node* &List , char x , char y){
	node* temp = list_search(List , y);
	if(temp == NULL){
		return ;
	}

	node * newnode = new node(x);

	newnode->next = temp->next;
	temp->next = newnode;
}

void list_insert_before(node* &List , char x , char y){
	node* temp = list_search(List , y);
	if(temp == NULL || List == NULL){
		return ;
	}

	node* newnode = new node(x);
	if(temp == List){
		// insertion at 
		newnode->next = List;
		List = newnode;
		return ;
	} else {

		node* temp2 = List;

		while(temp2->next != temp){
			temp2 = temp2->next;
		}
		newnode->next = temp2->next;
		temp2->next = newnode;
		return ;
	}

}

void list_delete_first(node* &List){
	if(List == NULL){
		cout << "-1"  << endl;
		return ;
	}

	node* temp = List;
	cout << temp->ch << endl;
	List = List->next;
	temp->next = NULL;
	delete temp;
	return ;
}


void list_delete_last(node*&List){
	if(List == NULL){
		cout << "-1" << endl;
		return ;
	}

	if(List->next == NULL){
		// last node of the list
		cout << List->ch << endl;
		node* temp = List;
		delete temp;
		List = NULL;
		return ;
	}
	else{
		node* temp = List;
		while(temp->next->next != NULL){
			temp = temp->next;
		}	
		cout << temp->next->ch << endl;
		temp->next = NULL;
		return ;
	}
}


void list_delete(node* &List, char y){
	node* temp = list_search(List , y);
	if(temp == NULL || List == NULL){
		cout << "-1" << endl;
		return ;
	}

	if(temp == List && temp->next == NULL){
		// last node of the list
		List = NULL;
		delete temp;
		cout << "-2" << endl;
		return ;
	}
	else if(temp == List){
		// first node of the list
		cout << temp->next->ch << endl;
		List = List->next;
		temp->next = NULL;
		delete temp;
		return ;
	}
	else{

			node* temp2 = List;
			while(temp2->next != temp){
				temp2 = temp2->next;
			}
			if(temp2->next->next == NULL){
				// last node
				temp2->next = NULL;
				delete temp;
				cout << "-2" << endl;
				return ;
			}
			cout << temp->next->ch << endl;
			delete temp;
			return;
	}

	// cout << temp->ch << endl;
}

void print_list(node* &List){
	if(List == NULL){
		cout << "NULL" << endl;
		return ;
	}

	node * temp = List;
	while(temp){
		cout << temp->ch << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(){

	node *List = NULL;
	char opt;
	char input;
	while(1){
		cin >> opt;
		switch(opt){
		case 'f':
			cin >> input;
			list_insert_front(List , input);
			break;
		case 't':
			cin >> input;
			list_insert_tail(List , input);
			break;
		case 'a':
			char y;
			cin >> input >> y;
			list_insert_after(List , input , y);
			break;
		case 'b':
			char ch;
			cin >> input >> ch;
			list_insert_before(List , input ,ch);
			break; 
		case 'd':
			cin >> input;
			list_delete(List , input);
			break;
		case 'i':
			list_delete_first(List);
			break;
		case 'l':
			list_delete_last(List);
			break;
		case 'p':
			print_list(List);
			break;
		case 'e':
			exit(0);
		}
	}



	return 0;
}