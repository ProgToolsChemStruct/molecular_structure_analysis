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

extern int totalatoms;
extern vector< vector<string> > vector_coords;  //referring to vector "vector_coords" in extraction.cpp

void atom_distance(vector< vector<string> > & vector_coords) {
		   
    ofstream log;
    log.open("log.txt", ios::app);

    cout <<"Interatomic distances (in Angstroms): " << endl;

    int i, j, k, l;
    string atom1, atom2, atom3, atom4;
    string x1_string, x2_string, y1_string, y2_string, z1_string, z2_string;
    double x1_double, x2_double, y1_double, y2_double, z1_double, z2_double;
    double distance;
    vector< vector<double> > R;
    vector<double> distance_vector;

    for(i = 0; i < totalatoms; i++) {
        for(j = i + 1; j < totalatoms; j++) {
            for(k = j + 1; k < totalatoms; k++) {
                for(l = k + 1; l < totalatoms; l++) {
                    atom1 = (vector_coords[i][0]);
                    atom2 = (vector_coords[j][0]);
                    atom3 = (vector_coords[k][0]);
                    atom4 = (vector_coords[l][0]);
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

                    distance_vector.push_back(distance);
                    R.push_back(distance_vector);

                    cout << atom1 << "  " << atom2 << "   " << distance << endl;
                }
            }
        }
    }
}

void unit_vects(int i, int j, 
                double x1_double, double x2_double, 
		double y1_double, double y2_double, 
		double z1_double, double z2_double, 
		vector< vector<double> > & R, 
		vector< vector<string> > & vector_coords) {

    double ex_ij, ey_ij, ez_ij;
    double ex_jk, ey_jk, ez_jk;
    double ex_kl, ey_kl, ez_kl;
    vector<double> e_ij;
    vector<double> e_jk;
    vector<double> e_kl;
    vector< vector<double> > unit_vectors;

    cout << "Bond angles (in degrees): " << endl;

    for(i = 0; i < totalatoms; i++) {
        for(j = i + 1; j < totalatoms; j++) {
            if(R[i][j] < 1.55) {
                ex_ij = ((-(x2_double - x1_double)) / R[i][j]);
                    e_ij.push_back(ex_ij);
                ey_ij = ((-(y2_double - y1_double)) / R[i][j]);
                    e_ij.push_back(ey_ij);
                ez_ij = ((-(z2_double - z1_double)) / R[i][j]);
                    e_ij.push_back(ez_ij);

                unit_vectors.push_back(e_ij);

                ex_jk = ((-(x2_double - x1_double)) / R[i][j]);
                    e_jk.push_back(ex_jk);
                ey_jk = ((-(y2_double - y1_double)) / R[i][j]);
                    e_jk.push_back(ey_jk);
                ez_jk = ((-(z2_double - z1_double)) / R[i][j]);
                    e_jk.push_back(ez_jk);

                unit_vectors.push_back(e_jk);

                ex_kl = ((-(x2_double - x1_double)) / R[i][j]);
                    e_kl.push_back(ex_kl);
                ey_kl = ((-(y2_double - y1_double)) / R[i][j]);
                    e_kl.push_back(ey_kl);
                ez_kl = ((-(z2_double - z1_double)) / R[i][j]);
                    e_kl.push_back(ez_kl);

                unit_vectors.push_back(e_kl);
            }
        }
    }
}

void bond_angle(int i, int j, int k, 
                string atom1, string atom2, string atom3, 
		vector< vector<double> > & R, 
		vector< vector<double> > & unit_vectors, 
		vector< vector<string> > & vector_coords) {

    double x1_unit, x2_unit, y1_unit, y2_unit, z1_unit, z2_unit;
    double angle_phi;
    vector<double> angles_vector;

    for(i = 0; i < totalatoms; i ++) {
        for( j = i + 1; j < totalatoms; j++) {
            for(k = j + 1; k < totalatoms; k++) {
                if(R[i][j] < 1.55) {
                    x1_unit = (unit_vectors[0][i]);  //ex_ij unit vector
                    x2_unit = (unit_vectors[0][j]);  //ex_jk unit vector
                    y1_unit = (unit_vectors[1][i]);  //ey_ij unit vector
                    y2_unit = (unit_vectors[1][j]);  //ey_jk unit vector
                    z1_unit = (unit_vectors[2][i]);  //ez_ij unit vector
                    z2_unit = (unit_vectors[2][j]);  //ez_jk unit vector

                    angle_phi = (acos(
		                 x1_unit * x2_unit +
                                 y1_unit * y2_unit +  //calculation of bond angle
                                 z1_unit * z2_unit));

                    angles_vector.push_back(angle_phi);

                    cout << atom1 << "  " << atom2 << "  " << atom3 << "   " << angle_phi << endl;
                }
            }
        }
    }
}
