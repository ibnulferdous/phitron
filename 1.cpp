#include <bits/stdc++.h>

using namespace std;

const int N = 10e3 + 7;
vector<int> adl[N];
bool visited[N];

void bfs(int s, stack<int>& st);

int main(void)
{
    int n, m;
    stack<int> st;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adl[u].push_back(v);
        adl[v].push_back(u);
    }

    bfs(1, st);

    while (!st.empty())
    {
        cout<< st.top() << " ";
        st.pop();
    }

    return 0;
}

void bfs(int s, stack<int>& st)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        st.push(u);

        for (int v : adl[u])
        {
            if (visited[v]) continue;
            q.push(v);
            visited[v] = true;
        }
    }
}

// 4 
// 4
// 1 2
// 3 4
// 1 3
// 2 4
