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

void merge_array(int arr[], int left, int middle, int right)
{
    int i,j,k;
    int left_array[middle - left+1], right_array[right - middle];
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
void merge_sort(int arr[], int left, int right)
{
    if(left<right)
    {
        int mid = (left + right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge_array(arr, left, mid, right);
    }
}
int main()
{
    int min_num, max_num;
    read_inputs("small.txt");
    merge_sort(arr, 0, len-1);
    for(int i= 0 ; i < len ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

