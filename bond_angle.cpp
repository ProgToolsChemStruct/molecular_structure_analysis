#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double ex_ji(double x_j, double x_i, double R_ji) {     
    return ((-(x_j-x_i))/R_ji);
}

double ey_ji(double y_j, double y_i, double R_ji) {
    return ((-(y_j-y_i))/R_ji);
}

double ez_ji(double z_j, double z_i, double R_ji) {
    return ((-(z_j-z_i))/R_ji);
}    

double ex_jk(double x_j, double x_k, double R_jk) {     
    return ((-(x_j-x_k))/R_jk);
}

double ey_jk(double y_j, double y_k, double R_jk) {
    return ((-(y_j-y_k))/R_jk);
}

double ez_jk(double z_j, double z_k, double R_jk) {
    return ((-(z_j-z_k))/R_jk);
}  

double ex_kl(double x_k, double x_l, double R_kl) {     
    return ((-(x_k-x_l))/R_kl);
}

double ey_kl(double y_k, double y_l, double R_kl) {
    return ((-(y_k-y_l))/R_kl);
}

double ez_kl(double z_k, double z_l, double R_kl) {
    return ((-(z_k-z_l))/R_kl);
}

double phi_ijk(double ex_ji, double ey_ji, double ez_ji, double ex_jk, double ey_jk, double ez_jk) {
    return acos((ex_ji)*(ex_jk)+(ey_ji)*(ey_jk)+(ez_ji)*(ez_jk));
}

double phi_jkl(double ex_kj, double ey_kj, double ez_kj, double ex_kl, double ey_kl, double ez_kl) {
    return acos((ex_kj)*(ex_kl)+(ey_kj)*(ey_kl)+(ez_kj)*(ez_kl));
}
