#include <bits/stdc++.h>

using namespace std;

int n, m, room = 0;
const int N = 1e3 + 7;
vector<string> g;
bool visited[N][N];

// Function declaration
void dfs(int i, int j);
bool isValid(int i , int j);

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        g.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j]) continue;
            if (g[i][j] == '#') continue;
            dfs(i, j);
            room++;
        }
    }

    cout << room << endl;

    return 0;
}

void dfs(int i, int j)
{
    // checking whether i and j is valid grid number
    if (!isValid(i , j)) return;
    if (visited[i][j]) return;
    if (g[i][j] == '#') return; 

    visited[i][j] = true;

    dfs(i, j - 1);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i + 1, j);
}

bool isValid(int i , int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}