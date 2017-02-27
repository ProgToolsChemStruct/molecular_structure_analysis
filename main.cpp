#include <iostream>
#include <string>
#include <fstream>

#include "main.h"
//#include "bond_angle.cpp"

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

int main(int argc, char* argv[]) {
    ifstream inputfile;
    string line;
    string header = "                           !   Optimized Parameters   !";

    //Check that input file was directed into the command line
    if (argc < 2) {
        cout << "Error: Inputfile not specified in command line\n";
        return 0;
    }

    //Open the input file and check that it opened
    inputfile.open(argv[1]);
    if (!inputfile.is_open()) {
        cout << "Error: Unable to open the input file.";
        return 1;
    }

    //Generate a log file and check that it opened
    ofstream logfile;
    logfile.open("log.txt");
    if (!logfile.is_open()) {
        cout << "Error: Unable to open the logfile.";
        return 2;
    }

    //Search the input file
    while (getline(inputfile, line)) {
		if (line.find(header, 0) != string::npos) {
			cout << "Found: " << header << endl;
		}
	}
	inputfile.close();
	cout << "Search Complete";
	logfile << "Found: " << header << endl;
	logfile.close();
	return 0;
}
	//Open the file bond_angle.cpp and check that it opened
//	ofstream bond_angle;
//	bond_angle.open("bond_angle.cpp");
//	if (!bond_angle.is_open()) {
//		cout << "Error: Unable to open bond_angle file.";
//		return 1;
//	}
	//Close the file bond_angle.cpp
//	bond_angle.close("bond_angle.cpp");
//	cout << "Bond angle calculation complete.";
//	return 0;
//}


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

