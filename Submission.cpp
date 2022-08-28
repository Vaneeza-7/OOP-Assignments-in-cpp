#include<iostream>
using namespace std;

	/*char* convertToTapCode(char*)


int main()
{

}

	char* convertToTapCode(char* str) {
		char** arr;
		int index1, index2;
		arr = new char* [5];                    //allocate memory for rows

		for (int i = 0; i < 5; i++)             //allocate memory for columns
		{
			*(arr + i) = new char[5];
		}

		int ascVal = 65;                        //filling the 2d array with alphabets
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (ascVal == 75)
				{
					arr[i][j] = char(++ascVal);
				}
				arr[i][j] = char(ascVal++);
			}

		}
		
		for (int i = 0; *(str + i) != '\0'; i++)
		{
			char letter = *(str + i);
			   //loop for checking letter in the 2d array ;
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (arr[j][k] == letter)
					{
						 index1 = j;
						 index2 = k;

					}

				}

			}

		}

		

	}*/
   /* void removePunctuation(char* str) {
	char* ptr = str;
	char* nptr = ptr;
	while (*str != 0)
	{
		if (*str >= '!' && *str <= '@')
		{
			*str = char(32);
		}
		str = str + 1;
	}

	while (*ptr != '\0')
	{
		*nptr = *ptr;

		if (*ptr == ' ')
		{
			while (*(ptr + 1) == ' ')
			{
				ptr = ptr + 1;
			}
		}
		ptr = ptr + 1;
		nptr = nptr + 1;
	}

	cout << nptr;
}*/

void removePunctuation(char* str) {
	char* ptr = str;
	char* nptr = ptr;
	int counter = 0;
	while (*str != '\0')
	{
		if (*str >= '!' && *str <= '@')
		{
			*str = char(32);
		}
		str = str + 1;
	}

	while (*nptr != '\0')                       //copy array elements to another pointer 
											   //whilst removing extra spaces
	{
		*nptr = *ptr;

		if (*ptr == ' ')
		{
			while (*(ptr + 1) == ' ')
			{
				ptr = ptr + 1;
			}
		}

		if (*ptr == ' ')
		{
			if (*(ptr + 1) == '\0')
			{
				*ptr = '\0';
				*nptr = '\0';
			}
		}
		ptr = ptr + 1;
		nptr = nptr + 1;
		counter++;
	}

	//*nptr='\0';

	for (int i = 0; i < counter; i++)
	{
		--nptr;
	}
	cout << nptr;
}


	bool
		isprimeNumber(int n, int i)
	{
		 if (n == i)
			return true;

		if (n % i == 0)
			return false;

		return isprimeNumber(n, i + 1);

		}

	char findUppercase(char* str)
	{
		if (*str >= 'A' && *str <= 'Z')
			return *str;

		else
			return findUppercase(str + 1);
	}


	/*int sum(int** array, int row, int column, int& evenSum, int& oddSum) {

		if (array[row][column]) % 2 == 0)
	          evenSum + array[row][column];

		if (*(array) % 2 != 0)
			return oddSum + *array;

		if (row >= 0 || column >= 0)
			return sum(array, row - 1, column - 1, evenSum, oddSum)
	}*/

	int sum(int** array, int row, int column, int& evenSum, int& oddSum) {



		if (array[row][column] % 2 == 0)
			evenSum = evenSum + array[row][column];


		if (array[row][column] % 2 != 0)
			oddSum = oddSum + array[row][column];

		if (column > 0 && row > 0)
			return sum(array, row, column - 1, evenSum, oddSum);

		else if (column < 0 && row>0)
			return sum(array, row - 1, column + 1, evenSum, oddSum);


		else return 0;
	}


	/*void printspace(int space)
{
    if(space<=0)
    return;
    
    cout<<" ";
    printspace(space-1);
}

void printRows(int end)
{ 
    if(end<0)
   return;
   
   else
    cout<<"* ";
    printRows(end-1);
}


void PrintPattern1(int start, int end)
{
    if(end<0)
    return;
    
    printRows(end);
    cout<<endl;
    printspace(end);
    PrintPattern1(start, end-1);
}*/