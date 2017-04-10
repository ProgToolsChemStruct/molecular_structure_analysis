#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

#include "distance.h"

using namespace std;

double calc_bond dist () {
    for ( i=0; i < totalatoms; i++) {
        extern vector< vector< string> > array; //referencing array created in extraction.cpp 
	    for (j=i+1; j < totalatoms; j++) {
	    string string_x1; string_x2; string_y1; string_y2; string_z1; string_z2;
	        string_x1 = array[i][2]; //turning two numbers from array to string
	        string_y1 = array[i][3];
	        string_z1 = array[i][4];
	        string_x2 = array[j][2];
	        string_y2 = array[j][3];
	        string_z2 = array[j][4];
	    double double_x1; double_x2; double_y1; double_y2; double_z1; double_z2;
	        double_x1 = atof(string_x1.c_str()) //turning string to a double to a character
		double_y1 = atof(string_y1.c_str())
		double_z1 = atof(string_z1.c_str())
		double_x2 = atof(string_x2.c_str())
		double_y2 = atof(string_y2.c_str())
		double_z2 = atof(string_z2.c_str())
	    distance =sqrt((double_x2-double_x1)pow2)(double_y2-double_y1)pow2)((double_z2-double_z1)pow2))) //calculation of distance between atoms
	        cout<< "distance from" << i <<  "to" << j << ":     " << distance <<endl;
            };
	};
}		   	
