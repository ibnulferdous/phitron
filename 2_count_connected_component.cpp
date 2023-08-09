#include <bits/stdc++.h>

using namespace std;

const int N = 10e3 + 7;
vector<int> adl[N];
bool visited[N];

void dfs(int u);

int main(void)
{
    int n, m, connected_comp = 0;
    cin >> n >> m;

    // Taking input of edges
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adl[u].push_back(v);
        adl[v].push_back(u);
    }

    // Looping over all the vertices/nodes
    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;

        // if not visited, add 1 to connected_component variable
        connected_comp++;
        cout << "Connected component " << connected_comp << " : ";
        dfs(i);
        cout << endl;
    }

    return 0;
}

void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : adl[u])
    {
        if (visited[v]) continue;
        dfs(v);
    }
}