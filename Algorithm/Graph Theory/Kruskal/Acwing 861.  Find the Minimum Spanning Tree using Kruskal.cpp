#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 2e5 + 10;

int n, m;
int p[N];

struct Edge
{
    int a, b, w;

    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edge[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {a, b, w};
    }

    sort(edge, edge + m);

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1)
        cout << "impossible" << endl;
    else
        cout << res << endl;

    return 0;
}