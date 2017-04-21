#include "extraction.h"

using namespace std;

vector< vector<string> > vector_coords;

int totalatoms = 10;

//Extracts Coords from Input and places them into a 2D array
int extract_input(const char *inputfile) {

    ifstream orig_file(inputfile);
    ofstream log;

    string line, sub_line;
    string header1 = "Redundant internal coordinates found in file";
    string footer1 = "Recover connectivity data from disk.";

    int count_line = 0;
    
    vector<string> temp_vector;

    assert(orig_file.good());
    log.open("log.txt", ios::app);

    //Parse for header key phrase
    while(getline(orig_file, line)) {
        count_line++;

        if(line.find(header1, 0) != string::npos) {
            log << "Found: " << header1 << " at position " << count_line << endl;

            //If it's found, skip first two lines 
            for(int i = 0; i < 500; i++) {
                getline(orig_file, line);
                if(i < 0) continue;

                //Make sure the string isn't the footer key phrase
                if (line.find(footer1, 0) == string::npos) {

                    //Place into temporary vector separated by newline
                    temp_vector.clear();
                    stringstream newstring(line);

                        //Separate data based upon commas
                        while(getline(newstring, sub_line, ',')) {
                            temp_vector.push_back(sub_line);
                        }

                        //Place comma-separated data into final vector
                        vector_coords.push_back(temp_vector);

                //When footer is found, end process
                } else { 
                      log << "Found: " << footer1 << endl;
                      log << "Search for main coordinates complete." << endl;
                      break;
                }
            }
        }
    }

    orig_file.close();
    log.close();
    return 0;
}

//Prints vector size and vector contents to console, logfile, and outputfile
int print_vector_coords() {

    ofstream log;
    ofstream outputfile;

    log.open("log.txt", ios::app);
    outputfile.open("outputfile.txt", ios::app);

    cout << "Model Parameters:" << endl << vector_coords.size() << endl;
    outputfile << "Model Parameters:" << endl << vector_coords.size() << endl;

    for(size_t i = 0; i < vector_coords.size(); i++) {

        for (size_t j = 0; j < vector_coords[i].size(); j++) {
            cout << vector_coords[i][j] << "     ";
            log << vector_coords[i][j] << "     ";
            outputfile << vector_coords[i][j] << "     ";
        }

        cout << endl;
        log << endl;
        outputfile << endl;
    }

    log.close();
    outputfile.close();
    return 0;
}
