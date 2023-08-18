#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool visited[N];
int level[N];
vector<int> parent(N, -1);

// Function declaration
bool find_route(int s, int d);

int main(void)
{
    stack<int> path;
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int flag = find_route(1, n);

    // If there is no route
    if (!flag)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    int curr = n;
    while (curr > -1)
    {
        path.push(curr);
        curr = parent[curr];
    }

    cout << path.size() <<endl;

    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
    
    return 0;
}

bool find_route(int s, int d)
{
    queue<int> q;
    q.push(s);
    bool flag = false;

    visited[s] = true;
    level[s] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == d) flag = true;

        for (int v : g[u])
        {
            if (visited[v]) continue;
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
            q.push(v);
        }
    }

    return flag;
}