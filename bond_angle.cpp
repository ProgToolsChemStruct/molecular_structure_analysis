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

extern vector< vector<string> > vector_coords;  //2D vector "vector_coords" in extraction.cpp

int number_atoms = (vector_coords.size());

typedef vector<int> Row;
typedef vector<double> dblRow;
typedef vector<Row> Matrix;
typedef vector<dblRow> dblMatrix;
    dblMatrix R(number_atoms,dblRow(number_atoms));
    Matrix bond_exist(number_atoms,Row(number_atoms));

vector<double> angRow;
vector< vector<double> > bond_angle_v;

void atom_distance_f(int number_atoms) {

    ofstream outputfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);

    cout << "Interatomic distances (in Angstroms): " << endl;
    log << "Interatomic distances (in Angstroms): " << endl;
    outputfile << "Interatomic distances (in Angstroms): " << endl;

    int i, j;

    for(i = 0; i < number_atoms; i++) {
        for(j = i + 1; j < number_atoms; j++) {
	
            string atom1 = (vector_coords[i][0]);
            string atom2 = (vector_coords[j][0]);
            string x1_string = (vector_coords[i][2]);
            string x2_string = (vector_coords[j][2]);
            string y1_string = (vector_coords[i][3]);
            string y2_string = (vector_coords[j][3]);
            string z1_string = (vector_coords[i][4]);
            string z2_string = (vector_coords[j][4]);

            double x1_double = atof(x1_string.c_str());
            double x2_double = atof(x2_string.c_str());
            double y1_double = atof(y1_string.c_str());
            double y2_double = atof(y2_string.c_str());
            double z1_double = atof(z1_string.c_str());
            double z2_double = atof(z2_string.c_str());

            double distance = (sqrt(
                            ((pow(x2_double - x1_double, 2))) +
                            ((pow(y2_double - y1_double, 2))) +  //calculation of interatomic distances
                            ((pow(z2_double - z1_double, 2)))));

            R[i][j] = distance;
	    R[j][i] = distance;
	    
	    if(distance < 1.55) {
	        bond_exist[i][j] = 1;
		bond_exist[j][i] = 1;
	    } else {
	        bond_exist[i][j] = 0;
		bond_exist[j][i] = 0;
              }
	      
     	    cout << atom1 << "  " << atom2 << "    " << R[i][j] << endl;
            log << atom1 << "  " << atom2 << "    " << R[i][j] << endl;
            outputfile << atom1 << "  " << atom2 << "    " << R[i][j] << endl;
        }
    }
}

double unit_vectors(int a1, int a2, int col) {

    string x1_string = (vector_coords[a1][col]);
    string x2_string = (vector_coords[a2][col]);
    double x1_double = atof(x1_string.c_str());
    double x2_double = atof(x2_string.c_str());
    
    double ex = ((-(x2_double - x1_double)) / R[a1][a2]);
    
    return ex;
}

void bond_angle_f(int number_atoms) {

    ofstream outputfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);
    
    int z = 0;
  
    cout << "Bond angles (in degrees): " << endl;
    log << "Bond angles (in degrees): " << endl;
    outputfile << "Bond angles (in degrees): " << endl;

    for(int i = 0; i < number_atoms; i++) {
        for(int j = 0; j < number_atoms; j++) {
	    if(bond_exist[i][j] == 1) {
	        for(int k = j + 1; k < number_atoms; k++) {
		    if(bond_exist[i][k] == 1) {

		        angRow.clear();
		      
		        double ex_ij = unit_vectors(i,j,2);
		        double ey_ij = unit_vectors(i,j,3);
		        double ez_ij = unit_vectors(i,j,4);
		        double ex_ik = unit_vectors(i,k,2);
		        double ey_ik = unit_vectors(i,k,3);
		        double ez_ik = unit_vectors(i,k,4);			
		        double angle_jik = ((acos(ex_ij * ex_ik +
			                          ey_ij * ey_ik +  //calculation of bond angle with conversion from radians to degrees
			                          ez_ij * ez_ik))
                                                  * (180/3.14159));
		        angRow.push_back(i);
		        angRow.push_back(j);
		        angRow.push_back(k);
		        angRow.push_back(ex_ij);
		        angRow.push_back(ey_ij);
		        angRow.push_back(ez_ij);
		        angRow.push_back(ex_ik);
		        angRow.push_back(ey_ik);
		        angRow.push_back(ez_ik);
		        angRow.push_back(angle_jik);
		        bond_angle_v.push_back(angRow);

		        z++;
		    }
	        }
	    }
        }
    }

    for(int i = 0; i < bond_angle_v.size(); i++) {
        double a1_double = (bond_angle_v[i][0]);
	double a2_double = (bond_angle_v[i][1]);
	double a3_double = (bond_angle_v[i][2]);
	int a1_int = a1_double;
	int a2_int = a2_double;
	int a3_int = a3_double;
	string a1_string = (vector_coords[a1_int][0]);
	string a2_string = (vector_coords[a2_int][0]);
	string a3_string = (vector_coords[a3_int][0]);	
	
	cout << a1_string << "  " << a2_string << "  " << a3_string << "  ";
        cout << a1_int << "  "   << a2_int << "  " << a3_int << "    ";
	cout << bond_angle_v[i][3] << "  ";
	cout << bond_angle_v[i][4] << "  ";
	cout << bond_angle_v[i][5] << "  ";
	cout << bond_angle_v[i][6] << "  ";
	cout << bond_angle_v[i][7] << "  ";
	cout << bond_angle_v[i][8] << "  ";
	cout << bond_angle_v[i][9];        
	cout << endl;
    }
}
