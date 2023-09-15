#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1510, M = N << 1;

int n;
int h[N], w[N], e[M], ne[N], idx;
int f[N][3];
int st[N];

void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
    f[u][0] = 1e9, f[u][1] = w[u], f[u][2] = 0;
    for (int i = h[u]; ~ i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][1] += min(f[j][0], min(f[j][1], f[j][2]));
        f[u][2] += min(f[j][0], f[j][1]);
    }
    
    for (int i = h[u]; ~ i; i = ne[i])
    {
        int j = e[i];
        // Assuming we let j be the guard node, then there are two possibilities in f[u][2]
        // 1. f[j][1] is the minimum, then we do not need to change anything.
        // 2. f[j][0] is the minimum, then we need to add the difference.
        // By iterate through every node j, wo can get the minimum number.
        // If, f[u][2]'s minimum elements are all f[j][0], then our transfer formula will select the best j to be the guard.
        // Else, during the iteration, we still cal through j, but the ans is still f[u][2], since other choices is always bigger via 2.
        f[u][0] = min(f[u][0], f[u][2] + f[j][1] - min(f[j][0], f[j][1]));
    }
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ )
    {
        int a, b, c, m;
        cin >> a >> c >> m;
        w[a] = c;
        for (int j = 1; j <= m; j ++ )
        {
            cin >> b;
            st[b] = true;
            add(a, b);
        }
    }
    
    int root = 0;
    while (st[++ root]);
    
    dfs(root);
    
    cout << min(f[root][0], f[root][1]) << endl;
    
    return 0;
}
