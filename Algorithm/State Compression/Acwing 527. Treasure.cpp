#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 14, M = 1 << N, INF = 0x3f3f3f3f;

int n, m;
int d[N][N];
int g[M];
int f[M][N];

int main()
{
    cin >> n >> m;

    memset(d, 0x3f, sizeof d);

    for (int i = 0; i < n; i++)
        d[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        d[a][b] = d[b][a] = min(d[a][b], w);
    }

    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if (d[j][k] != INF)
                        g[i] |= 1 << k;

    memset(f, 0x3f, sizeof f);

    for (int i = 0; i < n; i++)
        f[1 << i][0] = 0;

    for (int i = 0; i < 1 << n; i++)
        for (int j = (i - 1) & i; j; j = (j - 1) & i)
            if ((g[j] & i) == i)
            {
                int remain = i ^ j;
                int cost = 0;
                for (int k = 0; k < n; k++)
                    if (remain >> k & 1)
                    {
                        int t = INF;
                        for (int u = 0; u < n; u++)
                            if (j >> u & 1)
                                t = min(t, d[u][k]);
                        cost += t;
                    }

                for (int k = 1; k <= n; k++)
                    f[i][k] = min(f[i][k], f[j][k - 1] + cost * k);
            }

    int res = INF;
    for (int k = 1; k < n; k++)
        res = min(res, f[(1 << n) - 1][k]);

    cout << res << endl;

    return 0;
}
