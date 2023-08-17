#include <bits/stdc++.h>

using namespace std;

// custom type
typedef pair<int, int> pii;

// globals
const int N = 1e3 + 5;
vector<pii> g[N];
vector<bool> visited(N, false);
vector<int> dist(N, INT_MAX);
int s, d;

// Function declaration
void dijkstra(int s);

int main(void)
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    cin >> s >> d;

    dijkstra(s);

    cout << dist[d];

    return 0;
}

void dijkstra(int s)
{
    priority_queue< pii, vector<pii>, greater<pii> > pq;

    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (pii vpair : g[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v]) continue;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push( {dist[v], v} );
            }
        }
    }
}