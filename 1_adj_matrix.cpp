#include <bits/stdc++.h>

using namespace std;

const int N = 10e3 + 5;
int adjmat[N][N];

int main(void)
{
    int m, n; // m = vertices, n = edges
    int w; // if weighted, it will have this input
    cin>> m >> n;

    for (int i = 0; i < n; i++) // This loop will run for the number of edges
    {
        int u, v;
        cin>> u >> v;

        adjmat[u][v] = 1; // If directed, it will only have this line
        // adjmat[v][u] = 1; // If undirected, it will also have this line
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}