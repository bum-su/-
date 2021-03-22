#include<iostream>
using namespace std;

template<typename T>
class stack
{
private:
	T* _arr;
	int _size;
	int _top;

public:
	stack() {}
	stack(int size)
	{
		_size = size;
		_arr = new T[_size];
		_top = 0;
	}

	T* getArr()
	{
		return _arr;
	}

	int getTop()
	{
		return _top;
	}

	bool isFull()
	{
		if (_top == _size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty()
	{
		if (_top == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void push(int data)
	{
		if (!isFull())
		{
			_arr[_top++] = data;
		}
		else
		{
			cout << "FULL\n";
		}
	}

	void pop()
	{
		if (!isEmpty())
		{
			_arr[_top - 1] = NULL;
			_top--;
		}
		else
		{
			cout << "EMPTY\n";
		}
	}
};

template<typename T>
ostream& operator << (ostream& out, stack<T>& s)
{
	T *temp = s.getArr();

	out << "Front [ ";

	for (int i = 0; i < s.getTop(); i++)
	{
		out << temp[i];
		if (i < s.getTop() - 1) out << " | ";
	}
	out << " ] Top\n";

	return out;
}

int main()
{
	stack<int> s(5);

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);

	cout << s;

	s.pop();

	cout << s;

	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	cout << s;

	return 0;
}