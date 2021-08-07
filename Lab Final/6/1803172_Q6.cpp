#include <bits/stdc++.h>
using namespace std;

bool isSafetoPlaceQueen(vector<vector<int>> board, int row, int col)
{
    int n = board.size();

    for (int i = 0; i < row; i++)
        if (board[i][col])
        {
            return false;
        }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
        {
            return false;
        }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
        {
            return false;
        }

    return true;
}

void getSolution(vector<vector<int> >& board, int row, int &solution_count, int &iteration_count)
{
    int n = board.size();
    if (row == n)
    {
        solution_count++;
        cout<<"Solution #"<<solution_count<<" : "<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    cout<<"Q\t";
                else
                    cout<<"*\t";
            }
            cout<<endl;
        }
        cout<<"Iteration needed : "<<iteration_count<<endl;
        cout<<endl;
        iteration_count++;
    }
    for (int col = 0; col < n; col++)
    {
        iteration_count++;
        if (isSafetoPlaceQueen(board, row, col))
        {
            board[row][col] = 1;
            getSolution(board, row + 1, solution_count, iteration_count);
            board[row][col] = 0;
        }
    }
    return ;
}

void read_inputs(string file_name)
{
    ifstream input_stream;
    input_stream.open(file_name);
    if (!input_stream)
    {
        cout << "Cannot open file or File dose not exist.\n";
        exit(1);
    }
    int num, solution_count, iteration_count;
    while(input_stream >> num)
    {
        cout<<endl<<"For "<<num<<" Queens :"<<endl;
        vector<vector<int> > board(num, vector<int>(num, 0));
        solution_count = 0;
        iteration_count = 0;
        getSolution(board, 0, solution_count, iteration_count);
    }
    input_stream.close();
}
int main()
{
    read_inputs("queen.txt");
    return 0;
}

