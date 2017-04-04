#include "extraction.h"
#include <cstdio>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

//Deconstructor and Constructor Functions
Extraction::~Extraction(){}


Extraction::Extraction(const char *inputfile)
{
    //Open and extract rough coords from inputfile
    ifstream orig_file(inputfile);
    assert(orig_file.good());

    ofstream coordfile;
    ofstream log;
    coordfile.open("coordinates.txt");
    log.open("log.txt", ios::app);

    unsigned int count_line = 0;
    string header1 = "Redundant internal coordinates found in file";
    string footer1 = "Recover connectivity data from disk.";

    while (getline(orig_file, line)) {
        count_line++;

        if (line.find(header1, 0) != string::npos) {
            cout << "Found: " << header1 << " at position " << count_line << endl;
            log << "Found: " << header1 << " at position " << count_line << endl;

            for (int i = 1; i > 0; ++i) {
                coordfile << line << "\n";
                log << line << "\n"; 
                getline (orig_file, line);

                if (line.find(footer1, 0) != string::npos) {
                    cout << "Found: " << footer1 << endl;
                    log << "Found: " << footer1 << endl;
                    log << "Search for main coords complete." << endl;
                    break;
                }
            }
        }
    }

    orig_file.close();
    coordfile.close();
}


//Clear the top two unneccessary lines from coords file
unsigned int totalatoms;

void Extraction::trim_coords(int q)
{
    ifstream coordsfile;
    coordsfile.open("coordinates.txt");
    ofstream log;
    ofstream cleancoords;
    log.open("log.txt", ios::app);
    cleancoords.open("coordinates.csv");

    log << "Beginning attempt to clean coords file";

    int i = 0;
    count_line = 0;

    while (getline(coordsfile, line)) {

        if (i < q) {
            i++;

        } else {
            cleancoords << line << "\n";
            log << line << "\n";
            count_line++;
        }
    }

    cout << "File successfully cleaned" << endl;
    log << "File successfully cleaned" << endl;

    totalatoms = count_line;

    coordsfile.close();
    log.close();
    cleancoords.close();
    remove("coordinates.txt");
}

    
//Generate a 2D array from the coords file
vector< vector<string> > array;

void Extraction::array_coords()
{           
    ifstream cleancoords("coordinates.csv");
    ofstream outputcoords("coordinates.txt");
    ofstream log;
    log.open("log.txt", ios::app);

    log << "Beginning generation of 2D array" << endl;
    outputcoords << totalatoms << endl;

    while (getline(cleancoords,line)) {
        sub_array.clear();
        stringstream newstring(line);

        while (getline(newstring, sub_line, ',')) {
            sub_array.push_back(sub_line);
        }

        array.push_back(sub_array);
    }

    int i, j;

    cout << "\nNumber of atoms in the model: " << totalatoms << endl;
    cout << "Cartesian Coordinates extracted from the model:" << endl;

    for (i = 0; i < array.size(); i++) {

        for (j = 0; j < array[i].size(); j++) {
            cout << array[i][j] << "	";
            log << array[i][j] << "	";
            outputcoords << array[i][j] << "	";
        }

        cout << endl;
        log << endl;
        outputcoords << endl;
    }

    outputcoords.close();
    cleancoords.close();
    remove("coordinates.csv");
}

