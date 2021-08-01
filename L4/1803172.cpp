#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long ar[100010],i,j,k,len,spaceCnt1 = 0,CompCnt = 0;
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
void writeOutput(string filename, long long n, long long arr[])
{
    ofstream myfile;
    myfile.open (filename, fstream::out);
    for (long long i=0; i<n; i++)
    {
        long long x = arr[i];
        myfile << x << endl;
    }
    cout<<"      Sorted data saved in : "<<filename<<endl;
    myfile.close();
}
void merge_array(long long arr[], long long left, long long middle, long long right)
{
    long long left_array[middle - left+1], right_array[right - middle];
    spaceCnt1+=sizeof(left_array);
    spaceCnt1+=sizeof(right_array);
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
    int output = 0;
    string s = "";

    readFile("sort_i_4000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time = high_resolution_clock::now();
    mergeSort(ar,0,len-1);
    high_resolution_clock::time_point end_time = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end_time - sratt_time);

    cout<<endl<<"Total number of elements : "<<len<<endl<<"Merge Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);


    readFile("sort_i_4000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time1 = high_resolution_clock::now();
    quickSort(ar,0,len-1);
    high_resolution_clock::time_point end_time1 = high_resolution_clock::now();
    duration<double> time_span1 = duration_cast<duration<double>>(end_time1 - sratt_time1);

    cout<<endl<<endl<<"Quick Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);

    cout<<endl<<endl;

    readFile("sort_i_5000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time2 = high_resolution_clock::now();
    mergeSort(ar,0,len-1);
    high_resolution_clock::time_point end_time2 = high_resolution_clock::now();
    duration<double> time_span2 = duration_cast<duration<double>>(end_time2 - sratt_time2);

    cout<<endl<<"Total number of elements : "<<len<<endl<<"Merge Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);


    readFile("sort_i_5000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time3 = high_resolution_clock::now();
    quickSort(ar,0,len-1);
    high_resolution_clock::time_point end_time3 = high_resolution_clock::now();
    duration<double> time_span3 = duration_cast<duration<double>>(end_time3 - sratt_time3);

    cout<<endl<<endl<<"Quick Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);

    cout<<endl<<endl;

    readFile("sort_i_6000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time4 = high_resolution_clock::now();
    mergeSort(ar,0,len-1);
    high_resolution_clock::time_point end_time4 = high_resolution_clock::now();
    duration<double> time_span4 = duration_cast<duration<double>>(end_time4 - sratt_time4);

    cout<<endl<<"Total number of elements : "<<len<<endl<<"Merge Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);


    readFile("sort_i_6000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time5 = high_resolution_clock::now();
    quickSort(ar,0,len-1);
    high_resolution_clock::time_point end_time5 = high_resolution_clock::now();
    duration<double> time_span5 = duration_cast<duration<double>>(end_time5 - sratt_time5);

    cout<<endl<<endl<<"Quick Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);

    cout<<endl<<endl;

    readFile("sort_i_7000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time6 = high_resolution_clock::now();
    mergeSort(ar,0,len-1);
    high_resolution_clock::time_point end_time6 = high_resolution_clock::now();
    duration<double> time_span6 = duration_cast<duration<double>>(end_time6 - sratt_time6);

    cout<<endl<<"Total number of elements : "<<len<<endl<<"Merge Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);


    readFile("sort_i_7000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time7 = high_resolution_clock::now();
    quickSort(ar,0,len-1);
    high_resolution_clock::time_point end_time7 = high_resolution_clock::now();
    duration<double> time_span7 = duration_cast<duration<double>>(end_time7 - sratt_time7);

    cout<<endl<<endl<<"Quick Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);

    cout<<endl<<endl;

    readFile("sort_i_8000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time8 = high_resolution_clock::now();
    mergeSort(ar,0,len-1);
    high_resolution_clock::time_point end_time8 = high_resolution_clock::now();
    duration<double> time_span8 = duration_cast<duration<double>>(end_time8 - sratt_time8);

    cout<<endl<<"Total number of elements : "<<len<<endl<<"Merge Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);


    readFile("sort_i_8000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time9 = high_resolution_clock::now();
    quickSort(ar,0,len-1);
    high_resolution_clock::time_point end_time9 = high_resolution_clock::now();
    duration<double> time_span9 = duration_cast<duration<double>>(end_time9 - sratt_time9);

    cout<<endl<<endl<<"Quick Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);

    cout<<endl<<endl;

    readFile("sort_i_9000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time10 = high_resolution_clock::now();
    mergeSort(ar,0,len-1);
    high_resolution_clock::time_point end_time10 = high_resolution_clock::now();
    duration<double> time_span10 = duration_cast<duration<double>>(end_time10 - sratt_time10);

    cout<<endl<<"Total number of elements : "<<len<<endl<<"Merge Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);


    readFile("sort_i_9000.in");
    CompCnt = 0; spaceCnt1 = 0;
    spaceCnt1 = len * sizeof(long long);
    high_resolution_clock::time_point sratt_time11 = high_resolution_clock::now();
    quickSort(ar,0,len-1);
    high_resolution_clock::time_point end_time11 = high_resolution_clock::now();
    duration<double> time_span11 = duration_cast<duration<double>>(end_time11 - sratt_time11);

    cout<<endl<<endl<<"Quick Sort :\n";
    cout<<"            Time required  : "<<time_span.count()*1000<<"ms"<<endl;
    cout<<"            Space required : "<<spaceCnt1/1024<<"KB"<<endl;
    cout<<"      Number of comparison : "<<CompCnt<<endl;

    s = "Output_" + std::to_string(output) + ".txt";
    output++;
    writeOutput(s,len, ar);

    cout<<endl<<endl;


    return 0;
}
