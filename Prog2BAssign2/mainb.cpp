#include <iostream>
#include <iomanip>
#include <string>
#include "NumberListb.h"
using namespace std;

int menu(NumberList &list);

int main()
{
	NumberList list;
	int choice = 0;
	//char item[5], buyer[10], seller[10];
	//float price;

	choice = menu(list);
	while (choice != 1)
	{
		choice = menu(list);
	}
	
	int ducktape;
	cin >> ducktape;
	return 0;
}

int menu(NumberList &list)
{
	string item, buyer, seller;
	float price;
	int choice;
	cout << "Enter 1 to insert a node.\n";
	cout << "Enter 2 to delete a node.\n";
	cout << "Enter 3 to print the list.\n";
	cout << "Enter 4 to find a node.\n";
	cout << "Enter 5 to end program.\n";
	cin >> choice;
	cout << "===========================================\n";

	if (choice == 1)
	{
		cout << "Enter the item ID.\n";
		cin >> item;
		cout << "Enter the buyers name.\n";
		cin >> buyer;
		cout << "Enter the sellers name.\n";
		cin >> seller;
		cout << "Enter the final bidding price.\n";
		cin >> price;
		//list.insertNode(item, buyer, seller, price);
		list.appendNode(item, buyer, seller, price);
		cout << "The node was added.\n";
		cout << "===========================================\n";
		return 0;
	}
	if (choice == 2)
	{
		cout << "Enter the item ID of the node to be deleted.\n";
		cin >> item;
		list.deleteNode(item);
		cout << "The node was deleted.\n";
		cout << "===========================================\n";
		return 0;
	}
	if (choice == 3)
	{
		cout << "List Contents:\n";
		list.displayList();
		cout << "===========================================\n";
		return 0;
	}
	if (choice == 4)
	{
		cout << "Enter the item ID of the node to be searched.\n";
		cin >> item;
		list.findNode(item);
		cout << "===========================================\n";
		return 0;
	}
	if (choice == 5)
		return 1;
}