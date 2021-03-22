#include<iostream>
using namespace std;

template<typename T>
class queue
{
private:
	T* _arr;
	int _size;
	int _rear;
	int _front;

public:
	queue() {}
	queue(int size)
	{
		_rear = 0;
		_front = 0;
		_size = size;
		_arr = new T[_size];
	}

	int getRear()
	{
		return _rear;
	}

	T* getArr()
	{
		return _arr;
	}

	bool isFull()
	{
		if (_rear == _size)
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
		if (_rear == 0)
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
			_arr[_rear++] = data;
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
			for (int i = 0; i < _rear - 1; i++)
			{
				_arr[i] = _arr[i + 1];
			}
			_arr[_rear] = NULL;
			_rear--;
		}
		else
		{
			cout << "Empty\n";
		}
	}

	T& operator[](int index)
	{
		return _arr[index];
	}
};

template<typename T>
ostream& operator <<(ostream& out, queue<T>& q)
{
	T* temp = q.getArr();

	out << "Front [ ";

	for (int i = 0; i < q.getRear(); i++)
	{
		out << temp[i];

		if (i < q.getRear() - 1) out << " | ";
	}
	out << " ] Rear\n";

	return out;
}

int main()
{
	queue<int> q(5);

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	cout << q;

	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();

	cout << q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	q[0] = 1000;

	cout << q;

	return 0;
}