//********************************************************************
// ASU CSE310 Assignment #8 Fall 2024
// Name: El-Hadji Omar Bane
// ASU ID: 1230726447
// Description: This is the header file that defines an undirected graph
//              with an array of sites and routes
//********************************************************************

//include necessary header file here
#include "Route.h"
#include<iostream>

using namespace std;

class Map
{
private:
    int numOfSites, numOfRoutes;
    Site* setOfSites;   //an array of Site. Note: NOT allowed to change it to Site**
    Route* setOfRoutes; //an array of Route. Note: NOT allowed to change it to Route**

public:
    Map(int numOfSites, int numOfRoutes, Site* siteArray, Route* routeArray);
    ~Map();
    void make_set(Site* oneSite);
    Site* find_set(Site* oneSite);
    void link(Site* aSite, Site* bSite);
    void Union(Site* aSite, Site* bSite);
    void sortRoutes();
    void MST_Kruskal();

    //add any auxiliary functions in case you need them
    static bool sitesEqual(const Site* aSite, const Site* bSite);
    void sortHelper(int p, int r);
    int partition(int p, int r);
    void exchangeRoutes(int aIndex, int bIndex);  // switches the placement of indexes within the Route set
};

void Map::sortRoutes()
{
    this->sortHelper(0, this->numOfRoutes - 1);
}

//*******************************************************************
//This function performs the Kruskal algorithm on the graph
void Map::MST_Kruskal()
{
    // stores the safe routes/edges
    int numOfSafeRoutes = 0;
    Route* safeRouteArr = new Route[this->numOfRoutes];

    for (int i = 0; i < this->numOfSites; i++)
        this->make_set(&this->setOfSites[i]);
    this->sortRoutes();

    Route edge;
    for (int i = 0; i < this->numOfRoutes; i++)
    {
        edge = this->setOfRoutes[i];
        Site* u = edge.getSite1();
        Site* v = edge.getSite2();
        if (this->sitesEqual(this->find_set(u), this->find_set(v)) == false)  // if the edge isn't already in the safeRoute array
        {
            safeRouteArr[numOfSafeRoutes] = edge;  // adds edge to array
            numOfSafeRoutes++;
            this->Union(u, v);
        }
    }
    cout << "\nMST Kruskal Algorithm Result\n" << endl;
    double totalDistance = 0.0;

    for (int i = 0; i < numOfSafeRoutes; i++)
    {
        totalDistance += safeRouteArr[i].getDistance();
        safeRouteArr[i].printRoute();
    }

    cout << "=====================================================================================" << endl;
    cout << "Total Distance: " << totalDistance << " meters" << endl;

    delete[] safeRouteArr;
}

bool Map::sitesEqual(const Site* aSite, const Site* bSite)
{
    if (aSite->rank == bSite->rank && aSite->siteName == bSite->siteName)
        return true;
    return false;
}

// uses quicksort to sort routes
void Map::sortHelper(int p, int r)
{
    if (p < r)
    {
        int q = this->partition(p, r);
        sortHelper(p, q - 1);
        sortHelper(q + 1, r);
    }
}

int Map::partition(int p, int r)
{
    Route pivot = this->setOfRoutes[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (this->setOfRoutes[j].getDistance() <= pivot.getDistance())
        {
            i = i + 1;
            this->exchangeRoutes(i, j);
        }
    }
    this->exchangeRoutes(i + 1, r);
    return i + 1;
}

void Map::exchangeRoutes(int aIndex, int bIndex)
{
    // throws error if indexes are out of bounds
    if (aIndex >= this->numOfRoutes || bIndex >= this->numOfRoutes || aIndex < 0 || bIndex < 0)
        throw out_of_range("the exchanged indexes are out of bounds");

    Route tmp = this->setOfRoutes[aIndex];
    this->setOfRoutes[aIndex] = this->setOfRoutes[bIndex];
    this->setOfRoutes[bIndex] = tmp;
}

Map::Map(int numOfSites, int numOfRoutes, Site* siteArray, Route* routeArray)
{
    this->numOfSites = numOfSites;
    this->numOfRoutes = numOfRoutes;

    this->setOfSites = siteArray;
    this->setOfRoutes = routeArray;
}

Map::~Map()
{
}

void Map::make_set(Site* oneSite)
{
    oneSite->parent = oneSite;
    oneSite->rank = 0;
}

Site* Map::find_set(Site* oneSite)
{
    if (oneSite != oneSite->parent)
        oneSite->parent = this->find_set(oneSite->parent);
    return oneSite->parent;
}

void Map::link(Site* aSite, Site* bSite)
{
    if (aSite->rank > bSite->rank)
        bSite->parent = aSite;
    else aSite->parent = bSite;
    if (aSite->rank == bSite->rank)
        bSite->rank = bSite->rank++;
}

void Map::Union(Site* aSite, Site* bSite)
{
    this->link(this->find_set(aSite), this->find_set(bSite));
}
