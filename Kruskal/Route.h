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
        siteName = "";
        rank = -1;
        parent = nullptr;
    }

    //overloaded constructor
    Site(string name)
    {
        siteName = name;
        rank = -1;
        parent = nullptr;
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

Route::Route()
{
    this->site1 = nullptr;
    this->site2 = nullptr;
    this->distance = -1.0;
}

Route::Route(Site* site1, Site* site2, double distance)
{
    this->site1 = site1;
    this->site2 = site2;
    this->distance = distance;
}

Site* Route::getSite1()
{
    return this->site1;
}

Site* Route::getSite2()
{
    return this->site2;
}

double Route::getDistance()
{
    return this->distance;
}

void Route::printRoute()
{
    cout << left;
    cout << setw(33) << this->site1->siteName
        << setw(8) << "<--->"
        << setw(33) << this->site2->siteName
        << setw(3) << " = "
        << setw(8) << right << fixed << setprecision(1) << this->getDistance()
        << endl;
}
