/** 
 * @file extraction.h
 * @author Thomas Summers
 * @date 3 April 2017
 * 
 * @brief File containing class declarations for extracting info from and input file
 *
 * This file contains the declarations and functions used by the program to extract 
 * the desired coordinates from the user-specified input file and placing them into
 * an array.  The collective abilities are contained within the class Extraction.
 */


#include <string>
#include <fstream>
#include <vector>

using namespace std;

/**
 * @brief Class containing element used to extract info from the input file
 *
 * This class contains the declarations for a variety of elements used to parse the 
 * specified input file for specific keywords, extract the desired chemistry 
 * coordinates, and transfer the data into a useable array.
 */

class Extraction
{
    public:

    unsigned int count_line; /**< Public counter for determining location of keywords */

/**
 * This function "cleans" the specified lines from the top of the coords.  It is dependent
 * on the integer @p q which is used to determine the number of lines to not be included.
 * For simplicity, this function achieves the end result by extracting all info after the
 * specified amount and writing it to a new file.  In addition, the function counts the
 * total number of atoms in the model with the counter @c count_line storing it in the
 * external variable @c total_atoms for other use. 
 */
    void trim_coords(int q);

/**
 * This function generates an externally accessible array @c array containing the 
 * elements, their freeze codes (0 or -1) and their X, Y, Z Cartesian coordinates. These
 * characteristics are also stored in a file @c coordinates.txt that is accessible by the 
 * user after the program is run.
 */
    void array_coords();

/**
 * @brief Constructor function of class Extraction
 */
    Extraction (const char *inputfile);

/**
 * @brief Destructor function of class Extraction
 */
    ~Extraction ();

    private:

    string line; /**< Private variable used to store strings to generate the array */
    string sub_line; /** Private variable used to store parts of the main string */
    string header1; /** Private string storing info of first line parsed for */
    string footer1; /** Private string storing info of second line parsed for */
    vector<string> sub_array; /** Private array used to temporarily store strings */
};

extern unsigned int totalatoms; /** Externally defined variable storing total atom number */
extern std::vector< vector<string> > array; /** Externally defined array storing coords */
