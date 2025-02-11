// Assignment: ASU CSE310 HW#3 Fall 2024
// Your Name: El Hadji O. Bane
// ASU ID: 1230726447
// ASU Email address: eobane@asu.edu
// Description:
//********************************************************
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Each HotelBooking has a unique confirmNum
struct HotelBooking
{
    string hotelName;
    string arrivalDate;
    int confirmNum;
};

//class MaxHeap represents a max heap that contains HotelBooking objects. The underline data structure
//is a one dimensional array of HotelBooking.
class MaxHeap
{
    private:
    struct HotelBooking* bookingArr;	//an array of HotelBookings
    int capacity, size;

	public:
    MaxHeap(int capacity);
    ~MaxHeap();

	HotelBooking* getHotelBookingArr();
	int getSize();
	int getCapacity();
	int isFound(int oneConfirmNum);
	bool heapIncrease(int index, HotelBooking oneNewBooking);
	bool heapInsert(string hotelName, string arrivalDate, int confirmNum);
	void heapify(int index);
	HotelBooking getHeapMax();
	void extractHeapMax();
	int leftChild(int parentIndex);
	int rightChild(int parentIndex);
	int parent(int childIndex);
	void printHeap();
};

//Constructor to create a heap with the specified capacity
MaxHeap::MaxHeap(int capacity)
{
 	//----
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the heap.
//and prints the number of nodes deleted by it.
MaxHeap::~MaxHeap()
{
	//----
	cout << "\nThe number of deleted bookings is: " << num << endl;
}

//Insert the relevant HotelBooking object inside the heap at the correct location
bool MaxHeap::heapInsert(string hotelName, string arrivalDate, int confirmNum)
{
	//if the booking already exist, return false
	if (isFound(confirmNum) != -1)
	{
		cout << "\nDuplicated booking. Not added" << endl;
		return false;
	}

	//----
	//----
 }

void MaxHeap::printHeap()
{
	//----
	//----
	   cout << left;
	   cout << setw(18) << bookingArr[i].hotelName
            << setw(12) << bookingArr[i].arrivalDate
            << setw(8)  << bookingArr[i].confirmNum << endl;
}

//design all other functions according to the function definition and the resulting output testing cases
//----
//----
