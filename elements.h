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
  
#ifndef ELEMENTS_H
#define ELEMENTS_H

using namespace std; 
    
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
    ARGON 
};
    
    elements_hydrogen_to_argon element;
 
    string elements_to_string (elements_hydrogen_to_argon d) {
     
        if (element == HYDROGEN   ) return "H";
        if (element == HELIUM     ) return "He";
        if (element == LITHIUM    ) return "Li";
        if (element == BERLLYIUM  ) return "Be";
        if (element == BORON      ) return "B";
        if (element == CARBON     ) return "C";
        if (element == NITROGEN   ) return "N";
        if (element == OXYGEN     ) return "O";
        if (element == FLUORINE   ) return "Fl";
        if (element == NEON       ) return "Ne";
        if (element == SODIUM     ) return "Na";
        if (element == MAGNESIUM  ) return "Mg";
        if (element == ALUMINUM   ) return "Al";
        if (element == SILICON    ) return "Si";
        if (element == PHOSPHOROUS) return "P";
        if (element == SULFUR     ) return "S";
        if (element == CHLORINE   ) return "Cl";
        if (element == ARGON      ) return "Ar";
        
	cout << "Non-specified element present";
	/* exit, EXIT_FAILURE */     

return 0;
}
#endif //ELEMENTS_H 
