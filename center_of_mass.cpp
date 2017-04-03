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
}


//Calculate the sum of all of the masses of the elements
double total_mass = 0.00;

double calculate_total_mass ()
{
    ofstream log;
    log.open("log.txt", ios::app);

    log << "Calculations for the total mass of the model:" << endl;

    for (int i = 0; i < totalatoms; i++)
    {
        int element_number;
        extern vector< vector<string> > array;
        element_number = symbol_to_atomic_number(array[i][0]);
        log << element_number << "	";
        total_mass = total_mass + atomic_masses[element_number];
        log << std::scientific << total_mass << endl;
    }

    log << "Total Mass of model: " << total_mass << " amu" << endl;
    log.close();
    return total_mass;
}
