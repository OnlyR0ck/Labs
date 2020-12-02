#include "HelperLib.h"
#include "Stack.h"
#include "Stack.cpp"

namespace LabWork7
{
	Stack<int> nums;

	void Push()
	{
		int n;
		cout << "Enter new num to push it to the stack : ";
		n = correct_user_input();
		nums.push(n);
	}

	void Pop()
	{
		nums.pop();
	}

	void Peek()
	{
		cout << "Enter num which you want to access : ";
		int num = correct_user_input();
		cout << nums.peek(num) << endl;
	}

	void getSize()
	{
		cout << "Size of stack is : " << nums.size();
	}

	void showStack()
	{
		/*int size = nums.size();
		for(int i = 0;i<size;i++)
		{
			cout << nums.peek(i) << endl;
		}*/
		cout << nums;
	}

	void WriteToFile()
	{
		nums.toFile();
	}
}

int main()
{

	delegate* delegateArr = new delegate[6];
	delegateArr[0] = LabWork7::Push;
	delegateArr[1] = LabWork7::Pop;
	delegateArr[2] = LabWork7::Peek;
	delegateArr[3] = LabWork7::getSize;
	delegateArr[4] = LabWork7::showStack;
	delegateArr[5] = LabWork7::WriteToFile;
	auto* const names = new string[7];
	names[0] = "Add element";
	names[1] = "Remove top";
	names[2] = "Show element by number";
	names[3] = "Show stack size";
	names[4] = "Show stack";
	names[5] = "Write stack to file";
	names[6] = "Exit";
	Menu(delegateArr, 7, names);
	
	return 0;
}