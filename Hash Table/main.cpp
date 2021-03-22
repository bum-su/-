#include<iostream>
#define SIZE 10;
using namespace std;

struct bucket* HashTable = NULL;

struct node
{
	int key;
	int value;
	node* next;
};

struct bucket
{
	node* head;
	int count;
};

bool isEmpty(node* head)
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}

int hashFunc(int key)
{
	return key % SIZE;
}

node* createNode(int key, int value)
{
	node* newNode = (node*)malloc(sizeof(node));

	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void insert(int key, int value)
{
	int hashIndex = hashFunc(key);
	node* newNode = createNode(key, value);
	node* temp = HashTable[hashIndex].head;

	HashTable[hashIndex].count++;

	if (isEmpty(temp))
	{
		HashTable[hashIndex].head = newNode;
	}
	else
	{
		newNode->next = HashTable[hashIndex].head;
		HashTable[hashIndex].head = newNode;
	}
}

void remove(int key)
{
	int hashIndex = hashFunc(key);
	node* temp = HashTable[hashIndex].head;
	node* trace = (node*)malloc(sizeof(node));

	if (isEmpty(temp))
	{
		cout << "NOTHING\n";
	}
	else
	{
		if (temp->key == key)
		{
			HashTable[hashIndex].head = temp->next;
			HashTable[hashIndex].count--;
		}
		while (temp != NULL)
		{
			if (temp->key == key)
			{
				trace->next = temp->next;
				HashTable[hashIndex].count--;
			}
			trace = temp;
			temp = temp->next;
		}
	}
	free(temp);
	free(trace);
}

void print()
{
	for (int i = 0; i < 10; i++)
	{
		node* temp = HashTable[i].head;

		cout << "[ " << i << " ] : ";
		while (temp != NULL)
		{
			cout << "(key : " << temp->key << ", data : " << temp->value << ") -> ";
			temp = temp->next;
		}
		cout << "\n\n";
	}
}

int main()
{
	HashTable = (struct bucket*)calloc(10, sizeof(struct bucket));

	insert(10, 1);
	insert(20, 2);
	insert(30, 3);

	print();

	cout << "\n\n";

	remove(10);
	remove(20);
	remove(30);

	print();

	remove(40);

	return 0;
}