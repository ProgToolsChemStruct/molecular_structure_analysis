#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
//#include <Eigen/Dense>
//#include <Eigen/Eigenvalues>
//#include <Eigen/Core>

#include "inertia.h"
#include "angles.h"

using namespace Eigen;

extern vector< vector<string> >vector_coords; //vector in extration.cpp 
inertia_v = vector_coords.asDiagonal()
DiagonalMatrix<Scalar,SizeAtCompileTime> diagle(size);

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> Matrix;
typedef Eigen::Matrix<double, Eigen::Dynamic, 1>Vector;

using namespace std;

void calc_inertia() {

    ofstream outpulfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);
    
    cout << "Moment of inertia tensor (amu bohr^2): " << endl;
    log << "Moment of inertia tensor (amu bohr^2): " << endl;
    outputfile << "Moment of inertia temsor (amu bohr^2); " << endl;
    
    Matrix I(3,3);
    
    for(int i = 0; i < vector_coords.size(); i++) {
	I(0,0) = ((pow(vector_coords[i][3])2) + (pow(vector_coords[i][4])2)));
	I(1,1) = ((pow(vector_coords[i][2])2) + (pow(vector_coords[i][4])2)));
	I(2,2) = ((pow(vector_coords[i][2])2) + (pow(vector_coords[i[[4])2)));
	I(0,1) = ((vector_coords[i][2])*(vector_coords[i][3]));
	I(0,2) = ((vector_coords[i][2])*(vector_coords[i][4]));
	I(1,2) = ((vector_coords[i][3])*(vector_coords[i][4]));
    }	
    
    I(1,0) = I(0,1);
    I(2,0) = I(0,2);
    I(2,1) = I(1,2);
    
     
