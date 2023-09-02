#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 15, M = 1 << N;

struct Node
{
    int e, v;
};

int n, m;
vector<Node> head[N];
int f[M];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;
        head[s].push_back({e, v});
    }
    
    
}
