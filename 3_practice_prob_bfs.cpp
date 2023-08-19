#include <bits/stdc++.h>

using namespace std;

// Custom type declaration
typedef pair<int, int> cpair;

// Globals
int n, m, si, sj, di, dj;
const int N = 1e3 + 10;

vector<string> graph;
bool visited[N][N];
vector<cpair> directions = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

// Function declaration
void bfs();
bool isValid(int i, int j);

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;

        // searching the starting and ending points
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

        graph.push_back(x);
    }

    bfs();

    visited[di][dj] ? cout << "YES" : cout << "NO";

    return 0;
}

void bfs()
{
    queue<cpair> q;
    q.push( {si, sj} );
    visited[si][sj] = true;

    while (!q.empty())
    {
        cpair upair = q.front();
        q.pop();
        int ui = upair.first;
        int uj = upair.second;

        for (cpair d : directions)
        {
            int vi = ui + d.first;
            int vj = uj + d.second;

            if (!isValid(vi, vj)) continue;
            if (visited[vi][vj]) continue;
            if (graph[vi][vj] == 'x') continue;

            q.push( {vi, vj} );
            visited[vi][vj] = true;
        }
    }
}

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}