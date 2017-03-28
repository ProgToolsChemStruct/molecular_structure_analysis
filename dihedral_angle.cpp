#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

/**calculates dihedral angle between planes i-j-k and j-k-l*/
double Dihedral_Angle() {
    
    double ex_ijk = ((ey_ji*ez_jk)-(ez_ji*ey_jk));
    
    double ey_ijk = ((ez_ji*ex_jk)-(ex_ji*ez_jk));
    
    double ez_ijk = ((ex_ji*ey_jk)-(ey_ji*ex_jk));
    
    double ex_jkl = 
    
    double e_ji(double ex_ji, double ey_ji, double ez_ji); 

    double e_jk(double ex_jk, double ey_jk, double ez_jk);   

    double e_kl(double ex_kl, double ey_kl, double ez_kl); 

    double tau_ijkl(double ex_ji, double ey_ji, double ez_ji, double ex_jk, double ey_jk, double ez_jk, double ex_kl, double ey_kl, double ez_kl, double phi_ijk, double phi_jkl) {
    
    double e_ji[3] = {ex_ji, ey_ji, ez_ji};
