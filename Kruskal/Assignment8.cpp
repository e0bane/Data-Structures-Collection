//************************************************************************
// ASU CSE310 Assignment #8 Fall 2024
// Name: El-Hadji Omar Bane
// ASU ID: 1230726447
// Description: this is the main program that reads input from keyboard,
// it then use disjoint set data structure to perform Kruskal MST algorithm
// on the graph. //---- is where you need to add your own codes
//**************************************************************************

//include necessary header file
#include <iostream>
#include <string.h>
#include <sstream>
#include "Map.h"

using namespace std;

void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance);
bool includeSiteToArr(Site siteArr[], Site newSite, int arrSize, int numOfSites);  // adds sites to the array
int findSite(Site siteArr[], Site site, int arrSize, int numOfSites);

int main()
{
    //Maximum possible sites and route number
    const int MAX_SITE_NUM = 50, MAX_ROUTE_NUM = 100;
    int numOfSites = 0, numOfRoutes = 0;  //counter used to track actual number of sites and routes


    //create an array of Site which store all Sites (vertex of the graph)
    Site siteArr[MAX_SITE_NUM];

    //create an array of Route which store all Routes (edges of the graph)
    Route routeArr[MAX_ROUTE_NUM];

    //declare all necessary local variables here
    string token;
    stringstream stream;  // used to tokenize lines
    Site* aSite;
    string aName;  // site a's name
    Site* bSite;
    string bName;  // site b's name
    double distance;
    Route* aNewRoute;

    string oneLine;

    getline(cin, oneLine);

    while (oneLine.compare("End") != 0)
    {
        stream = stringstream(oneLine);
        //get one line from the input, extract the first token
        //create a Site object if it does not exist in site array,
        //insert it inside the site array. This will be first point of the 'aNewRoute'
        getline(stream, token, ',');
        aName = token;

        if (includeSiteToArr(siteArr, Site(aName), MAX_SITE_NUM, numOfSites))
            numOfSites++;

        // stores the created site
        aSite = &siteArr[findSite(siteArr, Site(aName), MAX_SITE_NUM, numOfSites)];

        //extract the arrival site info. check whether it exists in
        //site array or not, if not, create a new Site object, add it inside.
        //This site will be the second point of the 'aNewRoute'
        while (getline(stream, token, ','))  // extracts every arrival site
        {
            if (token.find('(') != -1 && token.find(')') != -1)  // if the parenthesis exists in the token
            {
                getArrSiteInfo(token, bName, distance);

                if (includeSiteToArr(siteArr, Site(bName), MAX_SITE_NUM, numOfSites))
                    numOfSites++;
                // stores the created site
                bSite = &siteArr[findSite(siteArr, Site(bName), MAX_SITE_NUM, numOfSites)];

                //by using the two sites we got above, create a new route, add
                //it inside route array
                routeArr[numOfRoutes] = Route(aSite, bSite, distance);
                numOfRoutes++;
            }
        }

        //get next line
        getline(cin, oneLine);

    } //repeat until the 'End'

    //Create a Map object by using site array and route array
    Map M = Map(numOfSites, numOfRoutes, siteArr, routeArr);

    cout << "Total historical sites you will visit: " << numOfSites << endl;

    //Run Kruskal MST algorithm on above map
    M.MST_Kruskal();
    return 0;
}

//****************************************************************
//By giving a string, for example 'Pantheon(300.5)', this function
//extract the arrival site name 'Pantheon' and distance '300.5' meters
//Note: the delimiter is left and right parenthesis
//****************************************************************
void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance)
{
    stringstream lineStream = stringstream(oneArrSiteInfo);

    string extract;

    getline(lineStream, extract, '(');
    arrSiteName = extract;

    // POTENTIAL ISSUE: when distance extracts, the double isn't exactly the same as the input (0.00001 off)
    getline(lineStream, extract, ')');
    distance = stod(extract);
}


// includes a site into the siteArr if the site doesn't exist in the array already 
bool includeSiteToArr(Site siteArr[], Site newSite, int arrSize, int numOfSites)
{
    if (findSite(siteArr, newSite, arrSize, numOfSites) != -1)  // site exists in the array
        return false;
    siteArr[numOfSites] = newSite;
    return true;
}

int findSite(Site siteArr[], Site site, int arrSize, int numOfSites)
{
    if (numOfSites >= arrSize)  // checks if the array is full
        throw out_of_range("the siteArr cannot contain additional sites: the array is full");

    for (int i = 0; i < numOfSites; i++)
    {
        if (Map::sitesEqual(&site, &siteArr[i]))
            return i;  // already exists in the array
    }
    return -1;
}