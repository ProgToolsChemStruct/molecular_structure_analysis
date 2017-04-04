/**
 * @file    dihedral_angle.h
 * @author  Kate Charbonnet
 * @param   none
 * @return  0 on success
 *
 * The purpose of this program is to calculate the dihedral angle, or torsion angle, (tau) between planes i-j-k
 * and j-k-l. 
 */

//header guard
#ifndef DIHEDRAL_ANGLE_H
#define DIHEDRAL_ANGLE_H

using namespace std;

//header content
double e_ji(double ex_ji, double ey_ji, double ez_ji); 

double e_jk(double ex_jk, double ey_jk, double ez_jk);   

double e_kl(double ex_kl, double ey_kl, double ez_kl); 

double tau_ijkl(
  double ex_ji, double ey_ji, double ez_ji, 
  double ex_jk, double ey_jk, double ez_jk, 
  double ex_kl, double ey_kl, double ez_kl, 
  double phi_ijk, double phi_jkl);

#endif
