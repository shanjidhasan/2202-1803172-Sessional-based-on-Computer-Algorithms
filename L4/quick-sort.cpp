#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int left,int right)
{
    int i=left-1;
    int j;
    int pi=arr[right];
    for(j=left;j<=right-1;j++)
    {
        if(arr[j]<pi)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[right]);
    return (i+1);
}
void quicksort(int arr[],int left,int right)
{
    if(left<right)
    {
      int pi= partition(arr,left,right);
      quicksort(arr,left,pi-1);
      quicksort(arr,pi+1,right);
    }
}
void printarray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
int main()
{
    int n,i=0,a[100000];
    ifstream file;
    file.open("sort_i_4000.in");
    if(file)
    {
        while(file>>n)
            {
                 a[i++]=n;
            }
    }
    else
        cout<<"file can't open"<<endl;
        file.close();
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        quicksort(a,0,i);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> d1 = duration_cast<duration<double>>(t2 - t1);
        cout<<"Time required : "<<d1.count()*1000<<"ms"<<endl;
        printarray(a,i);
    i = 0;
    file.open("sort_i_4000.in");
    if(file)
    {
        while(file>>n)
            {
                 a[i++]=n;
            }
    }
    else
        cout<<"file can't open"<<endl;
        file.close();
        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        mergeSort(a,0,i-1);
        high_resolution_clock::time_point t4 = high_resolution_clock::now();
        duration<double> d2 = duration_cast<duration<double>>(t4 - t3);
        cout<<"Time required : "<<d2.count()*1000<<"ms"<<endl;
        printarray(a,i);
}
