#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double phi_ijk(double ex_ji, ex_jk, ey_ji, ey_jk, ez_ji, ez_jk) {  //unit vector parameters for bond angle phi_ijk
        double ex_ji(double x_j, x_i, R_ji) {     
            ex_ji == ((-(x_j-x_i))/R_ji);
        }
        double ey_ji(double y_j, y_i, R_ji) {
            ey_ji == ((-(y_j-y_i))/R_ji);
        }
        double ez_ji(double z_j, z_i, R_ji) {
            ez_ji == ((-(z_j-z_i))/R_ji);
        }
        double ex_jk(double x_j, x_k, R_jk) {     
            ex_jk == ((-(x_j-x_k))/R_jk);
        }
        double ey_jk(double y_j, y_k, R_jk) {
            ey_jk == ((-(y_j-y_k))/R_jk);
        }
        double ez_jk(double z_j, z_k, R_jk) {
            ez_jk == ((-(z_j-z_k))/R_jk);
        }   
        cos(phi_ijk) == ((ex_ji*ex_jk)+(ey_ji*ey_jk)+(ez_ji*ez_jk));
    }
    double phi_jkl(double ex_jk, ey_jk, ez_jk, ex_kl, ey_kl, ez_kl) {  //unit vector parameters for bond angle phi_jkl
        double ex_jk(double x_j, x_k, R_jk) {     
            ex_jk == ((-(x_j-x_k))/R_jk);
        }
        double ey_jk(double y_j, y_k, R_jk) {
            ey_jk == ((-(y_j-y_k))/R_jk);
        }
        double ez_jk(double z_j, z_k, R_jk) {
            ez_jk == ((-(z_j-z_k))/R_jk);
        }   
        double ex_kl(double x_k, x_l, R_kl) {     
            ex_kl == ((-(x_k-x_l))/R_kl);
        }
        double ey_kl(double y_k, y_l, R_kl) {
            ey_kl == ((-(y_k-y_l))/R_kl);
        }
        double ez_kl(double z_k, z_l, R_kl) {
            ez_kl == ((-(z_k-z_l))/R_kl);
        }
        cos(phi_jkl) == ((ex_kj*ex_kl)+(ey_kj*ey_kl)+(ez_kj*ez_kl));
    }  
    return 0;
}
