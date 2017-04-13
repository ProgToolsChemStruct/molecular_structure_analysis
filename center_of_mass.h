/**
 * @file center_of_mass.h
 * @author Thomas Summers
 * @date 13 April 2017
 *
 * This file contains the declarations for the variables and functions used to 
 * calculate the center of mass of the model in the respective center_of_mass.cpp
 * file.  
 */

#include <vector>
#include <string>
#include <stdlib.h>

/**
 * The array is arranged based upon increasing atomic number.  The source for 
 * the atomic masses and other physical constants used throughout this program are 
 * from the National Institute of Standard and Technology website 
 * (http://physics.nist.gov/cgi-bin/Compositions/stand_alone.pl?ele=&ascii=html&isotype=some).
 */

const double atomic_masses[] =
{
0.00,
1.00782503223,
4.00260325413,
7.0160034366,
9.012183065,
11.00930536,
12.000000000,
14.00307400443,
15.99491461957,
18.99840316273,
19.9924401762,
22.9897692820,
23.985041697,
26.98153853,
27.97692653465,
30.97376199842,
31.9720711744,
34.968852682,
39.9623831237
};

/**
 * This function converts an input string @p symb into its respective 
 * integeric atomic number (i.e. Carbon gets converted to 6).
 */

int symbol_to_atomic_number(std::string symb);

/**
 * This function calculates the total mass of the model stored within the vector @p array.
 * This is achieved by converting the stored string atomic symbols (i.e. C, H, O) into 
 * their respective atomic numbers via the symbol_to_atomic_number() function and then
 * using this variable to obtain its respecitve stored atomic mass found in the array
 * #atomic_masses.
 */

double calculate_total_mass();

/**
 * This function calculates the products between atomic coordinates and their masses.
 * There is flexibility in that the function calls either the X, Y, or Z coordinates
 * to multiply against their respective atomic masses, depending on which integer
 * is placed in the function parameter
 */

double calc_prod_coords_mass(int position);
