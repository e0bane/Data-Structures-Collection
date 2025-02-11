// Assignment: ASU CSE310 Fall 2024 HW#3
// Name: El Hadji O. Bane
// ASU ID: 1230726447
// ASU Email Address: eobane@asu.edu
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
//             	//---- is where you should add your own code
//********************************************************************************

//----
//----

using namespace std;

void printMenu();
void heapSort(MaxHeap* oneMaxHeap);

int main()
{
	char input1 = 'Z';
	string hotelName;
	string arrivalDate;
	int confirmNum;

	int capacity;   //array capacity and index
	bool success = false;

    HotelBooking oneBooking;

	// instantiate an empty Heap
	MaxHeap* heap1 = nullptr;
	printMenu();

	do {
		cout << "\nWhat action would you like to perform?" << endl;
		cin.get(input1);
		cin.ignore(20, '\n');	//flush the buffer whenever you enter a char, integer, double
                                //if you have multiple char, integer, double entered, only flush once
		input1 = toupper(input1);

		// matches one of the cases
		switch (input1)
		{
			case 'C':	//create empty Heap with the relevant capacity
				cout << "\nPlease enter the heap capacity: ";
				cin >> capacity;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//----

			case 'D':	//delete the heap, call the destructor explicitly
				cout << "\nDelete the heap" << endl;
				//Add your own code
				//----

				//re-initialize it with default capacity 4
				//----
				break;

			case 'E':	//Extract the maximum node
                if (heap1 == nullptr)
                    cout << "\nEmpty heap, can NOT extract max" << endl;
                else
                {
                    //Add your own code
                    //----
                }
				break;

			case 'F':	//Find a HotelBooking
				cout << "\nEnter the booking confirmation number you want to search: ";
				cin >> confirmNum;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//----

				break;

			case 'I':	//Insert a HotelBooking
				cout << "\nEnter the hotel name: ";
				getline(cin, hotelName);

				cout << "\nEnter the arrival date: ";
				getline(cin, arrivalDate);

				cout << "\nEnter the booking confirmation number: ";
				cin >> confirmNum;
                cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//----

				break;

			case 'K':	//increase the confirmation num
				cout << "\nEnter the original confirmation number which you want to increase: ";
				cin >> confirmNum;
				cout << "\nEnter the new updated confirmation number: ";
				cin >> newConfirmNum;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//----
				break;

			case 'M':	//get maximum node

			    //Add your own code
				//----

                    cout << "\nThe maximum heap node is:" << endl;
                    cout << left << setw(18) << oneBooking.hotelName
                                 << setw(12) << oneBooking.arrivalDate
                                 << setw(8)  << oneBooking.confirmNum << endl;

				break;

			case 'P':	//Print heap contents
			    if (heap1 == nullptr)
                    cout << "\nEmpty heap, no elements" << endl;
                else
                    //Add your own code
                    //----
				break;

			case 'S':	//HeapSort
				cout << "\nHeap sort. Bookings will be sorted in increasing order of their confirmation numbers" << endl;
				//Add your own code
				//----
				break;

			case 'Q':	//Quit
				//Add your own code
				//----
				break;

			case '?':	//Display Menu
				printMenu();
				break;

			default:
				cout << "\nUnknown action" << endl;
				break;
		} //end of switch
	} while (input1 != 'Q');
	return 0;
}

//*************************************************************************************
//Given a max heap, we want to sort it in increasing order of confirmation number, put the
//sorting result inside another array and print it out
void heapSort(MaxHeap* oneMaxHeap)
{
    //Add your own code
	//----

}

//**The function displays the menu to the user**
void printMenu()
{
	cout << "Choice\t\tAction\n";
	cout << "------\t\t------\n";
	cout << "C\t\tCreate a heap\n";
	cout << "D\t\tDelete the heap\n";
	cout << "E\t\tExtract max node\n";
	cout << "F\t\tFind a booking by confirmation number\n";
	cout << "I\t\tInsert a booking\n";
	cout << "K\t\tIncrease a booking confirmation number\n";
	cout << "M\t\tGet the max node\n";
	cout << "P\t\tPrint the heap\n";
	cout << "S\t\tHeap Sort\n";
	cout << "Q\t\tQuit\n";
	cout << "?\t\tDisplay Help\n\n";
}
