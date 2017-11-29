//Bamphiane Annie Phongphouthai
//bp8qg
//November 28, 2017
//traveling.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"
/** @fn computeDistance(MiddleEartch &me, string start, vector<string> dests)
 *
 * @param me is the Middle earth object
 * @param start the city to begin the journey
 * @param dests vector is holding the destinations
 *
 * @return float distance to travel to cities
 * @brief calculates the distance between all the cities from the start
 *
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests);
/** @fn printRoute(string start, vector<string>dests)
 *
 * @brief prints the route
 * @param start the city to begin the journey
 * @param dests vector holding the destinations
 *
 */

void printRoute (string start, vector<string> dests);
/** @brief main function to produce output of the Traveling Sales Person algorithm
 * @details takes in 5 command line parameter inputs
 *
 * @param argc a.out
 * @param argv vector command line arguments
 * @return returns 0 upon completion
 *
 */


int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    
    //find shortest distance after looping
    string begin = dests[0];
    vector<string> finalItr=dests;

    //find permutation of shortest distances
    float shortestDist = computeDistance(me, begin, dests);
    float tempDist=0;
    while(next_permutation(dests.begin()+1, dests.end())){ //not including the start
      tempDist= computeDistance(me, begin, dests);
      if(tempDist<shortestDist){ //if statement to find the shortest distance
	shortestDist=tempDist;//update shortest distance if found
	finalItr = dests;
      }
    }
    //cout<<"Your journey will take you along the path ";
    cout<<"Minimum path has distance "<<shortestDist<<": ";
    printRoute(finalItr[0], finalItr);
    cout<<endl;
    //cout<<"and will have distance  "<<shortestDist<<endl;
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  sort(dests.begin()+1, dests.end()); //first sorts the cities
  float distance= 0;
  //string temp = dests[dests.size()-1];
  vector<string> temp = dests;
  temp.resize(dests.size()+1);
  temp.at(temp.size()-1)=temp.at(0);
  for(int i=0; i<dests.size(); i++){
    //distance+= me.getDistance(start, dests[i]);
    distance+= me.getDistance(temp.at(i), temp.at(i+1));
    start = dests[i];
  }
  //distance+= me.getDistance(dests[0], temp);
  return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
  for(int i=0; i<dests.size();i++){
    cout<<dests[i]<<" -> ";
  }
  cout<<start;
}
