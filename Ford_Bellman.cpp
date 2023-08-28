#include <bits/stdc++.h>

using namespace std;

// class for edges
class Edge
{
    public:
        int u;
        int v;
        int w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main(void)
{
    int n, e;
    cin >> n >> e;
    vector<Edge> adj;
    int dis[n + 1];

    // Assigning infinity into distance array
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    // making the distance of source as 0
    dis[1] = 0;

    // Taking the input
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
 
        Edge ed(u, v, w);

        adj.push_back(ed);
    }

    // Applying bellman Ford
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0, sz = adj.size(); j < sz; j++)
        {
            Edge ed = adj[j];
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            
            if (dis[u] == INT_MAX) continue;

            if (dis[v] > dis[u] + w) 
            // Relaxation is not possible if distance of U is infinity
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int res = dis[i] == INT_MAX? 30000 : dis[i];
        cout << res << " ";
    }

    return 0;
}