#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int dis[n + 1][n + 1];

    // resetting the distance array
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            dis[i][j] = w;
        }
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    // resetting the distance array
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}

