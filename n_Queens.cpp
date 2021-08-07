#include <bits/stdc++.h>
using namespace std;

bool isSafetoPlaceQueen(vector<vector<int>> board, int row, int col)
{
    int n = board.size();

    vector<int> nodes;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == row && j == col)
            {
                nodes.push_back(col+1);
            }
            if (board[i][j] == 1)
                nodes.push_back(j + 1);
        }
    }

    for (int i = 0; i < row; i++)
        if (board[i][col])
        {
            cout<<"Backtrack From Node: ";
            for(int j = 0 ; j < nodes.size() ; j++)
            {
                cout<<nodes[j]<<" ";
            }
            cout<<endl;
            return false;
        }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
        {
            cout<<"Backtrack From Node: ";
            for(int j = 0 ; j < nodes.size() ; j++)
            {
                cout<<nodes[j]<<" ";
            }
            cout<<endl;
            return false;
        }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
        {
            cout<<"Backtrack From Node: ";
            for(int j = 0 ; j < nodes.size() ; j++)
            {
                cout<<nodes[j]<<" ";
            }
            cout<<endl;
            return false;
        }

    return true;
}

void getSolution(vector<vector<int> >& board, int row)
{
    int n = board.size();
    if (row == n)
    {
        vector<int> nodes;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    nodes.push_back(j + 1);
            }
        }
        cout<<endl<<"Solution: ";
        for(int i = 0 ; i < nodes.size() ; i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<endl<<endl;
        return ;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafetoPlaceQueen(board, row, col))
        {
            board[row][col] = 1;
            getSolution(board, row + 1);
            board[row][col] = 0;
        }
    }
    return ;
}

int main()
{
    int n;
    cout<<"Enter number of Queens : ";
    cin>>n;
    vector<vector<int> > board(n, vector<int>(n, 0));
    getSolution(board, 0);
    return 0;
}

