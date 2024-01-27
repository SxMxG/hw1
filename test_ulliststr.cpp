#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    using namespace std;
    ULListStr dat;
    dat.push_back("pls");
    dat.push_front("work");
    dat.push_back("work");
    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
    // prints: 8 7 9
    cout << dat.size() << end;  // prints 3 since there are 3 strings stored
}
