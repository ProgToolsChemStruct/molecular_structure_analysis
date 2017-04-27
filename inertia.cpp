#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>

#include "inertia.h"
#include "angles.h"

using namespace Eigen;

extern vector< vector<string> >vector_coords; //vector in extration.cpp 
typedef std::vector< std::vector<double > inertia_m;
inertia_m(size3, std::vector<double>(size3));   //turning vector_coords to doubles to matrix inertia_m
    
using namespace std;

double tolerance = 1.0e-20;
int jtop;
double del, hi2, hj2, 

//calc inertia tensors    
void calc_inertia() {

    ofstream outpulfile;
    ofstream log;
    outputfile.open("outputfile.txt", ios::app);
    log.open("log.txt", ios::app);
    
    cout << "Moment of inertia tensor (amu bohr^2): " << endl;
    log << "Moment of inertia tensor (amu bohr^2): " << endl;
    outputfile << "Moment of inertia temsor (amu bohr^2); " << endl
    
    //Initialze diagonals into matrix ineria_m
    for(int i = 0; i < vector_coords.size(); i++) { 
	 i2= (vector_coords[i][2])
	     for (j = i+1; j < vector_coords.size(); j++) {
	         j2= (vector_coords [i][3])
		 I[j2] = 0.0;
		 }
        I[i2] = 1.0;
    }
    
    //Check off-diagonal elements
    do {
        hmax = 0.0
        for(i = 1; i < vector_coords.size(); i++) {
	    jtop = i-1;
	    for(j = 0; j < vector_coords.size(); j++) {
	        i2 = (vector_coords[i][2]);
		j2 = (vector_coords[i][3]);
		i2j2 = (vector_coords[i][2], vector_coords[i][3]);
		j2i2 = (vector_coords[i][3]. vector_coords[i][2]);
		hi2 = H[i2];
		hj2 = H[j2];
		hi2j2 = H[i2j2];
		hsq = pow(hi2j2, 2);
		
		if(hsq > hmax)
		    hmax = hsq;
		if(hsq < tolerance)
		    continue; //omit zero H(i2j2)
		del = hi2 - hj2;
		sign = 1.0;
		if(del < 0.0) {
		    sign = -1.0;
		    del = -del;
		}
		denom = del + sqrt(pow(del,2) + (4.0*hsq));            
		
		  			 
	 
   
