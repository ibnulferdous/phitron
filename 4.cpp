#include <bits/stdc++.h>

using namespace std;

// Globals
const int N = 1e3 + 10;
int n, m, rooms = 0;

vector<string> g;
bool visited[N][N];
vector< pair<int, int> > direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

// Function declaration
void dfs(int i, int j);
bool isValid(int i, int j);

int main(void)
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        g.push_back(s);
    }

    // Loop over every character of the strings
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j]) continue;
            if (g[i][j] == '#') continue;
            dfs(i, j);
            rooms++;
        }
    }

    cout << rooms;

    return 0;
}

void dfs(int i, int j)
{
    if (!isValid(i, j)) return;
    if (visited[i][j]) return;
    if (g[i][j] == '#') return;

    visited[i][j] = true;

    for (auto d : direc)
    {
        dfs(i + d.first, j + d.second);
    }
}

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}