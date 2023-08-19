#include <bits/stdc++.h>

using namespace std;

// Globals
const int N = 1e3 + 7;
int n, m, si, sj, di, dj;

vector<string> g;
bool visited[N][N];
vector< pair<int, int> > directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

// Function declaration
bool isValid(int i, int j);
void dfs(int i, int j);

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;

        // Finding the source and destination
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 's')
            {
                si = i;
                sj = j;
            }
            
            if (x[j] == 'e')
            {
                di = i;
                dj = j;
            }
        }

        g.push_back(x);
    }

    dfs(si, sj);

    visited[di][dj] ? cout << "YES" : cout << "YES";

    return 0;
}

void dfs(int i, int j)
{
    if (!isValid(i, j)) return;
    if (visited[i][j]) return;
    if (g[i][j] == 'x') return;

    visited[i][j] = true;

    for (auto d : directions)
    {
        dfs(i + d.first, j + d.second);
    }
}

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}







// Sample input
// 6 5
// .s.x.
// ...x.
// ..x..
// ..x..
// ..xex
// .....

