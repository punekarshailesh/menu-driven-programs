#include <iostream>
using namespace std;



class Node{
public:
	int data;
	Node* prev;
	Node* next;

	// create constructor
	Node(int inp){
		data = inp;
		this->prev = NULL;
		this->next = NULL;
	}

};


Node* list_search(Node*&List , int search){
	Node* temp = List;
	while(temp){
		if(temp->data == search){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void list_insert_front(Node* &List , int inp){
	if(List == NULL){
		// head node
		List = new Node(inp);
		return ;
	}

	Node* newnode = new Node(inp);
	newnode->next = List;
	List->prev = newnode;
	List = newnode;
	return ;
}

void list_insert_tail(Node* &List, int inp){

	if(List == NULL){
		List = new Node(inp);
		return ;
	}

	Node* temp  = List;
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	Node* newnode = new Node(inp);
	temp->next = newnode;
	newnode->prev = temp;
	return ;
}

void list_insert_after(Node* &List, int inp, int search){
	Node* temp = list_search(List , search);
	if(temp == NULL || List == NULL){
		// key not found or list is empty
		return ;
	}

	Node* newnode = new Node(inp);

	temp->next->prev = newnode;
	newnode->next = temp->next;
	temp->next = newnode;
	newnode->prev = temp;
	return ;
}

void list_insert_before(Node* &List , int inp, int search){
	Node* temp = list_search(List, search);
	if(temp == NULL || List == NULL){
		// key not found or list is empty
		return ;
	}

	Node* newnode = new Node(inp);
	newnode->prev = temp->prev;
	temp->prev->next = newnode;
	newnode->next = temp;
	temp->prev = newnode;
	return ;
}

void list_delete_initial(Node* &List){
	if(List == NULL){
		cout << "Not Found" << endl;
		return ;
	}

	cout << List->data << endl;
	Node* temp = List;
	List = List->next;
	List->prev = NULL;
	temp->next = NULL;
	delete temp;
	return ;
}

void list_delete_last(Node* &List){
	if(List == NULL){
		cout << "Not Found" << endl;
		return ;
	}

	Node* temp = List;

	while(temp->next != NULL){
		temp = temp->next;
	}

	cout << temp->data << endl;
	temp->prev->next = NULL;
	temp->prev = NULL;
	delete temp;
	return ;
}

void list_delete(Node* &List, int search){
	Node* temp = list_search(List , search);
	if(temp == NULL || List == NULL){
		cout << "Not Found" << endl;
		return ;
	}

	if(temp->next == NULL){
		// last node is deleted
		cout << "NULL" << endl;
		temp->prev->next = NULL;
		temp->prev = NULL;
		delete temp;
		return ;
	}

	if(temp == List){
		// to delete the first node
		List = List->next;
		cout << List->data << endl;
		List->prev = NULL;
		temp->next = NULL;
		delete temp;
	}
	else
	{
		// temp is pointing on the node to be deleted
		cout << temp->next->data << endl;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp->next = NULL;
		temp->prev = NULL;
		delete temp;
	}

	return ;
}

void print_reverse(Node* &List, int search){
	Node* temp = list_search(List , search);
	if(temp == NULL){
		cout << "Not Found" << endl;
	}
	Node* temp2 = List;
	while(temp2 != temp){
		temp2 = temp2->next;
	}

	while(temp2 != NULL){
		cout << temp2->data << " ";
		temp2 = temp2->prev;
	}
	cout << endl;
}

int main(){

	Node* List = NULL;

	char opt;
	int data;
	int search;
	while(1){
		cin >> opt;
		switch(opt){
		case 'f':
			cin >> data;
			list_insert_front(List , data);
			break;
		case 't':
			cin >> data;
			list_insert_tail(List , data);
			break;
		case 'a':
			cin >> data >> search;
			list_insert_after(List, data , search);
			break;
		case 'b':
			cin >> data >> search;
			list_insert_before(List , data , search);
			break;
		case 'i':
			list_delete_initial(List);
			break;
		case 'l':
			list_delete_last(List);
			break;
		case 'd':
			cin >> search;
			list_delete(List , search);
			break;
		case 'r':
			cin >> search;
			print_reverse(List , search);
			break;
		case 'e':
			exit(0);
		}
	}
	return 0;
}