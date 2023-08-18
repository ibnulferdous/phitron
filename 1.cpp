#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool visited[N];

// Function declaration
void circulate_cc(int u);

int main(void)
{
    vector<int> leaders;
    int n, e, count = 0;
    cin >> n >> e;

    for (int i = 1; i <= e; i++)
    {
        int s, d;
        cin >> s >> d;

        g[s].push_back(d);
        g[d].push_back(s);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        circulate_cc(i);
        leaders.push_back(i);
    }

    cout << leaders.size() - 1 <<endl; // printing the required roads
    for (int i = 1, sz = leaders.size(); i < sz; i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }

    return 0;
}

void circulate_cc(int u)
{
    visited[u] = true;
    for (int v : g[u])
    {
        if (visited[v]) continue;
        circulate_cc(v);
    }
}