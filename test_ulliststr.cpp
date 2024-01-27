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
    dat.push_front("pls");
    dat.push_front("work");
    dat.push_front("work");
    for(int i = 0;i<15;i++){
        dat.push_front("added");
    }
    for(int i = 0;i<15;i++){
        cout<< i <<dat.get(i)<<endl;
    }
    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << " " << dat.get(4) << " " << dat.get(5)<<endl;
    cout <<"do this even work"<<endl;
    // prints: 8 7 9
    cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
}
