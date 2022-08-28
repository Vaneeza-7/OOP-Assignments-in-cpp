

#include<iostream>
#include"Array.h"
using namespace std;

Array::Array()
{
	Size = 0;
	array = NULL;
	array = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		*(array + i) = 0;
	}
}

Array::Array(int size)
{
	Size = size;
	array = NULL;
	array = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		*(array + i) = 0;
	}
}

Array::Array(int* arr, int size)
{
	Size = size;
	array = NULL;
	array = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		*(array + i) = *(arr + i);
	}
}

Array::Array(const Array& obj)
{
	Size = obj.Size;
	array = NULL;
	array = new int[Size];
	for (int i = 0; i < Size;i++)
	{
		array[i] = obj.array[i];
	}
}

int& Array::operator[](int i)
{
	if (i >= Size)
		return array[0];
	else
		return array[i];
}

int& Array::operator[](int i)const
{
	if (i >= Size)
		return array[0];
	else
		return array[i];
}

const Array& Array::operator=(const Array& obj)
{
	Size = obj.Size;
	for (int i = 0; i < Size; i++)
	{
		array[i] = obj.array[i];
	}
	//return obj;
	const Array objNew(array, Size);
	return objNew;

}

Array Array::operator+(const Array& obj)
{

	if (Size > obj.Size)
	{
		int* arr = NULL;
		arr = new int[Size];
		for (int i = 0; i < obj.Size; i++)
		{
			arr[i] = obj.array[i];
		}

		for (int i = obj.Size; i < Size; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < Size; i++)
		{
			arr[i] = arr[i]+array[i];
		}

		Array objNew(arr, Size);
		return objNew;
		delete[]arr;
		arr = NULL;
	}

else if (obj.Size > Size)
	{
		int* arr = NULL;
		arr = new int[obj.Size];

		for (int i = 0; i < Size; i++)
		{
			arr[i] = array[i];
		}

		for (int i = Size; i < obj.Size; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < obj.Size; i++)
		{
			arr[i] = arr[i]+obj.array[i];
		}
		Array objNew(arr, obj.Size);
		return objNew;
		delete[]arr;
		arr = NULL;
	}

	else
	{
		int* arr = NULL;
		arr = new int[Size];

		for (int i = 0; i < Size; i++)
		{
			arr[i] = array[i];
		}
		for (int i = 0; i < Size; i++)
		{
			arr[i] = arr[i]+ obj.array[i];
		}

		Array objNew(arr, Size);
		return objNew;
		delete[]arr;
		arr = NULL;
	}
	return obj;
}

Array Array::operator-(const Array& obj)
{

	if (Size > obj.Size)
	{
		int* arr = NULL;
		arr = new int[Size];

		for (int i = 0; i < obj.Size; i++)
		{
			arr[i] = obj.array[i];
		}

		for (int i = obj.Size; i < Size; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < Size; i++)
		{
			arr[i] = arr[i] - array[i];
		}

		Array objNew(arr, Size);
		return objNew;
		delete[]arr;
		arr = NULL;
	}

	else if (obj.Size > Size)
	{
		int* arr = NULL;
		arr = new int[obj.Size];

		for (int i = 0; i < Size; i++)
		{
			arr[i] = array[i];
		}

		for (int i = Size; i < obj.Size; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < obj.Size; i++)
		{
			arr[i] = arr[i] - obj.array[i];
		}
		Array objNew(arr, obj.Size);
		return objNew;
		delete[]arr;
		arr = NULL;
	}

	else
	{
		int* arr = NULL;
		arr = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			arr[i] = array[i];
		}
		for (int i = 0; i < Size; i++)
		{
			arr[i] = arr[i] - obj.array[i];
		}

		Array objNew(arr, Size);
		return objNew;
		delete[]arr;
		arr = NULL;
	}
	return obj;
}

Array Array::operator++() //prefix
{
	for (int i = 0; i < Size; i++)
	{
		++array[i];
	}

	Array objNew(array, Size);
	return objNew;
}

Array Array::operator++(int i) //postfix
{
	for (int i = 0; i < Size; i++)
	{
		array[i]++;
	}

	Array objNew(array, Size);
	return objNew;
}

Array& Array::operator--(int i) //postfix
{
	for (int i = 0; i < Size; i++)
	{
		array[i]--;
	}

	Array objNew(array, Size);
	return objNew;
}

bool Array::operator==(const Array& obj)const
{
	bool flag = true;
	for (int i = 0; i < Size; i++)
	{
		if (array[i] != obj.array[i])
			flag = false;
	}
	return flag;
}

bool Array::operator!()
{
	bool flag = true;
	for (int i = 0; i < Size; i++)
	{
		if (array[i] != 0)
			flag = false;
	}
	return flag;
}

void Array::operator+=(const Array& obj)
{
	if (Size > obj.Size)
	{
		int* arr = NULL;
		arr = new int[Size];

		for (int i = 0; i < obj.Size; i++)
		{
			arr[i] = obj.array[i];
		}

		for (int i = obj.Size; i < Size; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < Size; i++)
		{
			arr[i] = arr[i] + array[i];
		}

		array = arr;
		Size = Size;
	}

	else if (obj.Size > Size)
	{
		int* arr = NULL;
		arr = new int[Size];

		for (int i = 0; i < Size; i++)
		{
			arr[i] = array[i];
		}

		for (int i = Size; i < obj.Size; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < obj.Size; i++)
		{
			arr[i] = arr[i] + obj.array[i];
		}
		
		array = arr;
		Size = obj.Size;
		
	}

	else
	{
		int* arr = NULL;
		arr = new int[Size];

		for (int i = 0; i < Size; i++)
		{
			arr[i] = array[i];
		}
		for (int i = 0; i < Size; i++)
		{
			arr[i] = arr[i] + obj.array[i];
		}

		array = arr;
		Size = obj.Size;
		
	}
}

int Array::operator()(int idx, int val)
{
	for (int i = 0; i < Size; i++)//copy this array into another by deleting that element, then shift newArray to the left
	{
		if (i == idx && array[i] == val)
			array[i] = array[i + 1];

	}
	return 1;
}

void Array::operator-=(const Array& obj)
{
	if (Size > obj.Size)
	{
		int* arr = NULL;
		arr = new int[Size];

		for (int i = 0; i < obj.Size; i++)
		{
			arr[i] = obj.array[i];
		}

		for (int i = obj.Size; i < Size; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < Size; i++)
		{
			arr[i] = arr[i] - array[i];
		}

		array = arr;
		Size = Size;
	}

	else if (obj.Size > Size)
	{
		int* arr = NULL;
		arr = new int[Size];

		for (int i = 0; i < Size; i++)
		{
			arr[i] = array[i];
		}

		for (int i = Size; i < obj.Size; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < obj.Size; i++)
		{
			arr[i] = arr[i] - obj.array[i];
		}

		array = arr;
		Size = obj.Size;

	}

	else
	{
		int* arr = NULL;
		arr = new int[Size];

		for (int i = 0; i < Size; i++)
		{
			arr[i] = array[i];
		}
		for (int i = 0; i < Size; i++)
		{
			arr[i] = arr[i] - obj.array[i];
		}

		array = arr;
		Size = obj.Size;

	}
}

Array::~Array()
{
	delete[]array;
	array = NULL;
}

ostream& operator<<(ostream& output, const Array& obj) //Outputs the Array
{
	for(int i=0; i<obj.Size; i++)
	output << obj.array[i] << " ";
	return output;
}


istream& operator>>(istream& input, Array& obj) //Inputs the Array
{
	for (int i = 0; i < obj.Size; i++)
		input >> obj.array[i];
	return input;

}
