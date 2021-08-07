#include <bits/stdc++.h>
using namespace std;
int arr[100010],len;
int rec_fib(int n)
{
    if((n==1)|| n==0)
    {
        return n;
    }
    else
    {
        return(rec_fib(n-1)+rec_fib(n-2));
    }
}
void readFile(string fname)
{
    int x,i=0;
    ifstream inFile;
    inFile.open(fname);
    if (!inFile)
    {
        cout << "Cannot open file.\n";
        exit(1);
    }
    while (inFile >> x)
    {
        arr[i++] = x;
    }
    inFile.close();
    len = i;
}
int main()
{
    readFile("small.txt");
    for(int i = 0 ; i < len ; i++)
    {
        cout << "Fibonacci Series by recursion function : ";
        for(int j = 0 ; j < arr[i] ; j++)
        {
            cout<<rec_fib(j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}

