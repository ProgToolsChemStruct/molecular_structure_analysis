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

//header content
void atom_dist(string x1_string, string x2_string,
               string y1_string, string y2_string,
               string z1_string, string z2_string,
	       double x1_double, double x2_double,
	       double y1_double, double y2_double,
	       double z1_double, double z2_double);
		 
extern vector< vector<double> > atomic_distance;

extern vector< vector<int> > bond_exist;

extern vector< vector<double> > unit_vector;

extern vector< vector< vector<double> > > bond_angle;

void angle_phi(double x1_unit, double x2_unit,
               double y1_unit, double y2_unit,
	       double z1_unit, double z2_unit);
#endif //BOND_ANGLE_H
