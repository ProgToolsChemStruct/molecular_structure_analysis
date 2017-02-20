#include <iostream>
#include <string>
#include <fstream>

#include "main.h"

using namespace std;

int atomic_distance (int atom_dist_x, int atom_dist_y, int atom_dist_z); //Defines atomic distance as combination of x, y, z coordinates

int main() {
	string input_file_name;
	ifstream input_file;

	//Display prompt for input file name
	cout << "Please input the name of Gaussian optimization file: ";
	cin >> input_file_name;

	//Check that input file opens
	input_file.open(input_file_name.c_str() );
	if (!input_file.is_open() ) {
		cout << "Error: Unable to open the input file.";
		return 1;
	}

	const string gaussian_output::HEADER_STRING = "OPTIMIZED PARAMETERS";
	const string gaussian_output::FOOTER_STRING = "GradGradGradGradGradGradGradGradGradGradGrad";

	//Read through the file and for now output the coordinates
	while (getline(input_file, gaussian_coordinates, FOOTER_STRING))
	{
		if (gaussian_coordinates.find(HEADER_STRING) != string::npos)
		{
			cout << gaussian_coordinates << "\n";
		}
	}

	return 0;
}

