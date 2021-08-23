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
#define maxn 100005
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
int n, m, time_DFS = 0;
dinh a[maxn];
int cnt = 0, top = 0;
int que[maxn];
int dd[maxn];
int scc = 0;
int dp[maxn];
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
            dd[v] = scc;
            if (v == u) break;
        }
    }
}
int qhd(int u)
{
    if (dp[u]!= -1) return dp[u];
    dp[u] = 1;
    for (int v : kevung[u])
        dp[u] = max(dp[u], qhd(v) + 1);
    return dp[u];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int test;
    cin  >> test;
    while (test --)
    {
    time_DFS = 0;
    top = 0;
    cnt = 0;
    reset(que);
    memset(dp , -1 , sizeof(dp));
    reset(dd);
    scc = 0;
    for (int i = 1; i <= maxn ; i ++)
    {
        a[i].num = a[i].low = 0;
    }
    reset(ke); reset(kevung);
    vi x;
    int co[maxn];
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        ke[u].PB(v);
        x.PB(u); x.PB(v);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int u : x)
        if (!a[u].num) dfs(u);
    for (int i : x)
        for (int v : ke[i]) if (dd[i] != dd[v]) kevung[dd[i]].PB(dd[v]);
    int res = -1;
    for (int i = 1; i <= scc; i ++)
    {
        qhd(i);
        res = max(res, dp[i]);
    }
    cout << ((res == scc) ? "YES\n" : "NO\n");
    }
}

