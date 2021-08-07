#include <bits/stdc++.h>
using std::cerr;
using std::endl;
#include <fstream>
using std::ofstream;
#include <cstdlib>
using namespace std;
int main()
{
    ofstream outdata;
    int i;

    outdata.open("input_10000.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<10000; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();

    outdata.open("input_20000.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<20000; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();
    outdata.open("input_30000.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<30000; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();
    outdata.open("input_40000.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<40000; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();
    outdata.open("input_50000.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<50000; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();

    outdata.open("input_60000.txt");
    if( !outdata )
    {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (i=0; i<60000; ++i)
    {
        int x = rand();
        outdata <<  x%10001 << endl;
    }
    outdata.close();
    cout<<"Output Generated"<<endl;


    return 0;
}
