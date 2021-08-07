#include<bits/stdc++.h>
using namespace std;
void find_rechable_nodes(vector<vector<int>> &graph, vector<int> &visited, int start_node)
{
    queue <int> q;
    int n = graph.size();
    visited[start_node - 1] = 1;
    q.push(start_node);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = 0; i < graph.size() ; i ++)
        {
            if(graph[x-1][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i+1);
            }
        }
    }
}
int main()
{
    int start_node, n, x;
    printf("\n Enter the number of vertices:");
    cin>>n;
    vector<vector<int> > graph;
    vector<int> visited(n, 0);
    printf("\n Enter graph data in matrix form:\n");
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<n; j++)
        {
            cin>>x;
            temp.push_back(x);
        }
        graph.push_back(temp);
        temp.clear();
    }
    printf("\n Enter the starting vertex:");
    cin>>start_node;
    find_rechable_nodes(graph, visited, start_node);
    cout<<"\n The node which are reachable are:\n";
    for(int i = 0; i < n ; i++)
    {
        if(visited[i] == 1 && i+1 != start_node)
            cout<<i+1<<" ";
    }
    cout<<endl;
}
