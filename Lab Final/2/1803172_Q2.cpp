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
void merge_array(long long arr[], long long left, long long middle, long long right)
{
    long long left_array[middle - left+1], right_array[right - middle];
    for (i = 0; i <= middle - left; i++)
    {
        left_array[i] = arr[left + i];
    }
    for (j = 0; j < right - middle; j++)
    {
        right_array[j] = arr[middle + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i <= middle - left && j < right - middle)
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k++] = left_array[i++];
        }
        else
        {
            arr[k++] = right_array[j++];
        }
        CompCnt++;
    }
    while (i <= middle - left)
    {
        arr[k++] = left_array[i++];
    }
    while (j < right - middle)
    {
        arr[k++] = right_array[j++];
    }
}
void mergeSort(long long arr[], long long Left, long long Right)
{
    if (Left < Right)
    {
        long long Middle = Left + (Right - Left) / 2;
        mergeSort(arr, Left, Middle);
        mergeSort(arr, Middle + 1, Right);
        merge_array(arr, Left, Middle, Right);
    }
}

int main()
{
    readFile("quick1.txt");
    CompCnt = 0;
    high_resolution_clock::time_point sratt_time = high_resolution_clock::now();
    mergeSort(ar,0,len-1);
    high_resolution_clock::time_point end_time = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end_time - sratt_time);

    cout<<endl<<"Total number of elements : "<<len<<endl<<"Merge Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    readFile("quick2.txt");
    CompCnt = 0;
    high_resolution_clock::time_point sratt_time2 = high_resolution_clock::now();
    mergeSort(ar,0,len-1);
    high_resolution_clock::time_point end_time2 = high_resolution_clock::now();
    duration<double> time_span2 = duration_cast<duration<double>>(end_time2 - sratt_time2);

    cout<<endl<<"Total number of elements : "<<len<<endl<<"Merge Sort :\n";
    cout<<"            Time required  : "<<time_span2.count()*1000<<"ms"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    readFile("quick3.txt");
    CompCnt = 0;
    high_resolution_clock::time_point sratt_time4 = high_resolution_clock::now();
    mergeSort(ar,0,len-1);
    high_resolution_clock::time_point end_time4 = high_resolution_clock::now();
    duration<double> time_span4 = duration_cast<duration<double>>(end_time4 - sratt_time4);

    cout<<endl<<"Total number of elements : "<<len<<endl<<"Merge Sort :\n";
    cout<<"            Time required  : "<<time_span4.count()*1000<<"ms"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    return 0;
}

