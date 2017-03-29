#include <string>
#include <fstream>
#include <vector>

using namespace std;


class Extraction
{
    public:

    unsigned int count_line;
    string line;
    string sub_line;
    string header1;
    string footer1;
    vector<string> sub_array;
    
    void trim_coords(int q);
    void array_coords();

    Extraction (const char *inputfile);
    ~Extraction ();
};


extern vector< vector<string> > array;
    
