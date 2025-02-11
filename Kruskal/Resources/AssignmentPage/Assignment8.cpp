//************************************************************************
// ASU CSE310 Assignment #8 Fall 2024
// Name: El-Hadji Omar Bane
// ASU ID: 1230726447
// Description: this is the main program that reads input from keyboard,
// it then use disjoint set data structure to perform Kruskal MST algorithm
// on the graph. //---- is where you need to add your own codes
//**************************************************************************

//include necessary header file
//----

using namespace std;

void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance);

int main()
{
    //Maximum possible sites and route number
    const int MAX_SITE_NUM = 50, MAX_ROUTE_NUM = 100;
    int numOfSites = 0, numOfRoutes = 0;  //counter used to track actual number of sites and routes


   //create an array of Site which store all Sites (vertex of the graph)
   //----

   //create an array of Route which store all Routes (edges of the graph)
   //----

   //declare all necessary local variables here
   //

   string oneLine;

   getline(cin, oneLine);

   while(oneLine.compare("End") != 0)
   {
      //get one line from the input, extract the first token
      //create a Site object if it does not exist in site array,
      //insert it inside the site array. This will be first point of the 'aNewRoute'
      //----
      //----

      //extract the arrival site info. check whether it exists in
      //site array or not, if not, create a new Site object, add it inside.
      //This site will be the second point of the 'aNewRoute'
      //----
      //----

      //by using the two sites we got above, create a new route, add
      //it inside route array
      //----
      //----

      //get next line
      getline(cin, oneLine);

   } //repeat until the 'End'

   //Create a Map object by using site array and route array
   //----

   cout << "Total historical sites you will visit: " << numOfSite << endl;

   //Run Kruskal MST algorithm on above map
   //----
}

//****************************************************************
//By giving a string, for example 'Pantheon(300.5)', this function
//extract the arrival site name 'Pantheon' and distance '300.5' meters
//Note: the delimiter is left and right parenthesis
//****************************************************************
void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance)
{
   //----
   //----
}

