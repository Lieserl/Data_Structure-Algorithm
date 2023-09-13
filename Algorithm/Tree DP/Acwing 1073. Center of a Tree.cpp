#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e4 + 10, M = N << 1, INF = 0x3f3f3f3f;

int n;
int h[N], e[M], ne[M], w[M], idx = 0;
int f[N][2], s[N][2];
int up[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dfs1(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        dfs1(j, u);
        if (w[i] + f[j][0] >= f[u][0])
            f[u][1] = f[u][0], f[u][0] = w[i] + f[j][0], s[u][1] = s[u][0], s[u][0] = j;
        else if (w[i] + f[j][0] > f[u][1])
            f[u][1] = w[i] + f[j][0], s[u][1] = j;
    }
}

void dfs2(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        if (j == s[i][0]) up[j] = w[i] + max(f[u][1], up[u]);
        else up[j] = w[i] + max(f[u][0], up[u]);
        dfs2(j, u);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    
    dfs1(1, -1);
    dfs2(1, -1);
    
    int res = INF;
    for (int i = 1; i <= n; i ++ )
        res = min(res, max(f[i][0], up[i]));
    
    cout << res << endl;
    
    return 0;
}
