#include <bits/stdc++.h>

using namespace std;
const int N = 10e5 + 7;
vector<int> adl[N];

int depth[N];
int height[N];

// function prototype
void dfs(int u);

int main(void)
{
    int m, n;
    cin>> m >> n;

    // Taking input into the adjacency list
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adl[u].push_back(v);
    }

    dfs(1);

    for (int i = 1; i <= m; i++)
    {
        cout<<"Depth of " << i << ": " << depth[i] << endl;
    }

    cout << "\n*******************\n";
    
    for (int i = 1; i <= m; i++)
    {
        cout<<"Height of " << i << ": " << height[i] << endl;
    }

    return 0;
}

void dfs(int u)
{
    // Step 1: actions after immediately enterying the node U

    for (int v : adl[u])
    {
        // Step 2: actions before calling dfs on children V
        depth[v] = depth[u] + 1; // children's depth = parent's depth + 1

        dfs(v);

        // step 3: actions after calling dfs on children V
        // 1. we get heigh from children
        // 2. so, we have to calculate it after calling dfs function on children
        // 3. parent's height = max of children's height + 1
        height[u] = max(height[u], height[v] + 1); 
    }

}