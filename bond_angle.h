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

void atom_distance(int number_atoms);

double unit_vectors(int a1, int a2, int col);
		
void bond_angle_f(int number_atoms);

void torsion_angle_f(int number_atoms);
      
#endif //BOND_ANGLE_H
