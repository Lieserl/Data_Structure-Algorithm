#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5e4 + 10;

int n, m;
int p[N], d[N];

// d[x] stands for the distance from x to root;
// if (d[x] - d[y]) % 3 = 0, x and y belong to the same species;
// if (d[x] - d[y]) % 3 = 1, x eat y;
// if (d[x] - d[y]) % 3 = 2 y eat x;

int find(int x)
{
    if (p[x] != x)
    {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        p[i] = i;

    int res = 0;
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (x > n || y > n)
        {
            res++;
            continue;
        }

        int px = find(x), py = find(y);
        if (op == 1)
        {
            if (px == py && (d[x] - d[y]) % 3)
                res++;
            else if (px != py)
            {
                p[px] = py;
                d[px] = d[y] - d[x];
            }
        }
        else
        {
            if (px == py && (d[x] - d[y] - 1) % 3)
                res++;
            else if (px != py)
            {
                p[px] = py;
                d[px] = d[y] - d[x] + 1;
            }
        }
    }

    cout << res << endl;

    return 0;
}
