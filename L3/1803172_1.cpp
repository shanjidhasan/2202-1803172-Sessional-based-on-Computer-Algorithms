#include<bits//stdc++.h>
using namespace std;
int arr[100010],len = 0;
void find_min_max(int &mini,int &maxi)
{
    for(int i = 0 ; i < len ; i++)
    {
        if(arr[i]<mini)
            mini = arr[i];
        if(arr[i]>maxi)
            maxi = arr[i];
    }
}
void devide_and_conquer_min_max(int i, int n, int &mini, int &maxi)
{
    if(n-i <= 1)
    {
        mini = min(arr[i],arr[n]);
        maxi = max(arr[i],arr[n]);
        return;
    }
    else
    {
        int min1,max1;
         devide_and_conquer_min_max(i,floor(((i + n)/2)),min1,max1);
        int min2,max2;
         devide_and_conquer_min_max(floor(((i + n)/2)),n,min2,max2);

        mini = min(min1,min2);
        maxi = max(max1,max2);
    }
}
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
        arr[i++] = x;
    }inFile.close();
    len = i;
}
int main()
{
    int a,b;
    string s = "";
    cout<<"Enter file name : ";
    cin>>s;
    while(s != "exit")
    {
        readFile(s);

        a = INT_MAX;
        b = INT_MIN;

        find_min_max(a,b);
        cout<<"Minimum and Maximum of "<<s<<" are : ";
        cout<<a<<"\t"<<b<<endl;

        devide_and_conquer_min_max(0,len-1,a,b);
        cout<<"Minimum and Maximum by divide and conquer of "<<s<<" are : ";
        cout<<a<<"\t"<<b<<endl;

        cout<<"\n\nEnter file name : ";
        cin>>s;
    }
    return 0;
}
