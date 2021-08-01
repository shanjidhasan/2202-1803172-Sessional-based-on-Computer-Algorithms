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

    outdata.open("input.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<50; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();

    outdata.open("input_100.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<100; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();
    outdata.open("input_500.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<500; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();
    outdata.open("input_1000.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<1000; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();
    outdata.open("input_1500.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<1500; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();

    outdata.open("input_2000.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<2000; ++i)
    {
        int x = rand();
        outdata <<  x << endl;
    }
    outdata.close();



    return 0;
}
