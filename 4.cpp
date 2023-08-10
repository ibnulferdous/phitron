#include <bits/stdc++.h>

using namespace std;

const int N = 10e3 + 7;
vector<int> adl[N];
bool visited[N];

void count_components(int u);

int main(void)
{
    int n, m, count = 0;
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

        count_components(i);
        count++;
    }

    cout << "Connected components : " << count;

    return 0;
}

void count_components(int u)
{
    visited[u] = true;

    for (int v : adl[u])
    {
        if (visited[v]) continue;
        count_components(v);
    }
}

// sample input
// 6
// 6
// 1 2
// 2 3
// 4 2
// 5 6
// 6 7
// 5 7

// 7
// 4
// 1 2
// 2 3
// 3 4
// 5 6

