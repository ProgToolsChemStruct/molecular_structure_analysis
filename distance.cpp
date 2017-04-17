#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <cassert>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "distance.h"
#include "bond_number.h"	

using namespace std;

extern unsigned int totalatoms;  //referring to totalatoms in extraction.cpp
extern vector< vector<string> > array;

int bond_distance = 1.55;  //average bond distance in Angstroms

int i, j, k;
string atom1_string, atom2_string;
string x1_string, x2_string, y1_string, y2_string, z1_string, z2_string;  //xyz coordinates as strings
double x1_double, x2_double, y1_double, y2_double, z1_double, z2_double;  //xyz coordinates as doubles
double x1_unit, x2_unit, y1_unit, y2_unit, z1_unit, z2_unit;  //xyz unit vectors
vector<double> atomic_distance;  //creation of 2D vector for interatomic distances
vector< vector<int> > bond_exist;  //creation of 2D vector: 1 for bond exists and 0 for bond does not exist
vector< vector<double> > unit_vector;  //creation of 2D vector for xyz unit vectors
vector< vector< vector<double> > > bond_angle;  //creation of 3D vector for bond angles
    
void distance::atom_dist() {
    ofstream log;
    log.open("log.txt", ios::app);

    cout << "Interatomic distances (in Angstroms): " << endl;

    for(i = 0; i < i < totalatoms; i++) {
        for(j = i + 1; j < totalatoms; j++) {
            atom1_string = (array[i][0]);
	    atom2_string = (array[j][0]);
            x1_string = (array[i][2]);
	    x2_string = (array[j][2]);
            y1_string = (array[i][3]);
            y2_string = (array[j][3]);
            z1_string = (array[i][4]);
            z2_string = (array[j][4]);

            x1_double = atof(x1_string.c_str());  //converting xyz coordinate strings to doubles
            x2_double = atof(x2_string.c_str());
            y1_double = atof(y1_string.c_str());
            y2_double = atof(y2_string.c_str());
            z1_double = atof(z1_string.c_str());
            z2_double = atof(z2_string.c_str());

            double distance = (sqrt(
                              ((pow(x2_double - x1_double, 2))) + 
                              ((pow(y2_double - y1_double, 2))) +  //calculation of interatomic distances
                              ((pow(z2_double - z1_double, 2)))));
		
            atomic_distance.push_back(distance);	
	         		
            cout << atom1_string << "  " << atom2_string << "   " << distance << endl;
            }
        }

        for(i = 0; i < totalatoms; i++) {
            for(j = i + 1; j < totalatoms; j++) {
                if(atomic_distance[i] > bond_distance) {  //if interatomic distance is greater than 1.55 Angstroms
                    bond_exist[i][j] = 0;  //0 for non-bonding
                }
                else bond_exist[i][j] = 1;  //1 for bonding
            }
        }
    }
