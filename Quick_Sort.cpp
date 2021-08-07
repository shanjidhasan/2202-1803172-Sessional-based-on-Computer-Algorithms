#include<bits/stdc++.h>
using namespace std;
int arr[100000], len;
void read_inputs(string file_name)
{
    ifstream input_stream;
    input_stream.open(file_name);
    if (!input_stream)
    {
        cout << "Cannot open file or File dose not exist.\n";
        exit(1);
    }
    int num, i = 0;
    while(input_stream >> num)
    {
        arr[i++] = num;
    }
    len = i;
    input_stream.close();
}

int Arraypartition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = Arraypartition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
int main()
{
    int min_num, max_num;
    read_inputs("small.txt");
    quickSort(arr, 0, len-1);
    for(int i= 0 ; i < len ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}


