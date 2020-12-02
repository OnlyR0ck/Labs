#pragma once
#include <iostream>
#include <fstream>
#include <forward_list>
#ifndef _stack_h_
#define _stack_h_

using namespace std;

template <class T>
class Stack
{
private:
	forward_list<T> list;
	T* topPtr;
	
public:
	Stack()  {}
	Stack(const Stack<T>&);
	~Stack();
	
	void pop();
	void push(const T&);
	const T& peek(int);
	int size() const;
	bool empty();
	const T& top() const;
	void operator+=(T&);
	void toFile();

	friend ostream& operator<<(ostream&, const Stack<T>&);
};
#endif

