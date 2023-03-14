#include <iostream>
#include <iomanip>
#include <string>
#include "NumberListb.h"
using namespace std;

void NumberList::appendNode(string item, string buyer, string seller, float price)
{
	ListNode *newNode;  
	ListNode *nodePtr;  

	newNode = new ListNode;
	//newNode->value = num;
	newNode->item = item;
	newNode->buyer = buyer;
	newNode->seller = seller;
	newNode->price = price;
	newNode->next = nullptr;

	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

void NumberList::operator=(const NumberList &other)
{
	ListNode *listptr2;
	listptr2 = other.head;
	while (listptr2 != nullptr)
	{
		appendNode(listptr2->item, listptr2->buyer, listptr2->seller, listptr2->price);
		listptr2 = listptr2->next;
	}
}

void NumberList::displayList() const
{
	ListNode *nodePtr; 

	nodePtr = head;
	if (!nodePtr)
		cout << "No contents.\n";

	while (nodePtr)
	{
		//cout << nodePtr->value << endl;
		cout << setw(10) << nodePtr->item << nodePtr->buyer << nodePtr->seller << nodePtr->price << endl;

		nodePtr = nodePtr->next;
	}
}

void NumberList::insertNode(string item, string buyer, string seller, float price)
{
	ListNode *newNode;					
	ListNode *nodePtr;					
	ListNode *previousNode = nullptr;	

	newNode = new ListNode;
	newNode->item = item;
	newNode->buyer = buyer;
	newNode->seller = seller;
	newNode->price = price;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
		tail = newNode;
	}
	else 
	{
		nodePtr = head;

		previousNode = nullptr;

		//while (nodePtr != nullptr && nodePtr->value < num)
		while(nodePtr != nullptr)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr = nullptr)
		{
			tail->next = newNode;    
			tail = newNode;
			tail->next = nullptr;
		}
		else if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else  
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void NumberList::deleteNode(string item)
{
	ListNode *nodePtr;      
	ListNode *previousNode = nullptr;

	if (!head)
		return;

	if (head->item == item)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		//while (nodePtr != nullptr && nodePtr->value != num)
		while(nodePtr != nullptr)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		//if (tail->item == item) 
		if (tail->item == item)
		{ 
			tail = previousNode;    
			delete nodePtr;    
			nodePtr = nullptr;    
			tail->next = nullptr; 
		}
		
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void NumberList::findNode(string item)
{
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	if (!head)
		return;

	if (head->item == item)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		//while (nodePtr != nullptr && nodePtr->value != num)
		while (nodePtr != nullptr)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		//if (tail->item == item) 
		if (tail->item == item)
		{
			/*tail = previousNode;
			delete nodePtr;
			nodePtr = nullptr;
			tail->next = nullptr;*/
			cout << setw(10) << nodePtr->item << nodePtr->buyer << nodePtr->seller << nodePtr->price << endl;
		}
		else
			cout << "Error. Node not found.\n";

		if (nodePtr)
		{
			/*previousNode->next = nodePtr->next;
			delete nodePtr;*/
		}
	}
}

NumberList::~NumberList()
{
	ListNode *nodePtr; 
	ListNode *nextNode;  

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}
}
