#include <bits/stdc++.h>

using namespace std;

const int N = 10e3 + 5;
vector<int> adl[N]; // array of vector to take grapgh input
bool visited[N]; // array to check visited vertices
int level[N]; // array of vertex's level

void bfs(int s);

int main(void)
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adl[u].push_back(v);
        adl[v].push_back(u);
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout<<"Vextex "<< i << " : " << level[i] << endl;
    }

    return 0;
}

void bfs(int s)
{
    // Step 1: take a queue and push root/first vertex into the queue
    // Step 2: queue empty na howa porjonto loop chalao
    // Step 3: queue theke front ta k ber koro and kothao save kore rakho
    // Step 4: front diye jabotiyo kaaj shesh koro
    // Step 5: front er children/neighbor der k queue te push koro

    // step 1
    queue<int> q;
    visited[s] = true;
    q.push(s);

    // step 2
    while (!q.empty())
    {
        // setp 3
        int u = q.front();
        q.pop();

        // step 4
        for (int v : adl[u])
        {
            if (visited[v]) continue;
            // step 5
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}