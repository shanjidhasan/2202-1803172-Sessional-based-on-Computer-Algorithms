#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long ar[100010],i,j,k,len,CompCnt = 0;
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
        ar[i++] = x;
    }
    inFile.close();
    len = i;
}

long long Arraypartition (long long arr[], long long low, long long high)
{
    long long pivot = arr[high];
    long long i = (low - 1);
    for (long long j = low; j <= high- 1; j++)
    {
        CompCnt++;
        if (arr[j] <= pivot)
        {
            i++;
            long long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    long long temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(long long arr[], long long low, long long high)
{
    if (low < high)
    {
        long long pivot = Arraypartition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}



int main()
{
    readFile("quick1.txt");
    CompCnt = 0;
    high_resolution_clock::time_point sratt_time1 = high_resolution_clock::now();
    quickSort(ar,0,len-1);
    high_resolution_clock::time_point end_time1 = high_resolution_clock::now();
    duration<double> time_span1 = duration_cast<duration<double>>(end_time1 - sratt_time1);

    cout<<"Total number of elements : "<<len<<endl;
    cout<<endl<<"Quick Sort :\n";
    cout<<"            Time required  : "<<time_span1.count()*1000<<"ms"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    cout<<endl<<endl;


    readFile("quick2.txt");
    CompCnt = 0;
    high_resolution_clock::time_point sratt_time3 = high_resolution_clock::now();
    quickSort(ar,0,len-1);
    high_resolution_clock::time_point end_time3 = high_resolution_clock::now();
    duration<double> time_span3 = duration_cast<duration<double>>(end_time3 - sratt_time3);

    cout<<"Total number of elements : "<<len<<endl;
    cout<<endl<<"Quick Sort :\n";
    cout<<"            Time required  : "<<time_span3.count()*1000<<"ms"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    cout<<endl<<endl;

    readFile("quick3.txt");
    CompCnt = 0;
    high_resolution_clock::time_point sratt_time5 = high_resolution_clock::now();
    quickSort(ar,0,len-1);
    high_resolution_clock::time_point end_time5 = high_resolution_clock::now();
    duration<double> time_span5 = duration_cast<duration<double>>(end_time5 - sratt_time5);

    cout<<"Total number of elements : "<<len<<endl;
    cout<<endl<<"Quick Sort :\n";
    cout<<"            Time required  : "<<time_span5.count()*1000<<"ms"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    cout<<endl<<endl;

    return 0;
}
