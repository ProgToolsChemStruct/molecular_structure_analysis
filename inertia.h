/**
 *@file inertia.h
 *@author Hannah Lozano
 *@param none
 *@return 0 upon success
 *
 *The purpose of this program is to determine the principal moments of inertia.
 */
 
//header guard
#ifndef INERTIA_H
#define INERTIA_H

double calc_inertia_diagonal (int pos1, int pos2);
/**
 * This function calculates the diagonal inertia tensor moments.
 */
double calc_inertia_off_diagonal (int pos1, int pos2);
/**
 * This function calculates the off-diagonal inertia tensor moments.
 */
void inertia_tensor ();
/**
 *This function outputs the nine inertia tensor moments to the screen.
 */

#endif //INERTIA_H
