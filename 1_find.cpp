#include <bits/stdc++.h>

using namespace std;

// Parent array
int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};

int find_leader(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

int main(void)
{
    int leader = find_leader(1);

    cout << leader;

    return 0;
}