#include <bits/stdc++.h>
using namespace std;
long long arr[100010],len = 0;
void readFile(string fname)
{
    long long x,i=0;
    ifstream inFile;
    inFile.open(fname);
    if (!inFile)
    {
        cout << "Error: file could not be opened.\n";
        exit(1);
    }
    while (inFile >> x)
    {
        arr[i++] = x;
    }
    inFile.close();
    len = i;
}
void find_max(long long i, long long n, long long &maxi)
{
    if(n-i == 0)
    {
        maxi = max(arr[i],maxi);
        return;
    }
    else if(n-i == 1)
    {
        maxi = max(maxi,max(arr[i],arr[n]));
        return;
    }
    find_max(i,(i+n)/2,maxi);
    find_max(((i+n)/2+1),n,maxi);
}
void bubble_sort(long long a[], long long n)
{
    long long temp, i;
    for(i = 0; i< n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1] )
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void countSort(long long a[], long long n)
{
    long long output[n+1];
    long long maxi = LLONG_MIN, i;
    find_max(0, n-1, maxi);
    long long count_arr[maxi+1];
    for(i = 0; i<=maxi; i++)
    {
        count_arr[i] = 0;
    }

    for(i = 0; i<n; i++)
    {
        count_arr[a[i]]++;
    }
    for(i = 1; i<=maxi; i++)
    {
        count_arr[i] += count_arr[i-1];
    }
    for(i = n - 1; i>=0 ; i--)
    {
        output[--count_arr[a[i]]] = a[i];
    }
}
int main()
{
    double diff1, diff2;
    long double d1, d2;
    readFile("input_10000.txt");
    auto t1 = chrono::steady_clock::now();
    bubble_sort(arr, len);
    auto t2 = chrono::steady_clock::now();
    diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t2-t1).count());
    readFile("input_10000.txt");

    auto t3 = chrono::steady_clock::now();
    countSort(arr, len);
    auto t4 = chrono::steady_clock::now();
    diff2 = double(chrono::duration_cast <chrono::nanoseconds> (t4-t3).count());
    d1 = diff1*1.0/1000000;
    d2 = diff2*1.0/1000000;
    cout<<"For "<<len<<" data : \nTime required in Bubble Sort : "<<d1<<" milliseconds"<<"\nTime required in Counting Sort : "<<d2<<" milliseconds"<<endl;


    readFile("input_20000.txt");
    auto t5 = chrono::steady_clock::now();
    bubble_sort(arr, len);
    auto t6 = chrono::steady_clock::now();
    diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t6-t5).count());
    readFile("input_20000.txt");

    auto t7 = chrono::steady_clock::now();
    countSort(arr, len);
    auto t8 = chrono::steady_clock::now();
    diff2 = double(chrono::duration_cast <chrono::nanoseconds> (t8-t7).count());
    d1 = diff1*1.0/1000000;
    d2 = diff2*1.0/1000000;
    cout<<"\n\nFor "<<len<<" data : \nTime required in Bubble Sort : "<<d1<<" milliseconds"<<"\nTime required in Counting Sort : "<<d2<<" milliseconds"<<endl;


    readFile("input_30000.txt");
    auto t9 = chrono::steady_clock::now();
    bubble_sort(arr, len);
    auto t10 = chrono::steady_clock::now();
    diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t10-t9).count());
    readFile("input_30000.txt");
    auto t11 = chrono::steady_clock::now();
    countSort(arr, len);
    auto t12 = chrono::steady_clock::now();
    diff2 = double(chrono::duration_cast <chrono::nanoseconds> (t12-t11).count());
    d1 = diff1*1.0/1000000;
    d2 = diff2*1.0/1000000;
    cout<<"\n\nFor "<<len<<" data : \nTime required in Bubble Sort : "<<d1<<" milliseconds"<<"\nTime required in Counting Sort : "<<d2<<" milliseconds"<<endl;


    readFile("input_40000.txt");
    auto t13 = chrono::steady_clock::now();
    bubble_sort(arr, len);
    auto t14 = chrono::steady_clock::now();
    diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t14-t13).count());
    readFile("input_40000.txt");
    auto t15 = chrono::steady_clock::now();
    countSort(arr, len);
    auto t16 = chrono::steady_clock::now();
    diff2 = double(chrono::duration_cast <chrono::nanoseconds> (t16-t15).count());
    d1 = diff1*1.0/1000000;
    d2 = diff2*1.0/1000000;
    cout<<"\n\nFor "<<len<<" data : \nTime required in Bubble Sort : "<<d1<<" milliseconds"<<"\nTime required in Counting Sort : "<<d2<<" milliseconds"<<endl;


    readFile("input_50000.txt");
    auto t17 = chrono::steady_clock::now();
    bubble_sort(arr, len);
    auto t18 = chrono::steady_clock::now();
    diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t18-t17).count());
    readFile("input_50000.txt");
    auto t19 = chrono::steady_clock::now();
    countSort(arr, len);
    auto t20 = chrono::steady_clock::now();
    diff2 = double(chrono::duration_cast <chrono::nanoseconds> (t20-t19).count());
    d1 = diff1*1.0/1000000;
    d2 = diff2*1.0/1000000;
    cout<<"\n\nFor "<<len<<" data : \nTime required in Bubble Sort : "<<d1<<" milliseconds"<<"\nTime required in Counting Sort : "<<d2<<" milliseconds"<<endl;


    readFile("input_60000.txt");
    auto t21 = chrono::steady_clock::now();
    bubble_sort(arr, len);
    auto t22 = chrono::steady_clock::now();
    diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t22-t21).count());
    readFile("input_60000.txt");
    auto t23 = chrono::steady_clock::now();
    countSort(arr, len);
    auto t24 = chrono::steady_clock::now();
    diff2 = double(chrono::duration_cast <chrono::nanoseconds> (t24-t23).count());
    d1 = diff1*1.0/1000000;
    d2 = diff2*1.0/1000000;
    cout<<"\n\nFor "<<len<<" data : \nTime required in Bubble Sort : "<<d1<<" milliseconds"<<"\nTime required in Counting Sort : "<<d2<<" milliseconds"<<endl;

    return 0;
}
