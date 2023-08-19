#include <bits/stdc++.h>

using namespace std;

// Custom types
typedef pair<int, int> cpair;

// Globals
const int N = 1e3 + 10;
int n, m, si, sj, di, dj;

vector<string> graph;
bool visited[N][N];
int dist[N][N];
vector<cpair> direct = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; 

// Function declarations
void find_distance();
bool isValid(int i, int j);

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;

        // Searching for the start and end point
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 's') si = i, sj = j;
            if (x[j] == 'e') di = i, dj = j;
        }

        graph.push_back(x);
    }

    find_distance();

    visited[di][dj] ? cout << "Distance: " << dist[di][dj] : cout << -1 ;

    return 0;
}

void find_distance()
{
    queue<cpair> q;
    q.push( {si, sj} );
    visited[si][sj] = true;
    dist[si][sj] = 0;

    while (!q.empty())
    {
        cpair upair = q.front();
        q.pop();

        int i = upair.first;
        int j = upair.second;

        for (auto d : direct)
        {
            int vi = i + d.first;
            int vj = j + d.second;

            if (!isValid(vi, vj)) continue;
            if (visited[vi][vj]) continue;
            if (graph[vi][vj] == 'x') continue;

            visited[vi][vj] = true;
            q.push( {vi, vj} );
            dist[vi][vj] = dist[i][j] + 1;
        }
    }

}

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}