#include <bits/stdc++.h>

using namespace std;

// Parent array
vector<int> parent(1000, -1);

int find_leader(int node)
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union (int a, int b)
{
    int leaderA = find_leader(a);
    int leaderB = find_leader(b);

    if (leaderA != leaderB)
    {
        parent[leaderB] = leaderA;
    }
}

int main(void)
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        dsu_union(u, v);
    }

    cout << find_leader(5);

    return 0;
}

// Sample input 
// 7 4
// 1 2 
// 2 3
// 4 5
// 6 5
