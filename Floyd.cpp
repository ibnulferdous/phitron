#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, max_distance = 0;
    cin >> n;

    long int dis[n+1][n+1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;

            if (w == -1) dis[i][j] = INT_MAX;
            else dis[i][j] = w;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] == INT_MAX || dis[k][j] == INT_MAX) continue;

                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                } 
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dis[i][j] > max_distance) {
                max_distance = dis[i][j];
            }
        }
    }

    cout << max_distance;

    return 0;
}