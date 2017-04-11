#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <cassert>
#include <vector>
#include <string>
#include <cstdlib>
#include "bond_angle.h"

using namespace std;

extern unsigned int totalatoms;
extern vector< vector<string> > array;  //referring to vector "array" created in extraction.cpp

float bond_distance = 1.54;  //average bond distance in Angstroms

int i;  //atom i
int j;  //atom j
int k;  //atom k
string x1_string;  //x coordinates as strings
string x2_string;
string y1_string;  //y coordinates as strings
string y2_string;
string z1_string;  //z coordinates as strings
string z2_string;
double x1_double;  //x coordinates as doubles
double x2_double;
double y1_double;  //y coordinates as doubles
double y2_double;
double z1_double;  //z coordinates as doubles
double z2_double;
double x1_unit;  //unit vector in x direction
double x2_unit;
double y1_unit;  //unit vector in y direction
double y2_unit;
double z1_unit;  //unit vector in z direction
double z2_unit;

vector< vector<double> > atomic_distance;  //creation of 2D vector containing interatomic distances
vector< vector<int> > bond_exist;  //creation of 2D vector containing 1 for bond exists and 0 for bond does not exist
vector< vector<double> > unit_vector;  //creation of 2D vector containing xyz unit vectors
vector< vector< vector<double> > > bond_angle;  //creation of 3D vector to contain bond angles between atoms i, j and k

void atom_dist() {
    
    ofstream log;
    log.open("log.txt", ios::app);

    for(i = 0; i < totalatoms; i++) {
        for(j = i + 1; j < totalatoms; j++) {
            x1_string = (array[i][2]);  //accessing x,y,z coordinates in vector "array"
            x2_string = (array[j][2]);
            y1_string = (array[i][3]);
            y2_string = (array[j][3]);
            z1_string = (array[i][4]);
            z2_string = (array[j][4]);
            
            x1_double = atof(x1_string.c_str());  //converting x,y,z coordinate strings to doubles
            x2_double = atof(x2_string.c_str());
            y1_double = atof(y1_string.c_str());
            y2_double = atof(y2_string.c_str());
            z1_double = atof(z1_string.c_str());
            z2_double = atof(z2_string.c_str());
        
            atomic_distance[i][j] = (sqrt(
                                    ((pow(x2_double - x1_double, 2))) + 
                                    ((pow(y2_double - y1_double, 2))) +  //calculation of interatomic distances
                                    ((pow(z2_double - z1_double, 2)))));
            
	    double distance_ij = atomic_distance[i][j];  //converting vector positions to doubles
        }
    }

    for(i = 0; i < totalatoms; i++) {
        for(j = i + 1; j < totalatoms; j++) {
            if(atomic_distance[i][j] > bond_distance) {  //if interatomic distance is greater than 1.54 Angstroms
                bond_exist[i][j] = 0;  //0 for non-bonding
		}
            else bond_exist[i][j] = 1;  //1 for bonding
        }
    }
}

void angle_phi() {

    ofstream log;
    log.open("log.txt", ios::app);

    for(i = 0; i < totalatoms; i++) {
        for(j = i + 1; j <= 4 ; j++) {
            x1_unit = unit_vector[i][2];  //placement of unit vectors in unit_vector
            x2_unit = unit_vector[j][2];
            y1_unit = unit_vector[i][3];
            y2_unit = unit_vector[j][3];
            z1_unit = unit_vector[i][4];
            z2_unit = unit_vector[j][4];
        
            if(bond_exist[i][j] == 1) {
                x1_unit = ((-(x2_double - x1_double)) / atomic_distance[i][j]);  //calculation of unit vectors between bonded atoms
                x2_unit = ((-(x2_double - x1_double)) / atomic_distance[i][j]);
                y1_unit = ((-(y2_double - y1_double)) / atomic_distance[i][j]);
                y2_unit = ((-(y2_double - y1_double)) / atomic_distance[i][j]);
                z1_unit = ((-(z2_double - z1_double)) / atomic_distance[i][j]);
                z2_unit = ((-(z2_double - z1_double)) / atomic_distance[i][j]);
            }        
        }
    }

    for(i = 0; i < totalatoms; i++) {
        for(j = i + 1; j < i; j++) {
            for(k = j + 1; k < j; k++) {
                bond_angle[i][j][k] = (acos(
                                      (x1_unit) * (x2_unit) + 
                                      (y1_unit) * (y2_unit) +  //calculation of bond angle between i, j and k
                                      (z1_unit) * (z2_unit)));
                double angle_phi = bond_angle[i][j][k];            
	    }
        }
    }
}
