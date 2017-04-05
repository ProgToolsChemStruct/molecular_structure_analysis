/**
  * @file elements.cpp
  * @author Hananh Lozano
  * @param none
  * @return name of element upon success
  *
  * The purpose of this program is to identify the first eighteen elements,     
  * hydrogen to argon, and assign them a number starting with 1.
  **/ 

#ifndef ELEMENTS_H
#define ELEMENTS_H

using namespace std; 
    
    enum elements_hydrogen_to_argon {
     HYDROGEN = 1,
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
     
     if (element == HYDROGEN   ) return "Hydrogen";
     if (element == HELIUM     ) return "Helium";
     if (element == LITHIUM    ) return "Lithium";
     if (element == BERLLYIUM  ) return "Beryllium";
     if (element == BORON      ) return "Boron";
     if (element == CARBON     ) return "Carbon";
     if (element == NITROGEN   ) return "Nitrogen";
     if (element == OXYGEN     ) return "Oxygen";
     if (element == FLUORINE   ) return "Fluorine";
     if (element == NEON       ) return "Neon";
     if (element == SODIUM     ) return "Sodium";
     if (element == MAGNESIUM  ) return "Magnesium";
     if (element == ALUMINUM   ) return "Aluminum";
     if (element == SILICON    ) return "Silicon";
     if (element == PHOSPHOROUS) return "Phosphorous";
     if (element == SULFUR     ) return "Sulfur";
     if (element == CHLORINE   ) return "Chlorine";
     if (element == ARGON      ) return "Argon";
    
    }
#endif //ELEMENTS_H 
