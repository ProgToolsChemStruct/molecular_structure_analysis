/**
 * @mainpage The Gaussian Optimization Analytical Tool (GOAT)
 *
 * Welcome to the Gaussian Optimization Analytical Tool (GOAT) documentation site!
 * Users may find relevant info related to this program, a program designed to provide
 * structural analyses of biomolecules successfully optimized using Gaussian software.
 *
 * @short   Main program
 * @file    main.cpp
 * @author  Kate Charbonnet, Hannah Lozano, and Thomas Summers
 * @param   none
 * @return  0 on success
 *
 * The purpose of this program is to provide preliminary structural information on biomolecules
 * optimized using Gaussian computational chemistry software.  Structural and chemical properties
 * identified include: element identification, bond length, bond angles, and dihedral
 * angles.  Input of the file to be analyzed will result in an output file listing all the structural
 * information of the molecule.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

#include "main.h"
#include "extraction.h"
#include "center_of_mass.h"
#include "bond_angle.h"
#include "dihedral_angle.h"
#include "elements.h"
#include "bond_length.h"
#include "bond_number.h"



using namespace std;

int main(int argc, char* argv[]) {

    ofstream logfile;
    fstream bond_angle;
    fstream dihedral_angle;
    fstream bond_length;

    //Check that inputfile was directed into the command line
    if (argc < 2) {
        cout << "Error: Inputfile not specified in command line\n";
        return 1;
    }

    //Generate a logfile
    logfile.open("log.txt");
    if (!logfile.is_open()) {
        cout << "Error: Unable to open the logfile.";
        return 2;
    } else {
        logfile << "Logfile for Gaussian Optimization Analytical Tool" << endl;
    }

    //Extract the raw coordinates from the inputfile in the commandline
    if (extract_input(argv[1]) != 0) {
        cout << "Error occured in extracting the coordinates.\n";
    } 

    //Print the vector size and vector contents
    if (print_vector_coords() != 0) {
        cout << "Error occured in printing the coordinates.\n";
    }

    //Calculate the model's total mass
    double model_mass = calculate_total_mass();

    //Calculate the model's center of mass coordinates
    double xcoord = calc_prod_coords_mass(2) / model_mass;
    double ycoord = calc_prod_coords_mass(3) / model_mass;
    double zcoord = calc_prod_coords_mass(4) / model_mass;

    cout << "Model's Center of Mass coordinates: " << endl
         << xcoord << "     " << ycoord << "     " << zcoord << endl;

    //Output the calculated interatomic distances
    //Bond_Length model;
    //model.atom_distance();
    
    //Output Bond numbers of atoms
    extern vector< vector<string> > vector_coords;
    
    int number_atoms = vector_coords.size();
    
    atom_distance(number_atoms);
    
    extern vector< vector<double> > R;
    extern vector< vector<int> > bond_exist;
    
    for(int i = 0; i < number_atoms; i++) {  //for loop for debugging purposes (not permanent)
        for(int j = i + 1; j < number_atoms; j++) {
            cout << bond_exist[i][j] << "    ";
        }
        
	    cout << endl;
	
    }
        
    //Output the number of bonds between atoms  
    number_bonds();
    
    //Calculate the molecule's bond angles
    extern vector< vector<double> > bond_angle_v;
    
    bond_angle_f(number_atoms);
    
    //Calculate the molecule's dihedral angles
    
}
