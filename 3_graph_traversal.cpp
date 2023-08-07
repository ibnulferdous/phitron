#include <bits/stdc++.h>

using namespace std;

const int N = 10e5 + 7;
vector<int> adl[N];
bool visited[N];

// Function prototype
void dfs(int u);

int main(void)
{
    int m, n;
    cin >> m >> n;

    // taking inputs into the adjacency list
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u>> v;

        adl[u].push_back(v);
        adl[v].push_back(u);
    }

    dfs(1);

    return 0;
}

void dfs(int u)
{
    // Step 1: actions just after entering the U vertex
    // Check whether we visited this vertex
    visited[u] = true;
    cout<< u << " ";
    for (int v : adl[u])
    {
        // Step 2: actions before entering an unvisited vertex (V) (neighbor)
        if (!visited[v]) dfs(v);
        // Step 3: actions after exiting a neighbor vertex (V)
    }
    // Step 4: actions before leaving the vertex/node (U)
}

// Sample input 1
// 10
// 9
// 1 2
// 1 3
// 1 10
// 2 4
// 3 5
// 3 6
// 4 7
// 4 8
// 6 9

// Sample input 2
// 9
// 10
// 1 2
// 2 3
// 3 8
// 8 9
// 8 7
// 1 5
// 5 6
// 5 4
// 4 7
// 6 7

// Sample input 3
// 11
// 11
// 1 2
// 2 3
// 3 8
// 8 9
// 8 7
// 1 5
// 5 6
// 5 4
// 4 7
// 6 7
// 10 11