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

    void isolate_input();

    Extraction (const char *inputfile);
    ~Extraction ();
};
