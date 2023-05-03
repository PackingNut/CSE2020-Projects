/**
 * Ryan Calderon 
 * 007535509
 * 4/16/23
 * 
 * File: Lab11wMain.cpp
 * 
 * This file is the main code file for our lab 11 project using the 
 * map files
 * 
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Map.h"

using namespace std;

int main()  
{

    double longi, lati;
    Map<string, Pair<double, double>> earth_map;
    string capital;
    cout << "Enter 5 of the World's capitals with longitude and latitude " << "\n\n";
    for(int i = 0; i < 5; i++)
    {
        cout << setw(15) << left << "Capital: ";
        cin >> capital;
        cout << setw(15) << left << "Longitude: ";
        cin >> longi;
        cout << setw(15) << left << "Latitude: ";
        cin >> lati;
        earth_map[capital] = Pair(longi, lati);
        cout << endl;
    }

    cout << "\n\n" << "Longitudes and Latitudes were entered for these capitals: " << endl;
    Set<string> capitals = earth_map.keys();
    Set<string>::iterator itr = capitals.begin();
    cout << fixed << setprecision(2);
    while(itr != capitals.end())
    {
        // cout << setw << endl;
        cout << setw(25) << left << *itr << setw(8) << right
            << earth_map[*itr].first << setw(8) << right 
            << earth_map[*itr].second << endl;

        itr++;
    }

    return 0;
}