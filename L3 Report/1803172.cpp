#include<bits//stdc++.h>
using namespace std;
long long arr[100010],len = 0;
long long cnt1=0,cnt2=0;
void find_min_max(long long &mini,long long &maxi)
{cnt1++;
    for(long long i = 0 ; i < len ; i++)
    {cnt1+=2;
        cnt1++;
        if(arr[i]<mini)
        {cnt1++;
            mini = arr[i];
        }
        cnt1++;
        if(arr[i]>maxi)
        {cnt1++;
            maxi = arr[i];
        }
    }
}
void divide_and_conquer_min_max(long long i, long long n, long long &mini, long long &maxi)
{
    cnt2++;
    if(n-i == 0)
    {
        cnt2+=2;
        maxi = max(arr[i],maxi);
        return;
    }
    else if(n-i == 1)
    {
        cnt2+=2;
        maxi = max(maxi,max(arr[i],arr[n]));
        return;
    }
    cnt2+=2;
    divide_and_conquer_min_max(((i+n)/2+1),n,mini,maxi);
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
    }inFile.close();
    len = i;
}
int main()
{
    long long a,b,data[100][8],i=0;
        cnt1=0;
        cnt2=0;
        readFile("input_10000.txt");
        data[i][0] = len;
        a = LLONG_MAX;
        b = LLONG_MIN;
        find_min_max(a,b);
        data[i][1] = a;
        data[i][2] = b;
        data[i][5] = cnt1;

        a = LLONG_MAX;
        b = LLONG_MIN;
        divide_and_conquer_min_max(0,len-1,a,b);
        data[i][3] = a;
        data[i][4] = b;
        data[i++][6] = cnt2;

        cnt1=0;
        cnt2=0;
        readFile("input_20000.txt");
        data[i][0] = len;
        a = LLONG_MAX;
        b = LLONG_MIN;
        find_min_max(a,b);
        data[i][1] = a;
        data[i][2] = b;
        data[i][5] = cnt1;

        a = LLONG_MAX;
        b = LLONG_MIN;
        divide_and_conquer_min_max(0,len-1,a,b);
        data[i][3] = a;
        data[i][4] = b;
        data[i++][6] = cnt2;

        cnt1=0;
        cnt2=0;
        readFile("input_30000.txt");
        data[i][0] = len;
        a = LLONG_MAX;
        b = LLONG_MIN;
        find_min_max(a,b);
        data[i][1] = a;
        data[i][2] = b;
        data[i][5] = cnt1;

        a = LLONG_MAX;
        b = LLONG_MIN;
        divide_and_conquer_min_max(0,len-1,a,b);
        data[i][3] = a;
        data[i][4] = b;
        data[i++][6] = cnt2;

        cnt1=0;
        cnt2=0;
        readFile("input_40000.txt");
        data[i][0] = len;
        a = LLONG_MAX;
        b = LLONG_MIN;
        find_min_max(a,b);
        data[i][1] = a;
        data[i][2] = b;
        data[i][5] = cnt1;

        a = LLONG_MAX;
        b = LLONG_MIN;
        divide_and_conquer_min_max(0,len-1,a,b);
        data[i][3] = a;
        data[i][4] = b;
        data[i++][6] = cnt2;

        cnt1=0;
        cnt2=0;
        readFile("input_50000.txt");
        data[i][0] = len;
        a = LLONG_MAX;
        b = LLONG_MIN;
        find_min_max(a,b);
        data[i][1] = a;
        data[i][2] = b;
        data[i][5] = cnt1;

        a = LLONG_MAX;
        b = LLONG_MIN;
        divide_and_conquer_min_max(0,len-1,a,b);
        data[i][3] = a;
        data[i][4] = b;
        data[i++][6] = cnt2;

    cout<<"Data\tNormal_Minimum\t  Normal_Maximum\t  DAC_Minimum\t  DAC_Maximum\t  Normal_Steps\t  DAC_Steps\n\n";
    for(long long j = 0 ; j < i ; j++)
    {
        cout<<data[j][0]<<"\t\t"<<data[j][1]<<"\t\t"<<data[j][2]<<"  \t\t"<<data[j][3]<<"\t\t"<<data[j][4]<<"\t\t"<<data[j][5]<<"\t\t"<<data[j][6]<<"\n\n";
    }
    return 0;
}
