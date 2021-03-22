#include<iostream>
using namespace std;

struct node
{
	node* leftChild;
	node* rightChild;
	int data;
};

void preOrder(node* ptr)
{
	if (ptr)
	{
		cout << ptr->data << " ";
		preOrder(ptr->leftChild);
		preOrder(ptr->rightChild);
	}
}

void inOrder(node* ptr)
{
	if (ptr)
	{
		inOrder(ptr->leftChild);
		cout << ptr->data << " ";
		inOrder(ptr->rightChild);
	}
}

void postOrder(node* ptr)
{
	if (ptr)
	{
		postOrder(ptr->leftChild);
		postOrder(ptr->rightChild);
		cout << ptr->data << " ";
	}
}

int main()
{
	node* tree = new node[16];

	for (int i = 1; i <= 15; i++)
	{
		tree[i].data = i + 1;
		tree[i].leftChild = NULL;
		tree[i].rightChild = NULL;
	}

	for (int i = 1; i <= 15; i++)
	{
		if (i % 2 == 0)
		{
			tree[i / 2].leftChild = &tree[i];
		}
		else
		{
			tree[i / 2].rightChild = &tree[i];
		}
	}

	postOrder(&tree[1]);

	return 0;
}