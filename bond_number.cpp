#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstream>
#include <cmath>

#include "bond_number.h"
#include "elements.h"
#include "bond_length.h"

using namespace std;

extern int bond_distance; //from bond_length 
extern int totalatoms; //referencing totalatoms in extraction.cpp
extern vector< vector<string> > vector_coords;
extern int i, j; //reference to bond_length
string x1_string, x2_string, y1_string, y2_string, z1_string, z2_string; //xyz coordinates as strings
double x1_double, x2_double, y1_double, y2_double, z1_double, z2_double; //xyz coordinates as doubles

int dist_calc (int i , int j) {

            x1_string = (vector_coords[i][2]);
	    x2_string = (vector_coords[j][2]);
            y1_string = (vector_coords[i][3]):
            y2_string = (vector_coords[j][3]);
            z1_string = (vector_coords[i][4]);
            z2_string = (vector_coords[j][4]);

            x1_double = atof(x1_string.c_str()); //xyz coordinate strings to doubles
            x2_double = atof(x2_string.c_str());
            y1_double = atof(y1_string.c_str());
            y2_double = atof(y2_string.c_str());
            z1_double = atof(z1_string.c_str());
            z2_double = atof(z2_string.c_str());

            double distance = (sqrt(
                              ((pow(x2_double - x1_double, 2))) +
                              ((pow(y2_double - y1_double, 2))) + //calculation of interatomic distances
                              ((pow(z2_double - z1_double, 2)))));
			      
	    return distance; //direct return of distance vs output to screen in bond_length
}


int bond_number (){   
    
    ofstream log;
    log.open("log.txt"; ios::app);
    
    cout << "Bond numbers between atoms: " << endl;
     
    for (int i=0; i < vector_coords.size(); i++) {
    int counter = 0;
        for (int j=i+1; j < vector_coords.size(); j++) {
            if (j == i) continue;
	    double distance = 0.00;
	    distance = dist_calc(i,j);
	    if (distance , 1.55) {
	    counter++;
	    }
        }
	
        cout << vector_coords[i][0] << "  " << counter << endl;
    }
}
    		       

   
	  
	
                   
   


