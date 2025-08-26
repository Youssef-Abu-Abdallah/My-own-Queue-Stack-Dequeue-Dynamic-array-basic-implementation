#pragma once
# include <iostream>
using namespace std;

template <class T> 
class clsDblLinkedList
{

protected:
	int _Size = 0;
	
public:

	class Node {
	public:
		T Value;
		Node* next;
		Node* prev;
	};

	Node* head = NULL;

	void InsertAtBeginning(T Value)
	{
		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->next = head;
		NewNode->prev = NULL;

		if (head != NULL)
		{
			head->prev = NewNode;
		}

		head = NewNode;
		_Size++;
	}

	void PrintList()
	{
		Node* Current = head;

		while (Current != NULL)
		{
			cout << Current->Value << " ";
			Current = Current->next;
		}
		cout << "\n";
		delete Current;
	}

	Node* Find(T Value)
	{
		Node* Current = head;
		while (Current != NULL)
		{
			if (Current->Value == Value)
			{
				return Current;
			}
			Current = Current->next;
		}
		return NULL;
	}

	void InsertAfter(Node* Current, T Value)
	{
		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->next = Current->next;
		NewNode->prev = Current;

		if (Current->next != NULL)
		{
			Current->next->prev = NewNode;
		}
		Current->next = NewNode;
		_Size++;

	}

	void InsertAtEnd(T Value)
	{
		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->next = NULL;

		if (head == NULL)
		{
			NewNode->prev = NULL;
			head = NewNode;
		}
		else
		{
			Node* Current = head;
			while (Current->next != NULL)
			{
				Current = Current->next;
			}
			Current->next = NewNode;
			NewNode->prev = Current;
		}
		
		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
		{
			return;
		}

		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}

		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}

		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{
		if (head == NULL)
		{
			return;
		}
		Node* Temp = head;
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		delete Temp;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
		{
			return;
		}
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_Size = 0;
			return;
		}
		Node* Current = head;
		while (Current->next->next != NULL)
		{
			Current = Current->next;
		}
		
		Node* temp = Current->next;
		Current->next = NULL;
		
		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void Clear()
	{
		while (_Size > 0)
		{	
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		if (head->next == NULL || head == NULL)
		{
			return;
		}
		Node* Current = head;
		Node* Temp = nullptr;

		while (Current != nullptr)
		{
			Temp = Current->prev;
			Current->prev = Current->next;
			Current->next = Temp;
			Current = Current->prev;
		}

		if (Temp != nullptr)
		{
			head = Temp->prev;
		}

	}

	Node* GetNode(int Index)
	{
		int Counter = 0;
		if (Index > _Size-1 || Index < 0)
		{
			return NULL;
		}
		Node* Current = head;
		while (Current != NULL && (Current->next != NULL))
		{
			if (Counter == Index)
			{
				break;
			}
			Counter++;
			Current = Current->next;
		}
		return Current;
	}

	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode == NULL)
		{
			return NULL;
		}
		else
		{
			return ItemNode->Value;
		}
	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL)
		{
			ItemNode->Value = NewValue;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool InsertAfter(int Index, T Value)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, Value);
			return true;
		}
		else
		{
			return false;
		}
	}



};

