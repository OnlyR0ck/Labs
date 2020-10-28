#include "Lab_three.h"

Set::Set()
{
	this->size = 1;
	arr = new int[size];
	arr[0] = 0;
}

Set::Set(int size)
{
	this->size = size;
	this->arr = new int[size];
}

Set::Set(int size, int* arr)
{
	this->size = size;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
	}
}

Set::Set(vector<int> arr)
{
	this->size = arr.size();
	this->arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = arr[i];
	}
}

Set::Set(const Set& my_object)
{
	this->size = my_object.size;
	this->arr = new int[this->size];

	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = my_object.arr[i];
	}
}

Set::~Set()
{
	delete[] arr;
}

void Set::set_set()
{
	cout << "Enter set's size: ";
	this->size = correct_user_input1();
	for (int i = 0; i < size; i++)
	{
		arr[i] = correct_user_input1();
	}
}

int* Set::get_set()
{
	return this->arr;
}

Set Set::operator&(const Set& object)
{
	sort(this->arr, this->arr + this->size);
	sort(object.arr, object.arr + object.size);
	vector<int> temp(this->size + object.size);
	vector<int>::iterator it;
	it = set_union(this->arr, this->arr + this->size, object.arr, object.arr + object.size, temp.begin());
	temp.resize(it - temp.begin());
	remove(temp);
	Set new_set(temp);
	return new_set;
}

Set Set::operator|(const Set& object)
{
	sort(this->arr, this->arr + this->size);
	sort(object.arr, object.arr + object.size);
	vector<int> temp(this->size + object.size);
	vector<int>::iterator it;
	it = set_intersection(this->arr, this->arr + this->size, object.arr, object.arr + object.size, temp.begin());
	temp.resize(it - temp.begin());
	Set new_set(temp);
	return new_set;
}

ostream& operator<<(ostream& out, const Set& set)
{
	out.clear();
	for (int i = 0; i < set.size; i++)
	{
		out << set.arr[i] << " ";
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Set& set)
{
	cout << "Enter set's size: ";
	set.size = correct_user_input1();
	cout << "Enter data: ";
	for (int i = 0; i < set.size; i++)
	{
		set.arr[i] = correct_user_input1();
	}
	return in;
}


void Menu()
{
	Set one, two, three;
	int code;
	while (true)
	{
		cout << "1 - Enter set's data.\n2 - Show sets.\n3 - Combine sets.\n4 - Cross sets.\n0 - Exit." << endl;
		cout << "Your choice : ";
		code = correct_user_input1();
		switch (code)
		{
		case 1:
			cin >> one;
			cin >> two;
			break;
		case 2:
			cout << "First: " << one;
			cout << "Second: " << two;
			_getch();
			break;
		case 3:
			cout << "Result: " << (one & two);
			_getch();
			break;
		case 4:
			cout << "Result: " << (one | two);
			_getch();
			break;
		case 0:
			exit(0);
			break;
		default:
			system("cls");
			break;
		}

		system("cls");
	}
}


int correct_user_input1()
{
	int value;
	while (!(cin >> value) or cin.get() != '\n')
	{
		cout << "Incorrect user input, try again : ";
		cin.clear();
		while (cin.get() != '\n');
	}
	return value;
}

void remove(vector<int>& v)
{
	auto end = v.end();
	for (auto it = v.begin(); it != end; ++it) {
		end = std::remove(it + 1, end, *it);
	}

	v.erase(end, v.end());
}