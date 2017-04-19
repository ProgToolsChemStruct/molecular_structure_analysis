/**
  * @file elements.cpp
  * @author Hananh Lozano
  * @param none
  * @return bond numbers upon success
  *
  * The purpose of this program is to determine the number of bonds between
  *bound atoms.
  */ 

//header guard
#ifndef BOND_NUMBER_H
#define BOND_NUMBER_H

int dist_calc (int i , int j); 

/**
 *This function does just the interatomic distance calculations for the bond      *nuumber calculations. 
 *It has a direct return instead of an output to the screen 
 *in the main file.
 */ 

int bond_number;

/**
 *This function uses the dist_calc function above to determine the exact number   *of bonds between atoms that are bound to each other.
 */    

#endif //BOND_NUMBER_H
