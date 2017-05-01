#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <cassert>

#include "inertia.h"
#include "angles.h"
#include "center_of_mass.h"
    
using namespace std;

extern vector< vector<string> >vector_coords; //vector in extration.cpp 

double calc_inertia_diagonal (int pos1, int pos2) { //calculates diagonal moments of inertia
double tensor = 0; 
    for(size_t i=0; i < vector_coords.size(); i++) {
        string string_val1 = vector_coords[i][pos1]; 
	string string_val2 = vector_coords[i][pos2]; 
	
	double double_val1 = atof(string_val1.c_str()); //string to double
	double double_val2 = atof(string_val2.c_str());
	
	double mass = atomic_masses[symbol_to_atomic_number(vector_coords[i][0])];
	
	tensor += mass * ((pow(double_val1, 2) + (pow(double_val2, 2)))); 
	
	}
	return tensor;	 
   }

double calc_inertia_off_diagonal (int pos1, int pos2) { //claclulates off-diagonal moments of inertia
double tensor = 0;
    for(size_t i=0; i < vector_coords.size(); i++) {
        string string_val1 = vector_coords[i][pos1];
	string string_val2 = vector_coords[i][pos2];
	
	double double_val1 = atof(string_val1.c_str()); //string to double
	double double_val2 = atof(string_val2.c_str());
	
	double mass = atomic_masses[symbol_to_atomic_number(vector_coords[i][0])];
	
	tensor += (mass * double_val1 * double_val2);

	}
	return tensor;
    }
	    
//calc the elements of the inertia    
void inertia_tensor() {

     cout << "Inertia tensor: " << endl;
    
    //get 3x3 matrix with 0 in each element 
     double arr[2][2];
	 for (int i=0; i < 2; i++){
	     for(int j=0; j < 2; j++){
	         arr[i][j] = 0.0; 
             }
	 }
    //add atom's contribution to each tensor element 
    arr[0][0] = calc_inertia_diagonal(3,4); //outputs diagonal moments of inertia
    arr[1][1] = calc_inertia_diagonal(2,4);
    arr[2][2] = calc_inertia_diagonal(2,3);
        
    arr[0][1] = calc_inertia_off_diagonal(2,3); //outputs off-diaonal moments of inertia
    arr[0][2] = calc_inertia_off_diagonal(2,4);
    arr[1][2] = calc_inertia_off_diagonal(3,4);
    
    arr[1][0] = arr[0][1]; //takes the off diagonal moments of inertia and equals them to their flipped spaces
    arr[2][0] = arr[0][2];
    arr[2][1] = arr[1][2];
  
    cout << arr[0][0] << "     " << arr[0][1] << "    " << arr[0][2] << endl;
    cout << arr[1][0] << "     " << arr[1][1] << "    " << arr[1][2] << endl;
    cout << arr[2][0] << "     " << arr[2][1] << "    " << arr[2][2] << endl;
    
    }
