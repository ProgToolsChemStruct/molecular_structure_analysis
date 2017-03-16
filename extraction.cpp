#include "extraction.h"
#include <cstdio>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>

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
    log.open("log.txt");
    unsigned int count_line = 0;
    string header1 = "Redundant internal coordinates found in file";
    string footer1 = "Recover connectivity data from disk.";

    while (getline(orig_file, line)) {
        count_line++;
        if (line.find(header1, 0) != string::npos) {
            cout << "Found: " << header1 << " at position " << count_line << endl;
            for (int i = 1; i > 0; ++i) {
                coordfile << line << "\n";
                log << line << "\n";
                cout << line << "\n";
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
