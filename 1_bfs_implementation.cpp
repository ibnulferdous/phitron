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


    return 0;
}

void bfs(int s)
{
    queue<int> q;
    visited[s] = true;

    // Step 1: push root/first vertex into the queue
    // Step 2: queue theke front ta k ber koro and kothao save kore rakho
    // Step 3: front diye jabotiyo kaaj shesh koro
    // Step 4: front er children/neighbor der k queue te push koro

    q.push(s);
}