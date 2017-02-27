#include <iostream>
#include <cmath>

using namespace std;

double ex_ji(double x_j, double x_i, double R_ji) {     
    double ex_ji_v = ((-(x_j-x_i))/R_ji);  //v for variable
    return ex_ji_v;
}
double ey_ji(double y_j, double y_i, double R_ji) {
    double ey_ji_v = ((-(y_j-y_i))/R_ji);  //v for variable
    return ey_ji_v;
}
double ez_ji(double z_j, double z_i, double R_ji) {
    double ez_ji_v = ((-(z_j-z_i))/R_ji);  //v for variable
    return ez_ji_v;
}
double ex_jk(double x_j, double x_k, double R_jk) {     
    double ex_jk_v = ((-(x_j-x_k))/R_jk); //v for variable
    return ex_jk_v;
}
double ey_jk(double y_j, double y_k, double R_jk) {
    double ey_jk_v = ((-(y_j-y_k))/R_jk);  //v for variable
    return ey_jk_v;
}
double ez_jk(double z_j, double z_k, double R_jk) {
    double ez_jk_v = ((-(z_j-z_k))/R_jk);  //v for variable
    return ez_jk_v;
}    
double ex_kl(double x_k, double x_l, double R_kl) {     
    double ex_kl_v = ((-(x_k-x_l))/R_kl);  //v for variable
    return ex_kl_v;
}
double ey_kl(double y_k, double y_l, double R_kl) {
    double ey_kl_v = ((-(y_k-y_l))/R_kl);  //v for variable
    return ey_kl_v;
}
double ez_kl(double z_k, double z_l, double R_kl) {
    double ez_kl_v = ((-(z_k-z_l))/R_kl);  //v for variable
    return ez_kl_v;
}
