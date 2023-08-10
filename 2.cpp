#include <bits/stdc++.h>

using namespace std;

const int N = 10e3 +7;
vector<int> adl[N];
bool visited[N];
int level[N];

void bfs(int s, int x);

int main(void)
{
    int n, m, x;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adl[u].push_back(v);
        adl[v].push_back(u);
    }

    cin >> x;
    bfs(1, x);

    return 0;
}

void bfs(int s, int x)
{
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visited[u] = true;
        
        if (u == x) cout << "Level of " << u << " : " << level[u] << endl;

        for (int v : adl[u])
        {
            if (visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

// Sample input
// 7 
// 6
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 7

// Sample input
// 8 
// 7
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 4 8
// 8
