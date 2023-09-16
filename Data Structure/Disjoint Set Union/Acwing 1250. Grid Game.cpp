#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 4e4 + 10;


int n, m;
int dx[2] = {0, 1}, dy[2] = {1, 0};
int p[N];

int get_idx(int x, int y)
{
    return (x - 1) * n + y;
}

int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n * n; i ++ ) p[i] = i;

    int res = 0;
    for (int i = 1; i <= m; i ++ )
    {
        int x, y, idx;
        char ch;
        cin >> x >> y >> ch;
        
        if (ch == 'D') idx = 0;
        else idx = 1;

        int a = find(get_idx(x, y)), b = find(get_idx(x + dx[idx], y + dy[idx]));
        if (a == b)
        {
            res = i;
               break;
        }
        else
           p[b] = a;
    }

    cout << res << endl;

    return 0;
}
