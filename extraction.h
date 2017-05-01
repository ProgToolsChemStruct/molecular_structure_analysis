/**
 * @file extraction.h
 * @author Thomas Summers
 * @date 13 April 2017
 * 
 * This file contains the declarations and functions used by the program to extract
 * the desired coordinates from the user-specified input file and placing them into
 * an array.
 */

#include <cstdio>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

/**
 * This function parses the input file specified by the user for a particular header.
 * Once it finds the header, it extracts the information, separates out the info
 * based upon comma-separation, and then places said data into a 2D array.  The
 * function continues until it either reaches the end footer string or until it finds
 * 500 atoms and their coordinates.
 */

int extract_input(const char *inputfile);

/**
 * This function prints the 2D vector and all of its information onto the console,
 * into the log file, and into the outputfile.
 */

int print_vector_coords();
