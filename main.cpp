#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "main.h"
#include "extraction.h"
#include "bond_angle.h"
#include "dihedral_angle.h"

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

int main(int argc, char* argv[])
{
    ofstream logfile;
    fstream bond_angle;
    fstream dihedral_angle;

    //Check that inputfile was directed into the command line
    if (argc < 2)
    {
        cout << "Error: Inputfile not specified in command line\n";
        return 1;
    }

    //Generate a logfile
    logfile.open("log.txt");
    if (!logfile.is_open())
    {
        cout << "Error: Unable to open the logfile.";
        return 3;
    } else {
        logfile << "Logfile for Gaussian Optimization Analytical Tool" << endl;
    }

    //Extract the raw coordinates from the inputfile in the commandline
    Extraction molecule(argv[1]);

    //Clean the coords file
    molecule.trim_coords(2);

    //Generate the 2D array of the coordinates
    molecule.array_coords();

    //Open the file bond_angle.cpp and check that it opened
    bond_angle.open("bond_angle.cpp");
    if (!bond_angle.is_open()) {
        cout << "Error: Unable to open file bond_angle.";
        return 1;
    }
    //Close the file bond_angle.cpp
    bond_angle.close();
    cout << "Bond angle calculation complete." << endl;
    return 0;
    
    //Open the file dihedral_angle.cpp and check that it opened
    dihedral_angle.open("dihedral_angle.cpp");
    if (!dihedral_angle.is_open()) {
        cout << "Error: Unable to open file dihedral_angle.";
        return 1;
    }
    //Close the file dihedral_angle.cpp
    dihedral_angle.close();
    cout << "Dihedral angle calculation complete.";
    return 0;
}
