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
#include "bond_angle.h"

using namespace std;

extern int totalatoms;  //int totalatoms in extraction.cpp
extern vector< vector<string> > vector_coords;  //2D vector "vector_coords" in extraction.cpp

typedef vector<int> Row;
typedef vector<double> dblRow;
typedef vector<Row> Matrix;
typedef vector<dblRow> dblMatrix;
    dblMatrix R(totalatoms,dblRow(totalatoms));
    Matrix bond_exist(totalatoms,Row(totalatoms));

vector<double> angRow;
vector< vector<double> > bond_angle_v;

void atom_distance(int number_atoms) {

    ofstream outputfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);

    cout << "Interatomic distances (in Angstroms): " << endl;
    log << "Interatomic distances (in Angstroms): " << endl;
    outputfile << "Interatomic distances (in Angstroms): " << endl;

    int i, j;
    string atom1, atom2;
    string x1_string, x2_string, y1_string, y2_string, z1_string, z2_string;
    double x1_double, x2_double, y1_double, y2_double, z1_double, z2_double;
    double distance;

    for(i = 0; i < number_atoms; i++) {
        for(j = i + 1; j < number_atoms; j++) {
	
            atom1 = (vector_coords[i][0]);
            atom2 = (vector_coords[j][0]);
            x1_string = (vector_coords[i][2]);
            x2_string = (vector_coords[j][2]);
            y1_string = (vector_coords[i][3]);
            y2_string = (vector_coords[j][3]);
            z1_string = (vector_coords[i][4]);
            z2_string = (vector_coords[j][4]);

            x1_double = atof(x1_string.c_str());
            x2_double = atof(x2_string.c_str());
            y1_double = atof(y1_string.c_str());
            y2_double = atof(y2_string.c_str());
            z1_double = atof(z1_string.c_str());
            z2_double = atof(z2_string.c_str());

            distance = (sqrt(
                            ((pow(x2_double - x1_double, 2))) +
                            ((pow(y2_double - y1_double, 2))) +  //calculation of interatomic distances
                            ((pow(z2_double - z1_double, 2)))));

            R[i][j] = distance;
	    
	    if(distance < 1.55) {
	        bond_exist[i][j] = 1;
	    } else {
	        bond_exist[i][j] = 0;
           }
	      
     	  cout << atom1 << "  " << atom2 << "    " << R[i][j] << endl;
          log << atom1 << "  " << atom2 << "    " << R[i][j] << endl;
          outputfile << atom1 << "  " << atom2 << "    " << R[i][j] << endl;

        }
    }
}

double unit_vectors(int a1, int a2, int col) {

    int number_atoms;
    string x1_string, x2_string;
    double x1_double, x2_double;
    double ex;

    x1_string = (vector_coords[a1][col]);
    x2_string = (vector_coords[a2][col]);
    x1_double = atof(x1_string.c_str());
    x2_double = atof(x2_string.c_str());
    
    ex = ((-(x2_double - x1_double)) / R[a1][a2]);
    
    return ex;

}

void bond_angle_f(int number_atoms) {

    ofstream outputfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);

    int z = 0;
    double ex_ij, ey_ij, ez_ij;
    double ex_ik, ey_ik, ez_ik;
    double angle_phi;
  
    cout << "Bond angles (in degrees): " << endl;
    log << "Bond angles (in degrees): " << endl;
    outputfile << "Bond angles (in degrees): " << endl;

    for(int i = 0; i < number_atoms; i++) {
        for(int j = i + 1; j < number_atoms; j++) {
	        if(bond_exist[i][j] == 1) {
	            for(int k = j + 1; k < number_atoms; k++) {
		            if(bond_exist[i][k] == 1) {
		      
		            angRow.clear();
		      
		            ex_ij = unit_vectors(i,j,2);
		            ey_ij = unit_vectors(i,j,3);
		            ez_ij = unit_vectors(i,j,4);
		      
		            ex_ik = unit_vectors(i,k,2);
		            ey_ik = unit_vectors(i,k,3);
		            ez_ik = unit_vectors(i,k,4);			

		            angle_phi = (acos(ex_ij * ex_ik +
			                          ey_ij * ey_ik +  //calculation of bond angle
			                          ez_ij * ez_ik));
		  
		            angRow.push_back(i);
		            angRow.push_back(j);
		            angRow.push_back(k);
			
		            angRow.push_back(ex_ij);
		            angRow.push_back(ey_ij);
		            angRow.push_back(ez_ij);
			
		            angRow.push_back(ex_ik);
		            angRow.push_back(ey_ik);
		            angRow.push_back(ez_ik);
			
		            angRow.push_back(angle_phi);
		  
		            bond_angle_v.push_back(angRow);
		  
		            z++;
		            }
	            }
	        }
        }
    }

    for(int i = 0; i < bond_angle_v.size(); i++) {
        for(int j = 0; j < 10; j++) {
            cout << bond_angle_v[i][j] << "    ";
        }
        
	    cout << endl;
	
    }

}
