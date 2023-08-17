#include <bits/stdc++.h>

using namespace std;

// Custom types
typedef pair<int, int> cp;

// Globals
const int N = 1e5 + 5;
const long long int INF = 1e18;

int nodes, edges;

vector<cp> adj[N];
bool visited[N];
int parent[N];
long long int dist[N];

// Functional declaration
void dijkstra(int source);

int main(void)
{
    stack<int> path;
    int src;
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++) 
    {
        int src, des, w;
        cin >> src >> des >> w;

        adj[src].push_back( {w, des} );
        adj[des].push_back( {w, src} );
    }

    src = 1;
    dijkstra(src);

    if (!visited[nodes]) 
    {
        cout << -1 << endl;
        return 0;
    }

    int curr = nodes;
    while (true)
    {
        path.push(curr);

        if (curr == src) break;

        curr = parent[curr];
    }

    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }


    return 0;
}

void dijkstra(int source)
{
    priority_queue< cp, vector<cp>, greater<cp> > pq;

    for (int i = 1; i <= nodes; i++)
    {
        dist[i] = INF;
    }

    // Manually set the distance of source and push it into PQ
    dist[source] = 0;
    pq.push( {dist[source], source} );

    // Looping over PQ
    while (!pq.empty())
    {
        // choose the pair with smallest distance and pop it from PQ
        cp selectedPair = pq.top();
        pq.pop();

        int selectedNode = selectedPair.second;

        // If visited, ignore the pair and do nothing
        if (visited[selectedNode]) continue;
        // else make the pair visited
        visited[selectedNode] = true;
        // cout << selectedNode << " ";

        // Loop over each pair
        for (cp child : adj[selectedNode])
        {
            int childNode = child.second;
            int w = child.first;

            if (dist[selectedNode] + w < dist[childNode])
            {
                dist[childNode] = dist[selectedNode] + w;
                pq.push( {dist[childNode], childNode} );
                parent[childNode] = selectedNode;
            }
        }
    }

}