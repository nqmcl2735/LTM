//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 500005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct dinh
{
    int low = 0, num = 0;
};
vector <int> ke[maxn];
vector <int> kevung[maxn];
int n, m, time_DFS;
dinh a[maxn];
int cnt = 0, top = 0;
int que[maxn];
int dd[maxn];
int scc = 0;
ll dp[maxn];
ll p[maxn];
ll w[maxn];
vector <int> res[maxn];
void dfs (int u)
{
    a[u].num = a[u].low = ++time_DFS;
    que[++top] = u;
    for (int i = 0; i < sz(ke[u]); i ++)
    {
        int v = ke[u][i];
        if (dd[v]) continue;
        if (!a[v].num)
        {
            dfs(v);
            a[u].low = min(a[u].low, a[v].low);
        }
        else a[u].low = min(a[u].low, a[v].num);
    }
    if (a[u].low == a[u].num)
    {
        scc++;
        while (1 != 0)
        {
            int v = que[top--];
            res[scc].PB(v);
            dd[v] = scc;
            if (v == u) break;
        }
        for (int v : res[scc]) p[scc] += w[v];
    }
}
bool game[maxn];
ll qhd(int u)
{
    if (dp[u]) return dp[u];
    if (game[u])
        dp[u] = p[u];
    else dp[u] = - 2000000000;
    for (int v : kevung[u])
        dp[u] = max(dp[u], qhd(v) + p[u]);
    return dp[u];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        ke[u].PB(v);
    }
//    for (int i = 1; i <= n; i ++)
//        cin >> w[i];
    int s, g;
    for (int i = 1; i <= n; i++)
        if (!a[i].num) dfs(i);
    for (int i = 1; i <= n; i ++)
        if (!dd[i]) {
            p[++scc] = w[i];
            dd[i] = scc;
        }
//    cin >> s >> g;
//    for (int i = 1; i <= g; i ++)
//    {
//        int u;
//        cin >> u;
//        game[dd[u]] = 1;
//    }
    cout << scc;
//    for (int i = 1; i <= n; i ++)
//        for (int v : ke[i])
//            if (dd[v] != dd[i]) kevung[dd[i]].PB(dd[v]);
//    cout << qhd(dd[s]);
}
