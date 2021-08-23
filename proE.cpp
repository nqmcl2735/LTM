//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
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
    int low = 0, num = 0, pre;
    bool game;
};
vector <int> ke[maxn];
int n, m, time_DFS;
dinh a[maxn];
int cnt = 0, top = 0;
int que[maxn];
int dd[maxn];
int scc = 0;
vector <int> ltm[maxn];
map <pii, ll> mp;
ll ans[maxn];
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
            ltm[scc].PB(v);
            dd[v] = scc;
            if (v == u) break;
        }
        ans[scc] = 1ll * sz(ltm[scc]) * (sz(ltm[scc]) - 1);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        pii x = {u, v};
        if (!mp[x]) ke[u].PB(v);
        mp[x] = 1;
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        if (!a[i].num) dfs(i);
    for (int i = 1; i <= scc; i ++)
        res += ans[i];
    for (int i = 1; i <= n; i ++)
        for (int v : ke[i]) if(dd[v] == dd[i])
        res -= mp[{i, v}];
    cout << res;
}
