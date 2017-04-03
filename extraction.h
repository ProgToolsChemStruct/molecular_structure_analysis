#include <string>
#include <fstream>
#include <vector>

using namespace std;


class Extraction
{
    public:

    unsigned int count_line;

    void trim_coords(int q);
    void array_coords();

    Extraction (const char *inputfile);
    ~Extraction ();

    private:

    string line;
    string sub_line;
    string header1;
    string footer1;
    vector<string> sub_array;
};

extern unsigned int totalatoms;
extern std::vector< vector<string> > array;
    
