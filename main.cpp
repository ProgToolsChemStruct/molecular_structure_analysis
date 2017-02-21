#include <iostream>
#include <string>
#include <fstream>

#include "main.h"

using namespace std;
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
 * identified include: element identification, bond length, bond order, central angles, and torsional
 * angles.  Input of the file to be analyzed will result in an output file listing all the structural
 * information of the biomolecule.
 */

int atomic_distance (int atom_dist_x, int atom_dist_y, int atom_dist_z); //Defines atomic distance as combination of x, y, z coordinates

int main() {
	ifstream inputfile;
	string line;
	string header = "OPTIMIZED PARAMETERS";

	//Open the input file and check that it opened
	inputfile.open("gaussian_opt_file");
	if (!inputfile.is_open() ) {
		cout << "Error: Unable to open the input file.";
		return 1;
	}
	
	//Search the input file
	while (getline(inputfile, line)) {
		if (line.find(header, 0) != string::npos) {
			cout << "Found: " << header << endl;
		}
	}
	inputfile.close();
	cout << "Search Complete";
	return 0;
}


	//const string gaussian_output::HEADER_STRING = "OPTIMIZED PARAMETERS";
	//const string gaussian_output::FOOTER_STRING = "GradGradGradGradGradGradGradGradGradGradGrad";

	//Read through the file and for now output the coordinates
	//while (getline(input_file, gaussian_coordinates, FOOTER_STRING))
	//{
		//if (gaussian_coordinates.find(HEADER_STRING) != string::npos)
		//{
			//cout << gaussian_coordinates << "\n";
		//}
	//}

	//return 0;
//}

