#include <iostream>
#include <fstream>
#include <string>

#include elements.h
/**
  * @file elements.cpp
  * @author Hananh Lozano
  * @param none
  * @return bond numbers upon success
  *
  * The purpose of this program is to determine how many bonds between atoms   
  * there will be.
  **/ 

using namespace std;  

    
    //elements and number of bonds 
    
    enum elements_to_bonds {
     HELIUM, NEON, or ARGON = 0 bonds
     HYDROGEN, LITHIUM, SODIUM, FLUORINE, or CHLORINE 
     BERYLLIUM, MAGNESIUM, OXYGEN, or SULFUR 
     BORON, ALUMINUM, NITROGEN, or PHOSPHOROUS  
     CARBON or SILICON
    }; 
 
     
     
    string elements_to_bonds (elements_to_bonds d){
    
     if (Hydrogen, Lithium, or Sodium) return "1 bond H,Li,Na";
     if (Beryllium or Magnesium)       return "2 bonds Be,Mg";
     if (Boron or Aluminum)            return "3 bonds B,Al";
     if (Carbon or Silicon)            return "4 bonds C,Si";
     if (Nitrogen or Phosphorous)      return "3 bonds N,P";
     if (Oxygen or Sulfur)             return "2 bonds O,S";
     if (Fluorine or Chlorine)         return "1 bond F, Cl";
     if (Helium, Neon, or Argon)       return "0 bonds He,Ne,Ar";   
     if else return "Error identifying bonds"  
     
     }  
