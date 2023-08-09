#include <bits/stdc++.h>

using namespace std;

const int N = 10e3 + 7;
vector<int> adl[N];
bool visited[N];

bool dfs(int u, int p);

int main(void)
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adl[u].push_back(v);
        adl[v].push_back(u); 
    }

    bool is_cycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        is_cycle |= dfs(1, -1);
    }

    is_cycle ? cout << "Cycle detected!" : cout << "No cycle detected!";

    return 0;
}

bool dfs(int u, int p)
{
    bool does_cycle_exist = false;
    visited[u] = true;

    for (int v : adl[u])
    {
        if (v == p) continue;
        if (visited[v]) return true;
        does_cycle_exist |= dfs(v, u); // does_cycle_exist = does_cycle_exist | dfs(v, u)
    }

    return does_cycle_exist;
}