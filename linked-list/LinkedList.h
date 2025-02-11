// ASU CSE310 Fall 2024 Assignment #1
// Name: El Hadji O. Bane
// ASU ID: 1230726447
// Description: Assignment 1
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//HotelBooking represents a Hotel's booking information
struct HotelBooking
{
    string hotelName;
    string arrivalDate;
    int confirmNum;     //booking confirmation No.
    struct HotelBooking* next;
};

//class LinkedList will contains a linked list of HotelBooking objects
class LinkedList
{
private:
    struct HotelBooking* head;
    HotelBooking* getHotelPtr(string hotelName, string arrivalDate, int confirmNum);

    static int compairBooking(HotelBooking* bookingA, HotelBooking* bookingB);

public:
    LinkedList();
    ~LinkedList();
    bool searchBooking(string hotelName, string arrivalDate, int confirmNum);
    bool addBooking(string hotelName, string arrivalDate, int confirmNum);
    void displayAllBookings();
    void displayBookingsByHotel(string hotelName);
    void displayBookingsByDate(string arrivalDate);
    int countAllBookings();
    int countBookingByHotel(string hotelName);
    int countBookingByDate(string arrivalDate);
    bool cancelOneBooking(string hotelName, string arrivalDate, int confirmNum);
    bool cancelAllBookingsByHotel(string hotelName);
    bool cancelAllBookingsByDate(string arrivalDate);
    bool delayABooking(string hotelName, string oldArrivalDate, int confirmNum, string newArrivalDate);
    bool changeAHotel(string oldHotelName, string arrivalDate, int confirmNum, string newHotelName);


};

//Constructor to initialize an empty linked list
LinkedList::LinkedList()
{
    //Add your own code
    this->head = nullptr;
    //----
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the existing linked list.
//It deletes all the nodes including the head and finally prints the number of nodes deleted by it.
//Return value: Prints the number of nodes deleted by it.
LinkedList::~LinkedList()
{
    //Add your own code
    int count = 0;

    HotelBooking* pastPtr = nullptr;
    HotelBooking* cursorPtr = head;

    while (cursorPtr != nullptr) {
        pastPtr = cursorPtr;
        cursorPtr = cursorPtr->next;

        delete pastPtr;
        count++;
    }

    cout << "\nThe number of deleted bookings is: " << count << "\n";
}

//**A function to find if the parameterized HotelBooking object is inside the LinkedList or not.
//Return true if it exists and false otherwise.
bool LinkedList::searchBooking(string hotelName, string arrivalDate, int confirmNum)
{
    //Add your own code
    HotelBooking* currentBooking = this->head;

    while (currentBooking != nullptr) {
        if (currentBooking->hotelName == hotelName
            && currentBooking->arrivalDate == arrivalDate
            && currentBooking->confirmNum == confirmNum)
        {
            return true;
        }
        currentBooking = currentBooking->next;
    }
    return false;
}

//***This is the most important function you need to work on since it build the linked list****
//Creates a new node and inserts it into the list at the right place.
//It also maintains an alphabetical ordering of HotelBookings by hotelName, arrival date
//and confirmation number. i.e. first by hotelName, then by arrival date, last by confirmation
//number. i.e. if two HotelBookings have the same hotelName, then the new HotelBooking should be
//inserted in alphabetical order of their arrival dates. Also it is possible that two or more
//HotelBookings have same hotelName and arrival dates, but their confirmation number must be different
//and they should be inserted into the list by increasing order of the number.
//Return value: true if it is successfully inserted and false in case of failures.
bool LinkedList::addBooking(string hotelName, string arrivalDate, int confirmNum)
{
    if (searchBooking(hotelName, arrivalDate, confirmNum) == true) { return false; }


    // instance construction
    HotelBooking* newBooking = new HotelBooking;  // instantiation
    newBooking->hotelName = hotelName;
    newBooking->arrivalDate = arrivalDate;
    newBooking->confirmNum = confirmNum;
    newBooking->next = nullptr;

    if (this->head == nullptr)
    {
        this->head = newBooking;
        return true;
    }

    HotelBooking* pastPtr = nullptr;
    HotelBooking* cursorPtr = head;

    bool correctPositionFound = false;
    
    // insertion point searching
    while (correctPositionFound == false && cursorPtr != nullptr)
    {
        //LinkedList::compairBooking(newBooking, cursorPtr) > 0 && cursorPtr != nullptr
        if (LinkedList::compairBooking(newBooking, cursorPtr) < 0) { correctPositionFound = true; }
        else 
        {
            pastPtr = cursorPtr;
            cursorPtr = cursorPtr->next;
        }
    }

    // insertion
    if (pastPtr == nullptr) 
    {  // front insertion
        newBooking->next = this->head;
        this->head = newBooking;
    }
    else 
    {
        newBooking->next = cursorPtr;
        pastPtr->next = newBooking;
    }

    return true;
}

//Display all HotelBookings in the linked list starting from the head.
void LinkedList::displayAllBookings()
{
    //Add your own code
    HotelBooking* temp = head;
    int counter = this->countAllBookings();
    
    while (temp != nullptr) {
        cout << left << setw(18) << temp->hotelName
            << setw(12) << temp->arrivalDate
            << setw(8) << temp->confirmNum << "\n";
        temp = temp->next;
    }

    cout << "\nTotal # of bookings: " << counter << "\n";
}

//Display all bookings with the specified hotelName.
void LinkedList::displayBookingsByHotel(string hotelName)
{
    //Add your own code
    HotelBooking* temp = head;
    int counter = this->countBookingByHotel(hotelName);

    cout << endl;
    while (temp != nullptr) {
        if (temp->hotelName == hotelName) 
        {
            cout << left << setw(18) << temp->hotelName
                << setw(12) << temp->arrivalDate
                << setw(8) << temp->confirmNum << "\n";

        }
        
        temp = temp->next;
    }
    

    if (counter == 0)//add your own condition )
        cout << "\nNo bookings with the specified hotelName found\n";
    else
        cout << "\nTotal: " << counter << " bookings found with " << hotelName << "\n";
}

//Display all bookings with the specified arrival date
void LinkedList::displayBookingsByDate(string arrivalDate)
{
    HotelBooking* cursorPtr = head;
    int counter = this->countBookingByDate(arrivalDate);

    cout << endl;
    while (cursorPtr != nullptr) {
        if (cursorPtr->arrivalDate == arrivalDate)
        {
            cout << left << setw(18) << cursorPtr->hotelName
                << setw(12) << cursorPtr->arrivalDate
                << setw(8) << cursorPtr->confirmNum << "\n";
        }
        cursorPtr = cursorPtr->next;
    }

    if (counter == 0)//add your own condition)
        cout << "\nNo bookings with the specified date found\n";
    else
        cout << "\nTotal: " << counter << " bookings found on " << arrivalDate << "\n";
}

//Returns the total number of bookings in the list
int LinkedList::countAllBookings()
{
    int total = 0;

    HotelBooking* cursorPtr = this->head;

    while (cursorPtr != nullptr) 
    {
        total++;
        cursorPtr = cursorPtr->next;
    }
    
    return total;
}

//Returns the total number of bookings by the specified hotel
int LinkedList::countBookingByHotel(string hotelName)
{
    int total = 0;

    HotelBooking* cursorPtr = this->head;

    while (cursorPtr != nullptr)
    {
        if (cursorPtr->hotelName == hotelName) { total++; }
        cursorPtr = cursorPtr->next;
    }

    return total;
}

//Returns the total number of bookings in the list by the specified arrival date
int LinkedList::countBookingByDate(string arrivalDate)
{
    int total = 0;

    HotelBooking* cursorPtr = this->head;

    while (cursorPtr != nullptr)
    {
        if (cursorPtr->arrivalDate == arrivalDate) { total++; }
        cursorPtr = cursorPtr->next;
    }

    return total;
}

//Cancel the specified HotelBooking from the list, releases the memory and updates pointers.
//Return true if it is successfully canceled, false otherwise.

bool LinkedList::cancelOneBooking(string hotelName, string arrivalDate, int confirmNum)
{
    if (this->searchBooking(hotelName, arrivalDate, confirmNum) == false) return false;
    HotelBooking* deletionPtr = nullptr;
    HotelBooking* pastPtr = nullptr;
    HotelBooking* cursorPtr = this->head;

    while (cursorPtr->hotelName != hotelName
        || cursorPtr->arrivalDate != arrivalDate
        || cursorPtr->confirmNum != confirmNum)
    {
        pastPtr = cursorPtr;
        cursorPtr = cursorPtr->next;
    }

    deletionPtr = cursorPtr;
    cursorPtr = cursorPtr->next;

    if (pastPtr == nullptr) { this->head = cursorPtr; }
    else { pastPtr->next = cursorPtr; }

    deletionPtr->next = nullptr;
    delete deletionPtr;
    return true;
}

//Cancel all bookings from a specific hotel, releases the memory and updates pointers.
//Return true if it is successfully canceled, false otherwise. Note: multiple HotelBookings
//might be canceled
bool LinkedList::cancelAllBookingsByHotel(string hotelName)
{
    HotelBooking* cursorPtr = head;
    bool cancelledBooking = false;

    string arrivalDate;
    int confirmNum;
    while (cursorPtr != nullptr)
    {
        if (cursorPtr->hotelName == hotelName)
        {
            // storing before moving cursor up
            arrivalDate = cursorPtr->arrivalDate;
            confirmNum = cursorPtr->confirmNum;

            cursorPtr = cursorPtr->next;
            this->cancelOneBooking(hotelName, arrivalDate, confirmNum);
            cancelledBooking = true;
        }
        else { cursorPtr = cursorPtr->next; }
    }

    return cancelledBooking;
}

//Removes all HotelBookings with the specified date, releases the memory and updates pointers.
//Return true if they are successfully removed, false otherwise. Note: all HotelBookings with
//the same arrival date should be removed from the list.
bool LinkedList::cancelAllBookingsByDate(string arrivalDate)
{
    HotelBooking* cursorPtr = head;
    bool cancelledBooking = false;

    string hotelName;
    int confirmNum;
    while (cursorPtr != nullptr)
    {
        if (cursorPtr->arrivalDate == arrivalDate)
        {
            // storing before moving cursor up
            hotelName = cursorPtr->hotelName;
            confirmNum = cursorPtr->confirmNum;

            cursorPtr = cursorPtr->next;
            this->cancelOneBooking(hotelName, arrivalDate, confirmNum);
            cancelledBooking = true;
        }
        else { cursorPtr = cursorPtr->next; }
    }

    return cancelledBooking;
}

//Modifies the arrival date of the given booking. Return true if it modifies successfully and
//false otherwise.
bool LinkedList::delayABooking(string hotelName, string oldArrivalDate, int confirmNum, string newArrivalDate)
{
    if (this->searchBooking(hotelName, oldArrivalDate, confirmNum) == false 
        || this->cancelOneBooking(hotelName, oldArrivalDate, confirmNum) == false
        || this->addBooking(hotelName, newArrivalDate, confirmNum) == false)
    { return false; }

    return true;
}

//Change a specific booking info. If found it inside the list and change its hotelName successfully, return
//true; otherwise return false. Note: after successfully change its hotelName, the linked list must
//still be in alphabetical order
bool LinkedList::changeAHotel(string oldHotelName, string arrivalDate, int confirmNum, string newHotelName)
{
    if (this->searchBooking(oldHotelName, arrivalDate, confirmNum) == false
        || this->cancelOneBooking(oldHotelName, arrivalDate, confirmNum) == false 
        || this->addBooking(newHotelName, arrivalDate, confirmNum) == false)
    { return false; }
    
    return true;
}


HotelBooking* LinkedList::getHotelPtr(string hotelName, string arrivalDate, int confirmNum)
{
    if (this->searchBooking(hotelName, arrivalDate, confirmNum) == false) { throw runtime_error("The desired hotel doesn't exist"); }

    HotelBooking* cursorPtr = this->head;
    while (cursorPtr->hotelName != hotelName
        || cursorPtr->arrivalDate != arrivalDate
        || cursorPtr->confirmNum != confirmNum)
    {
        cursorPtr = cursorPtr->next;
    }

    return cursorPtr;
}

inline int LinkedList::compairBooking(HotelBooking* bookingA, HotelBooking* bookingB)
{
    // IDs
    string bookingAID = bookingA->hotelName
        + bookingA->arrivalDate
        + static_cast<char>(bookingA->confirmNum > bookingB->confirmNum);
    string bookingBID = bookingB->hotelName
        + bookingB->arrivalDate
        + static_cast<char>(bookingA->confirmNum < bookingB->confirmNum);

    return bookingAID.compare(bookingBID);
}
