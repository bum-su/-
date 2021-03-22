#include<iostream>
using namespace std;

struct Node {
	int data;
    Node* next;
	Node* prev;
};

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

	// varaibles inialization
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void deleteNode(Node * Node)
{
	free(Node);
}

Node* getNodeAt(Node* head, int index)
{
	Node* node = head;
	int count = 0;
	while (node != NULL)
	{
		if (count++ == index)
		{
			return node;
		}
		node = node->next;
	}
	return NULL;
}

int countNode(Node* head)
{
	int count = 0;
	Node* node = head;

	while (node != NULL)
	{
		node = node->next;
		count++;
	}
	return count;
}

void addNode(Node** head, Node* newNode)
{
	// no list exists
	if ((*head) == NULL)
	{
		*head = newNode;
	}

	// list exists
	else
	{
		Node* node = (*head);
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = newNode;
		newNode->prev = node;
	}
}

void insertAfter(Node* Current, Node* newNode)
{
	//head
	if (Current->prev == NULL && Current->next == NULL)
	{
		Current->next = newNode;
		newNode->prev = Current;
	}

	//not head
	else {
		//if tail
		if (Current->next == NULL)
		{
			Current->next = newNode;
			newNode->prev = Current;
		}
		//in the middle of 2 nodes
		else
		{
			Current->next->prev = newNode;
			newNode->next = Current->next;
			Current->next = newNode;
			newNode->prev = Current;
		}
	}
}

void removeNode(Node** head, Node* remove)
{
	// head
	if (*head == remove)
	{
		*head = remove->next;
	}

	//when remove has next link to go
	if (remove->next != NULL)
	{
		remove->next->prev = remove->prev;
	}

	// when remove has prev link to go
	if (remove->prev != NULL)
	{
		remove->prev->next = remove->next;
	}
	deleteNode(remove);
}

void print(Node *head)
{
	Node *node = head;
	while (node != NULL)
	{
		cout << node->data << "->";
		node = node->next;
	}
	cout << "NULL\n";
}

int main()
{
	Node *list = NULL;
	Node *newNode = NULL;
	Node *Curr = NULL;

	int Case;
	int number, index;

	do
	{
		cout << "1. Add Node\n";
		cout << "2. insert After\n";
		cout << "3. remove node\n";
		cout << "4. print node\n";
		cout << "0. System exit\n";

		cin >> Case;

		switch (Case)
		{
		case 1:
			cout << "please enter number : ";
			cin >> number;
			newNode = createNode(number);
			addNode(&list, newNode);
			break;
		case 2:
			cout << "please enter number : ";
			cin >> number;
			cout << "please enter index : ";
			cin >> index;
			newNode = createNode(number);
			Curr = getNodeAt(list, index);
			insertAfter(Curr, newNode);
			break;
		case 3:
			cout << "please enter index : ";
			cin >> index;
			newNode = getNodeAt(list, index);
			removeNode(&list, newNode);
			break;
		case 4:
			print(list);
			break;
		}
	} while (Case != 0);
}