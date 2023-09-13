#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int f[N][N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dfs(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa) continue;
        dfs(v, u);
        for (int j = m; j >= 0; j -- )
            for (int k = 0; k <= j - 1; k ++ )
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[v][k] + w[i]);
    }
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    dfs(1, -1);

    cout << f[1][m] << endl;

    return 0;
}