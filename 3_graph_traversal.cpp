#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int m, n;
    cin >> m >> n;

    vector<int> adl[m + 1];

    // taking inputs into the adjacency list
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u>> v;

        adl[u].push_back(v);
        adl[v].push_back(u);
    }

    // Printing the adjacency list
    for (int i = 1; i <= m; i++)
    {
        cout<< "Vertex "<< i << ": ";
        for (int j : adl[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}