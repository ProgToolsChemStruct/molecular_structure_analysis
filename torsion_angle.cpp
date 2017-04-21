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
#include "torsion_angle.h"

using namespace std;

extern int number_atoms;
extern vector< vector<string> > vector_coords;
extern vector< vector<double> > bond_angle_v;
extern vector< vector<int> > bond_exist;
extern double unit_vectors(int a1, int a2, int col);

vector<double> torRow;
vector< vector<double> > torsion_angle_v;

void torsion_angle_f(int number_atoms) {

    ofstream outputfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);

    cout << "Torsion angles (in degrees): " << endl;
    log << "Torsion angles (in degrees): " << endl;
    outputfile << "Torsion angles (in degrees): " << endl;

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
		   
		   double angle_ikl = ((acos(ex_kl * ex_ik +
			                         ey_kl * ey_ik +  //calculation of bond angle with conversion from radians to degrees
			                         ez_kl * ez_ik))
                                                 * (180/3.14159));

                   double ex_ijk = ((ey_ij * ez_ik) - (ez_ij * ey_ik));
                   double ey_ijk = ((ez_ij * ex_ik) - (ex_ij * ez_ik));    
                   double ez_ijk = ((ex_ij * ey_ik) - (ey_ij * ex_ik));    
                   double ex_ikl = ((ey_kl * ez_kl) - (ez_ik * ey_kl));
                   double ey_ikl = ((ez_ik * ex_kl) - (ex_ik * ez_kl));    
                   double ez_ikl = ((ex_ik * ey_kl) - (ey_ik * ex_kl));
    
                   double exx = (ex_ijk * ex_ikl);
                   double eyy = (ey_ijk * ey_ikl);    
                   double ezz = (ez_ijk * ez_ikl);
    
                   double tau_ijkl = ((exx + eyy + ezz) / (sin(angle_jik)*sin(angle_ikl))) * (180/3.14159);
		   
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
		   torRow.push_back(angle_ikl);
		   torRow.push_back(tau_ijkl);
		  
		   torsion_angle_v.push_back(torRow);
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
		   double angle_ijl = ((acos(ex_jl * ex_ik +
			                     ey_jl * ey_ik +  //calculation of bond angle with conversion from radians to degrees
			                     ez_jl * ez_ik))
                                             * (180/3.14159));
                   double ex_ijk = ((ey_ij * ez_ik) - (ez_ij * ey_ik));
                   double ey_ijk = ((ez_ij * ex_ik) - (ex_ij * ez_ik));    
                   double ez_ijk = ((ex_ij * ey_ik) - (ey_ij * ex_ik));    
                   double ex_ijl = ((ey_jl * ez_jl) - (ez_ik * ey_jl));    
                   double ey_ijl = ((ez_ik * ex_jl) - (ex_ik * ez_jl));    
                   double ez_ijl = ((ex_ik * ey_jl) - (ey_ik * ex_jl));
                   double exx = (ex_ijk * ex_ijl);
                   double eyy = (ey_ijk * ey_ijl);    
                   double ezz = (ez_ijk * ez_ijl);
                   double tau_ijkl = ((exx + eyy + ezz) / (sin(angle_jik)*sin(angle_ijl))) * (180/3.14159);
		   
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
		   torRow.push_back(angle_ijl);
		   torRow.push_back(tau_ijkl);
		   torsion_angle_v.push_back(torRow);
	        }
	    }
	}
    }
    
    for(int i = 0; i < torsion_angle_v.size(); i++) {
        double a1_double = (torsion_angle_v[i][0]);
	double a2_double = (torsion_angle_v[i][1]);
	double a3_double = (torsion_angle_v[i][2]);
	double a4_double = (torsion_angle_v[i][3]);
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
        cout << torsion_angle_v[i][15];
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
