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
void find_min_max(int &min_num, int &max_num, int left, int right)
{
    if(left == right)
    {
        min_num = min(min_num, arr[left]);
        max_num = max(max_num, arr[right]);
        return;
    }
    else if(left == right -1)
    {
        if(arr[left] < arr[right])
        {
            min_num = min(arr[left], min_num);
            max_num = max(max_num, arr[right]);
        }
        else
        {
            min_num = min(arr[right], min_num);
            max_num = max(max_num, arr[left]);
        }
        return;
    }
    else
    {
        int mid = (left + right)/2;
        find_min_max(min_num, max_num, left, mid);
        find_min_max(min_num, max_num, mid+1, right);
    }


}
int main()
{
    int min_num, max_num;
    read_inputs("input.txt");
    min_num = INT_MAX;
    max_num = INT_MIN;
    find_min_max(min_num, max_num, 0, len);
    cout<<"Minimum : " << min_num<< endl<<"Maximum : " << max_num<<endl;
    return 0;
}
