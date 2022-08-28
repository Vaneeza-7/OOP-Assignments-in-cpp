/************************VANEEZA AHMAD***********
						  21I-0390
						  Section A
************************************************/



#include<iostream>
#include"Sequence.h"
using namespace std;

Sequence::Sequence()
{
	length = 10;
	pseq = new int[length];
	for (int i = 0; i < length; i++)
	{
		*(pseq + i) = 0;
	}
}

Sequence::Sequence(int lengthVal, int n1, int n2, int n3, int n4, int n5, int n6, int n7,
	int n8 , int n9 , int n10 )
{
	length = lengthVal;
	pseq = new int[10];
	pseq[0]=n1;
	pseq[1]=n2;
	pseq[2]=n3;
	pseq[3]=n4;
	pseq[4]=n5;
	pseq[5]=n6;
	pseq[6]=n7;
	pseq[7]=n8;
	pseq[8]=n9;
	pseq[9]=n10;

}

Sequence::Sequence(const Sequence& s)
{
   length = s.length;
   pseq = new int[length];               //creating deep copy
   int* temp = s.pseq;
   for (int i = 0; i < length; i++)
   {
	   pseq[i] = temp[i];
   }

}

int Sequence::getLength()
{
	return length;
}

int* Sequence:: getSeq()
{
	return pseq;
}

void Sequence::Sort(int n)
{
	int start = *(pseq + 0);
	int end = n;

	quickSort(pseq, start, end);

}

void quickSort(int* arr, int start, int end)
{
	if (start < end)
	{
		int P = partition(arr, start, end);
		quickSort(arr, start, P - 1);        //recursive call for left and right sorting
		quickSort(arr, P + 1, end);
	}
}

int partition(int* arr, int start, int end)
{
	int pivot = arr[end];                    //setting last element as pivot
	int pIndex = start;
	for (int i = start; i < end; i++)
	{
		if (*(arr+i) < pivot)                //shifting smaller elements to left side of pivot
		{
			int temp = *(arr+i);
		    *(arr+i) = *(arr+pIndex);
			*(arr + pIndex) = temp;
			pIndex++;

		}
	}

	int temp = *(arr + end);
	*(arr + end) = *(arr + pIndex);
	*(arr + pIndex) = temp;

	return pIndex;
}

Sequence::~Sequence()
{
	delete[]pseq;
	pseq = NULL;
}

int Sequence::RemoveDuplicates()
{
	return 0;
}

void Sequence::Rotate(int steps)
{
	int* temp = new int[steps];
	for (int i = 0; i < steps; i++)     //store the elements to be rotated in temp arr
	{
		*(temp + i) = *(pseq + i);
	}

	for (int i = 0; i < length; i++)    //shift array to left
	{
		pseq[i] = pseq[i + 1];
	}

	int Index = length - steps + 1;

	for (int i = 0; i <=steps; i++)  //replace by elements of temp arr
	{
		pseq[Index + i] = temp[i];
	}
}