#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct node
{
	string data;
	node* next;
	node* prev;
};

float nodenum = 1, count = 1;
string nodedata;
int op;
node* n;
node* head;
node* temp;
node* temp2;

void Display();
void Append();
void Remove();
void Insert();
void Clear();
void InsertAtHead();
void InsertAtTail();

int main()
{


		n = new node;
		head = n;
		temp = n;
		temp2 = n;
		n->prev = NULL;
		n->next = NULL;
		cout << "Data Stored In the First Node: ";
		getline(cin,n->data);
		system("CLS");
		do
		{
			cout << "\t\t\t\t\tDoubly Linked List\n\n";
			cout << "Choose From The Following: \n";
			cout << "1. Append\n";
			cout << "2. Display\n";
			cout << "3. Remove\n";
			cout << "4. Insert\n";
			cout << "5. Insert at head\n";
			cout << "6. Insert at Tail\n";
			cout << "Any Key to Exit\n";

			cin >> op;
			Clear();

			switch (op)
			{
			case 1:
			{
				Append();
				Clear();
				break;
			}
			case 2:
			{
				Display();
				Clear();
				break;
			}
			case 3:
			{
				Remove();
				Clear();
				break;
			}
			case 4:
			{
				Insert();
				Clear();
				break;
			}
			case 5:
			{
				InsertAtHead();
				Clear();
				break;
			}
			case 6:
			{
				InsertAtTail();
				Clear();
				break;
			}
			default:
			{
				exit;
				break;
			}

			}
		} while (op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6);
}
void Append()
{

		n = new node;
		temp->next = n;
		n->prev = temp;
		temp = temp->next;
		cin.ignore();
		cout << "Data in the node: ";
		getline(cin,n->data);
		n->next = NULL;
}

void Display()
{
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

void Remove()
{
	cout << "\nRemoving\n";
up:
	temp = head;
	cout << "1. Remove by node number\n";
	cout << "2. Remove by node data\n";;
	cin >> op;
	switch (op)
	{
	case 1:
	{
		heaven:
		float count = -1;
	START:
		cout << "Which node do you want to remove? ";
		cin >> nodenum;
		temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		if (count < nodenum)
		{
			cout << "Data at this index doesn't exist.\n";
			cout << "Choose between 0 and " << count << endl;
			goto heaven;
		}
		count = 0;
		temp = head;
		while (count < nodenum)
		{
			temp = temp->next;
			count++;
		}
		if (temp->next == NULL)
		{
			temp->prev->next = NULL;
			temp = head;
		}
		if (temp->prev == NULL)
		{
			head = temp->next;
			temp->next->prev = NULL;
			temp = head;
		}
		else if(temp->prev != NULL || temp->next != NULL)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		delete(temp);
		break;
	}
	}

}

void Insert()
{
	hell:
	float nodenum, nodedata, count = 0;
	cout << "\nInserting\n";
	temp = head;
	n = new node;
	cout << "At which node do you want to insert the node? ";
	cin >> nodenum;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	if (count < nodenum)
	{
		cout << "Invalid Index.";
		cout << "Choose between 0 and " << count << endl;
		Clear();
		goto hell;
	}
	count = 1;
	temp = head;
	cin.ignore();
	cout << "Data to be stored on this node: ";
	getline(cin,n->data);
	while (count != nodenum)
	{
		temp = temp->next;
		count++;
	}
	n->next = temp->next;
	temp->next = n;
	n->prev = temp;
	temp->next->prev = n;
}

void InsertAtHead()
{
	n = new node;
	cin.ignore();
	cout << "Data to be stored on this node: ";
	getline(cin,n->data);
	n->next = head;
	head->prev = n;
	n->prev = NULL;
	head = n;
}

void InsertAtTail()
{
	n = new node;
	cin.ignore();
	cout << "Data to be stored on this node: ";
	getline(cin,n->data);
	n->next = NULL;
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
}
void Clear()
{
	system("pause");
	system("CLS");
}