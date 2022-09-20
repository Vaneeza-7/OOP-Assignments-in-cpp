#include "pch.h"
#include"../Project1/busBooking.h"
TEST(bookSeats, T1) {

	int numOfRows = 9;
	char** bus = bookSeats(numOfRows);

	// Select seats 1A, 2B, and 4C

	char** testBus = new char* [numOfRows];

	for (int i = 0; i < numOfRows; i++)
		*(testBus + i) = new char[5];

	strcpy(*(testBus + 0), "1XBCD");
	strcpy(*(testBus + 1), "2AXCD");
	strcpy(*(testBus + 2), "3ABCD");
	strcpy(*(testBus + 3), "4ABXD");
	strcpy(*(testBus + 4), "5ABCD");
	strcpy(*(testBus + 5), "6ABCD");
	strcpy(*(testBus + 6), "7ABCD");
	strcpy(*(testBus + 7), "8ABCD");
	strcpy(*(testBus + 8), "9ABCD");

	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < 5; j++) {
			EXPECT_EQ(testBus[i][j], bus[i][j]);
		}
	}
}
TEST(bookSeats, T2) {
	
		int numOfRows = 5;
		char** bus = bookSeats(numOfRows);
	
		// Select seats 1A, 2B, 2C, 4D, and 5A
	
		char** testBus = new char* [numOfRows];
	
		for (int i = 0; i < numOfRows; i++)
			*(testBus + i) = new char[5];
	
		strcpy(*(testBus + 0), "1XBCD");
		strcpy(*(testBus + 1), "2AXXD");
		strcpy(*(testBus + 2), "3ABCD");
		strcpy(*(testBus + 3), "4ABCX");
		strcpy(*(testBus + 4), "5XBCD");

		for (int i = 0; i < numOfRows; i++) {
			for (int j = 0; j < 5; j++) {
				EXPECT_EQ(testBus[i][j], bus[i][j]);
			}
		}
}