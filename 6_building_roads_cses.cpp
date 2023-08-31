#include <bits/stdc++.h>

using namespace std;

// Global constant
const int N = 1e5 + 5;

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
    int n, m;
    cin >> n >> m;

    set_parent(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    map<int, bool> mp;
    vector<int> cities;

    for (int  i = 1; i <= n; i++)
    {
        int leader = find_leader(i);
        mp[leader] = true;
    }

    for (auto m : mp)
    {
        cities.push_back(m.first);
    }

    cout << cities.size() - 1 << endl;

    for (int x = 1, sz = cities.size(); x < sz; x++)
    {
        cout << cities[x - 1] << " " << cities[x] << endl;
    }

    return 0;
}