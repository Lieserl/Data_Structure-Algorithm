#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1e4 + 10;

int n;
int res;
vector<PII> s[N];
int f[N][2];

void dfs(int u, int fa)
{
    f[u][1] = f[u][0] = 0;
    
    for (auto v : s[u])
    {
        if (v.x == fa) continue;
        dfs(v.x, u);
        if (f[u][0] <= f[v.x][0] + v.y) f[u][1] = f[u][0], f[u][0] = f[v.x][0] + v.y;
        else if (f[u][1] < f[v.x][0] + v.y) f[u][1] = f[v.x][0] + v.y;
    }
    
    res = max(res, f[u][0] + f[u][1]);
}

int main()
{   
    cin >> n;
    
    for (int i = 1; i < n; i ++ )
    {
        int a, b, w;
        cin >> a >> b >> w;
        s[a].push_back({b, w});
        s[b].push_back({a, w});
    }
    
    dfs(1, -1);
    
    cout << res << endl;
    
    return 0;
}
