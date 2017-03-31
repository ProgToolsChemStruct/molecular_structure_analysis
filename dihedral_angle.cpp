#include <iostream>
#include <cmath>
#include <fstream>
#include "dihedral_angle.h"

using namespace std;

//calculates dihedral angle between planes i-j-k and j-k-l
double dihedral_angle() {
    
    //cross product of unit vectors
    double ex_ijk = ((ey_ji * ez_jk) - (ez_ji * ey_jk));
    
    double ey_ijk = ((ez_ji * ex_jk) - (ex_ji * ez_jk));
    
    double ez_ijk = ((ex_ji * ey_jk) - (ey_ji * ex_jk));
    
    double ex_jkl = ((ey_kl * ez_kl) - (ez_kj * ey_kl));
    
    double ey_jkl = ((ez_kj * ex_kl) - (ex_kj * ez_kl));
    
    double ez_jkl = ((ex_kj * ey_kl) - (ey_kj * ex_kl));
    
    //dot product and calculation of dihedral angle (tau)
    double exx = (ex_ijk * ex_jkl);
    
    double eyy = (ey_ijk * ey_jkl);
    
    double ezz = (ez_ijk * ez_jkl);
    
    double tau_ijkl = (exx + eyy + ezz) / (sin(phi_ijk)*sin(phi_jkl));
    
    //ensure dihedral angle is not negative before addition of sign
    if(tau_ijkl < -1.0) tau_ijkl = acos(-1.0);
    else if(tau_ijkl > 1.0) tau_ijkl = acos(1.0);
    else tau_ijkl = acos(tau);
    
    return tau_ijkl;
    
}

//determines sign of dihedral angle
double sign_tau() {
    
    double cross_yz = (ey_ijk * ez_jkl) - (ez_ijk * ey_jkl);
    
    double cross_xz = (ez_ijk * ex_jkl) - (ex_ijk * ez_jkl);
    
    double cross_xy = (ex_ijk * ey_jkl) - (ey_ijk * ex_jkl);
    
    double normal = cross_yz * cross_yz + cross_xz * cross_xz + cross_xy * cross_xy;
    
    cross_yz /= normal;
    
    cross_xz /= normal;
    
    cross_xy /= normal;
    
    double sign = 1.0;
    
    double dot = (cross_yz * ex_jk) + (cross_xz * ey_jk) + (cross_xy * ez_jk);
    
    if(dot < 0.0) sign = -1.0;
    
    return tau_ijkl * sign;
    
}
