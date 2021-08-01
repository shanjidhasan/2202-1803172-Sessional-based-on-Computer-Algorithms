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

    outdata.open("sort_i_4000.in");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i=0; i<4000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }

    outdata.close();

    outdata.open("sort_i_5000.in");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i=0; i<5000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }

    outdata.close();

    outdata.open("sort_i_6000.in");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i=0; i<6000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }

    outdata.close();

    outdata.open("sort_i_7000.in");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i=0; i<7000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }

    outdata.close();

    outdata.open("sort_i_8000.in");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i=0; i<8000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }

    outdata.close();

    outdata.open("sort_i_9000.in");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i=0; i<9000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }

    outdata.close();

    return 0;
}
