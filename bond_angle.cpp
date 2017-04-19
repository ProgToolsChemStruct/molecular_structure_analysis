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
    double a1_double, a2_double, a3_double;
    int a1_int, a2_int, a3_int;
    string a1_string, a2_string, a3_string;
    double ex_ij, ey_ij, ez_ij;
    double ex_ik, ey_ik, ez_ik;
    double angle_phi;
  
    cout << "Bond angles (in degrees): " << endl;
    log << "Bond angles (in degrees): " << endl;
    outputfile << "Bond angles (in degrees): " << endl;

    for(int i = 0; i < number_atoms; i++) {
        for(int j = 0; j < number_atoms; j++) {
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

		        angle_phi = ((acos(ex_ij * ex_ik +
			                  ey_ij * ey_ik +  //calculation of bond angle with conversion from radians to degrees
			                  ez_ij * ez_ik)) * (180/3.14159));
		  
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
        a1_double = (bond_angle_v[i][0]);
	a2_double = (bond_angle_v[i][1]);
	a3_double = (bond_angle_v[i][2]);
	
	a1_int = a1_double;
	a2_int = a2_double;
	a3_int = a3_double;
	
	a1_string = (vector_coords[a1_int][0]);
	a2_string = (vector_coords[a2_int][0]);
	a3_string = (vector_coords[a3_int][0]);	
	
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

vector<double> torRow;
vector< vector<double> > dihedral_angle_v;

void torsion_angle_f(int number_atoms) {

cout << "Beginning torsion angle function" << endl;

int col;

    for(int ba = 0; ba < bond_angle_v.size(); ba++) {
       int i = (bond_angle_v[ba][0]);
       int j = (bond_angle_v[ba][1]);
       int k = (bond_angle_v[ba][2]);
       for(int l = 0; l < number_atoms; l++) {
           if(l != i && l != k) {
	       if(bond_exist[k][l] == 1) {
	       
	           torRow.clear();
	       
	           double ex_ij = (bond_angle_v[ba][3]);
		   double ey_ij = (bond_angle_v[ba][4]);
		   double ez_ij = (bond_angle_v[ba][5]);
		   
		   double ex_ik = (bond_angle_v[ba][6]);
                   double ey_ik = (bond_angle_v[ba][7]);
                   double ez_ik = (bond_angle_v[ba][8]);
		   
		   double ex_kl = (unit_vectors(k,l,2));
		   double ey_kl = (unit_vectors(k,l,3));
		   double ez_kl = (unit_vectors(k,l,4));
		   
		   double angle_jik = bond_angle_v[ba][9];
		   
		   double angle_phi_ikl = ((acos(ex_kl * ex_ik +
			                  ey_kl * ey_ik +  //calculation of bond angle with conversion from radians to degrees
			                  ez_kl * ez_ik)) * (180/3.14159));

                   double ex_ijk = ((ey_ij * ez_ik) - (ez_ij * ey_ik));
                   double ey_ijk = ((ez_ij * ex_ik) - (ex_ij * ez_ik));    
                   double ez_ijk = ((ex_ij * ey_ik) - (ey_ij * ex_ik));    
                   double ex_ikl = ((ey_kl * ez_kl) - (ez_ik * ey_kl));
                   double ey_ikl = ((ez_ik * ex_kl) - (ex_ik * ez_kl));    
                   double ez_ikl = ((ex_ik * ey_kl) - (ey_ik * ex_kl));
    
                   double exx = (ex_ijk * ex_ikl);
                   double eyy = (ey_ijk * ey_ikl);    
                   double ezz = (ez_ijk * ez_ikl);
    
                   double tau_ijkl = ((exx + eyy + ezz) / (sin(angle_jik)*sin(angle_phi_ikl))) * (180/3.14159);
		   
		   torRow.push_back(i);
		   torRow.push_back(j);
		   torRow.push_back(k);
		   torRow.push_back(l);
		
		   torRow.push_back(ex_ij);
		   torRow.push_back(ey_ij);
		   torRow.push_back(ez_ij);
		
		   torRow.push_back(ex_ik);
		   torRow.push_back(ey_ik);
		   torRow.push_back(ez_ik);
		   
		   torRow.push_back(ex_kl);
                   torRow.push_back(ey_kl);
                   torRow.push_back(ez_kl);
		
		   torRow.push_back(angle_jik);
		   torRow.push_back(angle_phi_ikl);
		   torRow.push_back(tau_ijkl);
		  
		   dihedral_angle_v.push_back(torRow);
	        }
	    }
	}
    
    for(int l = 0; l < number_atoms; l++) {
           if(l != i && l != j) {
	       if(bond_exist[j][l] == 1) {
	       
	           torRow.clear();
	       
	           double ex_ij = (bond_angle_v[ba][3]);
		   double ey_ij = (bond_angle_v[ba][4]);
		   double ez_ij = (bond_angle_v[ba][5]);
		   
		   double ex_ik = (bond_angle_v[ba][6]);
                   double ey_ik = (bond_angle_v[ba][7]);
                   double ez_ik = (bond_angle_v[ba][8]);
		   
		   double ex_jl = (unit_vectors(j,l,2));
		   double ey_jl = (unit_vectors(j,l,3));
		   double ez_jl = (unit_vectors(j,l,4));
		   
		   double angle_jik = bond_angle_v[ba][9];
		   
		   double angle_phi_ijl = ((acos(ex_jl * ex_ik +
			                  ey_jl * ey_ik +  //calculation of bond angle with conversion from radians to degrees
			                  ez_jl * ez_ik)) * (180/3.14159));

                   double ex_ijk = ((ey_ij * ez_ik) - (ez_ij * ey_ik));
                   double ey_ijk = ((ez_ij * ex_ik) - (ex_ij * ez_ik));    
                   double ez_ijk = ((ex_ij * ey_ik) - (ey_ij * ex_ik));    
                   double ex_ijl = ((ey_jl * ez_jl) - (ez_ik * ey_jl));    
                   double ey_ijl = ((ez_ik * ex_jl) - (ex_ik * ez_jl));    
                   double ez_ijl = ((ex_ik * ey_jl) - (ey_ik * ex_jl));
    
                   double exx = (ex_ijk * ex_ijl);
                   double eyy = (ey_ijk * ey_ijl);    
                   double ezz = (ez_ijk * ez_ijl);
    
                   double tau_ijkl = ((exx + eyy + ezz) / (sin(angle_jik)*sin(angle_phi_ijl))) * (180/3.14159);
		   
		   torRow.push_back(i);
		   torRow.push_back(j);
		   torRow.push_back(k);
		   torRow.push_back(l);
		
		   torRow.push_back(ex_ij);
		   torRow.push_back(ey_ij);
		   torRow.push_back(ez_ij);
		
		   torRow.push_back(ex_ik);
		   torRow.push_back(ey_ik);
		   torRow.push_back(ez_ik);
		   
		   torRow.push_back(ex_jl);
                   torRow.push_back(ey_jl);
                   torRow.push_back(ez_jl);
		
		   torRow.push_back(angle_jik);
		   torRow.push_back(angle_phi_ijl);
		   torRow.push_back(tau_ijkl);
		  
		   dihedral_angle_v.push_back(torRow);
	        }
	    }
	}
    }
    
    for(int i = 0; i < dihedral_angle_v.size(); i++) {
        double a1_double = (dihedral_angle_v[i][0]);
	double a2_double = (dihedral_angle_v[i][1]);
	double a3_double = (dihedral_angle_v[i][2]);
	double a4_double = (dihedral_angle_v[i][3]);
	
	int a1_int = a1_double;
	int a2_int = a2_double;
	int a3_int = a3_double;
	int a4_int = a4_double;
	
	string a1_string = (vector_coords[a1_int][0]);
	string a2_string = (vector_coords[a2_int][0]);
	string a3_string = (vector_coords[a3_int][0]);
	string a4_string = (vector_coords[a4_int][0]);	
	
	cout << a1_string << "  " << a2_string << "  " << a3_string << "  " << a4_string << "  ";
	cout << a1_int << "  " << a2_int << "  " << a3_int << "  " << a4_int << "    ";
        cout << dihedral_angle_v[i][15];        
	cout << endl;
	
    }
}
    
    //ensure dihedral angle is not negative before addition of sign
 //   if(tau_ijkl < -1.0) tau_ijkl = acos(-1.0);
 // else if(tau_ijkl > 1.0) tau_ijkl = acos(1.0);
 //   else tau_ijkl = acos(tau);
    
 //   return tau_ijkl;

//determines sign of dihedral angle
//double sign_tau() {
        
//    double cross_yz = (ey_ijk * ez_jkl) - (ez_ijk * ey_jkl);
    
//    double cross_xz = (ez_ijk * ex_jkl) - (ex_ijk * ez_jkl);
    
//    double cross_xy = (ex_ijk * ey_jkl) - (ey_ijk * ex_jkl);
    
//    double normal = cross_yz * cross_yz + cross_xz * cross_xz + cross_xy * cross_xy;
    
//    cross_yz /= normal;
    
//    cross_xz /= normal;
    
//    cross_xy /= normal;
    
//    double sign = 1.0;
    
//    double dot = (cross_yz * ex_jk) + (cross_xz * ey_jk) + (cross_xy * ez_jk);
    
//    if(dot < 0.0) sign = -1.0;
    
//    return tau_ijkl * sign;
    
//    log << "Completed calculation of dihedral angle including sign of angle";
    
//    log.close();
