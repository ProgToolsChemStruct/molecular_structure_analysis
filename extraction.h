#include <string>
#include <fstream>

using namespace std;

class Extraction
{
    public:

    unsigned int count_line;
    string line;
    string header1;
    string footer1;

    void trim_coords(int q);

    Extraction (const char *inputfile);
    ~Extraction ();
};
