#include <bits/stdc++.h>

using namespace std;

// custom type
typedef pair<int, int> pii;

// Global variables
const int N = 1e3 + 5;
vector<pii> adj[N];
vector<bool> visited(N);
vector<int> dist(N, INT_MAX);

// Function declaration
void dijkstra(int source);

int main(void)
{
    int n, e, s, d;
    cin >> n >> e;

    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back( {v, w} );
    }

    cin >> s >> d;

    dijkstra(s);

    cout << dist[d];

    return 0;
}

void dijkstra(int source)
{
    priority_queue< pii, vector<pii>, greater<pii> > pq;

    dist[source] = 0;
    pq.push( {dist[source], source} );

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (pii vpair : adj[u])
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