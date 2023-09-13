#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1550, M = N << 1;

int n;
int h[N], e[M], ne[M], idx;
int f[N][2];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    f[u][0] = 0, f[u][1] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += f[j][1];
        f[u][1] += min(f[j][1], f[j][0]);
    }
}

int main()
{
    while (cin >> n)
    {
        idx = 0;
        memset(h, -1, sizeof h);
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n; i ++ )
        {
            int a, b, siz;
            scanf("%d:(%d)", &a, &siz);
            for (int j = 1; j <= siz; j ++ )
            {
                cin >> b;
                add(a, b);
                st[b] = true;
            }
        }

        int root = -1;
        while (st[++ root]);
        dfs(root);

        cout << min(f[root][0], f[root][1]) << endl;
    }

    return 0;
}