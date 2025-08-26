#pragma once

# include <iostream>
# include <stack>

using namespace std;

class clsMyString
{
private:
	string _Value = "";

	stack <string> _stUndo;
	stack <string> _stRedo;



public:

	string GetValue()
	{
		return _Value;
	}

	void SetValue(string Value)
	{
		_stUndo.push(_Value);
		_Value = Value;
	}

	__declspec (property(get = GetValue, put = SetValue)) string Value;

	void Undo()
	{
		if (!_stUndo.empty())
		{
			_stRedo.push(_Value);
			_Value = _stUndo.top();
			_stUndo.pop();
		}
	}

	void Redo() 
	{
		if (!_stRedo.empty())
		{
			_stUndo.push(_Value);
			_Value = _stRedo.top();
			_stRedo.pop();
		}
		
	}

};

