#include <bits/stdc++.h>
using std::cerr;
using std::endl;
#include <fstream>
using std::ofstream;
#include <cstdlib>
int main()
{
   ofstream outdata; // outdata is like cin
   int i; // loop index


outdata.open("input_50000.txt"); // opens the file
   if( !outdata ) { // file couldn't be opened
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
