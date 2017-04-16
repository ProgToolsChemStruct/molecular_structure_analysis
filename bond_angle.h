/**
 * @file    bond_angle.h
 * @author  Kate Charbonnet
 * @param   none
 * @return  0 on success
 *
 * The purpose of this program is to calculate bond angles (phi) using calculated unit vectors
 * and bond distances. 
 */

//header guard
#ifndef BOND_ANGLE_H
#define BOND_ANGLE_H

using namespace std;

void atom_distance(int i, int j, int k, int l, double distance, 
                   string atom1, string atom2, string atom3, string atom4,
		   string x1_string, string x2_string, 
		   string y1_string, string y2_string, 
		   string z1_string, string z2_string, 
		   double x1_double, double x2_double,
		   double y1_double, double y2_double,
		   double z1_double, double z2_double, 
		   vector< vector<string> > & vector_coords);

void unit_vects(int i, int j, 
                double x1_double, double x2_double, 
		double y1_double, double y2_double, 
		double z1_double, double z2_double, 
		vector< vector<double> > & R, 
		vector< vector<string> > & vector_coords);
		
void bond_angle_phi(int i, int j, int k, 
                    string atom1, string atom2, string atom3, 
		    vector< vector<double> > & R, 
		    vector< vector<double> > & unit_vectors, 
		    vector< vector<string> > & vector_coords);
      
#endif //BOND_ANGLE_H
