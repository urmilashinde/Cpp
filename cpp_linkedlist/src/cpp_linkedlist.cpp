//============================================================================
// Name        : cpp_linkedlist.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef struct Node{
	int data;
	Node* next;
} Node;

class List{

	Node* head;


public:
	void PrintList();
	void Push(int num);
	int Pop();
	int Length();
	void ReverseList();
	void ReverseList2();
	void InsertNth();
	void DeleteList();

	List();
	~List();

};

List::List()
{
	std::cout << "Constructor called" << std::endl;
	head = nullptr;
}

List::~List()
{
	std::cout << "Destructor called" << std::endl;
	DeleteList();
}

void List::PrintList()
{
	Node* temp_node = head;

	while(temp_node != nullptr)
	{
		std::cout<<temp_node->data << std::endl;
		temp_node = temp_node->next;
	}
}

void List::Push(int data)
{
	Node* new_node = new Node;

	new_node->data = data;
	new_node->next = head;

	head = new_node;
}

int List:: Pop()
{
	int data = 0;
	if( head == nullptr)
	{
		std::cout<<"List is empty"<<std::endl;
//		throw
	}
	else
	{
		Node* temp = head;
		data = head->data;
		head = head->next;
		delete temp;
	}

	return data;
}

int List::Length()
{
	int length = 0;
	if(head == nullptr)
	{
		std::cout<<"list is empty"<<std::endl;
	}
	else
	{
		Node *temp = head;
		while(temp != nullptr)
		{
			length++;
			temp = temp->next;
		}
	}

	return length;
}

void List::ReverseList2()
{

	Node* next = head->next;
	Node* current = head;
	Node* prev = head;

	while(current != nullptr)
	{
		next = current->next;
		if(current == head)
		{
			current->next = nullptr;
		}
		else
		{
			current->next = prev;
		}
		prev = current;
		current = next;

	}

	head = prev;
}
void List::ReverseList()
{
	Node* next = head->next;
	Node* current = head;
	Node* prev = head;

	if(head == nullptr)
		return;

	while(current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head->next = nullptr;
	head = prev;

}

void List::InsertNth()
{

}

void List::DeleteList()
{
	Node* temp = head;
	Node* current = head;

	while(temp != nullptr)
	{
		temp = current;
		current = current->next;
		delete temp;

	}

	head = nullptr;

}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	List mylist;

	std::cout<<"length of the list is "<< mylist.Length() << std::endl;

	for(int i=1; i<=5; i++)
	{
		mylist.Push(i);
	}

	mylist.PrintList();

	std::cout<<"Popping one element from list:"<<mylist.Pop() << std::endl;

	mylist.PrintList();

	mylist.ReverseList();

	mylist.PrintList();

	std::cout<<"length of the list is "<< mylist.Length() << std::endl;

	return 0;
}
