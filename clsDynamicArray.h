#pragma once
# include <iostream>
# include "clsDblLinkedList.h"

using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;


public:

	T* OriginalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
		{
			Size = 0;
		}

		_Size = Size;

		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index < 0 || Index >= _Size)
		{
			return false;
		}

		OriginalArray[Index] = Value;
		return true;

	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	int Size()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << *(OriginalArray + i) << " ";
			//or
			//cout << OriginalArray[i] << " ";

		}
		cout << "\n";
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
		{
			NewSize = 0;
		}

		_TempArray = new T[NewSize];

		// Limit Size of Original in case of the new size is less than the original
		if (NewSize < _Size)
		{
			_Size = NewSize;
		}

		// Assign values
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		// Expand Size in case of the new size is bigger than original size
		_Size = NewSize;

		delete[]OriginalArray;

		OriginalArray = _TempArray;
		// Note _TempArray and OriginalArray are pointing at the same address 
		// if you delete any of them now the address will disappear in both

	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[_Size - 1 - i];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int Index)
	{
		// Validation for index
		if (Index >= _Size || Index < 0)
		{
			return false;
		}

		_TempArray = new T[_Size - 1];
		_Size--;
		
		// copy all before index 
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		
		// copy all after index
		for (int i = Index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
			{
				return i;
			}
		}
		return -1;
	}

	bool DeleteItem(T Value)
	{
		int Index = Find(Value);
		if (Index == -1)
		{
			return false;
		}
		else
		{
			DeleteItemAt(Index);
			return true;
		}
	}

	bool InsertAt(int Index, T Value)
	{

		if (Index > _Size || Index < 0)
		{
			return false;
		}

		// update size
		_Size++;


		_TempArray = new T[_Size ];

		// Copy all items before index
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		// Add new element 
		_TempArray[Index] = Value;

		// Copy all that from index to the end
		for (int i = Index; i < _Size - 1; i++)
		{
			_TempArray[i+1] = OriginalArray[i];
		}
		
		
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}

	bool InsertBefore(int Index, T Value)
	{
		if (Index < 1)
		{
			return InsertAt(0 , Value);
		}
		else
		{
			return InsertAt(Index - 1, Value);
		}
	}


	bool InsertAfter(int Index, T Value)
	{
		if (Index < 0 || Index > _Size)
		{
			return false;
		}
		else
		{
			return InsertAt(Index + 1, Value);
		}
	}


};

