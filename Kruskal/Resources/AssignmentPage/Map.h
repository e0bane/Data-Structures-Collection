//********************************************************************
// ASU CSE310 Assignment #8 Fall 2024
// Name: El-Hadji Omar Bane
// ASU ID: 1230726447
// Description: This is the header file that defines an undirected graph
//              with an array of sites and routes
//********************************************************************

//include necessary header file here
//----

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
      //----
};


//finish each function according to above definition
//----
//----


//*******************************************************************
//This function performs the Kruskal algorithm on the graph
void Map::MST_Kruskal()
{
   cout << "\nMST Kruskal Algorithm Result\n" << endl;
   double totalDistance = 0.0;

   //----
   //----
   //----

   cout << "=====================================================================================" << endl;
   cout << "Total Distance: " << totalDistance << " meters" << endl;
}
