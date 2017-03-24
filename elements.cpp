#include <iostream>
#include <string>

#include "elements.h"

using namespace std; 
/**
  * @elementspage The Gaussian Optimization Analytical Tool (GOAT)
  *
  * Welcome to the Gaussian Optimization Analytical Tool (GOAT) documentation site! 
  * Users may find relevant info related to this program, a program designed to provide
  * structural analyses of biomolecules successfully optimized using Gaussian software.
  *
  * @short elements program
  * @file elements.cpp
  * @author Hananh Lozano
  * @param none
  * @return 
  *
  * The purpose of this program is to identify the first eighteen elements, hydrogen to argon, and assign them a         number starting with 1. Then it will take the enum and string files and build upon those to determine how many       bonds between atoms there will be.
  */   
      
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
    ARGON,

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

    //access coordinates.scv file
      
int main()
{
    /**if Hydrogen is less than Sodium return 1;
      *else return not 1;
      *if Beryllium is less than Magnesium return 2;
      *else return not 2;
      *if Boron is less than ALuminum return 3;
      *else return not 3;
      *if Carbon is less than Silicon return 4;
      *else return less than 4;
      *if Nitrogen is less than Phosphorous return 3;
      *else return not 3;
      *if Fluorine is less than Chlorine return 1;
      *else return not 1;
      *if Helium is less than Argon return 0;
      *else return "There are Bonds!" **/
     
}    

