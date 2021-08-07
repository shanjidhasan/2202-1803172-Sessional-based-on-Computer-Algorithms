#include <bits/stdc++.h>
using namespace std;
int test_case;
int knapsak_sizes[1000][2];
int weights_profits[1000][3];

int DP_knapSack(int weights[],int profits[], int n, int W)
{
    int i, j;
    vector<vector<int>> arr(n + 1, vector<int>(W + 1));
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (weights[i - 1] <= j)
                arr[i][j] = max((profits[i - 1]+arr[i - 1][j - weights[i - 1]]), arr[i - 1][j]);
            else
                arr[i][j] = arr[i - 1][j];
        }
    }
    return arr[n][W];
}

float greedy_knapsack(int weights[],int profits[], int n, int W)
{
    int i, j, pos;
    float d[n];
    float totalValue = 0, totalWeight = 0;
    for (i = 0; i < n; i++)
    {
        d[i] = profits[i]*1.0 / weights[i];
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(d[j] > d[i])
            {
                float temp = d[i];
                d[i] = d[j];
                d[j] = temp;
                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
                temp = profits[i];
                profits[i] = profits[j];
                profits[j] = temp;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(totalWeight + weights[i]<= W)
        {
            totalValue += profits[i]*1.0;
            totalWeight += weights[i]*1.0;
        }
        else
        {
            int wt = W-totalWeight;
            totalValue += (wt * d[i]*1.0);
            totalWeight += wt;
            break;
        }
    }
    return totalValue;
}
vector<int> removeDupWord(string str)
{
    vector<int> numbers;
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            stringstream degree(word);
            int temp = 0;
            degree >> temp;
            numbers.push_back(temp);
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    stringstream degree(word);
    int temp = 0;
    degree >> temp;
    numbers.push_back(temp);
    return numbers;

}
void readFile(string fname)
{
    int x = -1,y = 0,i = 0;
    ifstream inFile;
    inFile.open(fname);
    if (!inFile)
    {
        cout << "Cannot open file.\n";
        exit(1);
    }
    inFile >> test_case;

    string str;
    while (getline(inFile, str))
    {
        vector<int> numbers = removeDupWord(str);
        if(numbers.size() == 1)
        {
            x++;

            knapsak_sizes[x][0] = numbers.at(0);
            knapsak_sizes[x][1] = 0;
        }
        else if(numbers.size() == 3)
        {
            weights_profits[i][0] = numbers.at(0);
            weights_profits[i][1] = numbers.at(1);
            weights_profits[i++][2] = numbers.at(2);
            knapsak_sizes[x][1]++;
        }
        numbers.clear();
    }
    inFile.close();
}
int main()
{
    int weights[1000];
    int profits[1000];
    int n;
    int prev = 0;
    readFile("greedy.txt");
    for(int i = 1 ; i <= test_case ; i++)
    {
        int k = 0;
        for(int j = prev ; j < prev + knapsak_sizes[i][1] ; j++)
        {
            weights[k] = weights_profits[j][1];
            profits[k++] = weights_profits[j][2];
        }
        cout<<"Solution of knapsack "<<i<<" : "<<endl;

        cout<<"Solution by Fractional Knapsack using Greedy Algorithm : ";
        double soln1 = greedy_knapsack(weights, profits, knapsak_sizes[i][1], knapsak_sizes[i][0]);
        cout<<soln1<<endl;

        cout<<"Solution by 0-1 Knapsack using Dynamic Programming : ";
        int soln2 = DP_knapSack(weights, profits, knapsak_sizes[i][1], knapsak_sizes[i][0]);
        cout<<soln2<<endl<<endl;
        prev += knapsak_sizes[i][1];
    }
    return 0;
}


