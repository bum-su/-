#include<iostream>
using namespace std;

struct node
{
	node* next;
	int number;
};

bool isEmpty(node *head);
char menu();
int return_length(node *head);
void insertAsFirstElement(node *&head, node*&tail, int number);
void insert(node *&head, node *&tail, int number, int Case, int mid);
void remove(node *&head, node *&tail, int Case, int mid);
void showList(node *&head);

bool isEmpty(node *head)
{
	if (head == NULL)
		return true;
	else
		return false;
}

char menu(void)
{
	char choice;

	cout << "select menu\n";
	cout << "1. insert node\n";
	cout << "2. remove node\n";
	cout << "3. showlist\n";
	cout << "4. exit\n";

	cin >> choice;

	return choice;
}

int return_length(node *head)
{
	int count = 0;
	while (head != NULL)
	{
		head = head->next;
		count++;
	}
	return count;
}

void insertAsFirstElement(node *& head, node *& tail, int number)
{
	node *newNode = new node;

	newNode->number = number;
	newNode->next = NULL;
	head = newNode;
	tail = newNode;
}

void insert(node *&head, node *&tail, int number, int Case, int mid)
{
	node *newNode = new node;
	node *temp = head;
	if (isEmpty(head))
		insertAsFirstElement(head, tail, number);
	else if (head == tail || Case == 1 || mid == 0)
	{
		newNode->number = number;
		newNode->next = head;
		head = newNode;
	}
	else if (Case == 2) // tail
	{
		newNode->next = NULL;
		newNode->number = number;
		tail->next = newNode;
		tail = newNode;
	}
	else
	{
		for (int i = 0; i < mid - 1; i++)
			temp = temp->next;

		newNode->number = number;
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void remove(node *&head, node *&tail, int Case, int mid)
{
	if (isEmpty(head))
		cout << "This is already empty\n";
	else if (head == tail || (Case == 3 && mid == 0)) {
		delete head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		node *temp = head;
		if (Case == 1)
		{
			head = temp->next;
		}
		else if (Case == 2)
		{
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = NULL;
			tail = temp;
		}
		else
		{
			for (int i = 0; i < mid - 1; i++) {
				temp = temp->next;
			}
			temp->next = temp->next->next;
			temp->next->next = NULL;
		}
	}
}

void showList(node *&head)
{
	node *temp = head;
	for (int i = 0; i < return_length(head); i++)
	{
		cout << temp->number << " -> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

int main(void)
{
	node *head = NULL;
	node *tail = NULL;

	int number, insert_case, insert_mid = 1, remove_case, remove_mid = 0;
	char choice;

	do
	{
		choice = menu();

		switch (choice)
		{
		case '1':
			cout << "please enter number\n";
			cin >> number;
			cout << "please enter Case\n";
			cout << "1. insert head node\n";
			cout << "2. insert tail node\n";
			cout << "3. insert mid node\n";
			cin >> insert_case;
			if (insert_case < 4 && 0 < insert_case)
			{
				if (insert_case == 1 || insert_case == 2)
				{
					insert(head, tail, number, insert_case, insert_mid);
					break;
				}
				else
				{
					cin >> insert_mid;
					if (insert_mid < 0 || insert_mid > return_length(head) - 1)
					{
						cout << "out of range\n";
						break;
					}
					else
					{
						insert(head, tail, number, insert_case, insert_mid);
						break;
					}
				}
			}
			insert(head, tail, number, insert_case, insert_mid);
			break;
		case '2':
			cout << "1. remove head node\n";
			cout << "2. remove tail node\n";
			cout << "3. remove mid node\n";
			cin >> remove_case;
			if (remove_case < 4 && 0 < remove_case)
			{
				if (remove_case == 2 || remove_case == 1)
				{
					remove(head, tail, remove_case, remove_mid);
					break;
				}
				else
				{
					cin >> remove_mid;
					if (remove_mid > return_length(head) - 1 || remove_mid < 0)
					{
						cout << "out of range\n";
						break;
					}
					else
						remove(head, tail, remove_case, remove_mid);
					break;
				}
			}
			else
				break;
		case '3':
			showList(head);
			break;
		default:
			cout << "System exit\n";
		}
	} while (choice != '4');

	return 0;
}