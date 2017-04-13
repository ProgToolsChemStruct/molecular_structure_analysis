#include "center_of_mass.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Function that returns an Element Symbol's integeric Atomic Number
int symbol_to_atomic_number (string symb)
{
    if (symb == " H" ) return 1;
    if (symb == " He") return 2;
    if (symb == " Li") return 3;
    if (symb == " Be") return 4;
    if (symb == " B" ) return 5;
    if (symb == " C" ) return 6;
    if (symb == " N" ) return 7;
    if (symb == " O" ) return 8;
    if (symb == " F" ) return 9;
    if (symb == " Ne") return 10;
    if (symb == " Na") return 11;
    if (symb == " Mg") return 12;
    if (symb == " Al") return 13;
    if (symb == " Si") return 14;
    if (symb == " P" ) return 15;
    if (symb == " S" ) return 16;
    if (symb == " Cl") return 17;
    if (symb == " Ar") return 18;
return 0;
}


//Calculate the sum of all of the masses of the elements
double calculate_total_mass () {
    ofstream log;
    ofstream outputfile;

    log.open("log.txt", ios::app);
    outputfile.open("outputfile.txt", ios::app);

    log << "Calculations for the total mass of the model:" << endl;

    extern vector< vector<string> > vector_coords;
    double total_mass = 0.00;

    for(int i = 0; i < vector_coords.size(); i++)
    {
        int element_number;
        element_number = symbol_to_atomic_number(vector_coords[i][0]);
        log << element_number << "     ";
        total_mass = total_mass + atomic_masses[element_number];
        log << std::scientific << total_mass << endl;
    }

    if(total_mass == 0) {
        cout << "Warning: Mass calculated to be zero." << endl;
        log << "Warning: Mass calculated to be zero." << endl;
    }

    cout << "Total Mass of model: " << total_mass << " amu" << endl;
    log << "Total Mass of model: " << total_mass << " amu" << endl;
    outputfile << "\nTotal Mass of model: " << total_mass << "amu" << endl;

    log.close();
    outputfile.close();

    return total_mass;
}

//Calculates the products between atomic coordinates and their masses
double calc_prod_coords_mass(int position)
{
    ofstream log;
    double product = 0.00;
    extern vector< vector<string> > vector_coords;

    log.open("log.txt", ios::app);

    log << "Calculating the product of the coordinates and masses for the ";
    switch (position) {
        case 2:
        {
            log << "X coordinate\n";
            break;
        }
        case 3: 
        {
            log << "Y coordinate\n";
            break;
        }
        case 4:
        {
            log << "Z coordinate\n";
            break;
        }
    }

    for (int i = 0; i < vector_coords.size(); i++)
    {
        double element_mass;
        string coordinate_string;
        double coordinate_double;

        element_mass = atomic_masses[symbol_to_atomic_number(vector_coords[i][0])];
        log << element_mass << "     ";
        coordinate_string = vector_coords[i][position];
        coordinate_double = atof(coordinate_string.c_str());
        product = product + (element_mass * coordinate_double);
        log << std::scientific << product << endl;
    }

    log << "Final product: " << product << " amu" << endl;
    return product;
}
