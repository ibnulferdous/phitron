#include <bits/stdc++.h>

using namespace std;

const int N = 10e3 + 7;
vector<int> adl[N];
vector<int> cc[N];
bool visited[N];

void cc_count(int u, int count);

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
        count++;
        cc_count(i, count);
    }

    for (int i = 1; i <= count; i++)
    {
        cout << "Component " << i << " : ";
        for (int x : cc[i])
        {
            cout<< x << " ";
        }
        cout <<endl;
    }

    return 0;
}

void cc_count(int u, int count)
{
    visited[u] = true;
    // cout << u << " ";
    cc[count].push_back(u);

    for (int v : adl[u])
    {
        if (visited[v]) continue;
        cc_count(v, count);
    }
}

// 6
// 6
// 1 2
// 2 3
// 4 2
// 5 6
// 6 7
// 5 7

// 6
// 4
// 1 2
// 2 3
// 3 4
// 5 6
