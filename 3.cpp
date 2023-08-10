#include <bits/stdc++.h>

using namespace std;

const int N = 10e3 + 7;
vector<int> adl[N];
bool visited[N];

bool detect_cycle(int u, int parent);

int main(void)
{
    bool cycle = false;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adl[u].push_back(v);
        adl[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        cycle |= detect_cycle(i, -1);
    }

    cycle ? cout << "YES" : cout << "NO";

    return 0;
}

bool detect_cycle(int u, int parent)
{
    visited[u] = true;
    bool cycle = false;

    for (int v : adl[u])
    {
        if (parent == v) continue;
        if (visited[v]) return true;
        cycle |= detect_cycle(v, u);
    }

    return cycle;
}

// Sample Input
// 4
// 4
// 1 2
// 2 3
// 3 4
// 4 2

// 6
// 6
// 1 2
// 2 3
// 4 2
// 5 6
// 6 7
// 5 7
