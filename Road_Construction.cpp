#include <bits/stdc++.h>

using namespace std;

// Global constant
const int N = 1e5 + 5;

int cmp_cnt = 0, max_size = 0;

int parent[N];
int parentSize[N];

// Initially set the parent array
void set_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

// Find the leader of a node
int find_leader(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }

    return node;
}

// make groups and leaders between nodes
void dsu_union(int a, int b)
{
    int leaderA = find_leader(a);
    int leaderB = find_leader(b);

    if (leaderA != leaderB)
    {
        cmp_cnt--;

        if (parentSize[leaderA] >= parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
            max_size = max(max_size, parentSize[leaderA]);
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
            max_size = max(max_size, parentSize[leaderB]);
        }
    }
}

int main(void)
{
    int n, e;
    cin >> n >> e;

    set_parent(n);
    cmp_cnt = n;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        dsu_union(a, b);
        cout << cmp_cnt << " " << max_size << endl;
    }

    return 0;
}