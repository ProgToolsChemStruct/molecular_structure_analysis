/**
 * @file    angles.h
 * @author  Kate Charbonnet
 * @param   none
 * @return  0 on success
 *
 * The purpose of this program is to calculate molecular bond angles (phi) and torsion angles (tau).
 */

#ifndef ANGLES_H
#define ANGLES_H

using namespace std;

/** The function "atom_distance_f" calculates the distances between all the possible atom
 * pairings found in the input molecule and prints them out. Then, this function creates the
 * 2D vector "bond_exist" and uses it to determine which atoms are actually bonded to
 * each other (signifying bonds with the integer 1 and non-bonds with 0). The cutoff distance
 * used is 1.55 Angstroms, which is the average distance of a carbon-carbon single bond. The
 * vector "bond_exist" is printed out in the log.txt file for reference.
 */
void atom_distance_f(int number_atoms);

/** The function "unit_vectors" calculates the unit vectors needed for the later
 * bond angle and torsion angle calculations.
 */
double unit_vectors(int a1, int a2, int col);

/** The function "bond_angle_f" calculates all possible bond angles in the
 * input molecule.
 */
void bond_angle_f(int number_atoms);

/** The function "display_bond_angles" prints out the previously calculated
 * bond angles.
 */
void display_bond_angles(int number_atoms);

/** The function "torsion_angle_f" calculates all possible torsion angles
 * in the input molecule.
 */
void torsion_angle_f(int number_atoms);

/** The function "display_torsion_angles" prints out the previously calculated
 * torsion angles in the input molecule.
 */
void display_torsion_angles(int number_atoms);

#endif //ANGLES_H
