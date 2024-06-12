#include <iostream>

using namespace std;

class myVector
{
private:
	int* elements;
	int index;
	int capacity;
public:
	myVector()
	{
		capacity = 1;
		elements = new int[1];
		index = 0;
	}
	~myVector()
	{
		delete[] elements;
	}
	void push_back(int elem)
	{
		if (index < capacity)
		{
			elements[index] = elem;
		}
		else
		{
			// create new vector elements with double capacity
			int* temp = new int[capacity * 2];
		
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = elements[i];
			}
			// assign old values to new elements
			temp[index] = elem;
			capacity = capacity * 2;
			// delete old values
			delete[] elements;
			// return new elements with double sized.
			elements = temp;
		}
		index++;
	}
	void show()
	{
		for (int i = 0; i < index; i++)
		{
			cout << elements[i] << " ";
		}
		cout << endl;
		cout << "capacity = " << capacity << endl;
	}
};