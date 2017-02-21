#include <iostream>
#include <string>
#include <fstream>

#include "main.h"

using namespace std;

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

