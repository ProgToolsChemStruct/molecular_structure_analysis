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
#include "bond_length.h"

using namespace std;

extern unsigned int totalatoms;  //referring to totalatoms in extraction.cpp
extern vector< vector<string> > vector_coords;

int bond_distance = 1.55;  //average bond distance in Angstroms

extern int i, j, k;
string string_atom1, string_atom2;
string string_x1, string_x2, string_y1, string_y2, string_z1, string_z2;  //xyz coordinates as strings
double double_x1, double_x2, double_y1, double_y2, double_z1, double_z2;  //xyz coordinates as doubles
extern vector<double> atomic_distance;  //creation of 2D vector for interatomic distances
extern vector< vector<int> > bond_exist;  //creation of 2D vector: 1 for bond exists and 0 for bond does not exist
    
void Bond_Length::atom_dist() {
    ofstream log;
    log.open("log.txt", ios::app);

    cout << "Interatomic distances (in Angstroms): " << endl;

    for(i = 0; i < i < totalatoms; i++) {
        for(j = i + 1; j < totalatoms; j++) {
            string_atom1 = (vector_coords[i][0]);
	    string_atom2 = (vector_coords[j][0]);
            string_x1 = (vector_coords[i][2]);
	    string_x2 = (vector_coords[j][2]);
            string_y1 = (vector_coords[i][3]);
            string_y2 = (vector_coords[j][3]);
            string_z1 = (vector_coords[i][4]);
            string_z2 = (vector_coords[j][4]);

            double_x1 = atof(string_x1.c_str());  //converting xyz coordinate strings to doubles
            double_x2 = atof(string_x2.c_str());
            double_y1 = atof(string_y1.c_str());
            double_y2 = atof(string_y2.c_str());
            double_z1 = atof(string_z1.c_str());
            double_z2 = atof(string_z2.c_str());

            double distance = (sqrt(
                              ((pow(double_x2 - double_x1, 2))) + 
                              ((pow(double_y2 - double_y1, 2))) +  //calculation of interatomic distances
                              ((pow(double_z2 - double_y2, 2)))));
		
            atomic_distance.push_back(distance);	
	         		
            cout << string_atom1 << "  " << string_atom2 << "   " << distance << endl;
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
