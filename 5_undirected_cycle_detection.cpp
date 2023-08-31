#include <bits/stdc++.h>

using namespace std;

// Parent array
int parent[1000];
int parentLevel[1000];

// Initially set the parent array
void set_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
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
        if (parentLevel[leaderA] > parentLevel[leaderB]) 
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else 
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
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
        
        if (find_leader(u) == find_leader(v))
        {
            cout << "Cycle detected between: " << u << " " << v << endl;
        }
        else 
        {
            dsu_union(u, v);
        }
    }

    return 0;
}

// Sample input 
// 5 5
// 1 2 
// 1 4
// 2 3
// 4 5
// 2 5