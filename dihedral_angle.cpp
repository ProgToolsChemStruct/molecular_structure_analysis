#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double e_ji(double ex_ji, double ey_ji, double ez_ji); 

double e_jk(double ex_jk, double ey_jk, double ez_jk);   

double e_kl(double ex_kl, double ey_kl, double ez_kl); 

double tau_ijkl(double ex_ji, double ey_ji, double ez_ji, double ex_jk, double ey_jk, double ez_jk, double ex_kl, double ey_kl, double ez_kl, double phi_ijk, double phi_jkl) {
    
    double e_ji[3] = {ex_ji, ey_ji, ez_ji};
    
    
    c_x = (ey_ji*ez_jk)-(ez_ji*ey_jk)
    c_y = (ez_ji*ex_jk)-(ex_ji*ez_jk)
    c_z = (ex_ji*ey_jk)-(ey_ji*ex_jk)
