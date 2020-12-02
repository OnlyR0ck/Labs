#include "Stack.h"

template<class T>
inline Stack<T>::Stack(const Stack<T>& other)
{
	typename forward_list<T>::iterator begin = other.list.begin();
	typename forward_list<T>::iterator end = other.list.end();

	while(begin!=end)
	{
		this->list.push_front(*begin);
		++begin;
	}
	topPtr = &this->list.front();
}

template<class T>
Stack<T>::~Stack()
{
	this->list.clear();
}

template<class T>
void Stack<T>::pop()
{
	this->list.pop_front();
	topPtr = &this->list.front();
}

template<class T>
void Stack<T>::push(const T& obj)
{
	this->list.push_front(obj);
	topPtr = &this->list.front();
}

template<class T>
const T& Stack<T>::peek(int n)
{
	int ind = 0;
	auto begin = this->list.begin();
	auto end = this->list.end();
	while (begin != end)
	{
		if (ind == n) return *(begin);
		ind++;
		begin++;
	}
	
	cout << "The index is out of range" << endl;
	return NULL;
}

template<class T>
int Stack<T>::size() const
{
	int size = 0;
	auto begin = this->list.begin();
	auto end = this->list.end();
	while (begin != end)
	{
		begin++;
		size++;
	}
	return size;
}

template<class T>
bool Stack<T>::empty()
{
	return this->list.empty();
}

template<class T>
const T& Stack<T>::top() const
{
	return this->list.front();
}

template<class T>
void Stack<T>::operator+=(T& other)
{
	this->list.push_front(other);
	topPtr = &this->list.front();
}

template<class T>
void Stack<T>::toFile()
{
	fstream fout;
	fout.open("stack", ios::app);
	if(fout.is_open())
	{
		int size = this->size();
		for(int i = 0;i<size;i++)
		{
			fout << this->peek(i) << " ";
		}
		fout << endl;
	}
	fout.close();
}

template <class T>
ostream& operator<<(ostream& out, const Stack<T>& list)
{
	auto begin = list.begin();
	auto end = list.end();
	while (begin != end)
	{
		out << (*begin) << " ";
		begin++;
	}
	return out;
}
