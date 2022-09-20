#pragma once
#include<iostream>
using namespace std;

//this function selects the seats entered by user
void selectSeats(char**& bus, int numRows, int numCols, int rowSeat, int colSeat)
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			bus[rowSeat][colSeat] = 'X';
		}

	}
}

//this function returns true if seat is already occupied
bool checkSeatStatus(char**& bus, int numRows, int numCols, int rowSeat, int colSeat)
{
	bool flag = false;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (bus[rowSeat][colSeat] == 'X')
				flag = true;
		}

	}
	return flag;
}
//this function allocates rows and columns to a bus and, books seats to users based on their slection
char** bookSeats(int rows)
{
	int num = 49;   //ascii value of 1
	int cols = 5;
	int seat = 65;  //ascii value of A
	char** bus = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		bus[i] = new char[cols];
	}

	//filling array with seats

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (j == 0)
			{
				bus[i][j] = num;
				num++;
			}

			else
			{
				bus[i][j] = seat;
				seat++;
			}

		}
		seat = 65;
	}

	int seatRow, seatCol, seats;
	cout << "How many seats do you want?";
	cin >> seats;
	for (int i = 0; i < seats; i++)
	{
		cout << "Select Seats: ";
		cin >> seatRow >> seatCol;
		while (checkSeatStatus(bus, rows, cols, seatRow, seatCol))
		{
			cout << "Seat is already occupied. Select any other seat: ";
			cin >> seatRow >> seatCol;
		}
		selectSeats(bus, rows, cols, seatRow, seatCol);
	}

	return bus;
}
