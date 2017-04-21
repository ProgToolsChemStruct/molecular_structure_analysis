/**
  * @file elements.cpp
  * @author Hananh Lozano
  * @param none
  * @return name of element upon success
  *
  * The purpose of this program is to identify the first eighteen elements,     
  * hydrogen to argon, and assign them a number starting with 1.
  */ 
#include <stdlib.h>     /* exit, EXIT_FAILURE */  
  
//header guard
#ifndef ELEMENTS_H
#define ELEMENTS_H
    
enum elements_hydrogen_to_argon {
   
    HYDROGEN,
    HELIUM,
    LITHIUM,
    BERLLYIUM,
    BORON,
    CARBON,
    NITROGEN,
    OXYGEN,
    FLUORINE,
    NEON,
    SODIUM,
    MAGNESIUM,
    ALUMINUM,
    SILICON,
    PHOSPHOROUS,
    SULFUR,
    CHLORINE,
    ARGON,

};
   
/**This function takes elements Hydrogen to Argon and converts them into a  
 *number between 0 and 17. 
 */
   
string elements_to_string (elements_hydrogen_to_argon d);

/**This function takes the enumerated list number assignments for the elements 
 *and translated it back to the element words.
 */

#endif //ELEMENTS_H 
