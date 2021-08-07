#include <bits/stdc++.h>
using std::cerr;
using std::endl;
#include <fstream>
using std::ofstream;
#include <cstdlib>
int main()
{
    ofstream outdata;
    int i;

    outdata.open("quick1.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i=0; i<10000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }

    outdata.close();

    outdata.open("quick2.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i=0; i<30000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }

    outdata.close();

    outdata.open("quick3.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i=0; i<50000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }

    outdata.close();

    return 0;
}
