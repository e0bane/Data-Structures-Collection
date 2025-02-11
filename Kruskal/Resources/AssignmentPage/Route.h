//********************************************************************
// ASU CSE310 Assignment #8 Fall 2024
// Name: El-Hadji Omar Bane
// ASU ID: 1230726447
// Description: //---- is where you should add your own code
//********************************************************************

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Site represents one vertex of the map
struct Site
{
    string siteName;
    int rank;
    struct Site* parent;

   //C++ doesn't provide a default constructor, need it here.
   Site()
   {
        //----
        //----
   }

   //overloaded constructor
   Site(string name)
   {
      //----
      //----
   }
};

//Route represents one edge of the map which connects two historical sites of Rome
class Route
{
    private:
       struct Site* site1;
       struct Site* site2;
       double distance;

	public:
	   Route();
       Route(Site* site1, Site* site2, double distance);
       Site* getSite1();
       Site* getSite2();
       double getDistance();
       void printRoute();
};

//finish each function according to above definition
//----
//----


void Route::printRoute()
{
    cout << left;
    cout << setw(33) << site1->siteName
         << setw(8) << "<--->"
         << setw(33) << site2->siteName
         << setw(3) << " = "
         << setw(8) << right << fixed << setprecision(1) << getDistance()
         << endl;
}
