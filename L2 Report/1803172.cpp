#include <bits/stdc++.h>
using namespace std;
long long arr[100010],len;
long long rec_cont = 0, non_rec_cnt = 0;
long long rec_fib(long long n)
{rec_cont++;
    rec_cont+=2;
    if((n==1)|| n==0)
    {rec_cont++;
        return n;
    }
    else
    {
        rec_cont+=2;
        return(rec_fib(n-1)+rec_fib(n-2));
    }
}
int fib(int n)
{
    int b=0;    non_rec_cnt++;
    int a=1;    non_rec_cnt++;
    int x=0;    non_rec_cnt++;
    int i;  non_rec_cnt++;
    non_rec_cnt+=2;
    if (n==0 || n==1)
    {
        non_rec_cnt++;
        return n;
    }
    non_rec_cnt++;
    for(i=2; i<=n; i++)
    {non_rec_cnt+=2;
        x=a+b;  non_rec_cnt+=2;
        b=a;    non_rec_cnt++;
        a=x;    non_rec_cnt++;
    }
    non_rec_cnt++;
    return x;
}
void readFile(string fname)
{
    long long x,i=0;
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
    readFile("fibonacci.txt");
    for(long long i = 0 ; i < len ; i++)
    {
        rec_cont = 0;
        non_rec_cnt = 0;
        cout << "Fibonacci Series by recursion function : ";
        rec_cont++;
        for(long long j = 0 ; j < arr[i] ; j++)
        {rec_cont+=2;
            rec_cont++;
            cout<<rec_fib(j)<<" ";
        }
        cout<<endl;

        cout << "Fibonacci Series without recursion function : ";
        non_rec_cnt++;
        for(long long j = 0 ; j < arr[i] ; j++)
        {non_rec_cnt+=2;
            cout<<fib(j)<<" ";
        }
        cout<<endl<<endl;
        cout<<"Number of steps required in recursion function for "<<arr[i]<<" Fibonacci numbers : "<<rec_cont;
        cout<<"\nNumber of steps required in non-recursion function for "<<arr[i]<<" Fibonacci numbers : "<<non_rec_cnt;
        cout<<endl<<endl;
    }
    return 0;
}
