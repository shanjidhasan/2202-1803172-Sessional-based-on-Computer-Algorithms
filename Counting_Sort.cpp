#include <bits/stdc++.h>
using namespace std;
long long arr[100010],len = 0;
long long cnt1=0,cnt2=0;
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
void find_max(long long i, long long n, long long &maxi, long long &cnt2)
{
    cnt2++;
    if(n-i == 0)
    {
        cnt2+=1;
        maxi = max(arr[i],maxi);
        return;
    }
    else if(n-i == 1)
    {
        cnt2+=1;
        maxi = max(maxi,max(arr[i],arr[n]));
        return;
    }
    cnt2+=2;
    find_max(i,(i+n)/2,maxi,cnt2);
    find_max(((i+n)/2+1),n,maxi,cnt2);
}

void countSort(long long a[], long long n)
{
    long long output[n+1];
    long long maxi = LLONG_MIN, i;
    find_max(0, n-1, maxi, cnt2);
    cout<<maxi<<endl;
    long long count_arr[maxi+1];
    for(i = 0; i<=maxi; i++)
    {cnt2+=2;
        count_arr[i] = 0;cnt2++;
    }

    for(i = 0; i<n; i++)
    {cnt2+=2;
        count_arr[a[i]]++;cnt2++;
    }
    for(i = 1; i<=maxi; i++)
    {cnt2+=2;
        count_arr[i] += count_arr[i-1];cnt2++;
    }
    for(i = n - 1; i>=0 ; i--)
    {cnt2+=2;
        output[--count_arr[a[i]]] = a[i];cnt2++;
    }
    cout<<"\n\nCounting sort : \n";
    for(i = 0 ; i < n ; i++)
    {
        cout<<output[i]<<"\t";
    }
}
int main()
{
    cnt1 = 0;
    cnt2 = 0;
    readFile("input.txt");
    countSort(arr, len);
    cout<<"\n\nFor "<<len<<" data : "<<cnt1<<"\nStep count in Counting Sort : "<<cnt2<<endl;

    return 0;
}

