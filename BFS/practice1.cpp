//connected or not
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        mat[a][b] = 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (mat[a][b] == 1 || a==b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}








//connected nodes
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        vector<int> v;
        for (int i = 0; i < mat[a].size(); i++)
        {
            v.push_back(mat[a][i]);
        }
        if (v.size() == 0)
            cout << -1;
        else
        {
            sort(v.rbegin(), v.rend());
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}







//can go
#include <bits/stdc++.h>
using namespace std;

char mat[1005][1005];
bool visit[1005][1005];
bool found = false;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m)
        return false;
    return true;
}
void DFS(int src_i, int src_j)
{
    if (mat[src_i][src_j] == 'B')
    {
        found = true;
    }
    visit[src_i][src_j] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = src_i + d[i].first;
        int cj = src_j + d[i].second;
        if (valid(ci, cj) == true && mat[ci][cj] != '#' && visit[ci][cj] == false)
        {
            DFS(ci, cj);
        }
    }
}

int main()
{
    int src_i, src_j;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'A')
            {
                src_i = i;
                src_j = j;
            }
        }
    }

    memset(visit, false, sizeof(visit));
    DFS(src_i, src_j);

    if (found)cout << "YES";
    else cout << "NO";
}













//count appertment
#include <bits/stdc++.h>
using namespace std;

char arr[1005][1005];
bool visit[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m)
        return false;
    return true;
}

void DFS(int src_i, int src_j)
{
    visit[src_i][src_j] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = src_i + d[i].first;
        int cj = src_j + d[i].second;
        if (valid(ci, cj) == true && arr[ci][cj] == '.' && visit[ci][cj] == false)
        {
            DFS(ci, cj);
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int cnt = 0;

    memset(visit, false, sizeof(visit));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.' && visit[i][j] == false)
            {
                DFS(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}























//count appertment ii 
#include <bits/stdc++.h>
using namespace std;

char arr[1005][1005];
bool visit[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m)
        return false;
    return true;
}
int DFS(int src_i, int src_j, int cnt)
{
    visit[src_i][src_j] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = src_i + d[i].first;
        int cj = src_j + d[i].second;
        if (valid(ci, cj) == true && arr[ci][cj] == '.' && visit[ci][cj] == false)
        {
            cnt = DFS(ci, cj, cnt + 1);
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(visit, false, sizeof(visit));
    vector<int> rm;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.' && visit[i][j] == false)
            {
                int cnt = 1;
                cnt = DFS(i, j, cnt);
                rm.push_back(cnt);
            }
        }
    }
    sort(rm.begin(), rm.end());

    if (rm.size() == 0)
        cout << "0";

    for (int i = 0; i < rm.size(); i++)
    {
        cout << rm[i] << " ";
    }

    return 0;
}