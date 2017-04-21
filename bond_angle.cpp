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

int total_atoms = 100;  //set max number of atoms at 100
extern vector< vector<string> > vector_coords;  //2D vector "vector_coords" in extraction.cpp
extern int number_atoms;

typedef vector<int> Row;
typedef vector<double> dblRow;
typedef vector<Row> Matrix;
typedef vector<dblRow> dblMatrix;
    dblMatrix R(total_atoms,dblRow(total_atoms));  //vector containing interatomic distances in Angstroms
    Matrix bond_exist(total_atoms,Row(total_atoms));  //vector contains 1 for bond and 0 for no bond

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

    for(int i = 0; i < number_atoms; i++) {
        for(int j = i + 1; j < number_atoms; j++) {
	
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

           //making sure vector is initialized from either direction to avoid "nan"
            R[i][j] = distance;
	          R[j][i] = distance;

	          if(distance < 1.55) {
	              bond_exist[i][j] = 1;
		            bond_exist[j][i] = 1;
	          } else {
	                bond_exist[i][j] = 0;
		              bond_exist[j][i] = 0;
              }
           }

     	    cout << atom1 << "  " << atom2 << "    " << R[i][j] << endl;
          log << atom1 << "  " << atom2 << "    " << R[i][j] << endl;
          outputfile << atom1 << "  " << atom2 << "    " << R[i][j] << endl;
        }
    }

    log << "Bond exist vector (1 for bonding and 0 for non-bonding): " << endl;

    for(int i = 0; i < number_atoms; i++) {  //for loop for debugging purposes (not permanent)
        for(int j = i + 1; j < number_atoms; j++) {
            log << bond_exist[i][j] << "    ";
        }
	          log << endl;
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

//scan bond_exist vector seeking all places where at least 3 atoms connect
void bond_angle_f(int number_atoms) {

    ofstream outputfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);
    
    int z = 0;
  
    cout << "Bond angles (in degrees): " << endl;
    log << "Calculated unit vectors and bond angles (in degrees): " << endl;
    outputfile << "Bond angles (in degrees): " << endl;

    //scan bond_exist vector on ith row
    for(int i = 0; i < number_atoms; i++) {

        //scan columnns of ith row to look for atom that bonds to ith atom
        for(int j = 0; j < number_atoms; j++) {
	          if(bond_exist[i][j] == 1) {

                //scan columns of ith row seeking second atom that bonds to ith atom
	              for(int k = j + 1; k < number_atoms; k++) {

                    //found two atoms that bond to i, therefore have an angle to calculate
		                if(bond_exist[i][k] == 1) {
		      
		                    angRow.clear();
		      
                            double ex_ij = unit_vectors(i,j,2);
		                        double ey_ij = unit_vectors(i,j,3);
		                        double ez_ij = unit_vectors(i,j,4);
		                        double ex_ik = unit_vectors(i,k,2);
		                        double ey_ik = unit_vectors(i,k,3);
		                        double ez_ik = unit_vectors(i,k,4);			

		                        double angle_phi = ((acos(ex_ij * ex_ik +
			                                                ey_ij * ey_ik +  //calculation of bond angle between atoms j-i-k
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
		                        angRow.push_back(angle_phi);		  
		                        bond_angle_v.push_back(angRow);		  
		                        z++;
		                    }
                    }
               }
          }
     }
}

void display_bond_angles(int number_atoms) {

    ofstream outputfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);

    //found all bond angles, now time to display them
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
	      log << a1_string << "  " << a2_string << "  " << a3_string << "  ";
	      outputfile << a1_string << "  " << a2_string << "  " << a3_string << "  ";
        log << a1_int << "  "   << a2_int << "  " << a3_int << "    ";
	      log << bond_angle_v[i][3] << "  ";
	      log << bond_angle_v[i][4] << "  ";
	      log << bond_angle_v[i][5] << "  ";
	      log << bond_angle_v[i][6] << "  ";
	      log << bond_angle_v[i][7] << "  ";
	      log << bond_angle_v[i][8] << "  ";
        cout << bond_angle_v[i][9];
	      log << bond_angle_v[i][9];
        outputfile << bond_angle_v[i][9];
	      cout << endl;
        log << endl;
        outputfile << endl;
    }
}

vector<double> torRow;
vector< vector<double> > dihedral_angle_v;

void torsion_angle_f(int number_atoms) {

    ofstream outputfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);

cout << "Torsion angles (in degrees): " << endl;
log << "Torsion angles (in degrees): " << endl;
outputfile << "Torsion angles (in degrees): " << endl;

//scan bond angle vector from top to bottom looking for torsion angles
    for(int ba = 0; ba < bond_angle_v.size(); ba++) {
       int i = (bond_angle_v[ba][0]);
       int j = (bond_angle_v[ba][1]);
       int k = (bond_angle_v[ba][2]);

       //prevents finding duplicate mirror image torsion angles
       if(k > i) {

       //search for all atoms that bond to k that are not i
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
			                                               ey_kl * ey_ik +  //calculation of bond angle between atoms i-k-l
			                                               ez_kl * ez_ik))
                                                     * (180/3.14159));

                       double ex_ijk = ((ey_ij * ez_ik) - (ez_ij * ey_ik));
                       double ey_ijk = ((ez_ij * ex_ik) - (ex_ij * ez_ik));    
                       double ez_ijk = ((ex_ij * ey_ik) - (ey_ij * ex_ik));    
                       double ex_ikl = ((ey_ik * ez_kl) - (ez_ik * ey_kl));
                       double ey_ikl = ((ez_ik * ex_kl) - (ex_ik * ez_kl));    
                       double ez_ikl = ((ex_ik * ey_kl) - (ey_ik * ex_kl));
    
                       double exx = (ex_ijk * ex_ikl);
                       double eyy = (ey_ijk * ey_ikl);    
                       double ezz = (ez_ijk * ez_ikl);
    
                       double tau_ijkl = ((exx + eyy + ezz) / 
                                          (sin(angle_jik)*sin(angle_phi_ikl)))  //calculation of torsion angles (tau)
                                          * (180/3.14159);
		   
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
  }


        //search for all torsion angles connected to j, but do not find duplicate mirror image torsion angle
        if(j > i) {
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
			                                                 ez_jl * ez_ik))
                                                       * (180/3.14159));

                         double ex_ijk = ((ey_ij * ez_ik) - (ez_ij * ey_ik));
                         double ey_ijk = ((ez_ij * ex_ik) - (ex_ij * ez_ik));    
                         double ez_ijk = ((ex_ij * ey_ik) - (ey_ij * ex_ik));    
                         double ex_ijl = ((ey_ik * ez_jl) - (ez_ik * ey_jl));    
                         double ey_ijl = ((ez_ik * ex_jl) - (ex_ik * ez_jl));    
                         double ez_ijl = ((ex_ik * ey_jl) - (ey_ik * ex_jl));
    
                         double exx = (ex_ijk * ex_ijl);
                         double eyy = (ey_ijk * ey_ijl);    
                         double ezz = (ez_ijk * ez_ijl);
    
                         double tau_ijkl = ((exx + eyy + ezz) / 
                                            (sin(angle_jik)*sin(angle_phi_ijl)))  //calculation of torsion angles (tau)
                                            * (180/3.14159);
		   
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
    }
}

void display_torsion_angles(int number_atoms) {

    ofstream outputfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);

    //found all torsion angles, now time to display them
    //scan torsion angles vector displaying all found torsion angles
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
        log << a1_string << "  " << a2_string << "  " << a3_string << "  " << a4_string << "  ";
        outputfile << a1_string << "  " << a2_string << "  " << a3_string << "  " << a4_string << "  ";
	      log << a1_int << "  " << a2_int << "  " << a3_int << "  " << a4_int << "    ";
        cout << dihedral_angle_v[i][15];
        log << dihedral_angle_v[i][15];
        outputfile << dihedral_angle_v[i][15];
	      cout << endl;
        log << endl;
        outputfile << endl;
    }
}
