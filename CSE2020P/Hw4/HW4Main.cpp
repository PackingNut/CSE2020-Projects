/**
 * 
 * Ryan Calderon
 * 
 * File: Main.cpp
 * 
 * This is the main file of HW4, this will hold the created program for input and output 
 * behaviors that is desired for the project operation.
 * 
 * 
*/


#include <iostream>
#include "Map.h"
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>


using namespace std;

double haversine(double long1, double lat1, double long2, double lat2);

int main() 
{
    ifstream input;
    double longi, lati;

    Map<string, Pair<double, double>> earth_map;
    string capital;
    
    int choice1, choice2;
    bool contin = true;
    char answer;

    input.open("hw4_input.txt");
    
    //check for end of file with eof function call
    while (!input.eof())
    {
        input >> capital;
        input >> longi;
        input >> lati;
        earth_map[capital] = Pair(longi, lati);
    }

    Set<string> capitals = earth_map.keys();
    Set<string>::iterator itr = capitals.begin();
    cout << fixed << setprecision(4);
    
    while(contin == true){

        int count = 1;
        itr = capitals.begin();
        cout << "Choose your capitals from the list below" << endl << endl;
        while (itr != capitals.end())
        {
            cout << "(" << count << ")\t" << *itr << endl;
            itr++;
            count++;
        }
        cout << "\n\n";

        cout << "First Capital: (1-" << capitals.cardinality() << "): ";
        cin >> choice1;
        // choice1 = 1;
        Set<string>::iterator itr1 = capitals.begin();
        for (int i = 1; i < choice1; i++)
        {
            itr1++;
        }

        cout << "Second Capital: (1-" << capitals.cardinality() << "): ";
        cin >> choice2;
        // choice2 = 10;
        Set<string>::iterator itr2 = capitals.begin();
        for (int i = 1; i < choice2; i++)
        {
            itr2++;
        }
        cout << "\n\n";
        // cout << earth_map[*itr1].first << " " << earth_map[*itr1].second <<
        cout << "The Distance Between " << *itr1 << " and " << *itr2 << " is: ";
        cout << haversine(earth_map[*itr1].first,
                          earth_map[*itr1].second,
                          earth_map[*itr2].first,
                          earth_map[*itr2].second)
             << "\n\n";

        cout << "Want to continue with more capitals[y/n]: ";
        cin >> answer;
        if(answer != 'y')
        {
            contin = false;
        }
        
        
    }

    return 0;

}

double haversine(double long1, double lat1, double long2, double lat2)
{
    double lat1_rad = lat1 * M_PI / 180;
    double lat2_rad = lat2 * M_PI / 180;
    double delta_long_rad = (long2 - long1) * M_PI / 180;
    double delta_lat_rad = (lat2 - lat1) * M_PI / 180;
    double a = pow(sin(delta_lat_rad / 2), 2) + cos(lat1_rad) * cos(lat2_rad) *pow(sin(delta_long_rad / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371.0 * c;

}