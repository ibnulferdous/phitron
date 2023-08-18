#include <bits/stdc++.h>

using namespace std;

// custom types
typedef pair<int, int> cpair;

// Globals
const int N = 1e3 + 10;
int n, m, si, sj, di, dj;

vector<string> g;
bool visited[N][N];
int level[N][N];
cpair parent[N][N];
vector<cpair> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

// Function declaration
void bfs();
bool isValid(int i, int j);

int main(void)
{
    vector<cpair> path;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        // taking the graph as string
        string s;
        cin >> s;

        // looping over the string to find the source and destination
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'A') 
            {
                si = i;
                sj = j;
            }
            
            if (s[j] == 'B') 
            {
                di = i;
                dj = j;
            }
        }

        // pushing the string into the graph vector
        g.push_back(s);
    }

    bfs();

    // If source is visited then there is a path
    if (visited[di][dj]) {
        cout << "YES\n";
    }
    else 
    {
        cout << "NO";
        return 0;
    }

    cout << level[di][dj] << endl;

    cpair curr = {di, dj};

    while (curr.first != -1 && curr.second != -1)
    {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }

    reverse(path.begin(), path.end());

    for (int i = 1, sz = path.size(); i < sz; i++)
    {
        // if they are in the same row
        if (path[i - 1].first == path[i].first)
        {
            if (path[i - 1].second == path[i].second - 1) cout <<"R";
            else cout << "L";
        }
        else{
            if (path[i - 1].first == path[i].first - 1) cout << "D";
            else cout << "U";
        }
    }


    return 0;
}

void bfs()
{
    queue<cpair> q;
    q.push( {si, sj} );
    level[si][sj] = 0;
    parent[si][sj] = {-1, -1};

    while (!q.empty())
    {
        cpair upair = q.front();
        q.pop();
        int i = upair.first;
        int j = upair.second;
        // These two lines are different from teacher
        if (visited[i][j]) continue;
        visited[i][j] = true;

        for (auto d : direc)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (!isValid(ni, nj)) continue;
            if (visited[ni][nj]) continue;
            if (g[ni][nj] == '#') continue;

            q.push( {ni, nj} );
            level[ni][nj] = level[i][j] + 1;
            parent[ni][nj] = {i, j};

        }
    }


}

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}