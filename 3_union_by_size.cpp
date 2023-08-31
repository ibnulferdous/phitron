#include <bits/stdc++.h>

using namespace std;

// Parent array
int parent[1000];
int parentSize[1000];

// Initially set the parent array
void set_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

// find the leader of a node
int find_leader(int node)
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

// make groups between the nodes
void dsu_union (int a, int b)
{
    int leaderA = find_leader(a);
    int leaderB = find_leader(b);

    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] >= parentSize[leaderB]) 
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else 
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main(void)
{
    int n, e;
    cin >> n >> e;

    set_parent(n);

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        dsu_union(u, v);
    }

    cout << find_leader(4);
    return 0;
}

// Sample input 
// 7 4
// 1 2 
// 2 3
// 4 5
// 6 5