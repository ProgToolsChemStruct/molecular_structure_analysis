#include <iostream>
#include <string>

// header from elements.cpp

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
    
    }; 	
    
    
    //elements and number of bonds

int main()
{
    /**if Hydrogen, Lithium, or Sodium return "1 bond H,Li,Na";
    if Beryllium or Magnesium return "2 bonds Be,Mg";
    if Boron or Aluminum return "3 bonds B,Al";
    if Carbon or Silicon return "4 bonds C,Si";
    if Nitrogen or Phosphorous return "3 bonds N,P";
    if Oxygen or Sulfur return "2 bonds O,S";
    if Fluorine or Chlorine return "1 bond F, Cl";
    if Helium, Neon, or Argon return "0 bonds He,Ne,Ar";   
    }
    return null**/
     
};    
             
