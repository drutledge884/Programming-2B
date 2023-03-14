#pragma once
//#include <string>
class NumberList
{
private:
	struct ListNode
	{
		string item;
		string buyer;
		string seller;
		float price;
		struct ListNode *next;
	};

	ListNode *head;
	ListNode *tail;

public:
	NumberList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void operator=(const NumberList &other);

	~NumberList();

	void appendNode(string, string, string, float);
	void insertNode(string, string, string, float);
	void deleteNode(string);
	void displayList() const;

	/*double getValue()
	{
		ListNode myNode;
		return myNode.value;
	}*/

	void findNode(string item);

	ListNode* getNext()
	{
		ListNode myNode;
		return myNode.next;
	}
};

