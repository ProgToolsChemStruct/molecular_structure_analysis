/**
 * @file center_of_mass.h
 * @author Thomas Summers
 * @date 3 April 2017
 *
 * @brief File containing declarations for calculating the model center of mass
 *
 * This file contains the declarations for the variables and functions used to 
 * calculate the center of mass of the model in the respective center_of_mass.cpp
 * file.  
 */

#include <vector>
#include <string>

/**
 * @brief Array storing the masses of the most common isotope of atomic elements
 *
 * The array is arranged based upon increasing atomic number.  As such, array 
 * position 0 coordinates to the mass of Element Zero 
 * (additional info: http://masseffect.wikia.com/wiki/Element_Zero), array
 * position 1 coordinates to the mass of the Hydrogen atom with one neutron
 * in its nucleus, array position 2 coordinates to the mass of the Helium atom
 * with four neutrons in its nucleus, etc.  The source for the atomic masses
 * and other physical constants used throughout this program are from the
 * National Institute of Standard and Technology website 
 * (http://physics.nist.gov/cgi-bin/Compositions/stand_alone.pl?ele=&ascii=html&isotype=some).
 */

double atomic_masses[] =
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
 * @see totalatoms
 */
extern unsigned int totalatoms;

/**
 * @brief Externally declared variable used to store the total mass calculated
 */
extern double total_mass;

/**
 * @brief Function used to convert Atomic Symbols to Atomic Numbers
 *
 * Atoms are commonly characterized by their chemical symbol (i.e. the element
 * Carbon is commonly represented by its symbol C).  This function converts an
 * input string @p symb into its respective integeric atomic number (i.e. Carbon gets 
 * converted to 6).
 *
 * @param symb
 * @return The function returns the integeric atomic number of the symbol input
 */
int symbol_to_atomic_number(string symb);

/**
 * @brief Function used to calculate the total mass of a model stored in the vector "array"
 *
 * This function calculates the total mass of the model stored within the vector @p array.
 * This is achieved by converting the stored string atomic symbols (i.e. C, H, O) into 
 * their respective atomic numbers via the symbol_to_atomic_number() function and then
 * using this variable to obtain its respecitve stored atomic mass found in the array
 * #atomic_masses.  This value is usually stored in #total_mass.
 * 
 * @return The function returns a @c double of the total mass of the model
 * @see total_mass
 * @see symbol_to_atomic_number()
 * @see atomic_masses
 */
double calculate_total_mass();
